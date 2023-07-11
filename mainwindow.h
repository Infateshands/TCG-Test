#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "addset.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;
    // string to store user name to carry through to other pages/classes
    QString user;

private slots:
    void on_loginButton_clicked();


private:
    Ui::MainWindow *ui;
    pullUsersFromDatabase();

};
#endif // MAINWINDOW_H
