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

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    chessboard *cb = new chessboard();
    //cb->print_chessboard();
    
    //string temp[] = {"车","马","象","士","将","炮","兵"};
    //cb->print_chessboard();
    list<chessman *>::iterator i = cb->red_side->chessmen.begin();
    for(int k = 0; k < 3; k++)
        i++;
    chessman *cm = *i;
    list<point *> test = cm->Get_NextStep(cm->position);
    cb->print_chessboard();
    return 0;
}


