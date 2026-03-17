//
// Created by c on 4/17/24.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H

#include "MSBSFMLView.h"

class MSSFMLController{

    MSBSFMLView &view;
    MinesweeperBoard &board;
    sf::RenderWindow &window;

public:

    MSSFMLController(MSBSFMLView &view, MinesweeperBoard &board, sf::RenderWindow &window);
    void play();

};

#endif //SAPER_MSSFMLCONTROLLER_H
