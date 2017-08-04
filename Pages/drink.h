#ifndef DRINK_H
#define DRINK_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QModelIndex>
#include "database/dbmanager.h"
#include "database/winetable.h"
#include "winebox.h"
#include <QMap>

class Drink : public QWidget
{
    Q_OBJECT
public:
    explicit Drink(DbManager* db, QWidget *parent = nullptr);

signals:

private slots:
    void findWine();
    void drinkWine();
    void onRowChanged(QModelIndex index);

public slots:


private:
    WineBox* theBox;

    QLineEdit* colourEdit;
    QLineEdit* cellarEdit;
    QLineEdit* nameEdit;
    QLineEdit* vintageEdit;
    QLineEdit* varietyEdit;
    QLineEdit* vineyardEdit;
    QLineEdit* quantityEdit;

    QMap<QString, QString> drinkMap;
    int currentRow;
    WineTable *wineTable;
    DbManager* theDb;
    QGridLayout *setupSearch();
};

#endif // DRINK_H
