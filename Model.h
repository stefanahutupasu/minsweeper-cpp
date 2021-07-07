//
// Created by Stefana on 07.07.2021.
//

#ifndef RETAKE_MODEL_H
#define RETAKE_MODEL_H

#include <QTableView>
#include <QAbstractTableModel>
#include "Repo.h"
#include "Service.h"
#include <ctime>



class Model : public QAbstractTableModel {
Q_OBJECT




[[nodiscard]] int rowCount(const QModelIndex &parent) const override;

private:
vector<Cell> list;

public:

QColor colours[11] = {QColor("white"), QColor("#97fac7"), QColor("#efdbcf"),
                      QColor("#ab9adb"),QColor("#9ad0e6"),QColor("#e895e8"),QColor("#98ff98"),
                      QColor("#c2d3e0"), QColor("#d996dd"),QColor("#ddb396"),QColor("black"),};

explicit Model(const vector<Cell> list);

[[nodiscard]] int columnCount(const QModelIndex &parent) const override;

[[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

[[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

int colorIndex{};



};


#endif //RETAKE_MODEL_H
