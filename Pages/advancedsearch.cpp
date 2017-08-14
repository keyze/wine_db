#include "advancedsearch.h"
#include <QPushButton>
#include <QLabel>

AdvancedSearch::AdvancedSearch(DbManager *dbmanager, QWidget *parent) :
    QWidget(parent)
{
    db = dbmanager;
    QGridLayout* layout = new QGridLayout;
    initialiseParams(layout);
    populateSearch();
}

AdvancedSearch::~AdvancedSearch()
{
    this->close();
}


void AdvancedSearch::initialiseParams(QGridLayout *mainLayout)
{
    cellarBox = new QComboBox;
    colourBox = new QComboBox;
    nameBox = new QComboBox;
    vintageBox = new QComboBox;
    varietyBox = new QComboBox;
    vineyardBox = new QComboBox;

    QPushButton* searchBtn = new QPushButton(tr("Search"));
    connect(searchBtn, SIGNAL(clicked(bool)), this, SLOT(searchBtnPress()));

    QLabel *cellarlbl = new QLabel(tr("Cellar"));
    QLabel *colourlbl = new QLabel(tr("Colour"));
    QLabel *namelbl = new QLabel(tr("Name"));
    QLabel *vintagelbl = new QLabel(tr("Vintage"));
    QLabel *varietylbl = new QLabel(tr("Variety"));
    QLabel *vineyardlbl = new QLabel(tr("Vineyard"));

    mainLayout->addWidget(cellarlbl, 0, 0);
    mainLayout->addWidget(cellarBox, 0, 1);

    mainLayout->addWidget(colourlbl, 0, 2);
    mainLayout->addWidget(colourBox, 0, 3);

    mainLayout->addWidget(varietylbl, 1, 0);
    mainLayout->addWidget(varietyBox, 1, 1);

    mainLayout->addWidget(vintagelbl, 1, 2);
    mainLayout->addWidget(vintageBox, 1, 3);

    mainLayout->addWidget(vineyardlbl, 2, 0);
    mainLayout->addWidget(vineyardBox, 2, 1);

    mainLayout->addWidget(namelbl, 2, 2);
    mainLayout->addWidget(nameBox, 2, 3);

    mainLayout->addWidget(searchBtn, 3, 0, 1, 4);

    setLayout(mainLayout);
}

void AdvancedSearch::searchBtnPress()
{
    QString query = "";
    emit sigSearch(query);
}

void AdvancedSearch::populateSearch()
{
    cellarBox->clear();
    colourBox->clear();
    nameBox->clear();
    vineyardBox->clear();
    varietyBox->clear();
    vintageBox->clear();

    populateCellar();
    populateColour();
    populateName();
    populateVineyard();
    populateVariety();
    populateVintage();
}

void AdvancedSearch::populateCellar()
{
    QString search = "SELECT location FROM wines";
    QStringList cellarWines = db->searchQuery(search);
    cellarWines.removeDuplicates();

    foreach(QString s, cellarWines) {
        cellarBox->addItem(s);
    }

}

void AdvancedSearch::populateColour()
{
    QString search = "SELECT colour FROM wines";
    QStringList colourWines = db->searchQuery(search);
    colourWines.removeDuplicates();

    foreach(QString s, colourWines) {
        colourBox->addItem(s);
    }
}

void AdvancedSearch::populateName()
{
    QString search = "SELECT name FROM wines";
    QStringList nameWines = db->searchQuery(search);
    nameWines.removeDuplicates();

    foreach(QString s, nameWines) {
        nameBox->addItem(s);
    }
}

void AdvancedSearch::populateVineyard()
{
    QString search = "Select vineyard From wines";
    QStringList vineyardWines = db->searchQuery(search);
    vineyardWines.removeDuplicates();
    foreach(QString s, vineyardWines) {
        vineyardBox->addItem(s);
    }
}

void AdvancedSearch::populateVariety()
{
    QString search = "SELECT variety FROM wines";
    QStringList varietyWines = db->searchQuery(search);
    varietyWines.removeDuplicates();

    foreach(QString s, varietyWines) {
        varietyBox->addItem(s);
    }
}

void AdvancedSearch::populateVintage()
{
    QString search = "Select vintage from wines";
    QStringList vintageWines = db->searchQuery(search);
    vintageWines.removeDuplicates();
    foreach(QString s, vintageWines) {
        vintageBox->addItem(s);
    }
}
