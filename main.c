#include <stdio.h>
#include "vm.h"

// Sample program in VM assembly language
const uint8_t program[] = {
    LOAD << 4 | 0x0, 'A',       // LOAD R0, 'A'
    CALL_ENIGMA << 4 | 0x0,     // CALL_ENIGMA on R0
    STORE << 4 | 0x0, 0x10,     // STORE R0 at memory[0x10]
    LOAD << 4 | 0x1, 0x00,      // LOAD R1, 0 (initial state for Turing machine)
    CALL_TURING << 4 | 0x1,     // CALL_TURING on R1
    HLT << 4                     // HLT
};

int main() {
    VM vm;
    init_vm(&vm);

    // Load the program into VM memory
    for (int i = 0; i < sizeof(program); i++) {
        vm.memory[i] = program[i];
    }

    printf("Running the VM program...\n");
    run_vm(&vm);
    return 0;
}
