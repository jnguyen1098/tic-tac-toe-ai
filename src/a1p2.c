#include "tictactoe.h"

int main(void)
{
    FILE *fp;
    if (!(fp = fopen("strategyfile", "wb+")))
        return fprintf(stderr, "Could not open strategyfile\n"), 1;

    for (int i = 0; i < 19683; i++) {
        struct strategy_struct dummy = {-1, ' '};
        if (!fwrite(&dummy, sizeof(struct strategy_struct), 1, fp))
            return fprintf(stderr, "strategystruct write failed at %d\n", i), 2;
    }

    fclose(fp);
    return 0;
}
