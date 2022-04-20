#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "board.h"

static Board board;

int main(void)
{
    board_init(&board);
    board_display(&board);

    board_put_token(eUser1, 0, &board);
    board_display(&board);

    board_put_token(eUser2, 1, &board);
    board_display(&board);

    board_put_token(eUser1, 0, &board);
    board_display(&board);

    board_put_token(eUser2, 2, &board);
    board_display(&board);

    board_put_token(eUser1, 0, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    board_put_token(eUser2, 3, &board);
    board_display(&board);

    return 0;
}
