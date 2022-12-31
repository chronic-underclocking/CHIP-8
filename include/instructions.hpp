#ifndef INSTRUCTIONS
#define INSTRUCTIONS

#include "chip8.hpp"

// CLS
void _00E0(Chip8& chip);

// RET
void _00EE(Chip8& chip);

// JP addr
void _1nnn(Chip8& chip);

// CALL addr
void _2nnn(Chip8& chip);

// SE Vx, byte
void _3xkk(Chip8& chip);

// SNE Vx, byte
void _4xkk(Chip8& chip);

// SE Vx, Vy
void _5xy0(Chip8& chip);

// LD Vx, byte
void _6xkk(Chip8& chip);

// ADD Vx, byte
void _7xkk(Chip8& chip);

// LD Vx, Vy
void _8xy0(Chip8& chip);

// OR Vx, Vy
void _8xy1(Chip8& chip);

// AND Vx, Vy
void _8xy2(Chip8& chip);

// XOR Vx, Vy
void _8xy3(Chip8& chip);

// ADD Vx, Vy
void _8xy4(Chip8& chip);

// SUB Vx, Vy
void _8xy5(Chip8& chip);

// SHR Vx {, Vy}
void _8xy6(Chip8& chip);

// SUBN Vx, Vy
void _8xy7(Chip8& chip);

// SHL Vx {, Vy}
void _8xyE(Chip8& chip);

// SNE Vx, Vy
void _9xy0(Chip8& chip);

// LD I, addr
void _Annn(Chip8& chip);

// JP V0, address
void _Bnnn(Chip8& chip);

// RND Vx, byte
void _Cxkk(Chip8& chip);

// DRW Vx, Vy, height
void _Dxyn(Chip8& chip);

// SKP Vx
void _Ex9E(Chip8& chip);

// SKNP Vx
void _ExA1(Chip8& chip);

// LD Vx, DT
void _Fx07(Chip8& chip);

// LD Vx, K
void _Fx0A(Chip8& chip);

// LD DT, Vx
void _Fx15(Chip8& chip);

// LD ST, Vx
void _Fx18(Chip8& chip);

// ADD I, Vx
void _Fx1E(Chip8& chip);

// LD F, Vx
void _Fx29(Chip8& chip);

// LD B, Vx
void _Fx33(Chip8& chip);

// LD [I], Vx
void _Fx55(Chip8& chip);

// LD Vx, [I]
void _Fx65(Chip8& chip);

#endif