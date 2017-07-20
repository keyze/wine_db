#include "winetable.h"
#include <QMapIterator>

WineTable::WineTable(QSqlQueryModel *parent) :
    QSqlQueryModel(parent)
{
    initTable();
}

void WineTable::initTable()
{
    this->setHeaderData(0, Qt::Horizontal, QObject::tr("Colour"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("Variety"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
    this->setHeaderData(3, Qt::Horizontal, QObject::tr("Region"));
    this->setHeaderData(4, Qt::Horizontal, QObject::tr("Vineyard"));
    this->setHeaderData(5, Qt::Horizontal, QObject::tr("Vintage"));


}

void WineTable::searchColour(QString colour)
{
    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where colour ='" + colour + "'";
    this->setQuery(query);
}

void WineTable::searchCellar(QString cellar)
{

    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where cellar='" + cellar + "'";
    this->setQuery(query);
}

void WineTable::searchVintage(QString vintage)
{

    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where vintage='" + vintage + "'";
    this->setQuery(query);
}

void WineTable::searchVineyard(QString vineyard)
{

    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where vineyard='" + vineyard + "'";
    this->setQuery(query);
}

void WineTable::searchName(QString name)
{

    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where name='" + name + "'";
    this->setQuery(query);
}

void WineTable::searchVariety(QString variety)
{

    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where variety='" + variety + "'";
    this->setQuery(query);
}

void WineTable::searchQuery(QMap<QString, QString> wineAttributes)
{
    QString query = "SELECT colour, variety, name, region, vineyard, vintage FROM wines where quantity>0 ";
    QMapIterator<QString, QString> i(wineAttributes);
    while (i.hasNext()) {
        if (i.value() != "") {
            query = query + "AND " + i.key() + "='" + i.value() + "' ";
        }


    }
    this->setQuery(query);
}


