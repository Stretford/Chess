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
#include "chessboard.h"
#include "chessman.h"
#include <list>

using namespace std;


class chessboard;
class camp
{
private:
    bool side;
public:
    chessboard *chessBoard;
    list<chessman *> chessmen;
    camp(chessboard *, bool);
    //string get_chessman(int);
};

#endif /* defined(__Chess__camp__) */
