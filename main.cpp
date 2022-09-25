#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/*void Simple_SImulated_Annealing_Dialog::load_Graphics()
{
    //Loading the axes to plot the results
    ui->Mismatch_WidgetPlot->clearGraphs();

    //Adding the data to the gaph : Ploting into the axes
    ui->Mismatch_WidgetPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as deci
    ui->Mismatch_WidgetPlot->legend->setVisible(true);
    QFont legendFont = font(); // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->Mismatch_WidgetPlot->legend->setFont(legendFont);
    ui->Mismatch_WidgetPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we a
    ui->Mismatch_WidgetPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    ui->Variogram_WidgetPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as deci
    ui->Variogram_WidgetPlot->legend->setVisible(true);
    // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->Variogram_WidgetPlot->legend->setFont(legendFont);
    ui->Variogram_WidgetPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we a
    ui->Variogram_WidgetPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    //The background
    QBrush background_Brush;
    background_Brush.setStyle(Qt::SolidPattern);
    background_Brush.setColor(QColor(238, 238, 236));

    ui->Mismatch_WidgetPlot->setBackground(background_Brush);
    ui->Variogram_WidgetPlot->setBackground(background_Brush);

    //The axes
    QFont ticks_Font;
    ticks_Font.setFamily("Courier");
    ticks_Font.setPointSizeF(8.5);
    ticks_Font.setWeight(87);

    QPen ticks_Pen(QColor(132, 174, 135));
    ticks_Pen.setStyle(Qt::SolidLine);
    ticks_Pen.setWidthF(0.95);
    QPen ticks_Pen_2(QColor(166, 169, 162));
    ticks_Pen_2.setStyle(Qt::DotLine);
    ticks_Pen_2.setWidthF(0.65);

    ui->Mismatch_WidgetPlot->xAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->xAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->xAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot->xAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot->xAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot->xAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot->xAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot->xAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->xAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot->xAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot->xAxis->setLabel("F. Obj. 1");

    ui->Mismatch_WidgetPlot->yAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->yAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->yAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot->yAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot->yAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot->yAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot->yAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot->yAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot->yAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot->yAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot->yAxis->setLabel("F. Obj. 2");

    ui->Mismatch_WidgetPlot->addGraph();
    //ui->Mismatch_WidgetPlot->addGraph();



    ui->Variogram_WidgetPlot->xAxis->setTickPen(ticks_Pen);
    ui->Variogram_WidgetPlot->xAxis->setSubTickPen(ticks_Pen);
    ui->Variogram_WidgetPlot->xAxis->setTickLabelFont(ticks_Font);
    ui->Variogram_WidgetPlot->xAxis->setBasePen(ticks_Pen);
    ui->Variogram_WidgetPlot->xAxis->setLabelColor(QColor(32, 74, 135));
    ui->Variogram_WidgetPlot->xAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Variogram_WidgetPlot->xAxis->grid()->setVisible(true);
    ui->Variogram_WidgetPlot->xAxis->grid()->setPen(ticks_Pen);
    ui->Variogram_WidgetPlot->xAxis->grid()->setSubGridVisible(true);
    ui->Variogram_WidgetPlot->xAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Variogram_WidgetPlot->xAxis->setLabel("Lag distances (m)");

    ui->Variogram_WidgetPlot->yAxis->setTickPen(ticks_Pen);
    ui->Variogram_WidgetPlot->yAxis->setSubTickPen(ticks_Pen);
    ui->Variogram_WidgetPlot->yAxis->setTickLabelFont(ticks_Font);
    ui->Variogram_WidgetPlot->yAxis->setBasePen(tc_val[0][idx_arr] = real_ax_Mrgin[0] + k*x_step;icks_Pen);
    ui->Variogram_WidgetPlot->yAxis->setLabelColor(QColor(32, 74, 135));
    ui->Variogram_WidgetPlot->yAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Variogram_WidgetPlot->yAxis->grid()->setVisible(true);
    ui->Variogram_WidgetPlot->yAxis->grid()->setPen(ticks_Pen);
    ui->Variogram_WidgetPlot->yAxis->grid()->setSubGridVisible(true);
    ui->Variogram_WidgetPlot->yAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Variogram_WidgetPlot->yAxis->setLabel("Experimental Variogram ");

    ui->Variogram_WidgetPlot->addGraph();
    ui->Variogram_WidgetPlot->addGraph();
    ui->Variogram_WidgetPlot->addGraph();
    ui->Variogram_WidgetPlot->addGraph();
}

*/
