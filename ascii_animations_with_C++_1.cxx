#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // For system("cls") and Sleep()

int main() {
    int y = 10;
    int direction = 1;

    while (1) {
        system("cls"); // Clear the screen

        // Draw the ball
        for (int i = 0; i < y; i++) {
            printf("\n");
        }
        printf("O_O\n");

        y += direction;

        if (y == 1 || y == 20) {
            direction *= -1;
        }

        Sleep(100); // Adjust delay as needed
    }

    return 0;
}
