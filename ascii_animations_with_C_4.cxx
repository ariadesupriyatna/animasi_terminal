#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void draw_frame(int frame) {
    system("cls");

    switch (frame % 8) {
        case 0:
            printf("  /\n /  \\\n/    \\\n |__| |\n |  | |\n");
            break;
        case 1:
            printf(" / \n/  \\\n/    \\\n |__| |\n |  | |\n");
            break;
        case 2:
            printf("/  \n/  \\\n/    \\\n  ||  |\n  ||  |\n");
            break;
        case 3:
            printf("/  \n /  \\\n/    \\\n  ||  |\n  ||  |\n");
            break;
        case 4:
            printf("  /\n /  \\\n/    \\\n |__| |\n |  | |\n");
            break;
        case 5:
            printf(" / \n/  \\\n/    \\\n |__| |\n |  | |\n");
            break;
        case 6:
            printf("/  \n/  \\\n/    \\\n  ||  |\n  ||  |\n");
            break;
        case 7:
            printf("/  \n /  \\\n/    \\\n  ||  |\n  ||  |\n");
            break;
    }
}

int main() {
    int frame = 0;

    while (1) {
        draw_frame(frame);
        frame++;
        Sleep(200); // Adjust delay as needed
    }

    return 0;
}
