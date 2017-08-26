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
    QPushButton *find = new QPushButton(tr("find"));
    QPushButton *drink = new QPushButton(tr("Drink"));
    drink->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    QTableView *view = new QTableView;

    asearch = new AdvancedSearch(theDb);
    asearch->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    theBox = new WineBox;
    wineTable = new WineTable;
    view->setModel(wineTable);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    view->show();

    QGridLayout* layout = setupSearch();
  //  layout->addWidget(find, 4, 0, 1, 4);
    layout->addWidget(view, 1, 0, 1, 4);
    layout->addWidget(drink, 2, 2, 1, 2);
    this->setLayout(layout);

    connect(asearch, SIGNAL(sigSearch(QString)), this, SLOT(searchWine(QString)));
    connect(find, SIGNAL(clicked(bool)), this, SLOT(findWine()));
    connect(drink, SIGNAL(clicked(bool)), this, SLOT(drinkWine()));
    connect(view->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(onRowChanged(QModelIndex)));
}

QGridLayout* Drink::setupSearch()
{
    QGridLayout *layout = new QGridLayout;
//    QLabel*colourlbl = new QLabel(tr("Colour"));
//    QLabel *cellarlbl = new QLabel(tr("Cellar"));
//    QLabel *namelbl = new QLabel(tr("Name"));
//    QLabel *vintagelbl = new QLabel(tr("Vintage"));
//    QLabel *varietylbl = new QLabel(tr("Variety"));
//    QLabel *vineyardlbl = new QLabel(tr("Vineyard"));
    QLabel *quantitylbl = new QLabel(tr("Enter Quantity:"));
    quantitylbl->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    colourEdit = new QLineEdit;
    nameEdit = new QLineEdit;
    vintageEdit = new QLineEdit;
    varietyEdit = new QLineEdit;
    vineyardEdit = new QLineEdit;
    cellarEdit = new QLineEdit;
    quantityEdit = new QLineEdit;
    quantityEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    layout->addWidget(cellarlbl, 0, 0);
//    layout->addWidget(cellarEdit, 0, 1);

//    layout->addWidget(namelbl, 0, 2);
//    layout->addWidget(nameEdit, 0, 3);

//    layout->addWidget(varietylbl, 1, 0);
//    layout->addWidget(varietyEdit, 1, 1);

//    layout->addWidget(vineyardlbl, 1, 2);
//    layout->addWidget(vineyardEdit, 1, 3);

//    layout->addWidget(colourlbl, 2, 0);
//    layout->addWidget(colourEdit, 2, 1);

//    layout->addWidget(vintagelbl, 2, 2);
//    layout->addWidget(vintageEdit, 2, 3);

    layout->addWidget(asearch, 0, 0, 1, 4);
    layout->addWidget(quantitylbl, 2, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(quantityEdit, 2, 1, 1, 1);

    return layout;

}

void Drink::findWine()
{
    QMap<QString, QString> wineMap;
    wineMap.insert("colour", colourEdit->text());
    wineMap.insert("location", cellarEdit->text());
    wineMap.insert("name", nameEdit->text());
    wineMap.insert("vintage", vintageEdit->text());
    wineMap.insert("variety", varietyEdit->text());
    wineMap.insert("vineyard", vineyardEdit->text());


    wineTable->searchQuery(wineMap);
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



  //  QMap map;

}

//this->setHeaderData(0, Qt::Horizontal, QObject::tr("Colour"));
//this->setHeaderData(1, Qt::Horizontal, QObject::tr("Variety"));
//this->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
//this->setHeaderData(3, Qt::Horizontal, QObject::tr("Region"));
//this->setHeaderData(4, Qt::Horizontal, QObject::tr("Vineyard"));
//this->setHeaderData(5, Qt::Horizontal, QObject::tr("Vintage"));
