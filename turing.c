#include <stdio.h>
#include <string.h>
#include "turing.h"

void turing_decrypt(char *encrypted) {
    for (int i = 0; encrypted[i] != '\0'; ++i) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            encrypted[i] = ((encrypted[i] - 'A' - 3 + 26) % 26) + 'A';  // Reverse shift by 3
        }
    }
}
