#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 20
#define HEIGHT 20

void draw(int snake_x, int snake_y, int food_x, int food_y) {
    system("cls");

    // Top border
    for (int x = 0; x <= WIDTH + 1; x++) {
        if (x == 0 || x == WIDTH + 1) {
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (x == snake_x && y == snake_y) {
                printf("*"); // Snake
            } else if (x == food_x && y == food_y) {
                printf("O"); // Food
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // Bottom border
    for (int x = 0; x <= WIDTH + 1; x++) {
        if (x == 0 || x == WIDTH + 1) {
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int main() {
    int snake_x = WIDTH / 2;
    int snake_y = HEIGHT / 2;
    int food_x = rand() % WIDTH;
    int food_y = rand() % HEIGHT;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up

    while (1) {
        draw(snake_x, snake_y, food_x, food_y);

        if (kbhit()) {
            char key = getch();
            if (key == 'w') {
                direction = 3;
            } else if (key == 's') {
                direction = 1;
            } else if (key == 'a') {
                direction = 2;
            } else if (key == 'd') {
                direction = 0;
            }
        }

        switch (direction) {
            case 0:
                snake_x++;
                break;
            case 1:
                snake_y++;
                break;
            case 2:
                snake_x--;
                break;
            case 3:
                snake_y--;
                break;
        }

        // Check if snake eats food
        if (snake_x == food_x && snake_y == food_y) {
            food_x = rand() % WIDTH;
            food_y = rand() % HEIGHT;
            // Increase snake length here (not implemented)
        }

        // Check for wall collision
        if (snake_x < 0 || snake_x >= WIDTH || snake_y < 0 || snake_y >= HEIGHT) {
            break;
        }

        Sleep(100);
    }

    // Tambahkan garis pembatas saat game over
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("=");
    }
    printf("\nGame Over!\n");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("=");
    }

    return 0;
}
