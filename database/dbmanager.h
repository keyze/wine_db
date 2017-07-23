#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <wine.h>
#include <QMap>

class DbManager
{
public:
    DbManager();

    ~DbManager();

    bool isOpen() const;

    bool addWine(Wine* wine);

    void decrementQuantity(QMap<QString, QString> wineParams, int amount);

    bool removeWine();

    bool wineExists();

    bool printAllWines();

    QStringList searchQuery(const QString& query);

    int getQuantity(QMap<QString, QString> wineParams);
private:
    QSqlDatabase wine_db;


};

#endif // DBMANAGER_H
