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
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

chessboard::chessboard()
{
    black_side = new camp(this, true);
    red_side = new camp(this, false);

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 9;j++)
            chess_board[i][j] = 14;

    list<chessman *>::iterator ptrr, ptrb;
    for(ptrb = black_side->chessmen.begin(), ptrr = red_side->chessmen.begin(); ptrb != black_side->chessmen.end(); ptrb++, ptrr++)
    {
        chessman *cm = *ptrr;
        chess_board[cm->position->rowNum][cm->position->columnNum] = cm->type();
        cm = *ptrb;
        chess_board[cm->position->rowNum][cm->position->columnNum] = cm->type();
    }
}

chessboard::chessboard(int p[])
{
    
    black_side = new camp(this, true);
    red_side = new camp(this, false);
    
    for(int i = 0; i < 90; i++)
    {
        int g = i % 10, s = i / 10;
        chess_board[s][g] = p[i];
    }
}

bool chessboard::occupied(point *p)
{
    return chess_board[p->rowNum][p->columnNum] != 14;
}

bool chessboard::GetSide(point *p)
{
    return chess_board[p->rowNum][p->columnNum] < 7;
}

bool chessboard::self_camped(point *p, bool side)
{
    bool a = (chess_board[p->rowNum][p->columnNum] != 14 && side == GetSide(p));
    return a;
}

void chessboard::print_chessboard()
{

    string split = "\n|    |    |    |    |    |    |    | 　　|\n";
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9;j++)
        {
            string chessman = CHESSMAN[chess_board[i][j]];
            cout<< chessman;
            if(j != 8)
            cout<< "一一";
        }
        if(i == 4)
        {
            cout<< "\n|                                    　　|\n";
            continue;
        }
        if(i == 0 || i == 7)
            cout<< "\n|    |    |    | ╲ | ╱  |    |    |    |\n";
        else if(i == 1 || i == 8)
            cout<< "\n|    |    |    | ╱ | ╲  |    |    |    |\n";
        else if(i != 9)
            cout<< split;
    }
    //cout<< split;
    //printf("\033[7m ;31;41m 输出红色字符 \033[m");

}

void chessboard::inputTurn()
{
    cout<< "input the chessman coordinates(rowNum, columnNum):";
    point *p = new point(-1, -1);
    char s;
    cin >> p->rowNum >> s >> p->columnNum;
    while(!p->WithinBoard())
    {
        cout<< "Invalid coordinate";
        cin >> p->rowNum >> s >> p->columnNum;
        //return;
    }
    while(chess_board[p->rowNum][p->columnNum] == 14)   //empty
    {
        cout<< "No chessman found";
        cin >> p->rowNum >> s >> p->columnNum;
    }
    cout<< CHESSMAN[chess_board[p->rowNum][p->columnNum]] << ", destination:";
    
    cin >> p->rowNum >> s >> p->columnNum;
    while(!p->WithinBoard())
    {
        cout<< "Invalid coordinate";
        cin >> p->rowNum >> s >> p->columnNum;
        //return;
    }
}


