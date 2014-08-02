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

using namespace std;

//extern string chess_board[9][10];
void print_chessboard();
class chessboard
{
private:
    //string chessman[7];
    string chess_board[90];
public:
    camp *black_side;
    camp *red_side;
    chessboard();
    void print_chessboard();
};



#endif /* defined(__Chess__chessboard__) */
