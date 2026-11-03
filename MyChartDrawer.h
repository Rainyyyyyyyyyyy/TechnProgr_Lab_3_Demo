#ifndef MYCHARTDRAWER_H
#define MYCHARTDRAWER_H


#include <QWidget>
#include <QChartView>
#include "IDataReader.h"
#include <QLineSeries>
#include <QValueAxis>
#include <QVBoxLayout>
class ChartWidget: public QWidget {

    Q_OBJECT

private:
    QtCharts::QChartView *chartView;
    QtCharts::QChart *chart;
    QtCharts::QLineSeries *lineSeries;
    QtCharts::QValueAxis *Ox;
    QtCharts::QValueAxis *Oy;


    void InitAfterSetData(){
        chart = new QtCharts::QChart();
        chart->addAxis(Ox, Qt::AlignBottom);
        chart->addAxis(Oy, Qt::AlignLeft);


        lineSeries->attachAxis(Ox);
        lineSeries->attachAxis(Oy);


        chart->addSeries(lineSeries);
        chart->legend()->hide();

        chartView = new QtCharts::QChartView(chart, this);
        chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        QVBoxLayout *BoxLayout = new QVBoxLayout(this);
        BoxLayout->addWidget(chartView);

    }
public:
    // t = 0 : все точки равны 0. t = 1 : точки генерируются случайно
    ChartWidget(uint16_t NumberOfPoints=0, bool t = false, QWidget *parent = nullptr);
    ChartWidget(const QVector<QPointF> &points, QWidget *parent = nullptr);
    ~ChartWidget();

    void setData(const QVector<QPointF> &points);
};

#endif // MYCHARTDRAWER_H
