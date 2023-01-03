#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "chip8.hpp"

Chip8 chip;
void checkKeysHeld()
{
            if (GetKeyState('1') & 0x8000)
            {
                chip.keys[1] = true;
            }
            else
            {
                chip.keys[1] = false;
            }
            if (GetKeyState('2') & 0x8000)
            {
                chip.keys[2] = true;
            }
            else
            {
                chip.keys[2] = false;
            }
            if (GetKeyState('3') & 0x8000)
            {
                chip.keys[3] = true;
            }
            else
            {
                chip.keys[3] = false;
            }
            if (GetKeyState('4') & 0x8000)
            {
                chip.keys[0xC] = true;
            }
            else
            {
                chip.keys[0xC] = false;
            }
            if (GetKeyState('Q') & 0x8000)
            {
                chip.keys[4] = true;
            }
            else
            {
                chip.keys[4] = false;
            }
            if (GetKeyState('W') & 0x8000)
            {
                chip.keys[5] = true;
            }
            else
            {
                chip.keys[5] = false;
            }
            if (GetKeyState('E') & 0x8000)
            {
                chip.keys[6] = true;
            }
            else
            {
                chip.keys[6] = false;
            }
            if (GetKeyState('R') & 0x8000)
            {
                chip.keys[0xD] = true;
            }
            else
            {
                chip.keys[0xD] = false;
            }
            if (GetKeyState('A') & 0x8000)
            {
                chip.keys[7] = true;
            }
            else
            {
                chip.keys[7] = false;
            }
            if (GetKeyState('S') & 0x8000)
            {
                chip.keys[8] = true;
            }
            else
            {
                chip.keys[8] = false;
            }
            if (GetKeyState('D') & 0x8000)
            {
                chip.keys[9] = true;
            }
            else
            {
                chip.keys[9] = false;
            }
            if (GetKeyState('F') & 0x8000)
            {
                chip.keys[0xE] = true;
            }
            else
            {
                chip.keys[0xE] = false;
            }
            if (GetKeyState('Z') & 0x8000)
            {
                chip.keys[0xA] = true;
            }
            else
            {
                chip.keys[0xA] = false;
            }
            if (GetKeyState('X') & 0x8000)
            {
                chip.keys[0] = true;
            }
            else
            {
                chip.keys[0] = false;
            }
            if (GetKeyState('C') & 0x8000)
            {
                chip.keys[0xB] = true;
            }
            else
            {
                chip.keys[0xB] = false;
            }
            if (GetKeyState('V') & 0x8000)
            {
                chip.keys[0xF] = true;
            }
            else
            {
                chip.keys[0xF] = false;
            }
}

int main(int argc, char *argv[])
{
    if(chip.loadFile("chip8-test-suite.ch8"))
    {
        chip.memory[0x1FF] = 0x1u;
        for(;;)
        {
            checkKeysHeld();

            chip.nextCycle();

            if(chip.draw)
            {
                system("cls");
                for(int i = 0; i < 32; i++)
                {
                    for(int j = 0; j < 64; j++)
                    {
                        if(chip.display[(i * 64) + j])
                        {
                            std::cout << (char)254u;
                        }
                        else
                        {
                            std::cout << " ";
                        }
                    }
                    std::cout << std::endl;
                }
                chip.draw = false;
            }
/*
            if(_kbhit())
            {
                char key = _getch();
                if(key == '1')
                {
                    chip.keys[1] = true;
                }
                else if(key == '2')
                {
                    chip.keys[2] = true;
                }
                else if(key == '3')
                {
                    chip.keys[3] = true;
                }
                else if(key == '4')
                {
                    chip.keys[0xC] = true;
                }
                else if(key == 'Q')
                {
                    chip.keys[4] = true;
                }
                else if(key == 'W')
                {
                    chip.keys[5] = true;
                }
                else if(key == 'E')
                {
                    chip.keys[6] = true;
                }
                else if(key == 'R')
                {
                    chip.keys[0xD] = true;
                }
                else if(key == 'A')
                {
                    chip.keys[7] = true;
                }

                else if(key == 'S')
                {
                    chip.keys[8] = true;
                }

                else if(key == 'D')
                {
                    chip.keys[9] = true;
                }

                else if(key == 'F')
                {
                    chip.keys[0xE] = true;
                }

                else if(key == 'Z')
                {
                    chip.keys[0xA] = true;
                }

                else if(key == 'X')
                {
                    chip.keys[0] = true;
                }

                else if(key == 'C')
                {
                    chip.keys[0xB] = true;
                }

                else if(key == 'V')
                {
                    chip.keys[0xF] = true;
                }
            }*/
        }
    }
    else
    {
        std::cout << "ROM does not exist.";
    }
}