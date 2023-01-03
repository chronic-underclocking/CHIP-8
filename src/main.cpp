#include <iostream>
#include "chip8.hpp"

int main(int argc, char *argv[])
{
	Chip8 chip;
    if(chip.loadFile("pong2.c8")) std::cout << "File loaded\n";
    for(int i = 0; i < 5; i++)
    {
        chip.nextCycle();
    }
}