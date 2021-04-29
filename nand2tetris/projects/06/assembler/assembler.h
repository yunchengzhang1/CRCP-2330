//
// Created by AZ on 4/26/2021.
//
#include "parser.h"
#include "parser.h"
#include <iostream>
#include <unordered_map>
#ifndef INC_06_ASSEMBLER_H
#define INC_06_ASSEMBLER_H

class Assembler {
private:
    string input_filename_;
    uint16_t stack_pointer_;
    unordered_map<string, uint16_t> symbol_table_;
public:
    Assembler(const string& in){
        input_filename_(in),
        stack_pointer_(0x0010),
        symbol_table_({
        {"SP", 		0x0},
        {"LCL", 	0x1},
        {"ARG",  	0x2},
        {"THIS", 	0x3},
        {"THAT", 	0x4},
        {"R0", 		0x0},
        {"R1", 		0x1},
        {"R2", 		0x2},
        {"R3", 		0x3},
        {"R4", 		0x4},
        {"R5", 		0x5},
        {"R6", 		0x6},
        {"R7", 		0x7},
        {"R8", 		0x8},
        {"R9", 		0x9},
        {"R10", 	0xA},
        {"R11", 	0xB},
        {"R12", 	0xC},
        {"R13", 	0xD},
        {"R14", 	0xE},
        {"R15", 	0xF},
        {"SCREEN",  0x4000},
        {"KBD",		0x6000} }){
//            look for labeled commands
            Parser p1(in);
            unsigned int word = 0;
            while (p1.hasMoreCommands()) {
                p1.advance();
                if (p1.commandType() == L_COMMAND) { 	// Label definition.
                    symbol_table_[p1.symbol()] = word;
                }
                else {
                    // If  regular command, give memory location.
                    word++;
                }
            }

//            look for variable declare
            Parser p2(in);
            while (p2.hasMoreCommands()) {
                p2.advance();
                if (p2.commandType() == A_COMMAND) {
                    std::string s = p2.symbol();
                    if (!isdigit(s.front()) && !symbol_table_.count(s)) {
                        // Var. declaration.
                        symbol_table_[s] = stack_pointer_++;
                    }
                }
            }
        }
    }

    void translate(ostream& out) const{
        Parser p(input_filename_);
        Code c;

        while (p.hasMoreCommands()) {
            p.advance();
            switch (p.commandType()) {
                case A_COMMAND:
                {
                    // immediate / memory position
                    string s = p.symbol();
                    // symbol define
                    bitset<16> addr;
                    // number to immediate
                    if (isdigit(s.front())) {
                        addr = c.immediate(s);
                    }
                    else {
                        // Reference to a variable
                        assert(symbol_table_.count(s));
                        addr = symbol_table_.at(s);
                    }

                    out << std::bitset<16>(addr) << std::endl;
                    break;
                }
                case C_COMMAND:
                {
                    bitset<16> dest(c.dest(p.dest()));
                    bitset<16> jump(c.jump(p.jump()));
                    bitset<16> comp(c.comp(p.comp())); 
                    bitset<16> instr(comp | dest | jump);
                    out << instr << endl;
                    break;
                }
                case L_COMMAND:
                    break;
            }
        }
    }




};

#endif //INC_06_ASSEMBLER_H
