//
// Created by Stefana on 07.07.2021.
//

#ifndef RETAKE_MAINWINDOW_H
#define RETAKE_MAINWINDOW_H

#include <QHBoxLayout>
#include <QTableView>
#include <QLabel>
#include <QWidget>
#include "Service.h"
#include "Model.h"
#include <QLineEdit>
#include <QPushButton>
#include <utility>
#include <QMessageBox>

class MainWindow : public QWidget, public Observer {

Q_OBJECT

private:
    Service& service;
    Player player;
    QTableView* table{};
    QLineEdit* coordEdit{};
    QPushButton* revealButton{};
    QPushButton* markMineButton{};
   Model* model;
    void init();
    void connectS();
public:
    explicit MainWindow(Service &service, Player &p):service{service},player{p}
    {
       this->service.addObserver(this);
        init();
        connectS();

    }
    void markMine()
    {

        if(coordEdit->text()=="")return;
        std::string::size_type sizeType;

        int row = coordEdit->text().toStdString().at(0)-'0';
        char column = coordEdit->text().toStdString().at(1);
        this->service.markMine(row,column);


    }

    void reveal()
    {

        if(coordEdit->text()=="")return;
        std::string::size_type sizeType;

        int row = coordEdit->text().toStdString().at(0)-'0';
        char column = coordEdit->text().toStdString().at(1);
        //this->service.markMine(row,column);
        auto list=this->service.getCellList();
        for(auto c:list)
            if(c.getColumn()==column&&c.getRow()==row)
            {
                if(c.isRevealed1())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Oopsie!");
                    msgBox.setText("The cell is already revealed!");
                    msgBox.exec();
                }
                else if(c.isMine1())
                {
                    markMine();
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Oopsie!");
                    msgBox.setText("RIP!");
                    msgBox.exec();
                    this->destroy();
                }
                else
                {
                    this->service.setAdjacent(c);
                    this->service.markRevealed(c);

                }


            }
        if(row<1||row>8 || column<'A'||column>'G')
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Oopsie!");
            msgBox.setText("Invalid coordinate!");
            msgBox.exec();
        }
    }

    void update() override{

        auto list=this->service.getCellList();
        model = new Model(list);
        this->table->setModel(model);
        this->table->resizeColumnsToContents();

        this->table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);


    }



};



#endif //RETAKE_MAINWINDOW_H
