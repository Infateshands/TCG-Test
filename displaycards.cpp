#include "displaycards.h"
#include "ui_displaycards.h"
#include "addcard.h"
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QScrollArea>
#include "flowlayout.h"

DisplayCards::DisplayCards(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayCards)
{
    ui->setupUi(this);
    drawLayout();
    setLayout(cardsLayout);
}

DisplayCards::~DisplayCards()
{
    delete ui;
}

void DisplayCards::drawLayout(){
    cardsLayout = new QHBoxLayout;
    flowLayout = new FlowLayout;


    if(cards.size() > 0){
        for(int i = 0; i<cards.size(); i++){

            QFrame *frame = new QFrame;
//            frame->setFrameStyle(QFrame::StyledPanel);
            frame->setObjectName("cardFrame");
            frame->setStyleSheet("#cardFrame {"
                                 "border: 1px solid black;"
                                 "border-image: url(C:/Users/jayde/OneDrive/Desktop/charizard.jpg)"
                                 "}");
            frame->setMaximumWidth(125);
            frame->setMaximumHeight(175);
            QVBoxLayout *individualCard = new QVBoxLayout;
            QLabel *nameLabel = new QLabel(this);
            nameLabel->setText(cards[i].cardName);
//            individualCard->addWidget(nameLabel);
            QLabel *numberLabel = new QLabel(this);
            numberLabel->setText(cards[i].cardNumber);
//            individualCard->addWidget(numberLabel);
            QLabel *rarityLabel = new QLabel(this);
            rarityLabel->setText(cards[i].cardRarity);
            individualCard->addWidget(rarityLabel);
            frame->setLayout(individualCard);
            cardsLayout->addWidget(frame);
        }
    }else {
        qDebug() << "no cards in vector";
    }










}
