#include "MinesweeperBoard.h"
MinesweeperBoard::MinesweeperBoard()
{
    width = 10;
    height = 10;

    for(int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            Board[row][col] = {false, false, false};

    Board[0][0] = {true, false, false};
    Board[1][1] = {false, false, true};
    Board[0][2] = {true, true, false};
}

void MinesweeperBoard::DefaultSetup (int width, int height)
{
    for(int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            Board[row][col] = {false, false, false};
}
void MinesweeperBoard::GenerateDEBUG (int width, int height)
{
    for (int col = 0; col <= width; col++)
        Board[0][col] = {true,false,false};
    for (int row = 0; row <= height; row++)
        if (row%2 == 0)
            Board[row][0] = {true,false,true};
    for (int both = 0; both <= width; both++)
        Board[both][both] = {true,true,false};
}
void MinesweeperBoard::GenerateSCHEME(int width, int height, int value)
{
    int MinesCounter = (width * height + value - 1) / value;
    int row, col;

    while (MinesCounter != 0)
    {
        row = rand() % height;
        col = rand() % width;

        if (Board[row][col].hasMine)
            continue;

        Board[row][col] = {true, false, false};

        MinesCounter--;
    }
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this -> width = width;
    this -> height = height;
    this -> mode = mode;

    DefaultSetup(width, height);

    if (mode == DEBUG)
        GenerateDEBUG(width, height);

    if (mode == EASY)
        GenerateSCHEME(width, height, 10);

    if (mode == NORMAL)
        GenerateSCHEME(width, height, 5);

    if (mode == HARD)
        GenerateSCHEME(width, height, 3);
}

void MinesweeperBoard::debug_display() const
{
    char mina = '.';
    char odkrycie = '.';
    char flaga = '.';

    std::cout << "  ";
    for(int col = 0; col < width; col++)
        std::cout << "   " << col << "  ";
    std::cout << std::endl;

    for(int row = 0; row < height; row++)
    {
        std::cout << row << "  ";
        for(int col = 0; col < width; col++)
        {
            Field Obecne = Board[row][col];

            if(Obecne.hasMine)
                mina = 'M';

            if(Obecne.isRevealed)
                odkrycie = 'o';

            if(Obecne.hasFlag)
                flaga = 'f';

            std::cout << "[" << mina << odkrycie << flaga << "] ";
            mina = '.'; odkrycie = '.'; flaga = '.';
        }
        std::cout << std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const {return width;}
int MinesweeperBoard::getBoardHeight() const {return height;}
int MinesweeperBoard::getValue() const
{
    int value = 10;

    if (mode == NORMAL)
        value = 5;

    else if (mode == HARD)
        value = 3;

    return value;
}

int MinesweeperBoard::getMineCount() const
{
    int mines = 0;
    for(int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            if(Board[row][col].hasMine)
                mines++;
    return mines;
}

int MinesweeperBoard::countMines(int row, int col) const
{
    if (!Board[row][col].isRevealed)
        return -1;

    if (!FieldInsideCondition(row,col))
        return -1;

    int MinesAround = 0;

    for (int row_around = row - 1; row_around <= row + 1; ++row_around)
    {
        if(row_around < 0 or row_around >= height)
            continue;

        for(int col_around = col - 1; col_around <= col + 1; ++col_around)
        {
            if(col_around < 0 or col_around >= width)
                continue;

            if (Board[row_around][col_around].hasMine)
                MinesAround++;
        }
    }
    return MinesAround;
}

bool MinesweeperBoard::FieldInsideCondition(int row, int col) const
{
    return (!(row < 0 or row >= height or col < 0 or col >= width));
}
bool MinesweeperBoard::GameFinishedCondition() const
{
    return (getGameState() != RUNNING);
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(!FieldInsideCondition(row,col) or Board[row][col].isRevealed)
        return false;

    return Board[row][col].hasFlag;
}
bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if(!FieldInsideCondition(row,col))
        return false;

    return (Board[row][col].isRevealed);
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(GameFinishedCondition() or !FieldInsideCondition(row, col) or Board[row][col].isRevealed)
        return;

    Board[row][col].hasFlag = !Board[row][col].hasFlag;
}

void MinesweeperBoard::MultipleReveal(int row, int col)
{
    for(int current_row = row - 1; current_row <= row + 1; ++current_row)
        for(int current_col = col - 1; current_col <= col + 1; ++current_col)
            revealField(current_row,current_col);
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(!FieldInsideCondition(row,col) or GameFinishedCondition() or Board[row][col].isRevealed or Board[row][col].hasFlag)
        return;

    if(!Board[row][col].hasMine)
    {
        Board[row][col].isRevealed = true;
        first_move_made = true;

        if(countMines(row,col) == 0)
            MultipleReveal(row,col);

        return;
    }

    if(!first_move_made)
    {
        first_move_made = true;

    while(true)
        {
            int new_row = rand() % height;
            int new_col = rand() % width;

            if (Board[new_row][new_col].hasMine)
                continue;

            Board[new_row][new_col].hasMine = true;
            break;
        }
        Board[row][col].hasMine = false;
        Board[row][col].isRevealed = true;
    return;
    }

    Board[row][col].isRevealed = true;
    state = FINISHED_LOSS;
}

GameState MinesweeperBoard::getGameState() const
{
    if (state == FINISHED_LOSS)
        return FINISHED_LOSS;

    for(int row = 0; row < height; ++row)
        for(int col = 0; col < width; ++col)
        {
            if (Board[row][col].isRevealed and Board[row][col].hasMine)
                return FINISHED_LOSS;

            if(!Board[row][col].isRevealed and !Board[row][col].hasMine)
                return RUNNING;
        }
    return FINISHED_WIN;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(!FieldInsideCondition(row,col))
        return '#';

    if(!isRevealed(row,col))
        return hasFlag(row, col) ? 'F' : '_';

    if(Board[row][col].hasMine)
        return 'x';

    if(countMines(row,col) == 0)
        return ' ';
    else
        return static_cast<char>(countMines(row,col) + '0');
}

void MinesweeperBoard::Replay_Change_Game_Mode(int value)
{
    state = RUNNING;
    first_move_made = false;
    DefaultSetup(width,height);
    GenerateSCHEME(width,height,value);
}
