//
//  chessboard.cpp
//  Chess
//
//  Created by NStretford on 8/1/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessboard.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

chessboard::chessboard()
{
    black_side = new camp(true);
    red_side = new camp(false);
}

void chessboard::print_chessboard()
{
    
    std::string c = " —— ";
    std::string up = "|";
    std::cout << "车" << c <<"马"<< c <<"象"<< c <<"士"<< c <<"将"<< c
    <<"士"<< c <<"象"<< c <<"马"<< c <<"车";
    std::string split = "\n|     |     |    |     |     |    |     |     |";
    
    std::cout<<split;
    
    
}
