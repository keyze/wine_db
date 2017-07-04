#include "quicksearch.h"
#include <QLabel>
#include <QPushButton>

QuickSearch::QuickSearch(DbManager *dbmanager, QWidget *parent) :
    QWidget(parent)
{
    db = dbmanager;
    QGridLayout layout;
    initialiseParams(&layout);
    populateCellar();
    populateColour();
    populateName();
    populateVariety();
}



void QuickSearch::initialiseParams(QGridLayout *mainLayout)
{
    searchCellar = new QComboBox;
    searchColour = new QComboBox;
    searchVariety = new QComboBox;
    searchName = new QComboBox;

    QPushButton *cellarbtn = new QPushButton(tr("Search Cellar"));
    QPushButton *colourbtn = new QPushButton(tr("Search Colour"));
    QPushButton *varietybtn = new QPushButton(tr("Search Variety"));
    QPushButton *namebtn = new QPushButton(tr("Search Name"));

    connect(cellarbtn, SIGNAL(clicked(bool)), this, SLOT(cellarBtnPress()));
    connect(colourbtn, SIGNAL(clicked(bool)), this, SLOT(colourBtnPress()));
    connect(varietybtn, SIGNAL(clicked(bool)), this, SLOT(varietyBtnPress()));
    connect(namebtn, SIGNAL(clicked(bool)), this, SLOT(nameBtnPress()));

    mainLayout->addWidget(cellarbtn, 0, 0);
    mainLayout->addWidget(searchCellar, 0, 1);
    mainLayout->addWidget(colourbtn, 1, 0);
    mainLayout->addWidget(searchCellar, 1, 1);
    mainLayout->addWidget(varietybtn, 2, 0);
    mainLayout->addWidget(searchVariety, 2, 1);
    mainLayout->addWidget(namebtn, 3, 0);
    mainLayout->addWidget(searchName, 3, 1);

    setLayout(mainLayout);

}

void QuickSearch::populateCellar()
{
    QString search = "SELECT location FROM wines";
    QStringList cellarWines = db->searchQuery(search);
    cellarWines.removeDuplicates();

    foreach(QString s, cellarWines) {
        searchCellar->addItem(s);
    }
}

void QuickSearch::populateColour()
{
    QString search = "SELECT colour FROM wines";
    QStringList colourWines = db->searchQuery(search);
    colourWines.removeDuplicates();

    foreach(QString s, colourWines) {
        searchColour->addItem(s);
    }
}

void QuickSearch::populateVariety()
{
    QString search = "SELECT variety FROM wines";
    QStringList varietyWines = db->searchQuery(search);
    varietyWines.removeDuplicates();

    foreach(QString s, varietyWines) {
        searchVariety->addItem(s);
    }
}

void QuickSearch::populateName()
{
    QString search = "SELECT name FROM wines";
    QStringList nameWines = db->searchQuery(search);
    nameWines.removeDuplicates();

    foreach(QString s, nameWines) {
        searchName->addItem(s);
    }
}

QuickSearch::~QuickSearch()
{
    this->close();
}

void QuickSearch::colourBtnPress()
{
    emit sigSearchColour();
}

void QuickSearch::cellarBtnPress()
{
    emit sigSearchCellar();
}

void QuickSearch::varietyBtnPress()
{
    emit sigSearchVariety();
}

void QuickSearch::nameBtnPress()
{
    emit sigSearchName();
}
