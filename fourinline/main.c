#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "board.h"

static Board board;

int main(void)
{
    bool tokenOk;

    board_init(&board);
    board_display(&board);

    if(board_put_token(eUser1, 1, &board))
        board_display(&board);

    if(board_put_token(eUser2, 2, &board))
        board_display(&board);

    if(board_put_token(eUser1, 1, &board))
        board_display(&board);

    if(board_put_token(eUser2, 3, &board))
        board_display(&board);

    if(board_put_token(eUser1, 1, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    if(board_put_token(eUser2, 4, &board))
        board_display(&board);

    return 0;
}
