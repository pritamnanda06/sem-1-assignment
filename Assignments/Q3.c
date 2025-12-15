#include <stdio.h>
#include <string.h>
//House design with two bedrooms,a bathroom,a hall,a living room and a kitchen.

#define MAX_W 80
#define MAX_H 30

typedef struct {
    char name[16];
    int x, y;        
    int w, h;        
} Room;

void initGrid(char grid[MAX_H][MAX_W], int H, int W, char fill) {
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            grid[r][c] = fill;
        }
    }
}

void drawBorder(char grid[MAX_H][MAX_W], int H, int W) {
    
    for (int c = 0; c < W; c++) {
        grid[0][c]     = '#';
        grid[H-1][c]   = '#';
    }
    for (int r = 0; r < H; r++) {
        grid[r][0]     = '#';
        grid[r][W-1]   = '#';
    }
}

void drawRoom(char grid[MAX_H][MAX_W], int H, int W, Room room) {
    int x = room.x, y = room.y, w = room.w, h = room.h;

    
    if (x < 1) x = 1;
    if (y < 1) y = 1;
    if (x + w >= W-1) w = (W-2) - x;
    if (y + h >= H-1) h = (H-2) - y;

    
    for (int c = x; c <= x + w; c++) {
        grid[y][c]       = '#';
        grid[y + h][c]   = '#';
    }
    for (int r = y; r <= y + h; r++) {
        grid[r][x]       = '#';
        grid[r][x + w]   = '#';
    }

    
    int labelLen = (int)strlen(room.name);
    int lx = x + (w - labelLen) / 2;
    int ly = y + h / 2;
    if (lx < x + 1) lx = x + 1;
    if (ly < y + 1) ly = y + 1;

    for (int i = 0; i < labelLen && lx + i < x + w; i++) {
        grid[ly][lx + i] = room.name[i];
    }
}

void addDoor(char grid[MAX_H][MAX_W], int H, int W, int x, int y) {
   
    if (x >= 0 && x < W && y >= 0 && y < H) {
        if (grid[y][x] == '#') {
            grid[y][x] = ' ';
        }
    }
}

void printGrid(char grid[MAX_H][MAX_W], int H, int W) {
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            putchar(grid[r][c]);
        }
        putchar('\n');
    }
}

int main() {
    int W = 60, H = 22; 
    char grid[MAX_H][MAX_W];

   
    if (W > MAX_W || H > MAX_H) {
        printf("Canvas too large. Max W=%d, H=%d\n", MAX_W, MAX_H);
        return 1;
    }

    initGrid(grid, H, W, ' ');
    drawBorder(grid, H, W);

    
    Room living   = {"Living",   2,  2,  26, 10};
    Room kitchen  = {"Kitchen",  30, 2,  12, 10};
    Room bed1     = {"Bed-1",     2, 13, 18, 7};
    Room bed2     = {"Bed-2",    22, 13, 20, 7};
    Room bath     = {"Bath",     44, 13, 12, 7};
    Room hall    =  {"Hall",   44,  2, 12, 6};

    drawRoom(grid, H, W, living);
    drawRoom(grid, H, W, kitchen);
    drawRoom(grid, H, W, bed1);
    drawRoom(grid, H, W, bed2);
    drawRoom(grid, H, W, bath);
    drawRoom(grid, H, W, hall);

    
    addDoor(grid, H, W, 30, 7);   
    addDoor(grid, H, W, 28, 7);    

   
    addDoor(grid, H, W, 44, 6);    
    addDoor(grid, H, W, 28, 6);    

    
    addDoor(grid, H, W, 22, 16);   
    addDoor(grid, H, W, 20, 16);
   
    addDoor(grid, H, W, 44, 17);   
    addDoor(grid, H, W, 42, 17);   

    
    addDoor(grid, H, W, 41, 6);    
    addDoor(grid, H, W, 41, 8);    

   
    addDoor(grid, H, W, 50, H-1);

    printGrid(grid, H, W);
    return 0;
}