#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

void random_move(char (*board)[16], int *pos, int *last_pos)
{
    int possible_moves[4][2] = {{999, 999}, {999, 999}, {999, 999}, {999, 999}}; // 2 dimension array for 4 possible moves
    int moves_count = 0;                                                         // for possible moves array
    int i, j;

    srand(time(0));
    int r = rand() % 4; // random number for chose one of the moves

    i = pos[0] - 1; // for upper side
    j = pos[1];
    if ((i >= 0 && j >= 0) && (i != last_pos[0] || j != last_pos[1]) && (board[i][j] != 'W') && (board[i][j] != 'G'))
    {
        // printf("*****random_move i:%d j:%d\n", i, j);
        possible_moves[moves_count][0] = i;
        possible_moves[moves_count][1] = j;
        moves_count++;
    }

    i = pos[0];
    j = pos[1] - 1; // for left side
    if ((i >= 0 && j >= 0) && (i != last_pos[0] || j != last_pos[1]) && (board[i][j] != 'W') && (board[i][j] != 'G'))

    {
        // printf("*****random_move i:%d j:%d\n", i, j);
        possible_moves[moves_count][0] = i;
        possible_moves[moves_count][1] = j;
        moves_count++;
    }

    i = pos[0];
    j = pos[1] + 1; // for right side
    if ((i >= 0 && j >= 0) && (i != last_pos[0] || j != last_pos[1]) && (board[i][j] != 'W') && (board[i][j] != 'G'))

    {
        // printf("*****random_move i:%d j:%d\n", i, j);
        possible_moves[moves_count][0] = i;
        possible_moves[moves_count][1] = j;
        moves_count++;
    }

    i = pos[0] + 1; // for lower side
    j = pos[1];
    if ((i >= 0 && j >= 0) && (i != last_pos[0] || j != last_pos[1]) && (board[i][j] != 'W') && (board[i][j] != 'G'))

    {
        // printf("*****random_move i:%d j:%d\n", i, j);
        possible_moves[moves_count][0] = i;
        possible_moves[moves_count][1] = j;
        moves_count++;
    }

    do
    {
        if (possible_moves[r][0] != 999 && possible_moves[r][1] != 999)
        {
            // printf("-------------do i:%d , j: %d\n", possible_moves[r][0], possible_moves[r][1]);
            last_pos[0] = pos[0];
            last_pos[1] = pos[1];
            board[pos[0]][pos[1]] = '.';
            pos[0] = possible_moves[r][0];
            pos[1] = possible_moves[r][1];
            board[possible_moves[r][0]][possible_moves[r][1]] = '#';
            break;
        }
        else
            r = rand() % 4;
    } while (possible_moves[r][0] != 999 && possible_moves[r][1] != 999);
}

void print_board(char (*board)[16])
{
    system("cls");
    printf("< < < < < < < < < < < < <> > > > > > > > > > > > >\n");
    for (int i = 0; i < 16; i++)
    {
        printf("<");
        for (int j = 0; j < 16; j++)
        {

            printf("%02c ", board[i][j]);
        }
        printf(">\n");
    }
    printf("< < < < < < < < < < < < <> > > > > > > > > > > > >\n");
}

int main()
{
    int pos[2] = {3, 0};
    int last_pos[2];

    char board[16][16] = {{'.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', 'W', '.', '.', '.', '.', 'W', 'W', 'W', '.', '.', '.', 'W', '.', '.'},
                          {'#', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', 'W', 'W', 'W', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'G', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', 'W', 'W', 'W', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.', '.', '.', '.'},
                          {'.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', 'W', 'W', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '$', '.', '.', '.'}};

    print_board(board);

    while (1)
    {
        Sleep(2000);
        random_move(board, pos, last_pos);
        print_board(board);
        printf("POS: %d,%d\n", pos[0], pos[1]);
        printf("LAST POS: %d,%d\n", last_pos[0], last_pos[1]);
    }
}
