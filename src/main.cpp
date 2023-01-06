#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include "chip8.hpp"

Chip8 chip;

std::mutex mx;

void setCursorPosition(int x, int y)
{
    static const HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT) x, (SHORT) y};
    SetConsoleCursorPosition(hnd, coord);
}

void checkKeysHeld()
{
    for(;;)
    {
        if (GetKeyState('1') & 0x8000)
        {
            mx.lock();
            chip.keys[1] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[1] = false;
            mx.unlock();
        }
        if (GetKeyState('2') & 0x8000)
        {
            mx.lock();
            chip.keys[2] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[2] = false;
            mx.unlock();
        }
        if (GetKeyState('3') & 0x8000)
        {
            mx.lock();
            chip.keys[3] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[3] = false;
            mx.unlock();
        }
        if (GetKeyState('4') & 0x8000)
        {
            mx.lock();
            chip.keys[0xC] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xC] = false;
            mx.unlock();
        }
        if (GetKeyState('Q') & 0x8000)
        {
            mx.lock();
            chip.keys[4] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[4] = false;
            mx.unlock();
        }
        if (GetKeyState('W') & 0x8000)
        {
            mx.lock();
            chip.keys[5] = true;
            mx.unlock();        
        }
        else
        {
            mx.lock();
            chip.keys[5] = false;
            mx.unlock();
        }
        if (GetKeyState('E') & 0x8000)
        {
            mx.lock();
            chip.keys[6] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[6] = false;
            mx.unlock();
        }
        if (GetKeyState('R') & 0x8000)
        {
            mx.lock();
            chip.keys[0xD] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xD] = false;
            mx.unlock();
        }
        if (GetKeyState('A') & 0x8000)
        {
            mx.lock();
            chip.keys[7] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[7] = false;
            mx.unlock();
        }
        if (GetKeyState('S') & 0x8000)
        {
            mx.lock();
            chip.keys[8] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[8] = false;
            mx.unlock();
        }
        if (GetKeyState('D') & 0x8000)
        {
            mx.lock();
            chip.keys[9] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[9] = false;
            mx.unlock();
        }
        if (GetKeyState('F') & 0x8000)
        {
            mx.lock();
            chip.keys[0xE] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xE] = false;
            mx.unlock();
        }
        if (GetKeyState('Z') & 0x8000)
        {
            mx.lock();
            chip.keys[0xA] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xA] = false;
            mx.unlock();
        }
        if (GetKeyState('X') & 0x8000)
        {
            mx.lock();
            chip.keys[0] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0] = false;
            mx.unlock();
        }
        if (GetKeyState('C') & 0x8000)
        {
            mx.lock();
            chip.keys[0xB] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xB] = false;
            mx.unlock();
        }
        if (GetKeyState('V') & 0x8000)
        {
            mx.lock();
            chip.keys[0xF] = true;
            mx.unlock();
        }
        else
        {
            mx.lock();
            chip.keys[0xF] = false;
            mx.unlock();
        }
    }
}

int main(int argc, char *argv[])
{
    bool prevDisplay[64 * 32] = {};
    if(chip.loadFile(argv[1]))
    {
        std::thread keyPoll(&checkKeysHeld);
        system("cls");
        for(;;)
        {
            Sleep(1);

            chip.nextCycle();

            if(chip.draw)
            {
                for(int i = 0; i < 32; i++)
                {
                    for(int j = 0; j < 64; j++)
                    {
                        if(chip.display[(i * 64) + j] == prevDisplay[(i * 64) + j])
                        {
                            continue;
                        }
                        setCursorPosition(j, i);
                        if(chip.display[(i * 64) + j])
                        {
                            std::cout << (char)254u;
                        }
                        else
                        {
                            std::cout << " ";
                        }
                        setCursorPosition(0, 0);
                    }
                    std::cout << std::endl;
                }
                std::cout.flush();
                memcpy(prevDisplay, chip.display, 64 * 32);
                chip.draw = false;
            }
        }
    }
    else
    {
        std::cout << "ROM does not exist.";
    }
}