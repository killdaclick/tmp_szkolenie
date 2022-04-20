#include <stdio.h>
#include "board.h"
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void board_init(Board *b)
{
    assert(NULL != b);

    memset(b->board, eEmpty, ROWS*COLS);
}

void board_display(const Board* b)
{
    assert(NULL != b);

    board_print_header(eUpper);

    for(unsigned int row=0; row<ROWS; ++row)
    {
        board_print_row(row, b);
        if(row+1 != ROWS)
            board_print_boarder();
    }

    board_print_header(eDowner);
    putc('\n', stdout);

//    TokenState player = board_find_win(b);
//    if(eEmpty != player)
//    {
//        printf("Player %u win!\n\n", (uint32_t)player);
//    }
}


void board_print_boarder(void)
{
    char c;
    for(uint32_t i=0; i<m_rowBoarderLength; ++i)
    {
        c = ((i % 2 ) == 0) ? '+' : '-';
        putc(c, stdout);
    }
    putc('\n', stdout);
}

void board_print_cols(void)
{
    uint32_t num = 1;
    for(uint32_t i=0; i<m_rowBoarderLength; ++i)
    {
        if((i % 2 ) != 0)
        {
            putc(num + 48, stdout);
            ++num;
        }
        else
        {
            putc(' ', stdout);
        }
    }
    putc('\n', stdout);
}

void board_print_header(BoarderSide side)
{
    switch(side)
    {
        case eUpper:
            board_print_cols();
            break;
        case eDowner:
            board_print_boarder();
            break;
        default:
            return;
    }

    switch(side)
    {
        case eUpper:
            board_print_boarder();
            break;
        case eDowner:
            board_print_cols();
            break;
        default:
            return;
    }

}

char board_get_token_logo(TokenState s)
{
    switch(s)
    {
        case eUser1:
            return 'X';
        case eUser2:
            return 'Y';
        case eEmpty:
        default:
            return ' ';
    }
}

void board_print_row(uint32_t row, const Board *b)
{
    assert(ROWS > row);
    assert(NULL != b);

    const TokenState *rowData = &b->board[row*COLS];
    uint32_t num = 0;
    char c;
    for(uint32_t i=0; i<m_rowBoarderLength; ++i)
    {
        if((i % 2 ) != 0)
        {
            c = board_get_token_logo(rowData[num]);
            putc(c, stdout);
            ++num;
        }
        else
        {
            putc('|', stdout);
        }
    }
    putc('\n', stdout);
}

bool board_put_token(TokenState s, uint32_t col, Board *b)
{
    if( (COLS < col || col < 1) || eEmpty == s)
    {
        return false;
    }

    --col;
    char c = board_get_token_logo(s);
    TokenState *rowData;

    for(int row=ROWS-1; row>=0; --row)
    {
        TokenState* field = &b->board[row*COLS+col];
        if(*field == eEmpty)
        {
            *field = s;
            return true;
        }
    }

    return false;
}

TokenState board_find_win(Board *b)
{
//    // TODO: Diagonal win
//
//    for(int row=ROWS-1; row>=0; --row)
//    {
//        TokenState* field = &b->board[row*COLS+col];
//        if(*field == eEmpty)
//        {
//            *field = s;
//            break;
//        }
//    }
}
