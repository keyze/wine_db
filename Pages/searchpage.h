#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include "database/dbmanager.h"
#include "quicksearch.h"
#include "advancedsearch.h"
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>

class SearchPage : public QWidget
{
    Q_OBJECT
public:
    SearchPage(DbManager *dbManager, QWidget *parent=0);
    void clearPage();
    ~SearchPage();

    void repopulateSearch();
private slots:
    void searchDatabase(QString query);

    void quickSearchColour(QString colour);
    void quickSearchCellar(QString cellar);
    void quickSearchVariety(QString variety);
    void quickSearchName(QString name);
    void advancedSearchQuery(QString query);


private:
    QSqlQueryModel *initialiseModel();


    QuickSearch* qsearch;
    AdvancedSearch* asearch;
    QTableView* view;
    QSqlQueryModel* model;

};

#endif // SEARCHPAGE_H
