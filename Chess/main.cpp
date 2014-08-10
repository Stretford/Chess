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
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    chessboard *cb = new chessboard();
    //cb->print_chessboard();
    
    list<chessman *>::iterator i = cb->black_side->chessmen.begin();
    for(int k = 0; k < 1; k++)
        i++;
    chessman *cm = *i;
    cm->position = new point(6, 3);
    //vector<point *> test = cm->(new point(4, 2));
    step *step = new class step(cm, new point(2, 4));
    vector<point *> test = step->GetPossibleSteps();
    cb->print_chessboard();
    
    
    return 0;
}


