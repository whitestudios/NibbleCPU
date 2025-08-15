#include "../include/cpu.h"

int main()
{
    CPU cpu = { .PC = 0, .R0 = 0};
    uint8_t ram[16];
    uint8_t program[] = {
        0b10000000
    };
    run_cpu(&cpu, program, ram);

    return 0;
}