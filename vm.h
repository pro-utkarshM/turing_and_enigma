#ifndef VM_H
#define VM_H

#include <stdint.h>
#include <stdbool.h>
#include "enigma.h"
#include "turing.h"

// Opcode definitions
#define LOAD 0x1
#define STORE 0x2
#define ADD 0x3
#define JMP 0x4
#define CALL_ENIGMA 0x6
#define CALL_TURING 0x7
#define HLT 0xF

// VM structure
typedef struct {
    uint8_t memory[256];
    uint8_t registers[4];
    uint8_t pc;
    bool running;
} VM;

void init_vm(VM *vm);
void run_vm(VM *vm);
void decode_and_execute(VM *vm, uint8_t instruction);

#endif
