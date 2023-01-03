#ifndef ITABLE
#define ITABLE

#include <functional>

struct Chip8;

typedef std::function<void(Chip8&)> instruction;

void OP_0(Chip8& chip);
void OP_8(Chip8& chip);
void OP_E(Chip8& chip);
void OP_F(Chip8& chip);

struct InstructionTable
{
    instruction i_table[255]; // one over 0xFB
    InstructionTable();
    instruction& operator[](const int idx)
    {
        return i_table[idx];
    }
};

#endif