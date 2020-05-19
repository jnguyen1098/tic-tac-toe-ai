#include "tictactoe.h"

int main(void)
{
    char name[100];
    puts("SHALL WE PLAY A GAME?");

    printf("PLEASE ENTER YOUR NAME: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\r\n")] = 0;

    printf("GREETINGS %s\n", name);

    char input[1000];
    do {
        printf("Which side would you like to play (X/O)? ");
        fgets(input, 1000, stdin);
        input[strcspn(input, "\r\n")] = 0;
    } while (input[0] != 'O' && input[0] != 'X');

    int player_is_x = input[0] == 'X' ? 1 : 0;

    int curr_board = 0;
    char curr_move;
    
    FILE *fp = fopen("strategyfile", "r");
    if (!fp) { fprintf(stderr, "a1p5 can't open stratfile\n"); abort(); }

    for (;;) {
        char board[60];
        char b3[10];
        b3fromus(b3, curr_board);
        boardfromb3(board, b3);
        puts(board);

        curr_move = move_no(b3) < 0 ? 'O' : 'X';

        // win checking
        if (winner(curr_board) != ' ') {
            printf("Winner is %c\n",
                    winner(curr_board) == '1' ? 'O' : winner(curr_board) == '2' ? 'X' : 'T');
            exit(0);
        }

        if ((player_is_x && curr_move == 'X') || (!player_is_x && curr_move == 'O')) {
            int player_choice;
            printf("Your turn; choose a move [0-8]: ");
            scanf("%d", &player_choice);
            int potential = next(curr_board, player_choice);
            if (!potential) {
                puts("Invalid move! Try again");
            } else {
                curr_board = potential;
            }
        }

        else {
            struct strategy_struct tmp;
            get_record(fp, curr_board, &tmp);
            printf("My turn; my move is %d\n", tmp.best_move);
            int potential = next(curr_board, tmp.best_move);
            if (!potential) {
                puts("Computer made invalid move wtf");
                abort();
            } else {
                curr_board = next(curr_board, tmp.best_move);
            }
        }
    }

    fclose(fp);
    return 0;
}
