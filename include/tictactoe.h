#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// strategy struct
struct strategy_struct {
    char best_move;
    char winner;
};

// base-3 number to base-10 number
unsigned short b3tous(const char b3[10]);

// base-10 number to base-3 number
void b3fromus(char b3[10], unsigned short us);

// base-3 number to boardstring
void boardfromb3(char board[60], char b3[10]);

// determines move number; negative if turn=1, positive if turn=2
int move_no(char b3[10]);

// counts the pieces on a board
unsigned short count_pieces(unsigned short us);

// winner function. '2' if X won, '1' if O won, '0' if tie
char winner(unsigned short us);

// print board based on base-10 representation
void print_us(unsigned short us);

// return board record
void get_record(FILE *fp, unsigned short us, struct strategy_struct *record);

// set board record
void set_record(FILE *fp, unsigned short us, struct strategy_struct record);

// print board based on base-10, but from file
void print_offset(unsigned short us);

// next board
unsigned short next(unsigned short us, char pos);

// evaluates the best move
void evaluate_move(FILE *fp, unsigned short us, struct strategy_struct *record);


#endif
