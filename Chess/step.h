//
//  step.h
//  Chess
//
//  Created by apple_lab on 8/4/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#ifndef __Chess__step__
#define __Chess__step__

#include <iostream>
#include "chessboard.h"
#include "chessman.h"
#include "tools.h"
#include <list>
#include "camp.h"

using namespace std;

class step
{
private:
    list<point *> horse_stride(list<point *>, point *, bool);
public:
    chessboard *cb;
    chessman *cm;
    point *destination;
    point *previous_location;
    step(chessboard *, chessman *, point *);
    list<point *> GetPossibleSteps(point *);
    step *NextStep(chessman *, point *);
};

#endif /* defined(__Chess__step__) */
