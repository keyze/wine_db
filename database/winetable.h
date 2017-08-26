#ifndef WINETABLE_H
#define WINETABLE_H

#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
#include <QMap>

class WineTable : public QSqlQueryModel
{
    Q_OBJECT
public:

    explicit WineTable(QSqlQueryModel* parent=nullptr);
    void searchColour(QString colour);
    void searchCellar(QString cellar);
    void searchVintage(QString vintage);
    void searchVineyard(QString vineyard);
    void searchName(QString name);
    void searchVariety(QString variety);
    void searchQuery(QMap<QString, QString> wineAttributes);
    void search(QString query);


    void clearTable();
private:
    void initTable();

};

#endif // WINETABLE_H
