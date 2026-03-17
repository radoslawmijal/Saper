//
// Created by radek on 11.04.24.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    MinesweeperBoard &Board;
    MSBoardTextView View;

public:
    MSTextController(MinesweeperBoard &Board, MSBoardTextView &View);
    void play();
};

#endif //SAPER_MSTEXTCONTROLLER_H
