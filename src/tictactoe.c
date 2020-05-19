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


int move_no(char b3[10])
{
    int move = 0;
    for (int i = 0; i < 9; i++)
        if (b3[i] != '0')
            move++;
    return move % 2 ? move * -1 : move;
}

char winner(unsigned short us)
{
    char b3[10] = "";
    b3fromus(b3, us);

    // 8 ways for X to win
    if (b3[0] == '2' && b3[1] == '2' && b3[2] == '2')
        return '2';

    if (b3[3] == '2' && b3[4] == '2' && b3[5] == '2')
        return '2';

    if (b3[6] == '2' && b3[7] == '2' && b3[8] == '2')
        return '2';

    if (b3[0] == '2' && b3[3] == '2' && b3[6] == '2')
        return '2';

    if (b3[1] == '2' && b3[4] == '2' && b3[7] == '2')
        return '2';

    if (b3[2] == '2' && b3[5] == '2' && b3[8] == '2')
        return '2';

    if (b3[0] == '2' && b3[4] == '2' && b3[8] == '2')
        return '2';

    if (b3[2] == '2' && b3[4] == '2' && b3[6] == '2')
        return '2';

    // 8 ways for O to win
    if (b3[0] == '1' && b3[1] == '1' && b3[2] == '1')
        return '1';

    if (b3[3] == '1' && b3[4] == '1' && b3[5] == '1')
        return '1';

    if (b3[6] == '1' && b3[7] == '1' && b3[8] == '1')
        return '1';

    if (b3[0] == '1' && b3[3] == '1' && b3[6] == '1')
        return '1';

    if (b3[1] == '1' && b3[4] == '1' && b3[7] == '1')
        return '1';

    if (b3[2] == '1' && b3[5] == '1' && b3[8] == '1')
        return '1';

    if (b3[0] == '1' && b3[4] == '1' && b3[8] == '1')
        return '1';

    if (b3[2] == '1' && b3[4] == '1' && b3[6] == '1')
        return '1';

    // tie check
    for (int i = 0; i < 9; i++)
        if (b3[i] == '0')
            return ' ';

    return '0';
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

    int move = move_no(b3);
    int turn = move < 0 ? 1 : 2;
    move = move < 0 ? move * -1 : move;

    printf("Move: %d\n", move);
    printf("Turn: %d\n", turn);
    printf("Winner: %d\n", 69);

    for (int i = 0; i < 9; i++) {
        printf("%d -> %d\n", i, next(us, i));
    }

    puts("");
}

void get_record(FILE *fp, unsigned short us, struct strategy_struct *record)
{
    if (!fp) return;
    fseek(fp, sizeof(struct strategy_struct) * us, SEEK_SET);
    fread(record, sizeof(struct strategy_struct), 1, fp);
    return;
}

void set_record(FILE *fp, unsigned short us, struct strategy_struct record)
{
    if (!fp) return;
    fseek(fp, sizeof(struct strategy_struct) * us, SEEK_SET);
    fwrite(&record, sizeof(struct strategy_struct), 1, fp);
    return;
}

void print_offset(unsigned short us)
{
    char b3[10] = "";
    char board[60] = "";

    b3fromus(b3, us);
    boardfromb3(board, b3);

    printf("Board number: %d\n", us);

    printf("Board b3: %s\n", b3);
    puts(board);

    int move = move_no(b3);
    int turn = move < 0 ? 1 : 2;
    move = move < 0 ? move * -1 : move;

    printf("Move: %d\n", move);
    printf("Turn: %d\n", turn);

    FILE *fp = fopen("strategyfile", "r");
    struct strategy_struct record;
    get_record(fp, us, &record);

    printf("Best: %d\n", record.best_move);
    printf("Winner: %c\n", record.winner);

    for (int i = 0; i < 9; i++) {
        printf("%d -> %d\n", i, next(us, i));
    }

    puts("");
}

unsigned short next(unsigned short us, char pos)
{
    char b3[10] = "";
    b3fromus(b3, us);

    if (b3[(int)pos] != '0') return 0;

    b3[(int)pos] = move_no(b3) < 0 ? '1' : '2';

    return b3tous(b3);
}

unsigned short count_pieces(unsigned short us)
{
    unsigned short count = 0;
    char b3[10] = "";
    b3fromus(b3, us);

    for (int i = 0; i < 9; i++) {
        if (b3[i] != '0')
            count++;
    }

    return count;
}

char whose_turn(unsigned short us)
{
    if (count_pieces(us) % 2 == 0)
        return '2';                     // X's turn
    else if (count_pieces(us) % 2 != 0)
        return '1';                     // O's turn
    else
        return 0;                       // game over 
}


void evaluate_move(FILE *fp, unsigned short us, struct strategy_struct *record)
{
    struct strategy_struct find;

    int found_tie = 0;
    int tie_pos;
    int legal_move;

    for (int i = 0; i < 9; i++) {
        unsigned short next_board = next(us, i);
        get_record(fp, next_board, &find);

        if (whose_turn(us) == find.winner) {
            record->winner = find.winner;
            record->best_move = i;
            return;
        }

        else if (find.winner == '0') {
            found_tie = 1;
            tie_pos = i;
        }

        else {
            legal_move = i;
        }
    }

    if (found_tie) {
        record->winner = '0';
        record->best_move = tie_pos;
    }

    else {
        record->winner = whose_turn(us) == '1' ? '2' : '1';
        record->best_move = legal_move;
    }

    return;
}
