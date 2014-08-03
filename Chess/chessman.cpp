//
//  chessman.cpp
//  Chess
//
//  Created by NStretford on 8/3/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessman.h"

chessman::chessman(unit u, int row, int column)
{
    rowNum = row;
    columnNum = column;
    Type = u;
    
}

int chessman::type()
{
    if(side)
        return Type;
    return Type + 7;
}