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
    ostringstream os;
    string r, c;
    os<< rowNum;
    r = os.str();
    os.str("");
    os<< columnNum;
    c = os.str();
    
    return "(" + r + ", " + c + ")";
}

bool point::WithinBoard()
{
    return (rowNum >=0 && rowNum <= 9 && columnNum >=0 && columnNum <= 8);
}

bool point::StaysOpposite(bool side)
{
    bool a = side? rowNum >= 5 : rowNum < 5;
    return a;
}

bool point::InPalace(bool side)
{
    if(side)
        return rowNum <= 2 && columnNum >= 3 && columnNum <= 5;
    return rowNum >= 7 && columnNum >= 3 && columnNum <= 5;
}

bool point::IsEqualTo(point *p)
{
    return (rowNum == p->rowNum && columnNum == p->columnNum);
}


