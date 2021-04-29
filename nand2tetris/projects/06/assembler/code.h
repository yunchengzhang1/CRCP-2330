//
// Created by AZ on 4/28/2021.
//
#include <string>
#include <unordered_map>
#include <cassert>
#include <iostream>
#ifndef INC_06_CODE_H
#define INC_06_CODE_H
using namespace std;
class Code {

public:


    uint16_t 	comp(const std::string& s) const{
        if (opcodes_.count(s)){
            return opcodes_.at(s);
        }
    }

    uint8_t 	dest(const std::string& s) const{
        if (dests_.count(s)){
            return dests_.at(s);
        }
}

    uint8_t 	jump(const std::string& s) const{
        if (jumps_.count(s)){
            return jumps_.at(s);
        }
}

    uint16_t 	immediate(const std::string& s) const{
        int immediate;

        try {
            immediate = stoi(s);
        }
        catch (std::out_of_range) {
            cerr << "Error: " << s << " immediate out or range.";
            cerr << std::endl;
            throw std::runtime_error("Invalid immediate");
        }

        if (immediate < 0 || immediate > 32768) {
            cerr << "Error: " << s << " immediate out of range.";
            cerr << std::endl;
            throw std::runtime_error("Invalid immediate");
        }
        uint16_t res = immediate;
        return res;
    }

private:
//    back
    //    front
    Code():opcodes_({
                            // Comp. (a=0)
                            {"0",		0b1110101010000000},
                            {"1",		0b1110111111000000},
                            {"-1", 		0b1110111010000000},
                            {"D",		0b1110001100000000},
                            {"A",		0b1110110000000000},
                            {"!D", 		0b1110001101000000},
                            {"!A", 		0b1110110001000000},
                            {"-D", 		0b1110001111000000},
                            {"-A", 		0b1110110011000000},
                            {"D+1", 	0b1110011111000000},
                            {"A+1", 	0b1110110111000000},
                            {"D-1", 	0b1110001110000000},
                            {"A-1", 	0b1110110010000000},
                            {"D+A", 	0b1110000010000000},
                            {"D-A", 	0b1110010011000000},
                            {"A-D", 	0b1110000111000000},
                            {"D&A", 	0b1110000000000000},
                            {"D|A", 	0b1110010101000000},
                            // Comp. (a=1)
                            {"M",		0b1111110000000000},
                            {"!M", 		0b1111110001000000},
                            {"-M", 		0b1111110011000000},
                            {"M+1", 	0b1111110111000000},
                            {"M-1", 	0b1111110010000000},
                            {"D+M", 	0b1111000010000000},
                            {"D-M", 	0b1111010011000000},
                            {"M-D", 	0b1111000111000000},
                            {"D&M", 	0b1111000000000000},
                            {"D|M", 	0b1111010101000000}
                    }),

           jumps_({
                          {"", 		0b000},
                          {"JGT", 	0b001},
                          {"JEQ", 	0b010},
                          {"JGE", 	0b011},
                          {"JLT", 	0b100},
                          {"JNE", 	0b101},
                          {"JLE", 	0b110},
                          {"JMP",		0b111}
                  }),

           dests_({ 	// d1 d2 d3 0 0 0
                          {"", 		0b000000},
                          {"M", 		0b001000},
                          {"D", 		0b010000},
                          {"MD", 		0b011000},
                          {"A", 		0b100000},
                          {"AM", 		0b101000},
                          {"AD", 		0b110000},
                          {"AMD",		0b111000}
                  })
    {}

    unordered_map<string, uint8_t> jumps_;

    unordered_map<string, uint8_t> dests_;
};
#endif //INC_06_CODE_H
