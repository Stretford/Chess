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
#include "camp.h"
#include "tools.h"
#include <list>
#include <vector>
#include "chessboard.h"


using namespace std;

enum unit {CHARIOT, HORSE, BISHOP, GUARD, KING, CANON, PAWN};
static string CHESSMAN[15] = {"车","马","象","士","将","炮","卒","車","馬","相","仕","帥","砲","兵","一"};

class camp;
class chessman
{
protected:
    //list<point *> horse_stride(list<point *>, point *, bool);
public:
    unit Type;
    camp *Camp;
    point *position;
    int type();
    chessman(camp *, unit, int, int);
    string ToString();
    //vector<point *> NextPossibleSteps;
};

/*
class chariot: public chessman
{
public:
    chariot(int, int);
    virtual string ToString();
};

class horse: public chessman
{
public:
    horse(int, int);
    virtual string ToString();
};

class bishop: public chessman
{
public:
    bishop(int, int);
    virtual string ToString();
};

class guard: public chessman
{
public:
    guard(int, int);
    virtual string ToString();
};

class king: public chessman
{
public:
    king(int, int);
    virtual string ToString();
};

class canon: public chessman
{
public:
    canon(int, int);
    virtual string ToString();
};

class pawn: public chessman
{
public:
    pawn(int, int);
    virtual string ToString();
};
*/
#endif /* defined(__Chess__chessman__) */
