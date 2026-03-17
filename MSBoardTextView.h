//
// Created by radek on 11.04.24.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"

class MSBoardTextView
{
    const MinesweeperBoard& Board;

public:
    MSBoardTextView( const MinesweeperBoard &Board);
    void display();
};

#endif //SAPER_MSBOARDTEXTVIEW_H
