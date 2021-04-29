//
// Created by AZ on 4/26/2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#ifndef INC_06_PARSER_H
#define INC_06_PARSER_H
enum Command {A_COMMAND, C_COMMAND, L_COMMAND};
// Immediate for loading into A, Comp. instruction or symbol, respectively.
using namespace std;
class Parser {
private:
//    notice comment
    bool isComment(string&) const{
        if (line.find("//") == 0)
            return true;
        else
            return false;
    }

    bool validCommandFormat(const std::string&) const{
        if (s.find("@") == 0) // Load into A command
            return true;
        if (s.find("(") != string::npos) // Label
            return true;
        if (s.find("=") != string::npos || s.find(";") != string::npos) // Comp. command
            return true;
        return false;
    }
    void 			trimLeft(string&) const{
// Trim left white spaces.
        const string blank_spaces = " \t\v\n\f\r";
        line.erase(0, line.find_first_not_of(blank_spaces));
    }
    void 			trimRight(string&) const{
// Trim right white spaces and delete comments.
        const string blank_spaces = " \t\v\n\f\r";

        std::size_t comment_pos = line.find("//");
        if (comment_pos != 0 && comment_pos != string::npos) {
            // There is a comment following a command.
            line.erase(line.find_first_of("//"), string::npos);
        }

        line.erase(line.find_last_not_of(blank_spaces)+1, std::string::npos);
    }
    void 			printFileInfo(ostream&){
        std::istream::streampos parsed_pos = f_.tellg(); // Saving stream position.
        std::ios::iostate status = f_.rdstate();
        f_.clear();
        f_.seekg(0, std::ios::beg);
        unsigned int lines = 0;
        unsigned int comments = 0;
        std::string s;
        while (getline(f_, s)) {
            trimLeft(s);
            if (isComment(s))
                comments++;
            lines++;
        }
        os << "File has " << lines << " lines. ";
        os << lines-comments << " are commands. \n";

        f_.seekg(parsed_pos);		// Restoring stream to its original position.
        f_.setstate(status);
    }

    std::string 	filename_;
    std::ifstream 	f_;
    std::string 	current_line_;
    unsigned int 	current_line_number_;


public:
    Parser(const std::string& filename):
            filename_(filename),
            current_line_number_(0)
    {
        f_.open(filename.c_str(), std::ifstream::in); // (Open() wants a char* name.)
        assert(f_.is_open());
    }

    ~Parser() {
        f_.close();
    }
    bool hasMoreCommands(){
        if (f_.eof()) {	// No more file to check.
            return false;
        }

        // We have to look ahead for commands, skipping comments and blank lines.
        istream::streampos parsed_pos 	= f_.tellg(); // Saving stream state.
        ios::iostate 		status 		= f_.rdstate();
        f_.clear();

        bool res 					= false;
        unsigned int lines_read 	= 0; 	// So that if there's an error it displays where.
        do {
            std::string s;
            std::getline(f_, s);
            lines_read++;
            trimLeft(s);
            if (!s.empty() && !isComment(s)) { 	// Found a command line...
                if (!validCommandFormat(s)) { 	// ...but it's an invalid line!
                    std::cerr << "Error at line ";
                    std::cerr << current_line_number_ + lines_read;
                    std::cerr << ". '" << s << "': Invalid line" << std::endl;
                    throw std::runtime_error("Invalid line");
                }
                res = true;
                goto done;
            }
        } while (!f_.eof());

        done:
        f_.seekg(parsed_pos);		// Restoring stream to its original state.
        f_.setstate(status);
        return res;
    }
    void advance(){
        string s;
        do {
            getline(f_, s);
            current_line_number_++;
            trimLeft(s);
        } while (isComment(s) || s.empty());

        trimRight(s);
        current_line_ = s;
    }
    Command commandType() const{
        if (current_line_.find("@") == 0)
            return A_COMMAND;
        if (current_line_.find("(") != std::string::npos)
            return L_COMMAND;
        else
            return C_COMMAND;
    }
    string symbol() const{
        assert(commandType() == A_COMMAND || commandType() == L_COMMAND);
        std::string s = current_line_;
        s.erase(0,1); 				// Erasing '@' or '('
        size_t p = s.find(")");
        if (p != std::string::npos) // Looking for the ')'.
            s.erase(p, std::string::npos);

        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
    string dest() const{
//        command type is C
        assert(commandType() == C_COMMAND);
        std::string s = current_line_;
        size_t e = s.find("=");
        if (e == std::string::npos)
            s = ""; // Dest = null.
        else {
            s.erase(s.find("="), std::string::npos);
        }
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
    string comp() const{
        //        command type is C
        assert(commandType() == C_COMMAND);
        std::string s = current_line_;
        size_t p = s.find(";");
        if (p != std::string::npos)
            s.erase(p+1, std::string::npos);

        p = s.find("=");
        if (p != std::string::npos)
            s.erase(0, p+1);

        size_t end = s.find_last_not_of(";");
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s.substr(0, end+1);
    }
    string jump() const{
        //        command type is C
        assert(commandType() == C_COMMAND);
        std::string s = current_line_;
        size_t p = s.find(";");
        if (p != std::string::npos) {
            s.erase(0, p+1);
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            return s;
        }
        // No jmp mnemonic.
        return "";
    }

    // getters
    string currentLine() const{
        assert(!current_line_.empty());
        std::string s = current_line_;
        return s;
    }
    unsigned int currentLineNumber() const{
        return current_line_number_;
    }


};
#endif //INC_06_PARSER_H
