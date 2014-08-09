//
//  tools.h
//  Chess
//
//  Created by apple_lab on 8/4/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#ifndef __Chess__tools__
#define __Chess__tools__

#include <iostream>
#include <string>

using namespace std;

class point
{
public:
    int rowNum;
    int columnNum;
    point(int, int);
    string ToString();
    bool WithinBoard();
    bool StaysOpposite(bool);
    bool InPalace(bool);
};

#endif /* defined(__Chess__tools__) */
