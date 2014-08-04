//
//  chessman.cpp
//  Chess
//
//  Created by NStretford on 8/3/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessman.h"
#include "camp.h"

chessman::chessman(camp *cp, unit u, int row, int column)
{
    Camp = cp;
    Type = u;
    position = new point(row, column);
}

int chessman::type()
{
    if(Camp->Side())
        return Type;
    return Type + 7;
}

string chessman::ToString()
{
    return CHESSMAN[type()];
}

list<point *> chessman::Get_NextStep(point *p)
{
    list<point *> result;
    int left = p->columnNum - 1, right = p->columnNum + 1, up = p->rowNum - 1, down = p->rowNum + 1;
    switch(Type)
    {
        case CHARIOT:
        {
            while(left >= 0)
            {
                point *temp = new point(p->rowNum, left);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(right <= 8)
            {
                point *temp = new point(p->rowNum, right);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                right++;
            }
            while(up >= 0)
            {
                point *temp = new point(up, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                up--;
            }
            while(down <= 9)
            {
                point *temp = new point(down, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                down++;
            }
        }
        break;
        default:
            break;
            
    }
    
    return result;
}


/*
chariot::chariot(int row, int column)
{
    Type = CHARIOT;
    row = rowNum;
    column = columnNum;
}

horse::horse(int row, int column)
{
    Type = HORSE;
    row = rowNum;
    column = columnNum;
}

bishop::bishop(int row, int column)
{
    Type = BISHOP;
    row = rowNum;
    column = columnNum;
}

guard::guard(int row, int column)
{
    Type = GUARD;
    row = rowNum;
    column = columnNum;
}

king::king(int row, int column)
{
    Type = KING;
    row = rowNum;
    column = columnNum;
}

canon::canon(int row, int column)
{
    Type = CANON;
    row = rowNum;
    column = columnNum;
}

pawn::pawn(int row, int column)
{
    Type = PAWN;
    row = rowNum;
    column = columnNum;
}

string chariot::ToString() { return side ? "车" : "車"; }
*/