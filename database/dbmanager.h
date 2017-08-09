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

    bool decrementQuantity(QMap<QString, QString> wineParams, int amount);

    bool incrementQuantity(QMap<QString, QString> wineParams, int amount);

    bool removeWine();

    bool wineExists(Wine* wine);

    bool printAllWines();

    QStringList searchQuery(const QString& query);

    int getQuantity(QMap<QString, QString> wineParams);
private:
    QSqlDatabase wine_db;


    bool updateQuantity(QMap<QString, QString> wineParams, QString newQuantity);
};

#endif // DBMANAGER_H
