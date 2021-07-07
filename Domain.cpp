//
// Created by Stefana on 07.07.2021.
//

#include "Domain.h"

Player::Player(const string &name) : name(name) {}

const string &Player::getName() const {
    return name;
}

Cell::Cell(int row, char column, bool isMine, bool isRevealed, int adjacentMines) : row(row), column(column),
                                                                                    isMine(isMine),
                                                                                    isRevealed(isRevealed),
                                                                                    adjacentMines(adjacentMines) {}

int Cell::getRow() const {
    return row;
}

char Cell::getColumn() const {
    return column;
}

bool Cell::isMine1() const {
    return isMine;
}

bool Cell::isRevealed1() const {
    return isRevealed;
}

int Cell::getAdjacentMines() const {
    return adjacentMines;
}

void Cell::setRow(int row) {
    Cell::row = row;
}

void Cell::setColumn(char column) {
    Cell::column = column;
}

void Cell::setIsMine(bool isMine) {
    Cell::isMine = isMine;
}

void Cell::setIsRevealed(bool isRevealed) {
    Cell::isRevealed = isRevealed;
}

void Cell::setAdjacentMines(int adjacentMines) {
    Cell::adjacentMines = adjacentMines;
}
