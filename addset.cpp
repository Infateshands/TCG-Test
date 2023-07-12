#include "addset.h"
#include "ui_addset.h"
#include "addcard.h"
#include <QLabel>
#include <QVBoxLayout>
#include "displaycards.h"
#include "flowlayout.h"

AddSet::AddSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSet)
{
    ui->setupUi(this);
    DisplayCards *display = new class DisplayCards;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(display);
    ui->cardDisplayFrame->setLayout(layout);


//    connect(addCardButton, &QPushButton::clicked, this, &AddSet::addCard);




}

AddSet::~AddSet()
{
    delete ui;
}




void AddSet::on_addButton_clicked()
{
    AddCard *addCardWindow = new class AddCard;
    addCardWindow->show();
    close();

}

