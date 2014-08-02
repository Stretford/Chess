//
//  camp.h
//  Chess
//
//  Created by NStretford on 8/2/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#ifndef __Chess__camp__
#define __Chess__camp__

#include <iostream>
#include <string>

using namespace std;

static string chessman_black[7] = {"车","马","象","士","将","炮","卒"};
static string chessman_red[7] = {"車","馬","相","仕","帥","砲","兵"};

class camp
{
private:
    bool side;
    string chessman[7];
public:
    camp(bool);
    string get_chessman(int);
};

#endif /* defined(__Chess__camp__) */
