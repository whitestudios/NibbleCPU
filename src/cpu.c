#include "../include/cpu.h"
#include<stdio.h>
#include<stdlib.h>
 
// formato das instruçoes  0bOOOODDDD
// O -> opcode
// D -> dados, como um endereço ou um inteiro de 4 bits

/* LDI value -> Carrega um certo valor no acumulador.
 * ADD value -> Soma um certo valor com o valor ja presente no acumulador.
 * STA address -> Guarda o valor do acumulador na memoria ram.
 * LDA address -> Pega um valor da memoria ram e guarda no acumulador.
 * JMP address -> Pula para um outro endereço do programa 
 * ( o que nao funciona muito bem pq esse processador so endereça 4 bits de memoria KKKKK).
 * JZ -> Da um JMP se o valor do acumulador for 0
 */

void execute_instruction(CPU *cpu, uint8_t opcode, uint8_t data, uint8_t *ram)
{
    switch (opcode)
    {
    case 0b0000: /* Do nothing */                          break;
    case 0b0001: cpu->R0    = data;                  break; // LDI
    case 0b0010: cpu->R0    += data;                 break; // ADD
    case 0b0011: ram[data]  = cpu->R0;               break; // STA
    case 0b0100: cpu->R0    = ram[data];             break; // LDA
    case 0b0101: cpu->PC    = data;                  break; // JMP
    case 0b0111: if(cpu->R0 == 0) cpu->PC = data;    break; // JZ
    case 0b1000: printf("out: %d\n",cpu->R0);exit(0);break; // OUT
    
    default:
        printf("ERROR: unknown opcode in line %d \nexit..", cpu->PC);
        exit(1);
        break;
    }
    printf("PC => %d\n", cpu->PC);
    printf("R0 => %d\n", cpu->R0);
    for(int i = 0; i < 16; i++)
    {
        printf("RAM[%d] => %d\n", i, ram[i]);
    }
}

void run_cpu(CPU *cpu, uint8_t *program, uint8_t *ram)
{
    while(1)
    {
        uint8_t instruction = program[cpu->PC++];
        uint8_t opcode = instruction >> 4;
        uint8_t data = instruction & 0x0F;
        execute_instruction(cpu, opcode, data, ram);
    }

}