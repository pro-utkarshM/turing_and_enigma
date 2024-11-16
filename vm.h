#ifndef VM_H
#define VM_H

#define ENCRYPT 0
#define DECRYPT 1

typedef struct {
    char registers[16][256];  // Registers for storing strings
} VM;

void vm_init(VM *vm);
void vm_load(VM *vm, int reg, const char *data);
void vm_execute(VM *vm, int instruction, int reg);

#endif // VM_H
