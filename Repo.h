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
        int m=0;
        for(auto ac:this->getCellList())
            if(ac.getRow()!=c.getRow()&&ac.getColumn()!=c.getColumn())
                if(ac.isMine1())
                if(abs(ac.getColumn()-c.getColumn()==0)||abs(ac.getColumn()-c.getColumn()==1))
                    if(abs(ac.getRow()-c.getRow()==0)||abs(ac.getRow()-c.getRow()==1))
                        m+=1;

        for(int i=0;i<this->getCellList().size();i++)
            if(this->getCellList()[i].getRow()==c.getRow()&&this->getCellList()[i].getColumn()==c.getColumn())
                this->cellList[i].setAdjacentMines(m);
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

    void markRevealed(Cell& c)
    {
        for(int i=0;i<this->getCellList().size();i++)
            if(c.getColumn()==this->getCellList()[i].getColumn() && c.getRow()==this->getCellList()[i].getRow())
                this->cellList[i].setIsRevealed(true);
    }

};


#endif //RETAKE_REPO_H
