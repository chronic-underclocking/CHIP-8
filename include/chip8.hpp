#ifndef CHIP8
#define CHIP8

#include <cstdint>
#include "instructionTable.hpp"

struct Chip8
{
    uint8_t registers[16] = {};
    uint8_t memory[4096] = {};
    uint16_t idx_register;
    uint16_t pc;
    uint16_t stack[16] = {};
    uint8_t stack_pointer;
    uint8_t delayTimer;
    uint8_t soundTimer;
    uint8_t keys[16] = {};
    bool display[64 * 32] = {};
    uint16_t opcode;
    InstructionTable table;
    bool draw;

    Chip8();
    bool loadFile(const char* filename);
    void nextCycle();
    uint8_t random();
};

#endif