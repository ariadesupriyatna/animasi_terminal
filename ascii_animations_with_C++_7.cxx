#include <ncurses.h>
#include <unistd.h>
#include <math.h>

void draw_sunflower(int angle) {
    clear();

    // Batang
    mvprintw(10, 10, "|");
    mvprintw(9, 10, "|");
    mvprintw(8, 10, "|");

    // Pusat Bunga
    int centerX = 10;
    int centerY = 8;
    int radius = 3;

    // Jumlah kelopak
    int numPetals = 10;

    for (int i = 0; i < numPetals; i++) {
        double petalAngle = angle + i * 360 / numPetals;
        int x = centerX + radius * cos(petalAngle * M_PI / 180);
        int y = centerY + radius * sin(petalAngle * M_PI / 180);
        mvprintw(y, x, "/");
        mvprintw(y, x+1, "\\");
    }

    refresh();
}

int main() {
    initscr();
    noecho();
    curs_set(0);

    int angle = 0;
    while (1) {
        draw_sunflower(angle);
        angle = (angle + 5) % 360;
        usleep(100000);
    }

    endwin();
    return 0;
}
