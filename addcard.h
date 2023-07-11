#ifndef ADDCARD_H
#define ADDCARD_H

#include <QWidget>
#include <QImage>
#include <QVector>

namespace Ui {
class AddCard;
}

class AddCard : public QWidget
{
    Q_OBJECT

public:
    explicit AddCard(QWidget *parent = nullptr);
    ~AddCard();


    QString image;






private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddCard *ui;
};
struct Card {
    QString cardName;
    QString cardNumber;
    QString cardRarity;
    QString cardImage;


};
inline QVector <Card> cards;



#endif // ADDCARD_H

