#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <wine.h>


class DbManager
{
public:
    DbManager();

    ~DbManager();

    bool isOpen() const;

    bool addWine(Wine* wine);

    bool removeWine();

    bool wineExists();

    bool printAllWines();

    QStringList searchQuery(const QString& query);

private:
    QSqlDatabase wine_db;
};

#endif // DBMANAGER_H
