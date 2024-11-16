#include <stdio.h>
#include <time.h>
#include "vm.h"

int main() {
    printf("Running the VM program...\n");

    // Initialize VM
    VM vm;
    vm_init(&vm);

    // Example message to encrypt and decrypt
    const char *message = "HELLO";

    // Load message into register
    vm_load(&vm, 0, message);

    // Encrypt using Enigma
    printf("Encrypting message using Enigma...\n");
    vm_execute(&vm, ENCRYPT, 0);  // Encrypt the message in register 0

    // Store the encrypted message (for testing purposes)
    printf("Encrypted message: %s\n", vm.registers[0]);

    // Measure decryption time
    clock_t start = clock();  // Start time

    printf("Decrypting message using Turing machine...\n");
    vm_execute(&vm, DECRYPT, 0);  // Decrypt the message in register 0

    clock_t end = clock();  // End time

    // Output the decrypted message
    printf("Decrypted message: %s\n", vm.registers[0]);

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to decrypt: %.6f seconds\n", elapsed_time);

    return 0;
}
