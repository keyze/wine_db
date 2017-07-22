#ifndef DRINK_H
#define DRINK_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QModelIndex>

#include "database/winetable.h"

class Drink : public QWidget
{
    Q_OBJECT
public:
    explicit Drink(QWidget *parent = nullptr);

signals:

private slots:
    void findWine();
    void drinkWine();
    void onRowChanged(QModelIndex index);

public slots:


private:
    QLineEdit* colourEdit;
    QLineEdit* cellarEdit;
    QLineEdit* nameEdit;
    QLineEdit* vintageEdit;
    QLineEdit* varietyEdit;
    QLineEdit* vineyardEdit;
    QLineEdit* quantityEdit;

    int currentRow;
    WineTable *wineTable;
    QGridLayout *setupSearch();
};

#endif // DRINK_H
