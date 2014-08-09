//
//  chessman.cpp
//  Chess
//
//  Created by NStretford on 8/3/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "chessman.h"
#include "camp.h"

chessman::chessman(camp *cp, unit u, int row, int column)
{
    Camp = cp;
    Type = u;
    position = new point(row, column);
}

int chessman::type()
{
    if(Camp->Side())
        return Type;
    return Type + 7;
}

string chessman::ToString()
{
    return CHESSMAN[type()];
}

/*
list<point *> chessman::horse_stride(list<point *> l, point *p, bool horizontal)
{
    list<point *> result = l;
    if(!p->WithinBoard() || Camp->chessBoard->occupied(p))
        return l;
    if(horizontal)  //striding horizontally, check vertically
    {
        point *temp = new point(p->rowNum - 1, p->columnNum - 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum - 1, p->columnNum + 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum - 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum + 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
    }
    else    //striding vertically, then check horizontally
    {
        point *temp = new point(p->rowNum - 1, p->columnNum - 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum - 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum - 1, p->columnNum + 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
        temp = new point(p->rowNum + 1, p->columnNum + 1);
        if(temp->WithinBoard() && !Camp->chessBoard->occupied(temp))
            result.push_back(temp);
    }
    return result;
}

list<point *> chessman::GetNextStep(point *p)
{
    list<point *> result;
    int left = p->columnNum - 1, right = p->columnNum + 1, up = p->rowNum - 1, down = p->rowNum + 1;
    switch(Type)
    {
        case CHARIOT:
        case CANON:
        {
            while(left >= 0)
            {
                point *temp = new point(p->rowNum, left);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                left--;
            }
            while(right <= 8)
            {
                point *temp = new point(p->rowNum, right);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                right++;
            }
            while(up >= 0)
            {
                point *temp = new point(up, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
                    break;
                result.push_back(temp);
                up--;
            }
            while(down <= 9)
            {
                point *temp = new point(down, p->columnNum);
                if(Camp->chessBoard->occupied(temp))
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
            if(temp->WithinBoard() && !Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(Camp->Side()) && !Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum + 2, p->columnNum + 2);
            feet = new point(p->rowNum + 1, p->columnNum + 1);
            if(temp->WithinBoard() && !Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(Camp->Side()) && !Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum - 2);
            feet = new point(p->rowNum - 1, p->columnNum - 1);
            if(temp->WithinBoard() && !Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(Camp->Side()) && !Camp->chessBoard->occupied(temp))
                result.push_back(temp);
            temp = new point(p->rowNum - 2, p->columnNum + 2);
            feet = new point(p->rowNum - 1, p->columnNum + 1);
            if(temp->WithinBoard() && !Camp->chessBoard->occupied(feet) && !temp->StaysOpposite(Camp->Side()) && !Camp->chessBoard->occupied(temp))
                result.push_back(temp);
        }
            break;
        case GUARD:
            for(int i = -1;i <= 1;i += 2)
                for(int j = -1;j <= 1;j += 2)
                {
                    point *temp = new point(p->rowNum + i, p->columnNum + j);
                    if(temp->InPalace(Camp->Side()))
                        result.push_back(temp);
                }
            break;
        case KING:
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum + i, p->columnNum);
                if(temp->InPalace(Camp->Side()))
                    result.push_back(temp);
            }
            for(int i = -1; i <= 1;i += 2)
            {
                point *temp = new point(p->rowNum, p->columnNum + i);
                if(temp->InPalace(Camp->Side()))
                    result.push_back(temp);
            }
            break;
        case PAWN:
        {
            int nextRow = Camp->Side() ? p->rowNum + 1: p->rowNum - 1;
            point *temp = new point(nextRow, p->columnNum);
            if(!p->StaysOpposite(Camp->Side()))
            {
                int a = 3;
                if(!Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
            }
            else
            {
                point *temp = new point(p->rowNum, p->columnNum - 1);
                if(!Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
                temp = new point(p->rowNum, p->columnNum + 1);
                if(!Camp->chessBoard->occupied(temp))
                    result.push_back(temp);
                temp = new point(nextRow, p->columnNum);
                if(!Camp->chessBoard->occupied(temp))
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
        Camp->chessBoard->chess_board[temp->rowNum][temp->columnNum] = type();
    }

    return result;
}
*/

/*
chariot::chariot(int row, int column)
{
    Type = CHARIOT;
    row = rowNum;
    column = columnNum;
}

horse::horse(int row, int column)
{
    Type = HORSE;
    row = rowNum;
    column = columnNum;
}

bishop::bishop(int row, int column)
{
    Type = BISHOP;
    row = rowNum;
    column = columnNum;
}

guard::guard(int row, int column)
{
    Type = GUARD;
    row = rowNum;
    column = columnNum;
}

king::king(int row, int column)
{
    Type = KING;
    row = rowNum;
    column = columnNum;
}

canon::canon(int row, int column)
{
    Type = CANON;
    row = rowNum;
    column = columnNum;
}

pawn::pawn(int row, int column)
{
    Type = PAWN;
    row = rowNum;
    column = columnNum;
}

string chariot::ToString() { return side ? "车" : "車"; }
*/
