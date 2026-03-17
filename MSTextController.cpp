//
// Created by radek on 11.04.24.
//

#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &Board, MSBoardTextView &View) : Board(Board), View(View) {}

void MSTextController::play()
{
    int option = 0;
    int row = 0, col = 0;

    while (Board.getGameState() == RUNNING)
    {
        option = 0; row = 0; col = 0;
        View.display();
        std::cout << "What's your move?" << std::endl << "1. Reveal " << std::endl << "2. Flag" << std::endl;
        std::cin >> option;
        std::cout << "Which row?" << std::endl;
        std::cin >> row;
        std::cout << "Which col?" << std::endl;
        std::cin >> col;

        if(option == 1)
            Board.revealField(row,col);
        else
            Board.toggleFlag(row,col);
    }
    View.display();

    if(Board.getGameState() == FINISHED_LOSS)
        std::cout << "GAME OVER" << std::endl;
    else
        std::cout << "YOU WON" << std::endl;
}