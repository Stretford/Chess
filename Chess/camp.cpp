//
//  camp.cpp
//  Chess
//
//  Created by NStretford on 8/2/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "camp.h"
#include <string>
#include "chessman.h"

using namespace std;

camp::camp(chessboard *cb, bool s)
{
    /*initializing chessman strings
    for(int i = 0;i < 7;i++)
    {
        if(s)
            chessman[i] = CHESSMAN[i];
        else
            chessman[i] = CHESSMAN[i + 7];
    }*/
    int row = s ? 0 : 9;
    chessmen.push_back(new chessman(chariot, row, 0));
    chessmen.push_back(new chessman(chariot, row, 8));
    chessmen.push_back(new chessman(horse, row, 1));
    chessmen.push_back(new chessman(horse, row, 7));
    chessmen.push_back(new chessman(bishop, row, 2));
    chessmen.push_back(new chessman(bishop, row, 6));
    chessmen.push_back(new chessman(guard, row, 3));
    chessmen.push_back(new chessman(guard, row, 5));
    chessmen.push_back(new chessman(king, row, 6));
    chessmen.push_back(new chessman(canon, s ? 2 : 7, 1));
    chessmen.push_back(new chessman(canon, s ? 2 : 7, 7));
    for(int i = 0, j = 0; i < 5;i++, j += 2)
        chessmen.push_back(new chessman(pawn, s ? 3 : 6, j));
    side = s;
    chessBoard = cb;
}


