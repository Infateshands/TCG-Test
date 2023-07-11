#include "addcard.h"
#include "ui_addcard.h"
#include <QFileDialog>
#include <QImage>
#include "addset.h"


AddCard::AddCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCard)
{
    ui->setupUi(this);

}

AddCard::~AddCard()
{
    delete ui;
}

void AddCard::on_pushButton_2_clicked()
{
   image = QFileDialog::getOpenFileName();


}


void AddCard::on_pushButton_clicked()
{
   Card c1;
   c1.cardImage = image;
   c1.cardName = ui->name->text();
   c1.cardNumber = ui->number->text();
   c1.cardRarity = ui->rarity->text();

   cards.push_back(c1);
   qDebug() << c1.cardName + " added to vector";
   hide();
   AddSet *newAddSetWindow = new AddSet;
   newAddSetWindow->show();


}

