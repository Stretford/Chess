//
//  main.cpp
//  Chess
//
//  Created by NStretford on 8/1/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <iostream>
#include "chessboard.h"
#include "camp.h"
#include "step.h"

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    chessboard *cb = new chessboard();
    //cb->print_chessboard();
    
    list<chessman *>::iterator i = cb->black_side->chessmen.begin();
    for(int k = 0; k < 9; k++)
        i++;
    chessman *cm = *i;
    //list<point *> test = cm->GetNextStep(new point(4, 2));
    step *step = new class step(cb, cm, new point(2, 4));
    cb->print_chessboard();
    return 0;
}


