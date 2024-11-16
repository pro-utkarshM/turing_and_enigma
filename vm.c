#include <stdio.h>
#include "vm.h"

void init_vm(VM *vm) {
    vm->pc = 0;
    vm->running = true;
    for (int i = 0; i < 4; i++) vm->registers[i] = 0;
    for (int i = 0; i < 256; i++) vm->memory[i] = 0;
}

void decode_and_execute(VM *vm, uint8_t instruction) {
    uint8_t opcode = instruction >> 4;
    uint8_t operand = instruction & 0x0F;

    switch (opcode) {
        case LOAD:
            vm->registers[operand] = vm->memory[vm->pc++];
            printf("LOAD R%d, %c\n", operand, vm->registers[operand]);
            break;
        case STORE:
            vm->memory[vm->memory[vm->pc++]] = vm->registers[operand];
            printf("STORE [0x%X], R%d (%c)\n", operand, operand, vm->registers[operand]);
            break;
        case CALL_ENIGMA:
            vm->registers[operand] = enigma_encrypt(vm->registers[operand]);
            printf("CALL_ENIGMA R%d -> %c\n", operand, vm->registers[operand]);
            break;
        case CALL_TURING:
            run_turing_machine();
            break;
        case HLT:
            vm->running = false;
            printf("Program halted.\n");
            break;
        default:
            printf("Unknown opcode: 0x%X\n", opcode);
            vm->running = false;
            break;
    }
}

void run_vm(VM *vm) {
    while (vm->running) {
        uint8_t instruction = vm->memory[vm->pc++];
        decode_and_execute(vm, instruction);
    }
}
