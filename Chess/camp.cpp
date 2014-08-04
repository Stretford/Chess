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
    int row = s ? 0 : 9;
    
    chessmen.push_back(new chessman(this, CHARIOT, row, 0));
    chessmen.push_back(new chessman(this, CHARIOT, row, 8));
    chessmen.push_back(new chessman(this, HORSE, row, 1));
    chessmen.push_back(new chessman(this, HORSE, row, 7));
    chessmen.push_back(new chessman(this, BISHOP, row, 2));
    chessmen.push_back(new chessman(this, BISHOP, row, 6));
    chessmen.push_back(new chessman(this, GUARD, row, 3));
    chessmen.push_back(new chessman(this, GUARD, row, 5));
    chessmen.push_back(new chessman(this, KING, row, 4));
    chessmen.push_back(new chessman(this, CANON, s ? 2 : 7, 1));
    chessmen.push_back(new chessman(this, CANON, s ? 2 : 7, 7));
     
    for(int i = 0, j = 0; i < 5;i++, j += 2)
        chessmen.push_back(new chessman(this, PAWN, s ? 3 : 6, j));
    
    side = s;
    chessBoard = cb;
}

bool camp::Side()
{
    return side;
}

