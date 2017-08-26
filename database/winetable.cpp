#include "winetable.h"
#include <QMapIterator>
#include <QDebug>

WineTable::WineTable(QSqlQueryModel *parent) :
    QSqlQueryModel(parent)
{
    initTable();
}

void WineTable::initTable()
{
    this->setHeaderData(0, Qt::Horizontal, QObject::tr("Vineyard"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Vintage"));
    this->setHeaderData(3, Qt::Horizontal, QObject::tr("Variety"));
    this->setHeaderData(4, Qt::Horizontal, QObject::tr("Colour"));
    this->setHeaderData(5, Qt::Horizontal, QObject::tr("Region"));
    this->setHeaderData(6, Qt::Horizontal, QObject::tr("Quantity"));

}

void WineTable::searchColour(QString colour)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where colour ='" + colour + "'";
    this->setQuery(query);
    initTable();

}

void WineTable::searchCellar(QString cellar)
{

    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where location='" + cellar + "'";
    this->setQuery(query);
    initTable();
}

void WineTable::searchVintage(QString vintage)
{

    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where vintage='" + vintage + "'";
    this->setQuery(query);
    initTable();
}

void WineTable::searchVineyard(QString vineyard)
{

    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where vineyard='" + vineyard + "'";
    this->setQuery(query);
    initTable();
}

void WineTable::searchName(QString name)
{

    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where name='" + name + "'";
    this->setQuery(query);
    initTable();
}

void WineTable::searchVariety(QString variety)
{

    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where variety='" + variety + "'";
    this->setQuery(query);
    initTable();
}

void WineTable::searchQuery(QMap<QString, QString> wineAttributes)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where quantity>0 ";
    QMapIterator<QString, QString> i(wineAttributes);
    while (i.hasNext()) {
        i.next();
        if (i.value() != "") {
            query = query + "AND " + i.key() + "='" + i.value() + "' ";
        }


    }

    qDebug() << query;
    this->setQuery(query);
    initTable();
}

void WineTable::search(QString query)
{
    this->setQuery(query);
    initTable();
}

void WineTable::clearTable()
{
    this->clear();
}
