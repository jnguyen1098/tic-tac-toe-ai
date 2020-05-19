#include "tictactoe.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return fprintf(stderr, "Usage: %s us\n", argv[0]);
    print_us(atoi(argv[1]));
    return 0;
}
