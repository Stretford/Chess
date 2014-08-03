//
//  chessman.h
//  Chess
//
//  Created by NStretford on 8/3/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#ifndef __Chess__chessman__
#define __Chess__chessman__

#include <iostream>
#include <string>

using namespace std;

static enum unit {chariot, horse, bishop, guard, king, canon, pawn};
class chessman
{
private:
    unit Type;
public:
    int rowNum, columnNum;
    bool side;
    int type();
    chessman(unit, int, int);
    
};

#endif /* defined(__Chess__chessman__) */
