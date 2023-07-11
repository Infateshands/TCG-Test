#include "addset.h"
#include "ui_addset.h"
#include "addcard.h"
#include <QLabel>
#include <QVBoxLayout>


AddSet::AddSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSet)
{
    ui->setupUi(this);


    drawLayout();
    setLayout(mainLayout);


    connect(addCardButton, &QPushButton::clicked, this, &AddSet::addCard);




}

AddSet::~AddSet()
{
    delete ui;
}

void AddSet::addCard()
{
    AddCard *addCardWindow = new class AddCard;
    addCardWindow->show();
    close();
}

void AddSet::drawLayout(){
    mainLayout = new QVBoxLayout;
    mainLayout->SetFixedSize(500,500);
    franchiseEdit->setStyleSheet("background-color: #b031ff;"
                                 "border-radius: 10;");
    setNameEdit->setStyleSheet("background-color: #b031ff;"
                               "border-radius: 10;");
    mainLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(franchiseLabel);
    franchiseEdit->setFixedHeight(40);
    franchiseEdit->setFixedWidth(200);
    franchiseEdit->setObjectName("edit");
    mainLayout->addWidget(franchiseEdit);
    mainLayout->addWidget(setNameLabel);
    setNameEdit->setFixedHeight(40);
    setNameEdit->setFixedWidth(200);
    mainLayout->addWidget(setNameEdit);
    mainLayout->addWidget(addCardButton);
    QHBoxLayout *cardsLayout = new QHBoxLayout;

    for(int i = 0; i<cards.size(); i++){
        QFrame *frame = new QFrame;
        frame->setObjectName("cardFrame");
        frame->setStyleSheet("#cardFrame {"
                             "border: 1px solid black;"
                             "}"
                             "");
        QVBoxLayout *individualCard = new QVBoxLayout;
        QLabel *nameLabel = new QLabel(this);
        nameLabel->setText(cards[i].cardName);
        individualCard->addWidget(nameLabel);
        QLabel *numberLabel = new QLabel(this);
        numberLabel->setText(cards[i].cardNumber);
        individualCard->addWidget(numberLabel);
        QLabel *rarityLabel = new QLabel(this);
        rarityLabel->setText(cards[i].cardRarity);
        individualCard->addWidget(rarityLabel);
        frame->setLayout(individualCard);
        cardsLayout->addWidget(frame);
    }

    mainLayout->addLayout(cardsLayout);

}


