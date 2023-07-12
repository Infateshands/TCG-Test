#ifndef ADDSET_H
#define ADDSET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class AddSet;
}

class AddSet : public QWidget
{
    Q_OBJECT

public:
    explicit AddSet(QWidget *parent = nullptr);
    ~AddSet();

private slots:


    void on_addButton_clicked();

private:
    Ui::AddSet *ui;

    QVBoxLayout *mainLayout;
    QLabel *franchiseLabel = new QLabel("Franchise");
    QLabel *setNameLabel = new QLabel("Set Name");
    QLineEdit *franchiseEdit = new QLineEdit;
    QLineEdit *setNameEdit = new QLineEdit;


    QPushButton *addCardButton = new QPushButton("Add Card");





};


#endif // ADDSET_H
