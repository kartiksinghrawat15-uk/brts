#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Routeengine.h"
// #include "result.ui"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class Result;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void findRoute() ;

private slots:
    void on_pushButton_clicked();

    void on_pb_1_clicked();

private:
    Ui::MainWindow *ui;
    Ui::Result *iu;
    // main1 *mn1;
    Routeengine engine ;

};
#endif
