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


    void on_addButton_clicked();

    void on_browseButton_clicked();

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

