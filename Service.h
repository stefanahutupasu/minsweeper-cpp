//
// Created by Stefana on 07.07.2021.
//

#ifndef RETAKE_SERVICE_H
#define RETAKE_SERVICE_H

#include <utility>

#include "Repo.h"
#include "Observer.h"


class Service:public Observable
{

private:
    Repo repo;
public:
    Service()=default;
    explicit Service(Repo repo)
    {
        this->repo=repo;
    }

    vector<Player> getPlayerList()
    {
        return this->repo.getPlayerList();
    }

    vector<Cell> getCellList()
    {
        return this->repo.getCellList();
    }

    void markMine(int r, char c)
    {
        this->repo.markMine(r,c);
        this->notify();
    }
};
#endif //RETAKE_SERVICE_H
