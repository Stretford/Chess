//
//  step.cpp
//  Chess
//
//  Created by apple_lab on 8/4/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#include "step.h"

using namespace std;

step::step(chessboard *chsbd, chessman *chsm, point *dstn)
{
    cb = chsbd;
    cm = chsm;
    destination = dstn;
    previous_location = cm->position;
    cm->position = destination;
    cb->chess_board[cm->position->rowNum][cm->position->columnNum] = cm->type();
    cb->chess_board[previous_location->rowNum][previous_location->columnNum] = 14;
}


list<point *> step::horse_stride(list<point *> l, point *p, bool horizontal)
{
    list<point *> result = l;
    if(!p->WithinBoard() || cm->Camp->chessBoard->occupied(p))
        return l;
    if(horizontal)  //striding horizontally, check vertically
    {
        point *temp = new point(p->rowNum - 1, p->columnNum - 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum - 1, p->columnNum + 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum - 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum + 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
    }
    else    //striding vertically, then check horizontally
    {
        point *temp = new point(p->rowNum - 1, p->columnNum - 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum - 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum - 1, p->columnNum + 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum + 1);
        if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(temp))
            result.push_back(temp);
    }
    return result;
}

list<point *> step::GetPossibleSteps(point *p)
{
    list<point *> result;
    int left = p->columnNum - 1, right = p->columnNum + 1, up = p->rowNum - 1, down = p->rowNum + 1;
    switch(cm->Type)
    {
        case CHARIOT:
        case CANON:
        {
            while(left >= 0)
            {
                point *temp = new point(p->rowNum, left);
                if(cm->Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(right <= 8)
            {
                point *temp = new point(p->rowNum, right);
                if(cm->Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                right++;
            }
            while(up >= 0)
            {
                point *temp = new point(up, p->columnNum);
                if(cm->Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                up--;
            }
            while(down <= 9)
            {
                point *temp = new point(down, p->columnNum);
                if(cm->Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                down++;
            }
        }
            break;
        case HORSE:
            result = horse_stride(result, new point(up, p->columnNum), false);
            result = horse_stride(result, new point(down, p->columnNum), false);
            result = horse_stride(result, new point(p->rowNum, left), true);
            result = horse_stride(result, new point(p->rowNum, right), true);
            break;
        case BISHOP:
        {
            point *temp = new point(p->rowNum + 2, p->columnNum - 2);
            point *feet = new point(p->rowNum + 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum + 2, p->columnNum + 2);
            feet = new point(p->rowNum + 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum - 2);
            feet = new point(p->rowNum - 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum + 2);
            feet = new point(p->rowNum - 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->occupied(temp))
                result.push_back(temp);
        }
            break;
        case GUARD:
            for(int i = -1;i <= 1;i += 2)
                for(int j = -1;j <= 1;j += 2)
                {
                    point *temp = new point(p->rowNum + i, p->columnNum + j);
                    if(temp->InPalace(cm->Camp->Side()))
                        result.push_back(temp);
                }
            break;
        case KING:
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum + i, p->columnNum);
                if(temp->InPalace(cm->Camp->Side()))
                    result.push_back(temp);
            }
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum, p->columnNum + i);
                if(temp->InPalace(cm->Camp->Side()))
                    result.push_back(temp);
            }
            break;
        case PAWN:
        {
            int nextRow = cm->Camp->Side() ? p->rowNum + 1: p->rowNum - 1;
            point *temp = new point(nextRow, p->columnNum);
            if(!p->StaysOpposite(cm->Camp->Side()))
                if(!cm->Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
            else
            {
                point *temp = new point(p->rowNum, p->columnNum - 1);
                if(!cm->Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
                temp = new point(p->rowNum, p->columnNum + 1);
                if(!cm->Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
                temp = new point(nextRow, p->columnNum);
                if(!cm->Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
            }
        }
            break;
        default:
            break;
            
    }
    list<point *>::iterator item;
    for(item = result.begin(); item != result.end(); item++)
    {
        point *temp = *item;
        cm->Camp->chessBoard->chess_board[temp->rowNum][temp->columnNum] = cm->type();
    }
    return result;
}

step *step::NextStep(chessman *chsm, point *p)
{
    cb->chess_board[p->rowNum][p->columnNum] = chsm->type();
    cb->chess_board[previous_location->rowNum][previous_location->columnNum] = 14;

    return this;
}


