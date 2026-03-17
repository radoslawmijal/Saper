//
// Created by c on 4/17/24.
//

# include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MSBSFMLView &view, MinesweeperBoard &board, sf::RenderWindow &window) : view(view), board(board), window(window) {}

void MSSFMLController::play()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
            {
                int row = (event.mouseButton.y - view.GetOffset_y()) / view.GetSize();

                int col = (event.mouseButton.x - view.GetOffset_x()) / view.GetSize();

                if(event.mouseButton.button == sf::Mouse::Left)
                    board.revealField(row, col);

                if(event.mouseButton.button == sf::Mouse::Right)
                    board.toggleFlag(row, col);
            }

            int easy_mode = 10, normal_mode = 5, hard_mode = 3;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                board.Replay_Change_Game_Mode(easy_mode);                                     /*     Aby wybrać tryb trudności          */
                                                                                                    /*     Wcisnąć odpowiednie klawisze:      */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))                                 /*    1 - EASY, 2 - NORMAL , 3 - HARD     */
                board.Replay_Change_Game_Mode(normal_mode);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                board.Replay_Change_Game_Mode(hard_mode);

        }
        window.clear();
        view.draw(window);
        window.display();
    }
}