#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define KEY_UP 72


const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

int cursorX = 0;
int cursorY = 3;

int board[BOARD_HEIGHT][BOARD_WIDTH];
int turn = 1;   // White turn first

char colorNames[][6] = { "","WHITE","BLACK" };





bool checkCanPut(int _turn, int _x, int _y) {
    if (board[_y][_x] != 0) {
        return false;
    }
    else {
        return true;
    };
};

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    int inputCount;
    std::cin >> inputCount;
    std::wcout << inputCount;
    

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x] = 0;
        }
    };

    bool cantPut = false;
    
    while (1) {
        system("cls");
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                if ((x == cursorX) && (y == cursorY)) {
                    wprintf(L"⊙ ");  //●⚫⊙⚪⦾

                }
                else {
                    switch (board[y][x]) {
                    case 0: wprintf(L" ⋅ "); break;         // No color
                    case 1: wprintf(L"● "); break;
                    case 2: wprintf(L"○ "); break;
                    }
                }
            }
            std::wcout << std::endl;
        }
        
        if (cantPut) {
            std::wcout << "Can't Put" << std::endl;
        }
        else {
            std::wcout << colorNames[turn] << " turn" << std::endl;
        }

        cantPut = false;
        switch (_getch()) {
        case 'w': cursorY--; break;
        case 's': cursorY++; break;
        case 'a': cursorX--; break;
        case 'd': cursorX++; break;
        default: 
            if (checkCanPut(turn, cursorX, cursorY)) {
                board[cursorY][cursorX] = turn;
                if (turn == 1) {
                    turn = 2;
                }
                else {
                    turn = 1;
                }
                break;
            }
            else {
                cantPut = true;
            }
        }


        
        
    }
}
