#include "addset.h"
#include "ui_addset.h"
#include "addcard.h"


AddSet::AddSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSet)
{
    ui->setupUi(this);

    for(int i = 0; i<cards.size(); i++){
        ui->label->setText(cards[i].cardName);

    }

}

AddSet::~AddSet()
{
    delete ui;
}

void AddSet::on_addCardButton_clicked()
{
    AddCard *addCardWindow = new class AddCard;
    addCardWindow->show();
    close();
}

