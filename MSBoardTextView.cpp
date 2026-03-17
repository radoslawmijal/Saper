//
// Created by radek on 11.04.24.
//
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(const MinesweeperBoard &Board) : Board(Board){}

void MSBoardTextView::display()
{
    std::cout << "  ";
    for(int col = 0; col < Board.getBoardWidth(); col++)
        std::cout << "    " << col << "  ";
    std::cout << std::endl;

    for(int row = 0; row < Board.getBoardHeight(); row++)
    {
        std::cout << row << "     ";
        for(int col = 0; col < Board.getBoardWidth(); col++)
        {
            std::cout << Board.getFieldInfo(row,col) << "      ";
        }
        std::cout << std::endl;
    }
}