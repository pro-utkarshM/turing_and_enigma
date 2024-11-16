#include <stdio.h>
#include <string.h>

void enigma_encrypt(char *input) {
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = ((input[i] - 'A' + 3) % 26) + 'A';  // Shift by 3
        }
    }
}
