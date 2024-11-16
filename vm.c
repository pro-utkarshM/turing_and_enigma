#include <stdio.h>
#include <string.h>
#include "vm.h"
#include "enigma.h"
#include "turing.h"

void vm_init(VM *vm) {
    memset(vm->registers, 0, sizeof(vm->registers));
}

void vm_load(VM *vm, int reg, const char *data) {
    strncpy(vm->registers[reg], data, sizeof(vm->registers[reg]) - 1);
}

void vm_execute(VM *vm, int instruction, int reg) {
    switch (instruction) {
        case ENCRYPT:
            enigma_encrypt(vm->registers[reg]);
            break;
        case DECRYPT:
            turing_decrypt(vm->registers[reg]);
            break;
        default:
            printf("Unknown instruction.\n");
            break;
    }
}
