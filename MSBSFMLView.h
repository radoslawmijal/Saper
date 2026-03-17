//
// Created by c on 4/10/24.
//

#ifndef SAPER_MSBSFMLVIEW_H
#define SAPER_MSBSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSBSFMLView {

    MinesweeperBoard &board;
    int offset_x;
    int offset_y;
    int size;

public:
    MSBSFMLView(MinesweeperBoard &board);
    void draw(sf::RenderWindow &window);
    int GetOffset_x();
    int GetOffset_y();
    int GetSize();
};


#endif //SAPER_MSBSFMLVIEW_H
