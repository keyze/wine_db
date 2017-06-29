#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>



class DbManager
{
public:
    DbManager();

    ~DbManager();

    bool isOpen() const;

    bool addWine();

    bool removeWine();

    bool wineExists();

    bool printAllWines();

private:
    QSqlDatabase wine_db;
};

#endif // DBMANAGER_H
