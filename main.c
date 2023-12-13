#include <stdio.h>
#include <conio.h> // This is just for _getch() function
#include <string.h>
#include <stdbool.h>

// Define grid and screen sizes
#define GRID_SIZE 16
#define NUM_GRIDS_X 4
#define NUM_GRIDS_Y 4

// Define UDFs
void drawLine(char grid[GRID_SIZE][GRID_SIZE], int x1, int x2, int y1, int y2);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]);
void initGrid();
void menu();
void game();
void end();

// Define the 4D array that will store the map
char grids[NUM_GRIDS_Y][NUM_GRIDS_X][GRID_SIZE][GRID_SIZE];

// Main function only calls the entry
int main() {
    menu();
    return 0;
}

// Menu is how you start the game
void menu() {
    char m[10];
    system("cls");
    printf("             TerminalQuest\n");
    printf("=========================================\n");
    printf("  - Enter \"start\" to begin TerminalQuest\n");
    printf("  - Enter \"?\" for instructions\n");
    printf("  - Enter \"exit\" to exit\n");
    printf("=========================================\n");
    scanf_s("%s", &m, 10);

    //If the user enters start then start
    if (strcmp(m, "start") == 0) {
        game();
    } // If th user enters ? then show instructions
    else if (strcmp(m, "?") == 0) {
        system("cls");
        printf("Use WASD to move the player (@).\nGo to the border of one screen to move to the next.\nFind the exit of the maze (X) to win.\nA door (/) may get in your way, and you must find a key (^) to unlock it.\n\n");
        system("pause");
        menu();
    } // If the user enters exit then exit the game
    else if (strcmp(m, "exit") == 0) {
        system("cls");
        printf("Thank you for playing TerminalQuest!\n\n");
        exit(0);
    } // If the user enters anything else make them try again
    else {
        system("cls");
        printf("Incorrect entry, please try again.\n\n");
        system("pause");
        menu();
    }
}

// This is called when the user finishes the maze
void end() {
    system("cls");
    printf("You escaped the maze!\nAs a reward, a keylogger has been installed on your computer! :)\nJust kidding\n\n");
    system("pause");
    menu();
}

// This draws a line of walls on a screen between 2 given starting and ending coordinates
void drawLine(char grid[GRID_SIZE][GRID_SIZE], int x1, int x2, int y1, int y2) {
    // Calculate distance between start and end
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    // Iterates through the tiles in between the start and end and replaces each one with a wall
    while (1) {
        if (x1 >= 0 && x1 < GRID_SIZE && y1 >= 0 && y1 < GRID_SIZE) {
            grid[y1][x1] = '#';
        }
        if (x1 == x2 && y1 == y2) break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

// This initializes the grid. This is called at the beginning of every new game.
// The map is stored in a 4D array, so there are 4 nested loops to initially fill the entire map with '.'
void initGrid() {
    for (int gy = 0; gy < NUM_GRIDS_Y; gy++) {
        for (int gx = 0; gx < NUM_GRIDS_X; gx++) {
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    grids[gy][gx][i][j] = '.';
                }
            }
        }
    }

    // Draw grid 0, 0
    {
        //Walls
        drawLine(grids[0][0], 0, 15, 0, 0);
        drawLine(grids[0][0], 15, 15, 0, 3);
        drawLine(grids[0][0], 15, 15, 6, 15);
        drawLine(grids[0][0], 0, 6, 15, 15);
        drawLine(grids[0][0], 9, 15, 15, 15);
        drawLine(grids[0][0], 0, 0, 0, 15);
        //Smile
        drawLine(grids[0][0], 5, 5, 2, 2);
        drawLine(grids[0][0], 8, 8, 2, 2);
        drawLine(grids[0][0], 4, 4, 4, 4);
        drawLine(grids[0][0], 9, 9, 4, 4);
        drawLine(grids[0][0], 5, 8, 5, 5);
        //HI
        drawLine(grids[0][0], 7, 7, 7, 9);
        drawLine(grids[0][0], 7, 9, 8, 8);
        drawLine(grids[0][0], 9, 9, 7, 9);
        drawLine(grids[0][0], 11, 13, 7, 7);
        drawLine(grids[0][0], 12, 12, 7, 9);
        drawLine(grids[0][0], 11, 13, 9, 9);
    }
    // Draw grid 1, 0
    {
        //Walls
        drawLine(grids[0][1], 0, 15, 0, 0);
        drawLine(grids[0][1], 15, 15, 0, 3);
        drawLine(grids[0][1], 15, 15, 6, 15);
        drawLine(grids[0][1], 0, 6, 15, 15);
        drawLine(grids[0][1], 9, 15, 15, 15);
        drawLine(grids[0][1], 0, 0, 0, 3);
        drawLine(grids[0][1], 0, 0, 6, 15);
        //Inner Walls
        drawLine(grids[0][1], 0, 13, 13, 13);
        drawLine(grids[0][1], 13, 13, 0, 13);
        //LOL
        drawLine(grids[0][1], 2, 2, 4, 6);
        drawLine(grids[0][1], 2, 3, 6, 6);
        drawLine(grids[0][1], 5, 7, 4, 4);
        drawLine(grids[0][1], 7, 7, 4, 6);
        drawLine(grids[0][1], 5, 7, 6, 6);
        drawLine(grids[0][1], 5, 5, 4, 6);
        drawLine(grids[0][1], 9, 9, 4, 6);
        drawLine(grids[0][1], 9, 10, 6, 6);
    }
    // Draw grid 2, 0
    {
        //0
        drawLine(grids[0][2], 0, 7, 0, 0);
        drawLine(grids[0][2], 10, 15, 0, 0);
        //1
        drawLine(grids[0][2], 0, 7, 1, 1);
        drawLine(grids[0][2], 10, 15, 1, 1);
        //2
        drawLine(grids[0][2], 0, 7, 2, 2);
        drawLine(grids[0][2], 10, 15, 2, 2);
        //3
        drawLine(grids[0][2], 0, 7, 3, 3);
        drawLine(grids[0][2], 11, 15, 3, 3);
        //4
        drawLine(grids[0][2], 5, 8, 4, 4);
        drawLine(grids[0][2], 11, 15, 4, 4);
        //5
        drawLine(grids[0][2], 7, 8, 5, 5);
        drawLine(grids[0][2], 12, 15, 5, 5);
        //6
        drawLine(grids[0][2], 0, 2, 6, 6);
        drawLine(grids[0][2], 8, 9, 6, 6);
        drawLine(grids[0][2], 13, 15, 6, 6);
        //7
        drawLine(grids[0][2], 0, 4, 7, 7);
        drawLine(grids[0][2], 8, 10, 7, 7);
        drawLine(grids[0][2], 14, 15, 7, 7);
        //8
        drawLine(grids[0][2], 0, 5, 8, 8);
        drawLine(grids[0][2], 8, 11, 8, 8);
        //9
        drawLine(grids[0][2], 0, 5, 9, 9);
        drawLine(grids[0][2], 8, 13, 9, 9);
        //10
        drawLine(grids[0][2], 0, 5, 10, 10);
        drawLine(grids[0][2], 8, 15, 10, 10);
        //11
        drawLine(grids[0][2], 0, 5, 11, 11);
        drawLine(grids[0][2], 9, 15, 11, 11);
        //12
        drawLine(grids[0][2], 0, 6, 12, 12);
        drawLine(grids[0][2], 9, 15, 12, 12);
        //13
        drawLine(grids[0][2], 0, 6, 13, 13);
        drawLine(grids[0][2], 9, 15, 13, 13);
        //14
        drawLine(grids[0][2], 0, 6, 14, 14);
        drawLine(grids[0][2], 9, 15, 14, 14);
        //15
        drawLine(grids[0][2], 0, 6, 15, 15);
        drawLine(grids[0][2], 9, 15, 15, 15);
        //16
        drawLine(grids[0][2], 0, 6, 16, 16);
        drawLine(grids[0][2], 9, 15, 16, 16);
    }
    // Draw grid 3, 0
    {
        //Walls
        drawLine(grids[0][3], 0, 15, 0, 0);
        drawLine(grids[0][3], 15, 15, 0, 15);
        drawLine(grids[0][3], 0, 10, 15, 15);
        drawLine(grids[0][3], 13, 15, 15, 15);
        drawLine(grids[0][3], 0, 0, 0, 7);
        drawLine(grids[0][3], 0, 0, 10, 15);
        //Inner Wall
        drawLine(grids[0][3], 0, 10, 11, 11);
        drawLine(grids[0][3], 13, 15, 11, 11);
    }
    // Draw grid 0, 1
    {
        //Walls
        drawLine(grids[1][0], 0, 6, 0, 0);
        drawLine(grids[1][0], 9, 15, 0, 0);
        drawLine(grids[1][0], 15, 15, 0, 6);
        drawLine(grids[1][0], 15, 15, 9, 15);
        drawLine(grids[1][0], 5, 15, 15, 15);
        drawLine(grids[1][0], 0, 0, 0, 15);
        //Arrow
        drawLine(grids[1][0], 5, 8, 12, 9);
        drawLine(grids[1][0], 5, 5, 12, 9);
        drawLine(grids[1][0], 5, 8, 12, 12);
    }
    // Draw grid 1, 1
    {
        //Walls
        drawLine(grids[1][1], 0, 6, 0, 0);
        drawLine(grids[1][1], 9, 15, 0, 0);
        drawLine(grids[1][1], 15, 15, 2, 15);
        drawLine(grids[1][1], 0, 13, 15, 15);
        drawLine(grids[1][1], 0, 0, 0, 6);
        drawLine(grids[1][1], 0, 0, 9, 15);
        //Outer Stubs
        drawLine(grids[1][1], 3, 5, 1, 1);
        drawLine(grids[1][1], 10, 12, 1, 1);
        drawLine(grids[1][1], 14, 14, 3, 5);
        drawLine(grids[1][1], 14, 14, 10, 12);
        drawLine(grids[1][1], 3, 5, 14, 14);
        drawLine(grids[1][1], 10, 12, 14, 14);
        drawLine(grids[1][1], 1, 1, 3, 5);
        drawLine(grids[1][1], 1, 1, 10, 12);
        //Corner Garnishes
        drawLine(grids[1][1], 3, 3, 3, 3);
        drawLine(grids[1][1], 3, 5, 5, 3);
        drawLine(grids[1][1], 12, 12, 3, 3);
        drawLine(grids[1][1], 10, 12, 3, 5);
        drawLine(grids[1][1], 12, 12, 12, 12);
        drawLine(grids[1][1], 10, 12, 12, 10);
        drawLine(grids[1][1], 3, 3, 12, 12);
        drawLine(grids[1][1], 3, 5, 10, 12);
        //Crosshair Thing
        drawLine(grids[1][1], 7, 8, 7, 7);
        drawLine(grids[1][1], 7, 8, 8, 8);
        drawLine(grids[1][1], 7, 7, 3, 5);
        drawLine(grids[1][1], 8, 8, 3, 5);
        drawLine(grids[1][1], 10, 12, 7, 7);
        drawLine(grids[1][1], 10, 12, 8, 8);
        drawLine(grids[1][1], 7, 7, 10, 12);
        drawLine(grids[1][1], 8, 8, 10, 12);
        drawLine(grids[1][1], 3, 5, 7, 7);
        drawLine(grids[1][1], 3, 5, 8, 8);
    }
    // Draw grid 2, 1
    {
        //Walls
        drawLine(grids[1][2], 0, 6, 0, 0);
        drawLine(grids[1][2], 9, 15, 0, 0);
        drawLine(grids[1][2], 15, 15, 0, 6);
        drawLine(grids[1][2], 15, 15, 9, 15);
        drawLine(grids[1][2], 0, 6, 15, 15);
        drawLine(grids[1][2], 9, 13, 15, 15);
        drawLine(grids[1][2], 0, 0, 2, 6);
        drawLine(grids[1][2], 0, 0, 9, 15);
        //N
        drawLine(grids[1][2], 6, 9, 2, 2);
        drawLine(grids[1][2], 6, 6, 1, 1);
        drawLine(grids[1][2], 9, 9, 1, 1);
        //E
        drawLine(grids[1][2], 13, 13, 6, 9);
        drawLine(grids[1][2], 14, 14, 6, 6);
        drawLine(grids[1][2], 14, 14, 9, 9);
        //S
        drawLine(grids[1][2], 6, 9, 13, 13);
        drawLine(grids[1][2], 6, 6, 14, 14);
        drawLine(grids[1][2], 9, 9, 14, 14);
        //W
        drawLine(grids[1][2], 2, 2, 6, 9);
        drawLine(grids[1][2], 1, 1, 6, 6);
        drawLine(grids[1][2], 1, 1, 9, 9);
        //NW
        drawLine(grids[1][2], 2, 4, 2, 2);
        drawLine(grids[1][2], 4, 4, 2, 4);
        drawLine(grids[1][2], 2, 4, 4, 4);
        drawLine(grids[1][2], 2, 2, 2, 4);
        //NE
        drawLine(grids[1][2], 11, 13, 2, 2);
        drawLine(grids[1][2], 13, 13, 2, 4);
        drawLine(grids[1][2], 11, 13, 4, 4);
        drawLine(grids[1][2], 11, 11, 2, 4);
        //SE
        drawLine(grids[1][2], 11, 13, 11, 11);
        drawLine(grids[1][2], 13, 13, 11, 13);
        drawLine(grids[1][2], 11, 13, 13, 13);
        drawLine(grids[1][2], 11, 11, 11, 13);
        //SW
        drawLine(grids[1][2], 2, 4, 11, 11);
        drawLine(grids[1][2], 4, 4, 11, 13);
        drawLine(grids[1][2], 2, 4, 13, 13);
        drawLine(grids[1][2], 2, 2, 11, 13);
        //Inner Walls
        drawLine(grids[1][2], 6, 9, 4, 4);
        drawLine(grids[1][2], 11, 11, 6, 9);
        drawLine(grids[1][2], 6, 9, 11, 11);
        drawLine(grids[1][2], 4, 4, 6, 9);
        //Inner Cube
        drawLine(grids[1][2], 6, 9, 6, 6);
        drawLine(grids[1][2], 9, 9, 6, 9);
        drawLine(grids[1][2], 6, 9, 9, 9);
        drawLine(grids[1][2], 6, 6, 6, 9);
    }
    // Draw grid 3, 1
    {
        //Walls
        drawLine(grids[1][3], 0, 10, 0, 0);
        drawLine(grids[1][3], 13, 15, 0, 0);
        drawLine(grids[1][3], 15, 15, 0, 15);
        drawLine(grids[1][3], 2, 13, 15, 15);
        drawLine(grids[1][3], 0, 0, 0, 6);
        drawLine(grids[1][3], 0, 0, 9, 15);
        //Inner SemiCircle
        drawLine(grids[1][3], 2, 2, 2, 2);
        drawLine(grids[1][3], 2, 4, 3, 3);
        drawLine(grids[1][3], 4, 5, 4, 4);
        drawLine(grids[1][3], 5, 5, 4, 6);
        drawLine(grids[1][3], 6, 6, 6, 9);
        drawLine(grids[1][3], 5, 5, 9, 11);
        drawLine(grids[1][3], 4, 5, 11, 11);
        drawLine(grids[1][3], 2, 4, 12, 12);
        drawLine(grids[1][3], 1, 2, 13, 13);
        //Outer SemiCircle
        drawLine(grids[1][3], 5, 7, 1, 1);
        drawLine(grids[1][3], 7, 8, 2, 2);
        drawLine(grids[1][3], 8, 9, 3, 3);
        drawLine(grids[1][3], 9, 9, 3, 5);
        drawLine(grids[1][3], 10, 10, 5, 6);
        drawLine(grids[1][3], 10, 10, 9, 10);
        drawLine(grids[1][3], 9, 9, 10, 12);
        drawLine(grids[1][3], 8, 9, 12, 12);
        drawLine(grids[1][3], 7, 8, 13, 13);
        drawLine(grids[1][3], 5, 7, 14, 14);
    }
    // Draw grid 0, 2
    {
        //Walls
        drawLine(grids[2][0], 5, 15, 0, 0);
        drawLine(grids[2][0], 15, 15, 2, 15);
        drawLine(grids[2][0], 10, 10, 15, 15);
        drawLine(grids[2][0], 5, 5, 0, 15);
        drawLine(grids[2][0], 0, 0, 0, 15);
    }
    // Draw grid 1, 2
    {
        //Walls
        drawLine(grids[2][1], 0, 13, 0, 0);
        drawLine(grids[2][1], 15, 15, 0, 15);
        drawLine(grids[2][1], 0, 6, 15, 15);
        drawLine(grids[2][1], 9, 15, 15, 15);
        drawLine(grids[2][1], 0, 0, 2, 15);
        //1
        drawLine(grids[2][1], 3, 3, 1, 1);
        drawLine(grids[2][1], 9, 9, 1, 1);
        //2
        drawLine(grids[2][1], 2, 4, 2, 2);
        drawLine(grids[2][1], 6, 9, 2, 2);
        drawLine(grids[2][1], 11, 11, 2, 3);
        drawLine(grids[2][1], 14, 14, 2, 2);
        //3
        drawLine(grids[2][1], 6, 6, 3, 7);
        drawLine(grids[2][1], 13, 14, 3, 3);
        //4
        drawLine(grids[2][1], 1, 4, 4, 4);
        drawLine(grids[2][1], 8, 13, 4, 4);
        drawLine(grids[2][1], 12, 12, 4, 9);
        //5
        drawLine(grids[2][1], 4, 4, 5, 6);
        //6
        drawLine(grids[2][1], 2, 2, 6, 11);
        drawLine(grids[2][1], 6, 10, 6, 6);
        drawLine(grids[2][1], 10, 10, 6, 11);
        drawLine(grids[2][1], 14, 14, 6, 6);
        //7
            //nothing
        //8
        drawLine(grids[2][1], 2, 6, 8, 8);
        drawLine(grids[2][1], 8, 8, 8, 10);
        //9
        drawLine(grids[2][1], 12, 13, 9, 9);
        //10
        drawLine(grids[2][1], 4, 8, 10, 10);
        drawLine(grids[2][1], 4, 4, 10, 13);
        //11
        drawLine(grids[2][1], 13, 13, 11, 13);
        //12
        drawLine(grids[2][1], 6, 6, 12, 14);
        //13
        drawLine(grids[2][1], 2, 4, 13, 13);
        drawLine(grids[2][1], 7, 13, 13, 13);
        //14
            //nothing
    }
    // Draw grid 2, 2
    {
        //Walls
        drawLine(grids[2][2], 0, 13, 0, 0);
        drawLine(grids[2][2], 15, 15, 0, 13);
        drawLine(grids[2][2], 0, 15, 15, 15);
        drawLine(grids[2][2], 0, 0, 0, 15);
        //Inner Walls
        drawLine(grids[2][2], 2, 14, 2, 2);
        drawLine(grids[2][2], 1, 13, 4, 4);
        drawLine(grids[2][2], 2, 14, 6, 6);
        drawLine(grids[2][2], 1, 13, 8, 8);
        drawLine(grids[2][2], 2, 14, 10, 10);
        drawLine(grids[2][2], 2, 2, 11, 13);
        drawLine(grids[2][2], 4, 4, 12, 14);
        drawLine(grids[2][2], 6, 6, 11, 13);
        drawLine(grids[2][2], 8, 8, 12, 14);
        drawLine(grids[2][2], 10, 10, 11, 13);
        drawLine(grids[2][2], 12, 12, 12, 14);
        drawLine(grids[2][2], 13, 13, 12, 14);
    }
    // Draw grid 3, 2
    {
        //Walls
        drawLine(grids[2][3], 15, 15, 0, 15);
        drawLine(grids[2][3], 0, 0, 0, 1);
        drawLine(grids[2][3], 0, 0, 15, 15);
        //Inner Walls
        drawLine(grids[2][3], 2, 14, 0, 12);
        drawLine(grids[2][3], 0, 13, 2, 15);
        drawLine(grids[2][3], 0, 5, 13, 8);
        drawLine(grids[2][3], 2, 7, 15, 10);
        drawLine(grids[2][3], 8, 13, 5, 0);
        drawLine(grids[2][3], 10, 14, 7, 3);
    }
    // Draw grid 0, 3
    {
        //Walls
        drawLine(grids[3][0], 0, 0, 0, 15);
        drawLine(grids[3][0], 15, 15, 0, 9);
        drawLine(grids[3][0], 0, 2, 15, 15);
        drawLine(grids[3][0], 5, 15, 15, 15);
        //Inner Walls
        drawLine(grids[3][0], 5, 5, 0, 8);
        drawLine(grids[3][0], 10, 10, 0, 8);
        drawLine(grids[3][0], 1, 14, 9, 9);
    }
    // Draw grid 1, 3
    {
        //Walls
        drawLine(grids[3][1], 0, 6, 0, 0);
        drawLine(grids[3][1], 9, 15, 0, 0);
        drawLine(grids[3][1], 15, 15, 0, 10);
        drawLine(grids[3][1], 15, 15, 12, 14);
        drawLine(grids[3][1], 0, 15, 15, 15);
        drawLine(grids[3][1], 0, 0, 0, 9);
        //Inner Walls
        drawLine(grids[3][1], 10, 14, 1, 1);
        drawLine(grids[3][1], 11, 14, 2, 2);
        drawLine(grids[3][1], 12, 14, 3, 3);
        drawLine(grids[3][1], 13, 14, 4, 4);
        drawLine(grids[3][1], 14, 14, 5, 5);
        drawLine(grids[3][1], 5, 14, 14, 5);
        drawLine(grids[3][1], 1, 6, 8, 3);
        drawLine(grids[3][1], 1, 6, 7, 2);
        drawLine(grids[3][1], 2, 3, 2, 2);
        drawLine(grids[3][1], 2, 2, 3, 3);
    }
    // Draw grid 2, 3
    {
        //Walls
        drawLine(grids[3][2], 0, 15, 0, 0);
        drawLine(grids[3][2], 0, 15, 15, 15);
        drawLine(grids[3][2], 0, 0, 1, 10);
        drawLine(grids[3][2], 0, 0, 12, 14);
        //Inner Walls
        drawLine(grids[3][2], 7, 15, 7, 7);
        drawLine(grids[3][2], 7, 15, 8, 8);
    }
    // Draw grids 3, 3
    {
        //Walls
        drawLine(grids[3][3], 0, 0, 0, 0);
        drawLine(grids[3][3], 2, 13, 0, 0);
        drawLine(grids[3][3], 15, 15, 0, 15);
        drawLine(grids[3][3], 0, 15, 15, 15);
        //Inner Walls
        drawLine(grids[3][3], 0, 8, 7, 7);
        drawLine(grids[3][3], 0, 8, 8, 8);
        drawLine(grids[3][3], 0, 0, 0, 0);
        drawLine(grids[3][3], 7, 7, 0, 6);
        drawLine(grids[3][3], 8, 8, 0, 6);
    }
    // Add ending, doors, and key
    {
        //True Ending
        grids[0][2][0][8] = 'X';
        grids[0][2][0][9] = 'X';
        //Fake Ending
        grids[0][1][5][6] = 'X';
        //Doors
        grids[0][3][11][11] = '/';
        grids[0][3][11][12] = '/';
        //Key
        grids[3][0][7][2] = '^';
    }
}

// This displays the entire grid. This is called after every input.
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\033[H"); // Move cursor to the top-left corner to overwrite the previous grid instead of clearing it. (This prevents all flickering!!)

    // Print the curent screen
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// This displays the a minimap that shows which screen you are currently on
void displayMinimap(int gridX, int gridY) {
    printf("\n\nMinimap\n");

    // Print the minimap
    for (int i = 0; i < NUM_GRIDS_Y; i++) {
        for (int j = 0; j < NUM_GRIDS_X; j++) {
            if (i == gridY && j == gridX) {
                printf("X ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void game() {
    // Initialize all grids
    initGrid();

    // Set key state so the player can only go through the door when they get a key
    bool hasKey = false;

    // Initial position of the player at the start of the maze
    int PlayerX = 3;
    int PlayerY = 15;
    int currentGridX = 0;
    int currentGridY = 3;
    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '@';

    char userInput;

    // Clear any text from previous screens
    system("cls");

    do {
        // Display the current state of the screen and minimap
        displayGrid(grids[currentGridY][currentGridX]);
        displayMinimap(currentGridX, currentGridY);

        // Wait for user input for the direction they want to move in
        userInput = _getch();

        // Move the player based on the user input
        switch (userInput) {
        case 'w': // If the players presses W to go up...
            if (PlayerY > 0) { // Check if the player is bellow the top of the screen
                if (grids[currentGridY][currentGridX][PlayerY - 1][PlayerX] == 'X') { // If the player moves into the X then they win
                    end();
                }
                else if (grids[currentGridY][currentGridX][PlayerY - 1][PlayerX] == '/' && !hasKey) { // If the player doesn't have the key then don't let them through
                    system("cls");
                    printf("Looks like I need a key (^) to go throught this door (/).\nI should've listened to the instructions...\n\n");
                    system("pause");
                    system("cls");
                }
                else if (grids[currentGridY][currentGridX][PlayerY - 1][PlayerX] == '^') { // If the player moves into the ^ then notify them that they now have the key
                    hasKey = true;
                    system("cls");
                    printf("I aquired the key! Now I can open the door to the exit...\n\n");
                    system("pause");
                    system("cls");
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerY--;
                }
                else if (grids[currentGridY][currentGridX][PlayerY - 1][PlayerX] != '#') { // If the player is moving into anything other than a wall then update their position
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerY--;
                }
            }
            else {
                if (currentGridY > 0) { // If the player is at the top and wants to move up, check if they are under the top-most screen...
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.'; // Then move them to the bottom of the next screen on top
                    currentGridY--;
                    PlayerY = GRID_SIZE - 1;
                }
            }
            break;
        case 's': // If the player presses S to go down, repeat all the same logic for W except down instead of up.
            if (PlayerY < GRID_SIZE - 1) {
                if (grids[currentGridY][currentGridX][PlayerY + 1][PlayerX] == '^') {
                    hasKey = true;
                    system("cls");
                    printf("I aquired the key! Now I can open the door to the exit...\n\n");
                    system("pause");
                    system("cls");
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerY++;
                }
                else if (grids[currentGridY][currentGridX][PlayerY + 1][PlayerX] != '#') {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerY++;
                }
            }
            else {
                if (currentGridY < NUM_GRIDS_Y - 1) {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    currentGridY++;
                    PlayerY = 0;
                }
                else { // If the player tries to move down and they are on the bottom-most screen, tell them that they can't exit through the beginning. Meeting this condition is only possible at the entrance.
                    system("cls");
                    printf("Nice try, but you can't exit using the entrance...\n\n");
                    system("pause");
                    system("cls");
                }
            }
            break;
        case 'a': // If the player presses A to move left, repeat all the same logic for W except left instead of up.
            if (PlayerX > 0) {
                if (grids[currentGridY][currentGridX][PlayerY][PlayerX - 1] == '^') {
                    hasKey = true;
                    system("cls");
                    printf("I aquired the key! Now I can open the door to the exit...\n\n");
                    system("pause");
                    system("cls");
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerX--;
                }
                else if (grids[currentGridY][currentGridX][PlayerY][PlayerX - 1] != '#') {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerX--;
                }
            }
            else {
                if (currentGridX > 0) {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    currentGridX--;
                    PlayerX = GRID_SIZE - 1;
                }
            }
            break;
        case 'd': // If the player presses D to move right, repeat all the same logic for W except right instead of up.
            if (PlayerX < GRID_SIZE - 1) {
                if (grids[currentGridY][currentGridX][PlayerY][PlayerX + 1] == '^') {
                    hasKey = true;
                    system("cls");
                    printf("I aquired the key! Now I can open the door to the exit...\n\n");
                    system("pause");
                    system("cls");
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerX++;
                }
                else if (grids[currentGridY][currentGridX][PlayerY][PlayerX + 1] != '#') {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    PlayerX++;
                }
            }
            else {
                if (currentGridX < NUM_GRIDS_X - 1) {
                    grids[currentGridY][currentGridX][PlayerY][PlayerX] = '.';
                    currentGridX++;
                    PlayerX = 0;
                }
            }
            break;
        }

        grids[currentGridY][currentGridX][PlayerY][PlayerX] = '@'; // Puts the player in their new positions
    } while (userInput != 'q'); // Terminate the game loop if the player presses Q

    menu(); // If the game loop is terminated then send them back to the main menu
}