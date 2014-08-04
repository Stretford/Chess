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
    switch(Type)
    {
            int left = p->rowNum - 1, right = p->rowNum + 1, up = p->columnNum - 1, down = p->columnNum + 1;
        case CHARIOT:
            while(left >= 0)
            {
                point *temp = new point(left, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(right <= 8)
            {
                point *temp = new point(right, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(left >= 0)
            {
                point *temp = new point(left, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(left >= 0)
            {
                point *temp = new point(left, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
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