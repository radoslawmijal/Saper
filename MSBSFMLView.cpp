//
// Created by c on 4/10/24.
//
#include "MSBSFMLView.h"

MSBSFMLView::MSBSFMLView(MinesweeperBoard &board) : board(board) {offset_x = 500; offset_y = 50; size = 75;}

int MSBSFMLView::GetOffset_x() {return offset_x;}
int MSBSFMLView::GetOffset_y() {return offset_y;}
int MSBSFMLView::GetSize() {return size;}

void MSBSFMLView::draw(sf::RenderWindow &window)
{
    sf::RectangleShape field_mine(sf::Vector2f (size,size));
    sf::Texture mine_field;
    mine_field.loadFromFile("Images/Field_Mine.png");
    field_mine.setTexture(&mine_field);

    sf::RectangleShape field_flag(sf::Vector2f (size,size));
    sf::Texture flag_field;
    flag_field.loadFromFile("Images/Field_Flag.png");
    field_flag.setTexture(&flag_field);

    sf::RectangleShape field_unrevealed(sf::Vector2f (size,size));
    sf::Texture unrevealed_field;
    unrevealed_field.loadFromFile("Images/Field_Unrevealed.png");
    field_unrevealed.setTexture(&unrevealed_field);

    sf::RectangleShape field_no_mines(sf::Vector2f (size,size));
    sf::Texture no_mines_field;
    no_mines_field.loadFromFile("Images/Field_Revealed.png");
    field_no_mines.setTexture(&no_mines_field);

    sf::RectangleShape field_zero(sf::Vector2f (size,size));
    sf::Texture zero_field;
    zero_field.loadFromFile("Images/Field_Zero.png");
    field_zero.setTexture(&zero_field);

    sf::RectangleShape field_one(sf::Vector2f (size,size));
    sf::Texture one_field;
    one_field.loadFromFile("Images/Field_One.png");
    field_one.setTexture(&one_field);

    sf::RectangleShape field_two(sf::Vector2f (size,size));
    sf::Texture two_field;
    two_field.loadFromFile("Images/Field_Two.png");
    field_two.setTexture(&two_field);

    sf::RectangleShape field_three(sf::Vector2f (size,size));
    sf::Texture three_field;
    three_field.loadFromFile("Images/Field_Three.png");
    field_three.setTexture(&three_field);

    sf::RectangleShape field_four(sf::Vector2f (size,size));
    sf::Texture four_field;
    four_field.loadFromFile("Images/Field_Four.png");
    field_four.setTexture(&four_field);

    sf::RectangleShape field_five(sf::Vector2f (size,size));
    sf::Texture five_field;
    five_field.loadFromFile("Images/Field_Five.png");
    field_five.setTexture(&five_field);

    sf::RectangleShape field_six(sf::Vector2f (size,size));
    sf::Texture six_field;
    six_field.loadFromFile("Images/Field_Six.png");
    field_six.setTexture(&six_field);

    sf::RectangleShape field_seven(sf::Vector2f (size,size));
    sf::Texture seven_field;
    seven_field.loadFromFile("Images/Field_Seven.png");
    field_seven.setTexture(&seven_field);

    sf::RectangleShape field_eight(sf::Vector2f (size,size));
    sf::Texture eight_field;
    eight_field.loadFromFile("Images/Field_Eight.png");
    field_eight.setTexture(&eight_field);

    sf::RectangleShape field_nine(sf::Vector2f (size,size));
    sf::Texture nine_field;
    nine_field.loadFromFile("Images/Field_Nine.png");
    field_nine.setTexture(&nine_field);

    sf::RectangleShape you_won(sf::Vector2f (board.getBoardWidth() * size, board.getBoardHeight() * size));
    sf::Texture you_won_texture;
    you_won_texture.loadFromFile("Images/You_Won.png");
    you_won.setTexture(&you_won_texture);

    sf::RectangleShape you_lost(sf::Vector2f (board.getBoardWidth() * size, board.getBoardHeight() * size));
    sf::Texture you_lost_texture;
    you_lost_texture.loadFromFile("Images/You_Lose.png");
    you_lost.setTexture(&you_lost_texture);

    int mines_left_counter = board.getMineCount();

    for(int row = 0; row < board.getBoardHeight(); ++row)
        for(int col = 0; col < board.getBoardWidth(); ++col)
        {
            if(board.getGameState() == FINISHED_WIN)
            {
                sf::RectangleShape you_won_copy(you_won);
                you_won_copy.setPosition(offset_x, offset_y);
                window.draw(you_won_copy);
                continue;
            }
            if(board.getGameState() == FINISHED_LOSS)
            {
                sf::RectangleShape you_lost_copy(you_lost);
                you_lost_copy.setPosition(offset_x, offset_y);
                window.draw(you_lost_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == 'x')
            {
                sf::RectangleShape field_mine_copy(field_mine);
                field_mine_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_mine_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == 'F')
            {
                sf::RectangleShape field_flag_copy(field_flag);
                field_flag_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_flag_copy);
                mines_left_counter--;
                continue;
            }
            if(board.getFieldInfo(row,col) == '_')
            {
                sf::RectangleShape field_unrevealed_copy(field_unrevealed);
                field_unrevealed_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_unrevealed_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == ' ')
            {
                sf::RectangleShape field_no_mines_copy(field_no_mines);
                field_no_mines_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_no_mines_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '1')
            {
                sf::RectangleShape field_one_copy(field_one);
                field_one_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_one_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '2')
            {
                sf::RectangleShape field_two_copy(field_two);
                field_two_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_two_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '3')
            {
                sf::RectangleShape field_three_copy(field_three);
                field_three_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_three_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '4')
            {
                sf::RectangleShape field_four_copy(field_four);
                field_four_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_four_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '5')
            {
                sf::RectangleShape field_five_copy(field_five);
                field_five_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_five_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '6')
            {
                sf::RectangleShape field_six_copy(field_six);
                field_six_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_six_copy);
                continue;
            }
            if(board.getFieldInfo(row,col) == '7')
            {
                sf::RectangleShape field_seven_copy(field_seven);
                field_seven_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_seven_copy);
            }
            if(board.getFieldInfo(row,col) == '8')
            {
                sf::RectangleShape field_eight_copy(field_eight);
                field_eight_copy.setPosition(offset_x + size * col, offset_y + size * row);
                window.draw(field_eight_copy);
                continue;
            }
//grafiki zostaly stworzone za pomoca strony: https://www.pixilart.com
        }

    sf::RectangleShape score_tens (sf::Vector2f (size,size));
    sf::RectangleShape score_ones (sf::Vector2f (size, size));

    sf::Texture score_tens_texture;
    sf::Texture score_ones_texture;

    score_tens_texture.loadFromFile("Images/Field_Unrevealed.png");
    score_ones_texture.loadFromFile("Images/Field_Unrevealed.png");

    if(mines_left_counter / 10 == 1)
        score_tens_texture.loadFromFile("Images/Field_One.png");
    if(mines_left_counter / 10 == 2)
        score_tens_texture.loadFromFile("Images/Field_Two.png");
    if(mines_left_counter / 10 == 3)
        score_tens_texture.loadFromFile("Images/Field_Three.png");


    if(mines_left_counter % 10 == 0 and mines_left_counter > 0)
        score_ones_texture.loadFromFile("Images/Field_Zero.png");
    if(mines_left_counter % 10 == 1)
        score_ones_texture.loadFromFile("Images/Field_One.png");
    if(mines_left_counter % 10 == 2)
        score_ones_texture.loadFromFile("Images/Field_Two.png");
    if(mines_left_counter % 10 == 3)
        score_ones_texture.loadFromFile("Images/Field_Three.png");
    if(mines_left_counter % 10 == 4)
        score_ones_texture.loadFromFile("Images/Field_Four.png");
    if(mines_left_counter % 10 == 5)
        score_ones_texture.loadFromFile("Images/Field_Five.png");
    if(mines_left_counter % 10 == 6)
        score_ones_texture.loadFromFile("Images/Field_Six.png");
    if(mines_left_counter % 10 == 7)
        score_ones_texture.loadFromFile("Images/Field_Seven.png");
    if(mines_left_counter % 10 == 8)
        score_ones_texture.loadFromFile("Images/Field_Eight.png");
    if(mines_left_counter % 10 == 9)
        score_ones_texture.loadFromFile("Images/Field_Nine.png");

    score_tens.setTexture(&score_tens_texture);
    score_ones.setTexture(&score_ones_texture);

    score_tens.setPosition(0,0);
    score_ones.setPosition(size,0);

    window.draw(score_tens);
    window.draw(score_ones);
}