//
//  chessboard.h
//  Chess
//
//  Created by NStretford on 8/1/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#ifndef __Chess__chessboard__
#define __Chess__chessboard__

#include <iostream>
#include <string>
#include "camp.h"
#include "chessman.h"
#include "tools.h"

using namespace std;

class camp;
class point;
class chessboard
{
private:
    //string chessman[7];
    //int chess_board[10][9];
public:
    int chess_board[10][9];
    camp *black_side;
    camp *red_side;
    chessboard();
    chessboard(int[]);
    void print_chessboard();
    bool occupied(point *);
    bool self_camped(point *, bool);
    bool GetSide(point *);
    void inputTurn();
    //int[] chess_board_copy();
};



#endif /* defined(__Chess__chessboard__) */
