#ifndef QUICKSEARCH_H
#define QUICKSEARCH_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include "database/dbmanager.h"

class QuickSearch : public QWidget
{
    Q_OBJECT
public:
    QuickSearch(DbManager *dbmanager, QWidget* parent=0);
    ~QuickSearch();

signals:
    void sigSearchColour();
    void sigSearchCellar();
    void sigSearchVariety();
    void sigSearchName();

private slots:
    void colourBtnPress();
    void cellarBtnPress();
    void varietyBtnPress();
    void nameBtnPress();

private:
    DbManager *db;
    QComboBox* searchCellar;
    QComboBox* searchColour;
    QComboBox* searchVariety;
    QComboBox* searchName;

    void initialiseParams(QGridLayout *mainLayout);
    void populateCellar();
    void populateColour();
    void populateVariety();
    void populateName();

};

#endif // QUICKSEARCH_H
