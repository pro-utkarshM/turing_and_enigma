#include "turing.h"
#include <stdio.h>

#define TAPE_SIZE 10

// Initialize tape with some non-space values for better observation
char tape[TAPE_SIZE] = "101     "; // Start with '1's and spaces
int head_position = TAPE_SIZE / 2;  // Start at the middle of the tape
int turing_state = 0;

void print_tape() {
    // Print tape with head indicator
    for (int i = 0; i < TAPE_SIZE; i++) {
        if (i == head_position) {
            printf("[%c]", tape[i]);  // Mark the head position with []
        } else {
            printf(" %c ", tape[i]);
        }
    }
    printf("\n");
}

void run_turing_machine() {
    printf("Running Turing machine...\n");

    // Example Turing machine logic
    if (tape[head_position] == ' ') {
        tape[head_position] = '1';  // Write '1' if the cell is empty
        printf("Writing '1' at position %d\n", head_position);
    } else {
        tape[head_position] = ' ';  // Erase if it has '1'
        printf("Erasing at position %d\n", head_position);
    }

    // Print the current state of the tape before moving the head
    printf("Before moving head:\n");
    print_tape();

    // Move head right (wrap around if needed)
    head_position = (head_position + 1) % TAPE_SIZE;

    // Print the updated tape after head movement
    printf("After moving head to position %d:\n", head_position);
    print_tape();
}
