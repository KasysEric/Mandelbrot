#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_Graphics();

    std::cout<<" WELCOME TO THE PROBLEM 2 SOLVER ::::  Display the Mandelbrot Set : \n\n\n\n";

    std::cout<<" Within this experiment we are going to set the largest bound of the Mandelbrot \n\n\n\n BUT YOU ARE FREE TO GIVE THE RANGE OF VALUES IN WHICH TO LOOK c \n\n\n";

    std::vector<double> real_ax_Mrgin(2), img_ax_Mrgin(2);
    std::cout<<" Step 1 : Enter the lowest possible real part of c : ";
    std::cin>>real_ax_Mrgin[0];
    std::cout<<"\n Step 1 : Enter the highest possible real part of c : ";
    std::cin>>real_ax_Mrgin[1];

    std::cout<<" Step 1 : Enter the lowest possible imaginary part of c : ";
    std::cin>>img_ax_Mrgin[0];
    std::cout<<"\n Step 1 : Enter the highest possible imaginary part of c : ";
    std::cin>>img_ax_Mrgin[1];

    //Step two : Defining a scale of subdivision on each axe
    int x_sub = 0, y_sub = 0;
    std::cout<<" Step 2 : Enter the subdivision count on the real axe : ";
    std::cin>>x_sub;
    std::cout<<"\n Step 2 : Enter the subdivision count on the imaginary axe : ";
    std::cin>>y_sub;

    //Step 3 : The Main script
    double x_step = (real_ax_Mrgin[1] - real_ax_Mrgin[0])/x_sub, y_step = (img_ax_Mrgin[1] - img_ax_Mrgin[0])/y_sub;
    QVector<QVector<double> > c_val(2); //the list of c values
    c_val[0].resize((x_sub+1)*(y_sub+1)); c_val[1].resize((x_sub+1)*(y_sub+1));int idx_arr = 0;
    for(int k = 0; k <= x_sub; k++)
    {
        for(int l = 0; l <= y_sub; l++)
        {
            c_val[0][idx_arr] = real_ax_Mrgin[0] + k*x_step;
            c_val[1][idx_arr] = img_ax_Mrgin[0] + l*y_step;
            idx_arr++;
        }
    }
    plot_set(c_val[0], c_val[1], 0);

    QVector<QVector<double> > mandelbrot_set(2);
    for(int k = 0; k < c_val[0].size(); k++)
    {
        QVector<double> z_temp(2); z_temp[0] = c_val[0][k]; z_temp[1] = c_val[1][k];
        bool stop_Flag = true;
        int iteration_count = 0;
        while( (iteration_count < 100) && stop_Flag )
        {
            double nw_real_part = (z_temp[0] * z_temp[0]) - (z_temp[1] * z_temp[1]) + c_val[0][k];
            double nw_img_part = 2*( z_temp[0] * z_temp[1] ) + c_val[1][k];

            //bool comparing_z_old_N_new = (nw_real_part == z_temp[0]) && (nw_img_part == z_temp[1]);
            bool comparing_z_old_N_new = (nw_real_part <= 2.0) && (nw_real_part >= -2.0) && (nw_img_part <= 1.0) && (nw_img_part >= -1.0);
            if(comparing_z_old_N_new)
            {
                z_temp[0] = nw_real_part; z_temp[1] = nw_img_part;
                iteration_count++;
            }else{
                stop_Flag = false;
            }
        }
        if(stop_Flag)
        {
            mandelbrot_set[0].append(c_val[0][k]);
            mandelbrot_set[1].append(c_val[1][k]);
        }

    }
    plot_set(mandelbrot_set[0], mandelbrot_set[1], 1);
    double area_section = x_step*y_step*mandelbrot_set[0].size();
    ui->lineEdit->setText("SURFACE AREA = "+QString::number(area_section)+" S.I\^2");

    //Step 3 : The Main script - Second Resolution
    x_sub *= 10; y_sub *= 10;
    x_step = (real_ax_Mrgin[1] - real_ax_Mrgin[0])/x_sub, y_step = (img_ax_Mrgin[1] - img_ax_Mrgin[0])/y_sub;
    QVector<QVector<double> > c_val2(2); //the list of c values
    c_val2[0].resize((x_sub+1)*(y_sub+1)); c_val2[1].resize((x_sub+1)*(y_sub+1));idx_arr = 0;
    for(int k = 0; k <= x_sub; k++)
    {
        for(int l = 0; l <= y_sub; l++)
        {
            c_val2[0][idx_arr] = real_ax_Mrgin[0] + k*x_step;
            c_val2[1][idx_arr] = img_ax_Mrgin[0] + l*y_step;
            idx_arr++;
        }
    }
    plot_set(c_val2[0], c_val2[1], 2);

    QVector<QVector<double> > mandelbrot_set2(2);
    for(int k = 0; k < c_val2[0].size(); k++)
    {
        QVector<double> z_temp(2); z_temp[0] = c_val2[0][k]; z_temp[1] = c_val2[1][k];
        bool stop_Flag = true;
        int iteration_count = 0;
        while( (iteration_count < 100) && stop_Flag )
        {
            double nw_real_part = (z_temp[0] * z_temp[0]) - (z_temp[1] * z_temp[1]) + c_val2[0][k];
            double nw_img_part = 2*( z_temp[0] * z_temp[1] ) + c_val2[1][k];

            //bool comparing_z_old_N_new = (nw_real_part == z_temp[0]) && (nw_img_part == z_temp[1]);
            bool comparing_z_old_N_new = (nw_real_part <= 2.0) && (nw_real_part >= -2.0) && (nw_img_part <= 1.0) && (nw_img_part >= -1.0);
            if(comparing_z_old_N_new)
            {
                z_temp[0] = nw_real_part; z_temp[1] = nw_img_part;
                iteration_count++;
            }else{
                stop_Flag = false;
            }
        }
        if(stop_Flag)
        {
            mandelbrot_set2[0].append(c_val2[0][k]);
            mandelbrot_set2[1].append(c_val2[1][k]);
        }

    }
    plot_set(mandelbrot_set2[0], mandelbrot_set2[1], 3);
    double area_section_2 = x_step*y_step*mandelbrot_set2[0].size();
    ui->lineEdit_2->setText("SURFACE AREA = "+QString::number(area_section_2)+" S.I\^2");

    //Step 3 : The Main script - Third Resolution
    x_sub *= 5; y_sub *= 5;
    x_step = (real_ax_Mrgin[1] - real_ax_Mrgin[0])/x_sub, y_step = (img_ax_Mrgin[1] - img_ax_Mrgin[0])/y_sub;
    QVector<QVector<double> > c_val3(2); //the list of c values
    c_val3[0].resize((x_sub+1)*(y_sub+1)); c_val3[1].resize((x_sub+1)*(y_sub+1));idx_arr = 0;
    for(int k = 0; k <= x_sub; k++)
    {
        for(int l = 0; l <= y_sub; l++)
        {
            c_val3[0][idx_arr] = real_ax_Mrgin[0] + k*x_step;
            c_val3[1][idx_arr] = img_ax_Mrgin[0] + l*y_step;
            idx_arr++;
        }
    }
    plot_set(c_val3[0], c_val3[1], 4);

    QVector<QVector<double> > mandelbrot_set3(2);
    for(int k = 0; k < c_val3[0].size(); k++)
    {
        QVector<double> z_temp(2); z_temp[0] = c_val3[0][k]; z_temp[1] = c_val3[1][k];
        bool stop_Flag = true;
        int iteration_count = 0;
        while( (iteration_count < 100) && stop_Flag )
        {
            double nw_real_part = (z_temp[0] * z_temp[0]) - (z_temp[1] * z_temp[1]) + c_val3[0][k];
            double nw_img_part = 2*( z_temp[0] * z_temp[1] ) + c_val3[1][k];

            //bool comparing_z_old_N_new = (nw_real_part == z_temp[0]) && (nw_img_part == z_temp[1]);
            bool comparing_z_old_N_new = (nw_real_part <= 2.0) && (nw_real_part >= -2.0) && (nw_img_part <= 1.0) && (nw_img_part >= -1.0);
            if(comparing_z_old_N_new)
            {
                z_temp[0] = nw_real_part; z_temp[1] = nw_img_part;
                iteration_count++;
            }else{
                stop_Flag = false;
            }
        }
        if(stop_Flag)
        {
            mandelbrot_set3[0].append(c_val3[0][k]);
            mandelbrot_set3[1].append(c_val3[1][k]);
        }

    }
    plot_set(mandelbrot_set3[0], mandelbrot_set3[1], 5);
    double area_section_3 = x_step*y_step*mandelbrot_set3[0].size();
    ui->lineEdit_3->setText("SURFACE AREA = "+QString::number(area_section_3)+" S.I\^2");

    QVector<double> area_Values(3), resolution_Values(3);
    area_Values[0] = area_section; area_Values[1] = area_section_2; area_Values[2] = area_section_3;
    resolution_Values[2] = x_sub*y_sub; x_sub /= 5; y_sub /= 5;
    resolution_Values[1] = x_sub*y_sub; x_sub /= 10; y_sub /= 10;
    resolution_Values[0] = x_sub*y_sub;

    plot_set(resolution_Values, area_Values, 6);
}

void MainWindow::load_Graphics()
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

    //The background
    QBrush background_Brush;
    background_Brush.setStyle(Qt::SolidPattern);
    background_Brush.setColor(QColor(238, 238, 236));

    ui->Mismatch_WidgetPlot->setBackground(background_Brush);

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
    ui->Mismatch_WidgetPlot->xAxis->setLabel("Real Part");

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
    ui->Mismatch_WidgetPlot->yAxis->setLabel("Imaginary Part");

    ui->Mismatch_WidgetPlot->addGraph();
    ui->Mismatch_WidgetPlot->addGraph();

    //SECOND RESOLUTION
    //Loading the axes to plot the results
    ui->Mismatch_WidgetPlot2->clearGraphs();

    //Adding the data to the gaph : Ploting into the axes
    ui->Mismatch_WidgetPlot2->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as deci
    ui->Mismatch_WidgetPlot2->legend->setVisible(true);
    QFont legendFont2 = font(); // start out with MainWindow's font..
    legendFont2.setPointSize(9); // and make a bit smaller for legend
    ui->Mismatch_WidgetPlot2->legend->setFont(legendFont2);
    ui->Mismatch_WidgetPlot2->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we a
    ui->Mismatch_WidgetPlot2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    //The background
    QBrush background_Brush2;
    background_Brush2.setStyle(Qt::SolidPattern);
    background_Brush2.setColor(QColor(238, 238, 236));

    ui->Mismatch_WidgetPlot2->setBackground(background_Brush2);

    //The axes

    ui->Mismatch_WidgetPlot2->xAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->xAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->xAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot2->xAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->xAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot2->xAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot2->xAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot2->xAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->xAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot2->xAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot2->xAxis->setLabel("Real Part");

    ui->Mismatch_WidgetPlot2->yAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->yAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->yAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot2->yAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->yAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot2->yAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot2->yAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot2->yAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot2->yAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot2->yAxis->setLabel("Imaginary Part");

    ui->Mismatch_WidgetPlot2->addGraph();
    ui->Mismatch_WidgetPlot2->addGraph();

    //THIRD RESOLUTION
    //Loading the axes to plot the results
    ui->Mismatch_WidgetPlot3->clearGraphs();

    //Adding the data to the gaph : Ploting into the axes
    ui->Mismatch_WidgetPlot3->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as deci
    ui->Mismatch_WidgetPlot3->legend->setVisible(true);
    ui->Mismatch_WidgetPlot3->legend->setFont(legendFont2);
    ui->Mismatch_WidgetPlot3->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we a
    ui->Mismatch_WidgetPlot2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    //The background
    background_Brush2.setStyle(Qt::SolidPattern);
    background_Brush2.setColor(QColor(238, 238, 236));

    ui->Mismatch_WidgetPlot3->setBackground(background_Brush2);

    //The axes

    ui->Mismatch_WidgetPlot3->xAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->xAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->xAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot3->xAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->xAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot3->xAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot3->xAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot3->xAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->xAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot3->xAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot3->xAxis->setLabel("Real Part");

    ui->Mismatch_WidgetPlot3->yAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->yAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->yAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot3->yAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->yAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot3->yAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot3->yAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot3->yAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot3->yAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot3->yAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot3->yAxis->setLabel("Imaginary Part");

    ui->Mismatch_WidgetPlot3->addGraph();
    ui->Mismatch_WidgetPlot3->addGraph();

    //GRAPH
    //Loading the axes to plot the results
    ui->Mismatch_WidgetPlot4->clearGraphs();

    //Adding the data to the gaph : Ploting into the axes
    ui->Mismatch_WidgetPlot4->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as deci
    ui->Mismatch_WidgetPlot4->legend->setVisible(true);
    ui->Mismatch_WidgetPlot4->legend->setFont(legendFont2);
    ui->Mismatch_WidgetPlot4->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we a
    ui->Mismatch_WidgetPlot4->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    //The background
    background_Brush2.setStyle(Qt::SolidPattern);
    background_Brush2.setColor(QColor(238, 238, 236));

    ui->Mismatch_WidgetPlot4->setBackground(background_Brush2);

    //The axes

    ui->Mismatch_WidgetPlot4->xAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->xAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->xAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot4->xAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->xAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot4->xAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot4->xAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot4->xAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->xAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot4->xAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot4->xAxis->setLabel("Resolution");

    ui->Mismatch_WidgetPlot4->yAxis->setTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->yAxis->setSubTickPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->yAxis->setTickLabelFont(ticks_Font);
    ui->Mismatch_WidgetPlot4->yAxis->setBasePen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->yAxis->setLabelColor(QColor(32, 74, 135));
    ui->Mismatch_WidgetPlot4->yAxis->setTickLabelColor(QColor(52, 94, 155));
    ui->Mismatch_WidgetPlot4->yAxis->grid()->setVisible(true);
    ui->Mismatch_WidgetPlot4->yAxis->grid()->setPen(ticks_Pen);
    ui->Mismatch_WidgetPlot4->yAxis->grid()->setSubGridVisible(true);
    ui->Mismatch_WidgetPlot4->yAxis->grid()->setSubGridPen(ticks_Pen_2);
    ui->Mismatch_WidgetPlot4->yAxis->setLabel("Surface Area");

    ui->Mismatch_WidgetPlot4->addGraph();
}

void MainWindow::plot_set(QVector<double> x_in, QVector<double> y_in, int idx_axes)
{
    switch (idx_axes) {
    case 1:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::darkBlue);
        pen_Graph_0.setWidthF(3.5);
        ui->Mismatch_WidgetPlot->graph(1)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot->graph(1)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot->graph(1)->setName("The Mandelbrot Set");

        //ui->Mismatch_WidgetPlot->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot->replot();
    }
        break;
    case 2:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::black);
        pen_Graph_0.setWidthF(1.5);
        ui->Mismatch_WidgetPlot2->graph(0)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot2->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot2->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot2->graph(0)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot2->graph(0)->setName("The Complex Space");

        ui->Mismatch_WidgetPlot2->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot2->replot();
    }
        break;
    case 3:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::darkYellow);
        pen_Graph_0.setWidthF(2.5);
        ui->Mismatch_WidgetPlot2->graph(1)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot2->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot2->graph(1)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot2->graph(1)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot2->graph(1)->setName("The Mandelbrot Set - Scnd. Precision");

        //ui->Mismatch_WidgetPlot->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot2->replot();
    }
        break;
    case 4:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::gray);
        pen_Graph_0.setWidthF(1.5);
        ui->Mismatch_WidgetPlot3->graph(0)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot3->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot3->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot3->graph(0)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot3->graph(0)->setName("The Complex Space ");

        ui->Mismatch_WidgetPlot3->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot3->replot();
    }
        break;
    case 5:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::darkMagenta);
        pen_Graph_0.setWidthF(3.5);
        ui->Mismatch_WidgetPlot3->graph(1)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot3->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot3->graph(1)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot3->graph(1)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot3->graph(1)->setName("The Mandelbrot Set - Thrd. Precision");

        //ui->Mismatch_WidgetPlot->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot3->replot();
    }
        break;
    case 6:
    {
        //Graph 01
        QPen pen_Graph_0(Qt::darkMagenta);
        pen_Graph_0.setWidthF(1.5);
        ui->Mismatch_WidgetPlot4->graph(0)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot4->graph(0)->setLineStyle(QCPGraph::lsStepCenter);
        ui->Mismatch_WidgetPlot4->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
        ui->Mismatch_WidgetPlot4->graph(0)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot4->graph(0)->setName("Surface Area Vs Resolution");

        ui->Mismatch_WidgetPlot4->rescaleAxes(true);

        //ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot4->replot();
    }
        break;

    default:
    {
        //Graph 01
        //double mg_Up = maxOf(cost_2.data(), cost_2.size()) + (0.2*maxOf(cost_2.data(), cost_2.size()));

        //Graph 01
        QPen pen_Graph_0(Qt::darkRed);
        pen_Graph_0.setWidthF(1.5);
        ui->Mismatch_WidgetPlot->graph(0)->setData(x_in, y_in);
        ui->Mismatch_WidgetPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->Mismatch_WidgetPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
        ui->Mismatch_WidgetPlot->graph(0)->setPen(pen_Graph_0);
        ui->Mismatch_WidgetPlot->graph(0)->setName("The Complex Space");

        ui->Mismatch_WidgetPlot->rescaleAxes(true);
        ui->Mismatch_WidgetPlot->update();
        ui->Mismatch_WidgetPlot->replot();
    }
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

