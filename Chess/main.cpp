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
    //chessboard *cb = new chessboard();
    //cb->print_chessboard();
    
    //string temp[] = {"车","马","象","士","将","炮","兵"};
    camp *black = new camp(true);
    camp *red = new camp(false);
    return 0;
}


