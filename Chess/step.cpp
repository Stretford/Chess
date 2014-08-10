//
//  step.cpp
//  Chess
//
//  Created by apple_lab on 8/4/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#include "step.h"

using namespace std;

step::step(chessman *chsm, point *dstn)
{
    //cb = chsbd;
    cm = chsm;
    destination = dstn;
    previous_location = cm->position;
    //cm->position = destination;
    //cb->chess_board[cm->position->rowNum][cm->position->columnNum] = cm->type();
    //cb->chess_board[previous_location->rowNum][previous_location->columnNum] = 14;
}


vector<point *> step::horse_stride(vector<point *> l, direction dir)
{
    vector<point *> result = l;
    bool side = cm->Camp->Side();
    switch(dir)
    {
        case LEFT:
        {
            point *p = new point(cm->position->rowNum, cm->position->columnNum - 1);
            if(!p->WithinBoard() || cm->Camp->chessBoard->occupied(p))
                return l;
            point *temp = new point(p->rowNum - 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum + 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
        }
            break;
        case RIGHT:
        {
            point *p = new point(cm->position->rowNum, cm->position->columnNum + 1);
            if(!p->WithinBoard() || cm->Camp->chessBoard->occupied(p))
                return l;
            point *temp = new point(p->rowNum - 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum + 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
        }
            break;
        case UP:
        {
            point *p = new point(cm->position->rowNum - 1, cm->position->columnNum);
            if(!p->WithinBoard() || cm->Camp->chessBoard->occupied(p))
                return l;
            point *temp = new point(p->rowNum - 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum - 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
        }
            break;
        case DOWN:
        {
            point *p = new point(cm->position->rowNum + 1, cm->position->columnNum);
            if(!p->WithinBoard() || cm->Camp->chessBoard->occupied(p))
                return l;
            point *temp = new point(p->rowNum + 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum + 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
        }
            break;
    }
    return result;
}

vector<point *> step::GetPossibleSteps()
{
    point *p = cm->position;
    vector<point *> result;
    bool side = cm->Camp->Side();
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
                {
                    if(side != cm->Camp->chessBoard->GetSide(temp))
                        result.push_back(temp);
                    break;
                }
                result.push_back(temp);
                left--;
            }
            while(right <= 8)
            {
                point *temp = new point(p->rowNum, right);
                if(cm->Camp->chessBoard->occupied(temp))
                {
                    if(side != cm->Camp->chessBoard->GetSide(temp))
                        result.push_back(temp);
                    break;
                }
                result.push_back(temp);
                right++;
            }
            while(up >= 0)
            {
                point *temp = new point(up, p->columnNum);
                if(cm->Camp->chessBoard->occupied(temp))
                {
                    if(side != cm->Camp->chessBoard->GetSide(temp))
                        result.push_back(temp);
                    break;
                }
                result.push_back(temp);
                up--;
            }
            while(down <= 9)
            {
                point *temp = new point(down, p->columnNum);
                if(cm->Camp->chessBoard->occupied(temp))
                {
                    if(side != cm->Camp->chessBoard->GetSide(temp))
                        result.push_back(temp);
                    break;
                }
                result.push_back(temp);
                down++;
            }
        }
            break;
        case HORSE:
            result = horse_stride(result, LEFT);
            result = horse_stride(result, RIGHT);
            result = horse_stride(result, UP);
            result = horse_stride(result, DOWN);
            break;
        case BISHOP:
        {
            point *temp = new point(p->rowNum + 2, p->columnNum - 2);
            point *feet = new point(p->rowNum + 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum + 2, p->columnNum + 2);
            feet = new point(p->rowNum + 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum - 2);
            feet = new point(p->rowNum - 1, p->columnNum - 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum + 2);
            feet = new point(p->rowNum - 1, p->columnNum + 1);
            if(temp->WithinBoard() && !cm->Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                result.push_back(temp);
        }
            break;
        case GUARD:
            for(int i = -1;i <= 1;i += 2)
                for(int j = -1;j <= 1;j += 2)
                {
                    point *temp = new point(p->rowNum + i, p->columnNum + j);
                    if(temp->InPalace(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                        result.push_back(temp);
                }
            break;
        case KING:
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum + i, p->columnNum);
                if(temp->InPalace(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
            }
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum, p->columnNum + i);
                if(temp->InPalace(cm->Camp->Side()) && !cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
            }
            break;
        case PAWN:
        {
            int nextRow = cm->Camp->Side() ? p->rowNum + 1: p->rowNum - 1;
            point *temp = new point(nextRow, p->columnNum);
            if(!p->StaysOpposite(cm->Camp->Side()))
            {
                if(!cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
            }
            else
            {
                point *temp = new point(p->rowNum, p->columnNum - 1);
                if(!cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
                temp = new point(p->rowNum, p->columnNum + 1);
                if(!cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
                temp = new point(nextRow, p->columnNum);
                if(!cm->Camp->chessBoard->self_camped(temp, side))
                    result.push_back(temp);
            }
        }
            break;
        default:
            break;
            
    }
    //list<point *>::iterator item;
    for(int i = 0;i < result.size();i++)
    {
        point *temp = result[i];
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


