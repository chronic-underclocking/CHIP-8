#include "instructions.hpp"
#include <iostream>

// CLS
void _00E0(Chip8& chip)
{
    for(int i = 0; i < 64 * 32; i++)
    {
        chip.display[i] = 0;
    }
}

// RET
void _00EE(Chip8& chip)
{
    chip.stack_pointer--;
    chip.pc = chip.stack[chip.stack_pointer];
}

// JP addr
void _1nnn(Chip8& chip)
{
    chip.pc = chip.opcode & 0x0FFFu;
}

// CALL addr
void _2nnn(Chip8& chip)
{
    chip.stack[chip.stack_pointer] = chip.pc;
    chip.stack_pointer++;
    chip.pc = chip.opcode & 0x0FFFu;
}

// SE Vx, byte
void _3xkk(Chip8& chip)
{
    if(chip.registers[((chip.opcode & 0x0F00u) >> 8u)] 
        == (chip.opcode & 0x00FFu))
    {
        chip.pc += 2;
    }
}

// SNE Vx, byte
void _4xkk(Chip8& chip)
{
    if(chip.registers[((chip.opcode & 0x0F00u) >> 8u)] 
        != (chip.opcode & 0x00FFu))
    {
        chip.pc += 2;
    }
}

// SE Vx, Vy
void _5xy0(Chip8& chip)
{
    if(chip.registers[((chip.opcode & 0x0F00u) >> 8u)] 
        == chip.registers[((chip.opcode & 0x00F0u) >> 4u)])
    {
        chip.pc += 2;
    }
}

// LD Vx, byte
void _6xkk(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] = (chip.opcode & 0x00FFu);
}

// ADD Vx, byte
void _7xkk(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] += (chip.opcode & 0x00FFu);
}

// LD Vx, Vy
void _8xy0(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] =
        chip.registers[((chip.opcode & 0x00F0u) >> 4u)];
}

// OR Vx, Vy
void _8xy1(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] |=
        chip.registers[((chip.opcode & 0x00F0u) >> 4u)];
}

// AND Vx, Vy
void _8xy2(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] &=
        chip.registers[((chip.opcode & 0x00F0u) >> 4u)];
}

// XOR Vx, Vy
void _8xy3(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] ^=
        chip.registers[((chip.opcode & 0x00F0u) >> 4u)];
}

// ADD Vx, Vy
void _8xy4(Chip8& chip)
{
    uint8_t val1 = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
    uint8_t val2 = chip.registers[((chip.opcode & 0x00F0u) >> 4u)];

    if(val1 + val2 > 255) chip.registers[0xF] = 1;
    else chip.registers[0xF] = 0;

    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] = 
        ((val1 + val2) & 0xFFu);
}

// SUB Vx, Vy
void _8xy5(Chip8& chip)
{
    uint8_t val1 = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
    uint8_t val2 = chip.registers[((chip.opcode & 0x00F0u) >> 4u)];

    if(val1 > val2) chip.registers[0xF] = 1;
    else chip.registers[0xF] = 0;

    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] -= val2;
}

// SHR Vx {, Vy << "\n";}
void _8xy6(Chip8& chip)
{
    uint8_t val = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];

    if(val & 0x1u) chip.registers[0xF] = 1;
    else chip.registers[0xF] = 0;

    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] /= 2;
}

// SUBN Vx, Vy
void _8xy7(Chip8& chip)
{
    uint8_t val1 = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
    uint8_t val2 = chip.registers[((chip.opcode & 0x00F0u) >> 4u)];

    if(val2 > val1) chip.registers[0xF] = 1;
    else chip.registers[0xF] = 0;

    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] = val2 - val1;
}

// SHL Vx {, Vy << "\n";}
void _8xyE(Chip8& chip)
{
    uint8_t val = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];

    if(val & 0x80u) chip.registers[0xF] = 1;
    else chip.registers[0xF] = 0;

    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] *= 2;
}

// SNE Vx, Vy
void _9xy0(Chip8& chip)
{
    if(chip.registers[((chip.opcode & 0x0F00u) >> 8u)] 
        != chip.registers[((chip.opcode & 0x00F0u) >> 4u)])
    {
        chip.pc += 2;
    }
}

// LD I, addr
void _Annn(Chip8& chip)
{
    chip.idx_register = (chip.opcode & 0x0FFFu);
}

// JP V0, address
void _Bnnn(Chip8& chip)
{
    chip.pc = (chip.opcode & 0x0FFFu) + chip.registers[0];
}

// RND Vx, byte
void _Cxkk(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] =
        (chip.random() & (chip.opcode & 0x00FFu));
}

// DRW Vx, Vy, height
void _Dxyn(Chip8& chip)
{
	uint8_t x = chip.registers[((chip.opcode & 0x0F00u) >> 8u)] % 64;
	uint8_t y = chip.registers[((chip.opcode & 0x00F0u) >> 4u)] % 32;
    uint8_t height = chip.opcode & 0x000Fu;

	chip.registers[0xF] = 0;

	for (uint8_t row = 0; row < height; row++)
	{
		uint8_t sprite = chip.memory[chip.idx_register + row];

		for (uint8_t col = 0; col < 8; col++)
		{
			uint8_t spritePixel = sprite & (0x80u >> col);
			bool* screenPixel = &chip.display[(y + row) * 64 + (x + col)];

			if (spritePixel)
			{
				if (*screenPixel == 1)
				{
					chip.registers[0xF] = 1;
				}
                
				*screenPixel ^= 1;
			}
		}
	}
    chip.draw = true;
}

// SKP Vx
void _Ex9E(Chip8& chip)
{
	uint8_t key = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];

	if(chip.keys[key])
	{
		chip.pc += 2;
	}
}

// SKNP Vx
void _ExA1(Chip8& chip)
{
	uint8_t key = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];

	if(!chip.keys[key])
	{
		chip.pc += 2;
	}
}

// LD Vx, DT
void _Fx07(Chip8& chip)
{
    chip.registers[((chip.opcode & 0x0F00u) >> 8u)] = chip.delayTimer;
}

// LD Vx, K
void _Fx0A(Chip8& chip)
{
    uint8_t Vx = (chip.opcode & 0x0F00u) >> 8u;

    while (true)
    {
        if(chip.keys[0])
        {
            chip.registers[Vx] = 0;
        }
        else if(chip.keys[1])
        {
            chip.registers[Vx] = 1;
        }
        else if(chip.keys[2])
        {
            chip.registers[Vx] = 2;
        }
        else if(chip.keys[3])
        {
            chip.registers[Vx] = 3;
        }
        else if(chip.keys[4])
        {
            chip.registers[Vx] = 4;
        }
        else if(chip.keys[5])
        {
            chip.registers[Vx] = 5;
        }
        else if(chip.keys[6])
        {
            chip.registers[Vx] = 6;
        }
        else if(chip.keys[7])
        {
            chip.registers[Vx] = 7;
        }
        else if(chip.keys[8])
        {
            chip.registers[Vx] = 8;
        }
        else if(chip.keys[9])
        {
            chip.registers[Vx] = 9;
        }
        else if(chip.keys[10])
        {
            chip.registers[Vx] = 10;
        }
        else if(chip.keys[11])
        {
            chip.registers[Vx] = 11;
        }
        else if(chip.keys[12])
        {
            chip.registers[Vx] = 12;
        }
        else if(chip.keys[13])
        {
            chip.registers[Vx] = 13;
        }
        else if(chip.keys[14])
        {
            chip.registers[Vx] = 14;
        }
        else if(chip.keys[15])
        {
            chip.registers[Vx] = 15;
        }
    }
}

// LD DT, Vx
void _Fx15(Chip8& chip)
{
    chip.delayTimer = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
}

// LD ST, Vx
void _Fx18(Chip8& chip)
{
    chip.soundTimer = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
}

// ADD I, Vx
void _Fx1E(Chip8& chip)
{
    chip.idx_register += chip.registers[((chip.opcode & 0x0F00u) >> 8u)];
}

// LD F, Vx
void _Fx29(Chip8& chip)
{
    chip.idx_register = 0x050 +
                    (5 * chip.registers[((chip.opcode & 0x0F00u) >> 8u)]);
}

// LD B, Vx
void _Fx33(Chip8& chip)
{
    uint8_t val = chip.registers[((chip.opcode & 0x0F00u) >> 8u)];

    chip.memory[chip.idx_register + 2] = val % 10;
    val /= 10;
    chip.memory[chip.idx_register + 1] = val % 10;
    val /= 10;
    chip.memory[chip.idx_register] = val % 10;
}

// LD [I], Vx
void _Fx55(Chip8& chip)
{
    uint8_t val = ((chip.opcode & 0x0F00u) >> 8u);

    for(uint8_t i = 0; i < val; i++)
    {
        chip.memory[chip.idx_register + i] = chip.registers[i];
    }
}

// LD Vx, [I]
void _Fx65(Chip8& chip)
{
    uint8_t val = ((chip.opcode & 0x0F00u) >> 8u);

    for(uint8_t i = 0; i < val; i++)
    {
        chip.registers[i] = chip.memory[chip.idx_register + i];
    }
}