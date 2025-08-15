#ifndef CPU_H
#define CPU_H

#include<stdint.h>

typedef struct
{
    uint8_t R0; // acumulator
    uint8_t PC; // Program counter
} CPU;

void execute_instruction(CPU *cpu, uint8_t opcode, uint8_t data,uint8_t *ram);
void run_cpu(CPU *cpu, uint8_t *program, uint8_t *ram);
#endif // CPU_H
