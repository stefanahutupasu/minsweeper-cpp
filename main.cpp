#include <QApplication>
#include <QPushButton>
#include <fstream>
#include "MainWindow.h"

#include <sstream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //QPushButton button("Hello world!", nullptr);
    //button.resize(200, 100);
    //button.show();
    Repo repo;
    ifstream fin;
    std::string line;
    fin.open("F:\\e3-913-stefana-hutupasu\\input.txt");
    int mines;
    int size;
    if(fin.bad()) perror("oopsie"); else {
        std::getline(fin, line);
        std::istringstream iss(line);
        iss>>size;
        std::getline(fin, line);
        std::istringstream isss(line);
        isss>>mines;
        string name;
        for(int i=0;i<4;i++) {
            std::getline(fin, line);
            std::istringstream issss(line);

            issss >> name;
            repo.addPlayer(Player(name));
        }
    }

    for(int i=1;i<9;i++)
        for(char c='A';c<'A'+8;c++)
        repo.addCell(Cell(i,c,false,false,0));
    Service service(repo);
    for(auto e: service.getPlayerList())
    {auto* m = new MainWindow(service, e);
        m->show();}





    return QApplication::exec();
}
