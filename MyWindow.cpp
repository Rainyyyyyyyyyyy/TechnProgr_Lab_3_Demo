#include <QApplication>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QTreeView>
#include <QWidget>
#include <QStatusBar>
#include <QDir>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QBoxLayout>

#include "MyChartDrawer.h"
#include "MyWindow.h"



    void MyMainWindow::Init(){
        this->setGeometry(100,100, 1000, 500);
        this->setStatusBar(new QStatusBar(this));
        this->statusBar()->showMessage("Выбранный путь: ");

        QWidget *central = new QWidget(this);
        this->setCentralWidget(central);

        fileSystemModel = new QFileSystemModel();
        fileSystemModel -> setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
        fileSystemModel -> setRootPath(QDir::homePath());

    }

    MyMainWindow::~MyMainWindow() {};
    // t = 0 : все точки равны 0. t = 1 : точки генерируются случайно
    MyMainWindow::MyMainWindow(uint32_t NumberOfPoints, bool t, QWidget *parent) : QMainWindow(parent){

        Init();

        QHBoxLayout *hbox = new QHBoxLayout(this->centralWidget());
        QSplitter *splitter = new QSplitter(Qt::Horizontal, this->centralWidget());
        fileTreeView = new QTreeView(this->centralWidget());
        fileTreeView -> setModel(fileSystemModel);
        fileTreeView -> expandAll();
        splitter->addWidget(fileTreeView);
        //splitter->addWidget(new QLabel("polka"));

        //QBoxLayout *vida_layout = new QVBoxLayout(central);
        ChartWidget *vida = new ChartWidget(NumberOfPoints, t, this->centralWidget());
        //vida_layout->addWidget(vida);

        splitter->addWidget(vida);

        hbox->addWidget(splitter);
    }

    MyMainWindow::MyMainWindow(const QVector<QPointF> &points, QWidget *parent) : QMainWindow(parent){
        Init();

        QHBoxLayout *hbox = new QHBoxLayout(this->centralWidget());


        QSplitter *splitter = new QSplitter(Qt::Horizontal, this->centralWidget());
        fileTreeView = new QTreeView(this->centralWidget());
        fileTreeView -> setModel(fileSystemModel);
        fileTreeView -> expandAll();
        splitter->addWidget(fileTreeView);
        //splitter->addWidget(new QLabel("polka"));

        //QBoxLayout *vida_layout = new QVBoxLayout(central);
        ChartWidget *vida = new ChartWidget(points, this->centralWidget());
        //vida_layout->addWidget(vida);

        splitter->addWidget(vida);

        hbox->addWidget(splitter);
    }

