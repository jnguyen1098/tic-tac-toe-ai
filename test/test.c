#include "tictactoe.h"

void test(int lhs, int rhs)
{
    if (lhs != rhs) {
        printf("%d != %d\n", lhs, rhs);
        abort();
    }
}

int main(void)
{
    puts("********** TESTING START **********");

    struct {
        char b3[10];
        unsigned short us;
    } answers[1000] = {
        {"000000001", 1},
        {"000000002", 2},
        {"000000010", 3},
        {"000000011", 4},
        {"001200201", 1234},
        {"222222220", 19680},
        {"222222221", 19681},
        {"222222222", 19682},
        {"NULL", 0}
    };

    /* base-10 to base-3 testing */
    printf("Testing base-10 to base-3... ");
    for (int i = 0; answers[i].us; i++)
        test(b3tous(answers[i].b3), answers[i].us);
    puts("complete!");

    /* base-3 to base-10 testing */
    printf("Testing base-3 to base-10... ");
    char b3[10] = "";
    for (int i = 0; answers[i].us; i++)
        test((b3fromus(b3, answers[i].us), strcmp(b3, answers[i].b3)), 0);
    puts("complete!");

    /* test */
    for (int i = 0; i < 10; i++)
        print_us(i);
    for (int i = 19673; i < 19683; i++)
        print_us(i);

    puts("********** TESTING END **********");
    return 0;
}
