//
// Created by macieja on 20.04.2022.
//

#pragma once

#include <stdint.h>

#define ROWS        6
#define COLS        7

#if ROWS > 9 || COLS > 9
#error "Not yet implemented"
#endif

static const uint32_t m_rowBoarderLength = COLS + (COLS+1);

typedef uint8_t Token;

typedef enum TokenState_t
{
    eEmpty = 0,
    eUser1,
    eUser2
} TokenState;

typedef struct Board_t
{
    TokenState board[COLS*ROWS];
} Board;

typedef enum BoarderSide_t
{
    eUpper = 0,
    eDowner
} BoarderSide;

void board_init(Board *b);
void board_display(const Board* b);
void board_print_cols(void);
void board_print_boarder(void);
void board_print_header(BoarderSide side);
void board_print_row(uint32_t row, const Board *b);
char board_get_token_logo(TokenState s);
void board_put_token(TokenState s, uint32_t col, Board *b);
