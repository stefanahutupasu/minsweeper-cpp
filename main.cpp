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
        for(int i =1;i<mines+1;i++)
        {
            int ok=0;
            while(!ok)
            {
                int r=rand()%7+1;
                char c = 'A' + rand()%7;
                for(auto x:repo.getCellList()) if(x.getRow()==r&&x.getColumn()==c) {
                    if(x.isMine1())break;
                    else {repo.markMineStart(r,c);ok=1;}
                }

            }
        }
    Service service(repo);
    for(auto e: service.getPlayerList())
    {auto* m = new MainWindow(service, e);
        m->show();}





    return QApplication::exec();
}
