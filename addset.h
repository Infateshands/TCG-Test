#ifndef ADDSET_H
#define ADDSET_H

#include <QWidget>

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
    void on_addCardButton_clicked();

private:
    Ui::AddSet *ui;
};

#endif // ADDSET_H
