#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() {
    srand(time(NULL));

    MinesweeperBoard board(10,10,NORMAL);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);
    board.debug_display();
    ctrl.play();
    return 0;
}