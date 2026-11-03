#include "MyChartDrawer.h"




#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QVBoxLayout>


ChartWidget::ChartWidget(uint16_t NumberOfPoints, bool t, QWidget *parent) : QWidget(parent) {
    QVector<QPointF> points;

    if(t == false){
        for(uint32_t i=0; i<NumberOfPoints; i++){
            points.append( QPointF(i, 0.0));
        }
    }else{
        for(uint32_t i=0; i<NumberOfPoints; i++){
            double a = rand()%10 + 1;
            double b = rand()% 10 + 1;
            points.append( QPointF(i, a/b));
        }
    }



    Ox = new QtCharts::QValueAxis(this);
    Oy = new QtCharts::QValueAxis(this);

    QPen pen(Qt::red); pen.setWidth(2);

    lineSeries = new QtCharts::QLineSeries(this);
    lineSeries->setPen(pen);

    setData(points);

    InitAfterSetData();
}


ChartWidget::ChartWidget(const QVector<QPointF> &points, QWidget *parent) : QWidget(parent){


    Ox = new QtCharts::QValueAxis(this); Ox->setTickCount(11);
    Oy = new QtCharts::QValueAxis(this); Oy->setTickCount(9);

    QPen pen(Qt::red); pen.setWidth(2);

    lineSeries = new QtCharts::QLineSeries(this);
    lineSeries->setPen(pen);
    setData(points);

     InitAfterSetData();

}

void ChartWidget::setData(const QVector<QPointF> &points){
    if(lineSeries == nullptr || lineSeries == NULL){
        throw std::invalid_argument("LineSeries is nullptr (or NULL)!");
    }
    this->lineSeries->replace(points);
    double min_x = 0.0;
    double max_x = 0.0;
    double min_y = 0.0;
    double max_y = 0.0;
    size_t n = points.size();
    for(size_t i=0; i<n; i++){
        if(max_x < points[i].x())max_x = points[i].x();
        if(min_x >  points[i].x())min_x = points[i].x();

        if(max_y < points[i].y())max_y = points[i].y();
        if(min_y >  points[i].y())min_y = points[i].y();
    }

    double dx = (max_x - min_x) / 10;
    double dy = (max_y - min_y) / 10;
    if(Ox == nullptr || Oy == nullptr ||
        Ox == NULL|| Oy == NULL){
        throw std::invalid_argument("Axis is nullptr (or NULL)!");
    }
    Ox->setRange(min_x, max_x + dx);
    Oy->setRange(min_y, max_y + dy);

}

ChartWidget::~ChartWidget() { }
