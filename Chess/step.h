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
    enum direction {LEFT, RIGHT, UP, DOWN};
    vector<point *> horse_stride(vector<point *>, direction);
public:
    chessboard *cb;
    chessman *cm;
    point *destination;
    point *previous_location;
    step(chessman *, point *);
    vector<point *> GetPossibleSteps();
    step *NextStep(chessman *, point *);
};

#endif /* defined(__Chess__step__) */
