#include "dbmanager.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

static const QString path =  "/home/msm/wine_db/wine.db";

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

bool DbManager::addWine()
{
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

DbManager::~DbManager()
{
    if (wine_db.isOpen()) {
        wine_db.close();
    }
}
