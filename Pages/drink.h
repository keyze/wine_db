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
#include "advancedsearch.h"
#include <QMap>

class Drink : public QWidget
{
    Q_OBJECT
public:
    explicit Drink(DbManager* db, QWidget *parent = nullptr);
    void clearPage();

signals:

private slots:

    void searchWine(QString query);
    void drinkWine();
    void onRowChanged(QModelIndex index);

public slots:


private:
    WineBox* theBox;


    QLineEdit* quantityEdit;

    AdvancedSearch *asearch;

    QMap<QString, QString> drinkMap;
    int currentRow;
    WineTable *wineTable;
    DbManager* theDb;
    QGridLayout *setupSearch();
};

#endif // DRINK_H
