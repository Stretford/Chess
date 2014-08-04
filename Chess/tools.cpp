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
