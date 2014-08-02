//
//  camp.cpp
//  Chess
//
//  Created by NStretford on 8/2/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include "camp.h"
#include <string>

using namespace std;

camp::camp(bool s)
{
    int n = sizeof(chessman_black) / sizeof(chessman_black[0]);
    for(int i = 0;i < n;i++)
    {
        if(s)
            chessman[i] = chessman_black[i];
        else
            chessman[i] = chessman_red[i];
    }
    side = s;
    for(int i = 0;i < n;i++)
    {
        
        cout<< chessman[i];
    }
    cout << "\n";
}

string camp::get_chessman(int k)
{
    return chessman[k];
}
