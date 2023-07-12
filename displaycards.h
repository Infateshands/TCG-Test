#ifndef DISPLAYCARDS_H
#define DISPLAYCARDS_H

#include <QWidget>
#include <QHBoxLayout>
#include "flowlayout.h"

namespace Ui {
class DisplayCards;
}

class DisplayCards : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayCards(QWidget *parent = nullptr);
    ~DisplayCards();
    QHBoxLayout* mainLayout;
    QHBoxLayout *cardsLayout;
    QBoxLayout *layout ;
    FlowLayout *flowLayout;
    void drawLayout();

public slots:

private:
    Ui::DisplayCards *ui;
};

#endif // DISPLAYCARDS_H
