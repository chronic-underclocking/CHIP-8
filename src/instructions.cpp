#include "instructions.hpp"
#include <iostream>

// CLS
void _00E0(Chip8& chip) {std::cout << __func__ << "\n";};

// RET
void _00EE(Chip8& chip) {std::cout << __func__ << "\n";};

// JP addr
void _1nnn(Chip8& chip) {std::cout << __func__ << "\n";};

// CALL addr
void _2nnn(Chip8& chip) {std::cout << __func__ << "\n";};

// SE Vx, byte
void _3xkk(Chip8& chip) {std::cout << __func__ << "\n";};

// SNE Vx, byte
void _4xkk(Chip8& chip) {std::cout << __func__ << "\n";};

// SE Vx, Vy
void _5xy0(Chip8& chip) {std::cout << __func__ << "\n";};

// LD Vx, byte
void _6xkk(Chip8& chip) {std::cout << __func__ << "\n";};

// ADD Vx, byte
void _7xkk(Chip8& chip) {std::cout << __func__ << "\n";};

// LD Vx, Vy
void _8xy0(Chip8& chip) {std::cout << __func__ << "\n";};

// OR Vx, Vy
void _8xy1(Chip8& chip) {std::cout << __func__ << "\n";};

// AND Vx, Vy
void _8xy2(Chip8& chip) {std::cout << __func__ << "\n";};

// XOR Vx, Vy
void _8xy3(Chip8& chip) {std::cout << __func__ << "\n";};

// ADD Vx, Vy
void _8xy4(Chip8& chip) {std::cout << __func__ << "\n";};

// SUB Vx, Vy
void _8xy5(Chip8& chip) {std::cout << __func__ << "\n";};

// SHR Vx {, Vy << "\n";}
void _8xy6(Chip8& chip) {std::cout << __func__ << "\n";};

// SUBN Vx, Vy
void _8xy7(Chip8& chip) {std::cout << __func__ << "\n";};

// SHL Vx {, Vy << "\n";}
void _8xyE(Chip8& chip) {std::cout << __func__ << "\n";};

// SNE Vx, Vy
void _9xy0(Chip8& chip) {std::cout << __func__ << "\n";};

// LD I, addr
void _Annn(Chip8& chip) {std::cout << __func__ << "\n";};

// JP V0, address
void _Bnnn(Chip8& chip) {std::cout << __func__ << "\n";};

// RND Vx, byte
void _Cxkk(Chip8& chip) {std::cout << __func__ << "\n";};

// DRW Vx, Vy, height
void _Dxyn(Chip8& chip) {std::cout << __func__ << "\n";};

// SKP Vx
void _Ex9E(Chip8& chip) {std::cout << __func__ << "\n";};

// SKNP Vx
void _ExA1(Chip8& chip) {std::cout << __func__ << "\n";};

// LD Vx, DT
void _Fx07(Chip8& chip) {std::cout << __func__ << "\n";};

// LD Vx, K
void _Fx0A(Chip8& chip) {std::cout << __func__ << "\n";};

// LD DT, Vx
void _Fx15(Chip8& chip) {std::cout << __func__ << "\n";};

// LD ST, Vx
void _Fx18(Chip8& chip) {std::cout << __func__ << "\n";};

// ADD I, Vx
void _Fx1E(Chip8& chip) {std::cout << __func__ << "\n";};

// LD F, Vx
void _Fx29(Chip8& chip) {std::cout << __func__ << "\n";};

// LD B, Vx
void _Fx33(Chip8& chip) {std::cout << __func__ << "\n";};

// LD [I], Vx
void _Fx55(Chip8& chip) {std::cout << __func__ << "\n";};

// LD Vx, [I]
void _Fx65(Chip8& chip) {std::cout << __func__ << "\n";};