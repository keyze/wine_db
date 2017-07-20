#include "dbmanager.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

static const QString path =  "/home/msm/wine_db/wine.db";
        //"/Volumes/SUMS/wine_db/wine.db";
        // "/home/msm/wine_db/wine.db";

DbManager::DbManager()
{
    wine_db = QSqlDatabase::addDatabase("QSQLITE");
    wine_db.setDatabaseName(path);

    if (!wine_db.open()) {
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }
}

bool DbManager::isOpen() const
{
    return wine_db.isOpen();
}

bool DbManager::addWine(Wine *wine)
{
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO wines (colour, variety, name, region, vineyard,"
                        "vintage, description, price, location, quantity)"
                        "VALUES (:colour, :variety, :name, :region, :vineyard,"
                        ":vintage, :description, :price, :location, :quantity)");
    insertQuery.bindValue(":colour", wine->getColour());
    insertQuery.bindValue(":variety", wine->getVariety());
    insertQuery.bindValue(":name", wine->getName());
    insertQuery.bindValue(":region", wine->getRegion());
    insertQuery.bindValue(":vineyard", wine->getVineyard());
    insertQuery.bindValue(":vintage", wine->getVintage());
    insertQuery.bindValue(":description", wine->getDescription());
    insertQuery.bindValue(":price", wine->getPrice());
    insertQuery.bindValue(":location", wine->getLocation());
    insertQuery.bindValue(":quantity", wine->getQuantity());

    return insertQuery.exec();


    return true;
}

bool DbManager::removeWine()
{
    return true;
}

bool DbManager::wineExists()
{
    return true;
}

bool DbManager::printAllWines()
{
    return true;
}

QStringList DbManager::searchQuery(const QString &query)
{
   QSqlQuery sqlQuery(query);
   QStringList options;

   while (sqlQuery.next()) {
       QString result = sqlQuery.value(0).toString();
       options << result;
   }
   return options;
}

DbManager::~DbManager()
{
    if (wine_db.isOpen()) {
        wine_db.close();
    }
}
