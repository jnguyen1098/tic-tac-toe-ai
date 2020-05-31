#include "tictactoe.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return fprintf(stderr, "Usage: %s number\n", argv[0]), 1;
    int move = atoi(argv[1]);

    FILE *fp;
    if (!(fp = fopen("strategyfile", "rb+")))
        return fprintf(stderr, "Could not open strategyfile\n"), 2;

    for (int i = 0; i < 19683; i++) {
        char b3[10] = "";
        b3fromus(b3, i);
        if (count_pieces(i) == move) {
            if (winner(i) != ' ') {
                struct strategy_struct tmp = {-1, winner(i)};
                set_record(fp, i, tmp);
            } else {
                struct strategy_struct tmp;
                evaluate_move(fp, i, &tmp);
                set_record(fp, i, tmp);
            }
        }
    }

    puts("");
    fclose(fp);
    return 0;
}
