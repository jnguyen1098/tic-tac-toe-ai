#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// base-3 number to base-10 number
unsigned short b3tous(const char b3[10]);

// base-10 number to base-3 number
void b3fromus(char b3[10], unsigned short us);

// base-3 number to boardstring
void boardfromb3(char board[60], char b3[10]);

// print board based on base-10 representation
void print_us(unsigned short us);

#endif
