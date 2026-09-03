#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QComboBox"
#include "QString"
#include "QMessageBox"
// #include "main1.cpp"
#include <Routeengine.cpp>
#include <ui_result.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ui(new Ui::Result)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow {"
                        "background-image: url(C:/Users/ishus/Downloads/ChatGPT Image Jun 14, 2026, 04_09_07 PM.png);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-size: cover;"   // Stretch to fit
                        "}");

    // setupLocations();

    // Connect Search Button
    connect(ui->pb_1, &QPushButton::clicked,
            this, &MainWindow::on_pb_1_clicked);


    QStringList S = {"CHOOSE" , "LALGHATI", "BAIRAGARH", "AIIMS" , "EME", "BHOPAL_ISBT"};
    ui->cb_2->addItems(S);

    // Set default selected item
    ui->cb_2->setCurrentIndex(0);

    QStringList S1 = {"CHOOSE","LALGHATI", "BAIRAGARH", "AIIMS" , "EME", "BHOPAL_ISBT"};
    ui->cb_1->addItems(S1);
    ui->cb_1->setCurrentIndex(0);
    // engine.findRoute(source,destination);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findRoute()
{
    string source =
        ui->cb_1->currentText().toStdString();

    string destination =
        ui->cb_2->currentText().toStdString();

    string routeResult =
        engine.findRoute(source, destination);

    ui->te_1->setText(
        QString::fromStdString(routeResult)
        );
}


void MainWindow::on_pb_1_clicked()
{
    QString start = ui->cb_2->currentText();
    QString end   = ui->cb_1->currentText();

    if (start == end) {
        QMessageBox::warning(this, "Error", "Start and End cannot be same!");
        return;
    }

    // Call your route finding algorithm
    QString route = findRoute(start, end);
    int distance  = total_dis(start, end);
    int time  = total_time(start, end);
    // Show Result
    // QString result = QString("Route: %1 → %2\n"
    //                          "Distance: %3 km\n"
    //                          "Path: %4")
    //                      .arg(start, end)
    //                      .arg(distance)
    //                      .arg(route);

/*    ui->textEditResult->setText(result); */  // Show in QTextEdit
}

