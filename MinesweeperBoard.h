#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <iostream>
#include <ctime>

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};

class MinesweeperBoard
{
    int width;
    int height;
    Field Board[100][100];
    GameMode mode;
    GameState state = RUNNING;
    bool first_move_made = false;

    void DefaultSetup(int width, int height);
    void GenerateSCHEME(int width, int height, int value);
    void GenerateDEBUG(int width, int height);
    void MultipleReveal(int width, int height);

    bool FieldInsideCondition(int row,int col) const;
    bool GameFinishedCondition() const;

    int getValue() const;

public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);

    void debug_display() const;
    void Replay_Change_Game_Mode(int value);

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;

    bool hasFlag(int row, int col) const;
    bool isRevealed(int row, int col) const;

    void toggleFlag(int row, int col);
    void revealField(int row, int col);

    GameState getGameState() const;

    char getFieldInfo(int row, int col) const;
};

#endif
