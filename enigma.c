#include "enigma.h"
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

const char ROTOR[ALPHABET_SIZE + 1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";  // Now with space for null terminator
const char REFLECTOR[ALPHABET_SIZE + 1] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

int rotor_position = 0;

void step_rotor() {
    rotor_position = (rotor_position + 1) % ALPHABET_SIZE;
}

char enigma_encrypt(char ch) {
    // Process through rotor, reflector, and back through rotor
    int pos = (ch - 'A' + rotor_position) % ALPHABET_SIZE;
    ch = ROTOR[pos];
    ch = REFLECTOR[ch - 'A'];
    
    // Reverse through the rotor (finding position safely)
    char *rotor_ptr = strchr(ROTOR, ch);
    if (rotor_ptr != NULL) {
        pos = (rotor_ptr - ROTOR - rotor_position + ALPHABET_SIZE) % ALPHABET_SIZE;
        ch = 'A' + pos;
    }
    
    step_rotor();
    return ch;
}
