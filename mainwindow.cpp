#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "home.h"
#include "addset.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <qdebug.h>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    // THIS IS THE CONSTRUCTOR, ALL OF THIS RUNS WHEN THIS CLASS/PAGE IS CALLED


    ui->setupUi(this); // this sets up the UI from design mode

    // check if database exists

    if(QFile::exists("test.db")){
        qDebug() << "exists";    // qdebug prints to the console
    }else{
        qDebug() << "not exists";
    }

    // establish db connection and open

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    db.open();


}

MainWindow::~MainWindow()
{
    delete ui;
}

// function when login button is clicked. THIS IS CALLED A SLOT. THE SIGNAL IS THE PRESS OF THE BUTTON. SIGNALS AND SLOTS are very important
void MainWindow::on_loginButton_clicked()
{
    // variables to store user input
    QString userName = ui->userNameInput->text();
    QString password = ui->passwordInput->text();

    // boolean used when user is found
    bool userFound;

    // new database query
    QSqlQuery q1;

    // run select on query
    q1.exec("SELECT * FROM users"); // selecting user table data - * means all columns, we could do SELECT userName FROM users if we just wanted to grab the user name

    // for each row in users table, check if userName and password match database table
    while(q1.next()){
        if(userName == q1.value(0).toString() && password == q1.value(1).toString()){
            userFound = true;
            user = q1.value(0).toString(); // set user to username from databse - user is delcared in header file so it accesible in other pages
        }
    }

    // when user found
    if(userFound == true){
        AddSet *homeScreenWindow = new class AddSet; // weve imported 'Home' header file up top. setting variable to new instance of that class
        homeScreenWindow->show(); // showing that class (opening the page)
        this->close(); // closes this screen - can also just use close();
    }
    else {
        QMessageBox::information(this,"No", "wrong"); // error message when username or password is incorrect
    };

    // we could aslo run 2 if statements inside the while statement to check the user name and password seperatly and set
    // boolean variables accordignly, then we could tell the user which input was incorrect






}



