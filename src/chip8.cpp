#include "chip8.hpp"
#include <time.h>
#include <random>
#include <fstream>

Chip8::Chip8()
{
    uint8_t sprites[81] = 
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    for(int i = 0; i < 80; i++)
    {
        memory[0x050 + i] = sprites[i];
    }

    pc = 0x200; // ROM instructions start address
	
    long int seed = (unsigned)(time(0));
	srand(seed);

    idx_register = 0;
    stack_pointer = 0;
    delayTimer = 0;
    soundTimer = 0;
    draw = false;
}

uint8_t Chip8::random()
{
    return (rand() % 256);
}

bool Chip8::loadFile(const char* filename)
{
    std::ifstream ROM(filename, std::ios::binary | std::ios::ate);
	if(ROM)
	{
		std::streampos size = ROM.tellg();
		char* buffer = new char[size];
		ROM.seekg(0, std::ios::beg);
		ROM.read(buffer, size);
		for(long int i = 0; i < size; i++)
		{
			memory[0x200 + i] = buffer[i];
		}
		delete[] buffer;
        ROM.close();
        return true;
	}
    return false;
}

void Chip8::nextCycle()
{
    // Fetch
    opcode = (memory[pc] << 8u) | (memory[pc + 1]);
    pc += 2;

    // Decode and execute
    table[(opcode & 0xF000u) >> 12u](*this);

    if(delayTimer > 0) delayTimer--;
    if(soundTimer > 0) soundTimer--;
}