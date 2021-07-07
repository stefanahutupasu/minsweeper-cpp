//
// Created by Stefana on 07.07.2021.
//

#include "Model.h"
#include <QString>
#include <utility>

int Model::columnCount(const QModelIndex &parent) const {
    return 8;
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
                case 0:
                    return QString("A");
                case 1:
                    return QString("B");
                case 2:
                    return QString("C");
                case 3:
                    return QString("D");
                case 4:
                    return QString("E");
                case 5:
                    return QString("F");
                case 6:
                    return QString("G");
                case 7:
                    return QString("H");
                default: return QVariant();

            }
        }

        if (orientation == Qt::Vertical) {
            switch (section)
            {
                case 0:
                    return QString("1");
                case 1:
                    return QString("2");
                case 2:
                    return QString("3");
                case 3:
                    return QString("4");
                case 4:
                    return QString("5");
                case 5:
                    return QString("6");
                case 6:
                    return QString("7");
                case 7:
                    return QString("8");
                default: return QVariant();

            }
        }
    }
    return QVariant();
}

QVariant Model::data(const QModelIndex &index, int role) const {

    //bList = mgmt.getAllBuildings();
    auto row = index.row();
    auto column = index.column();
   // Cell element();
    for(auto b:this->list)
        if(b.getRow()==row+1 && b.getColumn()=='A'+column)
        {
            if(b.isRevealed1()&&b.isMine1()&&role == Qt::BackgroundRole) return QColor("red");
            if(role == Qt::BackgroundRole && !b.isRevealed1())return QColor("light green");
                if(b.isMine1()&&b.isRevealed1()) return QVariant("*");
            if(b.isRevealed1()==0) return QVariant();
            if(b.isRevealed1())return QVariant(b.getAdjacentMines());
            if(b.isRevealed1()&&b.isMine1()&&role == Qt::BackgroundRole) return QColor("red");

            return QVariant();
        }
    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;


    //if(role == Qt::BackgroundRole && element.getArea() == this->list[0].getArea())
    //    return QColor("blue");
    //else if (role==Qt::BackgroundRole)
     //   return colours[colorIndex];
    return QVariant();


}

Model::Model(const vector<Cell> list): list{list}{


    //colorIndex = rand() % 8 + 1;

}

int Model::rowCount(const QModelIndex &parent) const {
    return 8;
}


