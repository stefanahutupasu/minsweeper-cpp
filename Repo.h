//
// Created by Stefana on 07.07.2021.
//

#ifndef RETAKE_REPO_H
#define RETAKE_REPO_H

#include "Domain.h"

class Repo
{
private:
    vector<Player> playerList{};
    vector<Cell> cellList{};

public:
    Repo()=default;
    void addPlayer(const Player& p){
        this->playerList.push_back(p);
    }
    void addCell(const Cell& c)
    {
        this->cellList.push_back(c);

    }

    const vector<Player> &getPlayerList() const {
        return playerList;
    }

    const vector<Cell> &getCellList() const {
        return cellList;
    }

    void setAdjacentMines(Cell& c)
    {
        int m;
        c.setAdjacentMines(m);
    }


    void markMine(int i,char c)
    {
        for(int j=0;j<this->getCellList().size();j++)
        {
            if(this->getCellList()[j].getRow()==i&&this->getCellList()[j].getColumn()==c)
            {this->cellList[j].setIsMine(true);
            this->cellList[j].setIsRevealed(true);
            }

        }
    }

    void markMineStart(int i,char c)
    {
        for(int j=0;j<this->getCellList().size();j++)
        {
            if(this->getCellList()[j].getRow()==i&&this->getCellList()[j].getColumn()==c)
            {this->cellList[j].setIsMine(true);
                //this->cellList[j].setIsRevealed(true);
            }

        }
    }
};


#endif //RETAKE_REPO_H
