#ifndef MYWINDOW_H
#define MYWINDOW_H


#include <QApplication>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QTreeView>
#include <QWidget>


#include "MyChartDrawer.h"




class MyMainWindow : public QMainWindow{
    Q_OBJECT
private:

    QFileSystemModel *fileSystemModel;  // слева дерево папок, доходим до файла.json и показывает справа его содержимое
    QTreeView *fileTreeView;              // для отображения папок в виде дерева


    void Init();
public:
    ~MyMainWindow();
    // t = 0 : все точки равны 0. t = 1 : точки генерируются случайно
    MyMainWindow(uint32_t NumberOfPoints=0, bool t=false, QWidget *parent = nullptr);

    MyMainWindow(const QVector<QPointF> &points, QWidget *parent = nullptr);
};

#endif // MYWINDOW_H
