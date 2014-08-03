//
//  chessboard.cpp
//  Chess
//
//  Created by NStretford on 8/1/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessboard.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


using namespace std;

chessboard::chessboard()
{
    black_side = new camp(this, true);
    red_side = new camp(this, false);
    
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 9;j++)
            chess_board[i][j] = 14;
    /*
    for(int i = 0, j = 0;i < 5;i++, j += 2)
    {
        chess_board[0][i] = i;
        chess_board[0][8 - i] = i;
        chess_board[9][i] = i + 7;
        chess_board[9][8 - i] = i + 7;
        chess_board[3][j] = 6;
        chess_board[3][8 - j] = 6;
        chess_board[6][j] = 13;
        chess_board[6][8 - j] = 13;
    }
    chess_board[2][1] = chess_board[2][7] = 5;
    chess_board[7][1] = chess_board[7][7] = 12;
     */
    
}

void chessboard::print_chessboard()
{

    string split = "\n|    |    |    |    |    |    |    |    |\n";
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9;j++)
        {
            string chessman = CHESSMAN[chess_board[i][j]];
            cout<< chessman;
            if(j != 8)
            cout<< "一一";
        }
        if(i == 4)
        {
            cout<< "\n|                                       |\n";
            continue;
        }
        if(i != 9)
            cout<< split;
    }
    //cout<< split;
    printf("\033[7m ;31;41m 输出红色字符 \033[m");
    
}
