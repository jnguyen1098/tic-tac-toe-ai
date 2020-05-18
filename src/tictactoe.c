#include "tictactoe.h"

unsigned short b3tous(const char b3[10])
{
    unsigned short result = 0;

    for (int i = 8, exp = 1; i >= 0; i--) {
        result += (b3[i] - '0') * exp;
        exp *= 3;
    }

    return result;
}

void b3fromus(char b3[10], unsigned short us)
{
    for (int i = 8; i >= 0; us /= 3, i--)
        b3[i] = (us % 3) + '0';
    b3[9] = 0;
}

void boardfromb3(char board[60], char b3[10])
{
    strcpy(board, "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");
    for (int i = 0; i < 9; i++) {
        board[1 + (4 * i) + ((i / 3) * 12)] = b3[i] == '0' ? ' ' : b3[i] == '1' ? 'O' : 'X';
    }
}

void print_us(unsigned short us)
{
    char b3[10] = "";
    char board[60] = "";

    b3fromus(b3, us);
    boardfromb3(board, b3);

    printf("Board number: %d\n", us);

    printf("Board b3: %s\n", b3);
    puts(board);

    int move = 0; for (int i = 0; i < 9; i++) if (b3[i] != '0') move++;
    printf("Move: %d\n", move);

    printf("Turn: %d\n\n", move % 2 ? 1 : 2);
}
