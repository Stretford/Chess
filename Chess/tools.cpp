//
//  tools.cpp
//  Chess
//
//  Created by apple_lab on 8/4/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#include "tools.h"
#include <string>
#include <sstream>

using namespace std;

point::point(int row, int column)
{
    rowNum = row;
    columnNum = column;
}

string point::ToString()
{
    stringstream ss;
    string r, c;
    ss<< rowNum;
    ss>> r;
    ss<<columnNum;
    ss>> c;
    return "(" + r + ", " + c + ")";
}

bool point::WithinBoard()
{
    return (rowNum >=0 && rowNum <= 9 && columnNum >=0 && columnNum <= 8);
}

bool point::StaysOpposite(bool side)
{
    return side? rowNum >= 5 : rowNum < 5;
}

bool point::InPalace(bool side)
{
    if(side)
        return rowNum <= 2 && columnNum >= 3 && columnNum <= 5;
    return rowNum >= 7 && columnNum >= 3 && columnNum <= 5;
}


