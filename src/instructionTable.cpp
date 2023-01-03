#include "instructionTable.hpp"
#include "instructions.hpp"

void OP_0(Chip8& chip)
{
    InstructionTable f_table;
    f_table.i_table[0x10 + (chip.opcode & 0x000Fu)](chip);
}

void OP_8(Chip8& chip)
{
    InstructionTable f_table;
    f_table.i_table[0x80 + (chip.opcode & 0x000Fu)](chip);
}

void OP_E(Chip8& chip)
{
    InstructionTable f_table;
    f_table.i_table[0xE0 + (chip.opcode & 0x000Fu)](chip);
}

void OP_F(Chip8& chip)
{
    InstructionTable f_table;
    if((chip.opcode & 0x00FFu) == 0x0055u)
    {
        f_table.i_table[0xF1](chip);
    }
    else if ((chip.opcode & 0x00FFu) == 0x0065u)
    {
        f_table.i_table[0xF2](chip);
    }
    else
    {
        f_table.i_table[0xF0 + (chip.opcode & 0x000Fu)](chip);
    }
}

InstructionTable::InstructionTable()
{
    // nullify array
    for (int i = 0; i < 255; i++)
    {
        i_table[i] = [](Chip8 &) {};
    }

    i_table[0x0] = OP_0;
    i_table[0x10] = _00E0;
    i_table[0x1E] = _00EE;

    i_table[0x1] = _1nnn;
    i_table[0x2] = _2nnn;
    i_table[0x3] = _3xkk;
    i_table[0x4] = _4xkk;
    i_table[0x5] = _5xy0;
    i_table[0x6] = _6xkk;
    i_table[0x7] = _7xkk;

    i_table[0x8] = OP_8;
    i_table[0x80] = _8xy0;
    i_table[0x81] = _8xy1;
    i_table[0x82] = _8xy2;
    i_table[0x83] = _8xy3;
    i_table[0x84] = _8xy4;
    i_table[0x85] = _8xy5;
    i_table[0x86] = _8xy6;
    i_table[0x87] = _8xy7;
    i_table[0x8E] = _8xyE;

    i_table[0x9] = _9xy0;
    i_table[0xA] = _Annn;
    i_table[0xB] = _Bnnn;
    i_table[0xC] = _Cxkk;
    i_table[0xD] = _Dxyn;

    i_table[0xE] = OP_E;
    i_table[0xE1] = _ExA1;
    i_table[0xEE] = _Ex9E;

    i_table[0xF] = OP_F;
    i_table[0xF1] = _Fx55; // special case
    i_table[0xF2] = _Fx65; // special case
    i_table[0xF3] = _Fx33;
    i_table[0xF5] = _Fx15;
    i_table[0xF7] = _Fx07;
    i_table[0xF8] = _Fx18;
    i_table[0xF9] = _Fx29;
    i_table[0xFA] = _Fx0A;
    i_table[0xFE] = _Fx1E;
}