#include "drink.h"
#include <QPushButton>
#include <QLabel>
#include <QTableView>
#include <QHeaderView>
#include <QMap>
#include <QDebug>

Drink::Drink(QWidget *parent) : QWidget(parent), currentRow(0)
{
    QPushButton *find = new QPushButton(tr("find"));
    QPushButton *drink = new QPushButton(tr("Drink"));
    QTableView *view = new QTableView;
    wineTable = new WineTable;
    view->setModel(wineTable);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    view->show();

    QGridLayout* layout = setupSearch();
    layout->addWidget(find, 4, 0, 1, 4);
    layout->addWidget(view, 5, 0, 1, 4);
    layout->addWidget(drink, 6, 2, 1, 2);
    this->setLayout(layout);

    connect(find, SIGNAL(clicked(bool)), this, SLOT(findWine()));
    connect(drink, SIGNAL(clicked(bool)), this, SLOT(drinkWine()));
    connect(view->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(onRowChanged(QModelIndex)));
}

QGridLayout* Drink::setupSearch()
{
    QGridLayout *layout = new QGridLayout;
    QLabel*colourlbl = new QLabel(tr("Colour"));
    QLabel *cellarlbl = new QLabel(tr("Cellar"));
    QLabel *namelbl = new QLabel(tr("Name"));
    QLabel *vintagelbl = new QLabel(tr("Vintage"));
    QLabel *varietylbl = new QLabel(tr("Variety"));
    QLabel *vineyardlbl = new QLabel(tr("Vineyard"));
    QLabel *quantitylbl = new QLabel(tr("Quantity"));

    colourEdit = new QLineEdit;
    nameEdit = new QLineEdit;
    vintageEdit = new QLineEdit;
    varietyEdit = new QLineEdit;
    vineyardEdit = new QLineEdit;
    cellarEdit = new QLineEdit;
    quantityEdit = new QLineEdit;

    layout->addWidget(cellarlbl, 0, 0);
    layout->addWidget(cellarEdit, 0, 1);

    layout->addWidget(namelbl, 0, 2);
    layout->addWidget(nameEdit, 0, 3);

    layout->addWidget(varietylbl, 1, 0);
    layout->addWidget(varietyEdit, 1, 1);

    layout->addWidget(vineyardlbl, 1, 2);
    layout->addWidget(vineyardEdit, 1, 3);

    layout->addWidget(colourlbl, 2, 0);
    layout->addWidget(colourEdit, 2, 1);

    layout->addWidget(vintagelbl, 2, 2);
    layout->addWidget(vintageEdit, 2, 3);

    layout->addWidget(quantitylbl, 6, 0);
    layout->addWidget(quantityEdit, 6, 1);

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

void Drink::drinkWine()
{

}

void Drink::onRowChanged(QModelIndex index)
{
    int row = index.row();
    qDebug() << index.row();
    QString colour = index.sibling(row, 0).data().toString();
    qDebug() << colour;
}

