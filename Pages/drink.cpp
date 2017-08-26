#include "drink.h"
#include <QPushButton>
#include <QLabel>
#include <QTableView>
#include <QHeaderView>
#include <QMap>
#include <QDebug>
#include <QSpacerItem>

Drink::Drink(DbManager *db, QWidget *parent) : QWidget(parent),  currentRow(0), theDb(db)
{
    QFont drinkFont;
    drinkFont.setPixelSize(20);
    drinkFont.setBold(true);

    QFont viewFont;
    viewFont.setPixelSize(20);

    QPushButton *drink = new QPushButton(tr("Drink"));
    drink->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    drink->setMaximumHeight(50);
    drink->setFont(drinkFont);
    QTableView *view = new QTableView;

    asearch = new AdvancedSearch(theDb);
    asearch->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    theBox = new WineBox;
    wineTable = new WineTable;
    view->setModel(wineTable);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->setFont(viewFont);

    view->show();

    QGridLayout* layout = setupSearch();

    layout->addWidget(view, 1, 0, 1, 4);
    layout->addWidget(drink, 2, 2, 1, 2);
    this->setLayout(layout);

    connect(asearch, SIGNAL(sigSearch(QString)), this, SLOT(searchWine(QString)));

    connect(drink, SIGNAL(clicked(bool)), this, SLOT(drinkWine()));
    connect(view->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(onRowChanged(QModelIndex)));
}

QGridLayout* Drink::setupSearch()
{
    QGridLayout *layout = new QGridLayout;
    QFont lblFont;
    lblFont.setBold(true);
    lblFont.setPixelSize(20);

    QFont editFont;
    editFont.setPixelSize(20);

    QLabel *quantitylbl = new QLabel(tr("Enter Quantity:"));
    quantitylbl->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    quantitylbl->setFont(lblFont);

    quantityEdit = new QLineEdit;
    quantityEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    quantityEdit->setFont(editFont);
    quantityEdit->setMaximumHeight(50);



    layout->addWidget(asearch, 0, 0, 1, 4);
    layout->addWidget(quantitylbl, 2, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(quantityEdit, 2, 1, 1, 1);

    return layout;

}


void Drink::searchWine(QString query)
{
    wineTable->search(query);
}

void Drink::drinkWine()
{
    if (drinkMap.isEmpty()) {
        theBox->setNoWineSelectedtoDrink();
    } else if (quantityEdit->text() != "") {
        if (theDb->decrementQuantity(drinkMap, quantityEdit->text().toInt())) {
            theBox->setSuccessDrink();
            wineTable->clearTable();
            drinkMap.clear();

        } else {
            theBox->setFailNotEnoughDrink();
        }

    } else {
        theBox->setNoQuantityDrink();
    }
    theBox->ok();

}

void Drink::onRowChanged(QModelIndex index)
{
    int row = index.row();
    qDebug() << index.row();
    QString vineyard = index.sibling(row, 0).data().toString();
    QString name = index.sibling(row, 1).data().toString();
    QString vintage = index.sibling(row, 2).data().toString();
    QString variety = index.sibling(row, 3).data().toString();
    QString colour = index.sibling(row, 4).data().toString();
    QString region = index.sibling(row, 5).data().toString();


    drinkMap.insert("colour", colour);
    drinkMap.insert("region", region);
    drinkMap.insert("name", name);
    drinkMap.insert("vintage", vintage);
    drinkMap.insert("variety", variety);
    drinkMap.insert("vineyard", vineyard);




}


