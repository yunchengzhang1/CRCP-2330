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
//    front
    Code();

    uint16_t 	comp(const std::string&) const;

    uint8_t 	dest(const std::string&) const;

    uint8_t 	jump(const std::string&) const;

    uint16_t 	immediate(const std::string&) const;

private:
//    back
    std::unordered_map<std::string, uint16_t> opcodes_;

    std::unordered_map<std::string, uint8_t> jumps_;

    std::unordered_map<std::string, uint8_t> dests_;
};
#endif //INC_06_CODE_H
