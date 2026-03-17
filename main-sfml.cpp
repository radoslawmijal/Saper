//
// Created by c on 4/10/24.
//
#include "MinesweeperBoard.h"
#include "MSBSFMLView.h"
#include "MSSFMLController.h"

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, HARD);
    MSBSFMLView view (board);
    MSSFMLController controller (view, board, window);

    controller.play();

    return 0;
}

            /*  DOKUMENTACJA

 Grafiki stworzone przy pomocy strony: https://www.pixilart.com

     Aby wybrać tryb trudności
     Wcisnąć odpowiednie klawisze:
    1 - EASY, 2 - NORMAL , 3 - HARD  */