//
//  chessman.cpp
//  Chess
//
//  Created by NStretford on 8/3/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessman.h"

chessman::chessman(camp *cp, unit u, int row, int column)
{
    Camp = cp;
    Type = u;
    rowNum = row;
    columnNum = column;
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