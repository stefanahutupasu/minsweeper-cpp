//
// Created by Stefana on 07.07.2021.
//

#include "MainWindow.h"
#include <utility>
#include <QHeaderView>
#include <QVBoxLayout>

void MainWindow::init() {
    table = new QTableView();
    //this->setWindowTitle(QString::fromStdString(this->player.getName()));
    this->setWindowTitle(QString::fromStdString(this->player.getName()));
    auto layout = new QVBoxLayout{this};
    coordEdit = new QLineEdit;
    coordEdit->setPlaceholderText("Enter a cell coordinate");
    layout->addWidget(table);
    layout->addWidget(coordEdit);

    revealButton = new QPushButton("Reveal", this);
    markMineButton = new QPushButton("Mark mine", this);
    layout->addWidget(revealButton);
    layout->addWidget(markMineButton);

    auto list=this->service.getCellList();
    model = new Model(list);
    this->table->setModel(model);
    this->table->resizeColumnsToContents();

    this->table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

}

void MainWindow::connectS() {
    connect(markMineButton, &QPushButton::released,this , &MainWindow::markMine);
    connect(revealButton, &QPushButton::released,this , &MainWindow::reveal);

}
