//
// Created by Stefana on 07.07.2021.
//

#ifndef RETAKE_DOMAIN_H
#define RETAKE_DOMAIN_H

#include <cstdio>
#include <string>
#include <utility>
#include <cstring>
#include <sstream>
#include <vector>


using namespace std;
class Player{
public:
    Player(const string &name);

private:
    string name;
public:
    const string &getName() const;

public:

};


class Cell{
public:
    Cell(int row, char column, bool isMine, bool isRevealed, int adjacentMines);

private:
    int row;
public:
    int getRow() const;

    char getColumn() const;

    bool isMine1() const;

    bool isRevealed1() const;

    int getAdjacentMines() const;

private:
    char column;
public:
    void setRow(int row);

    void setColumn(char column);

    void setIsMine(bool isMine);

    void setIsRevealed(bool isRevealed);

    void setAdjacentMines(int adjacentMines);

private:
    bool isMine;
    bool isRevealed;
    int adjacentMines;

};

#endif //RETAKE_DOMAIN_H
