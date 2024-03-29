#pragma once

#define STACK_SIZE 65535

#include <common.h>
#include<mmu.h>

typedef struct {
    u8 A, F;
    u8 B, C;
    u8 D, E;
    u8 H, L;
    u16 SP;
    u16 PC;
    u8 IR;
    u8 IE;
} registers;

typedef struct {
    bool Z, N, H, C;
} register_flags;

class CPU{
public:
        CPU();
        void cpu_fetch(u16 addr, MMU& mmu);
        void cpu_decode_exec(MMU& mmu);

        u16 get_reg16_af();
        u16 get_reg16_bc();
        u16 get_reg16_de();
        u16 get_reg16_hl();

        void set_reg16_af(u16 nn);
        void set_reg16_bc(u16 nn);
        void set_reg16_de(u16 nn);
        void set_reg16_hl(u16 nn);

        void stack_push(u8 n);
        u8 stack_pop();

        registers regs;
        register_flags flags;
        u8 stack[STACK_SIZE];
        u8 curr_opcode;
};
