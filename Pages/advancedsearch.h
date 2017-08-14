#ifndef ADVANCEDSEARCH_H
#define ADVANCEDSEARCH_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include "database/dbmanager.h"

class AdvancedSearch : public QWidget
{
    Q_OBJECT
public:
    AdvancedSearch(DbManager* dbmanager, QWidget* parent=0);
    ~AdvancedSearch();

    void populateSearch();
signals:
    void sigSearch(QString);

private slots:
    void searchBtnPress();
private:
    DbManager* db;

    QComboBox* cellarBox;
    QComboBox* colourBox;
    QComboBox* varietyBox;
    QComboBox* nameBox;
    QComboBox* vintageBox;
    QComboBox* vineyardBox;

    void initialiseParams(QGridLayout* mainLayout);
    void populateCellar();
    void populateColour();
    void populateVariety();
    void populateName();
    void populateVintage();
    void populateVineyard();


};

#endif // ADVANCEDSEARCH_H
