#include "quicksearch.h"
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

QuickSearch::QuickSearch(DbManager *dbmanager, QWidget *parent) :
    QWidget(parent)
{
    db = dbmanager;
    QGridLayout *layout = new QGridLayout;
    initialiseParams(layout);
    populateCellar();
    populateColour();
    populateName();
    populateVariety();
}





void QuickSearch::initialiseParams(QGridLayout *mainLayout)
{
    QFont boxFont;
    boxFont.setPixelSize(20);
    QVBoxLayout *topLayout = new QVBoxLayout;

    QGroupBox *theBox = new QGroupBox;

    searchCellar = new QComboBox;
    searchColour = new QComboBox;
    searchVariety = new QComboBox;
    searchName = new QComboBox;

    searchCellar->setFont(boxFont);
    searchColour->setFont(boxFont);
    searchVariety->setFont(boxFont);
    searchName->setFont(boxFont);

    QFont paramFont;
    paramFont.setPixelSize(20);
    paramFont.setBold(true);
    paramFont.setItalic(true);

    QPushButton *cellarbtn = new QPushButton(tr("Search Cellar"));
    QPushButton *colourbtn = new QPushButton(tr("Search Colour"));
    QPushButton *varietybtn = new QPushButton(tr("Search Variety"));
    QPushButton *namebtn = new QPushButton(tr("Search Name"));

    cellarbtn->setFont(paramFont);
    colourbtn->setFont(paramFont);
    varietybtn->setFont(paramFont);
    namebtn->setFont(paramFont);

    connect(cellarbtn, SIGNAL(clicked(bool)), this, SLOT(cellarBtnPress()));
    connect(colourbtn, SIGNAL(clicked(bool)), this, SLOT(colourBtnPress()));
    connect(varietybtn, SIGNAL(clicked(bool)), this, SLOT(varietyBtnPress()));
    connect(namebtn, SIGNAL(clicked(bool)), this, SLOT(nameBtnPress()));

    mainLayout->addWidget(cellarbtn, 0, 1);
    mainLayout->addWidget(searchCellar, 0, 0);
    mainLayout->addWidget(colourbtn, 1, 1);
    mainLayout->addWidget(searchColour, 1, 0);
    mainLayout->addWidget(varietybtn, 2, 1);
    mainLayout->addWidget(searchVariety, 2, 0);
    mainLayout->addWidget(namebtn, 3, 1);
    mainLayout->addWidget(searchName, 3, 0);
    theBox->setLayout(mainLayout);
    topLayout->addWidget(theBox);
    setLayout(topLayout);

}

void QuickSearch::populateCellar()
{
    QString search = "SELECT location FROM wines";
    QStringList cellarWines = db->searchQuery(search);
    cellarWines.removeDuplicates();

    foreach(QString s, cellarWines) {
        searchCellar->addItem(s);
    }
    searchCellar->insertItem(0, "Home Cellar");
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

void QuickSearch::populateSearch()
{
    searchName->clear();
    searchVariety->clear();
    searchColour->clear();
    searchCellar->clear();

    populateCellar();
    populateColour();
    populateName();
    populateVariety();
}

QuickSearch::~QuickSearch()
{
    this->close();
}

void QuickSearch::colourBtnPress()
{
    QString colour = searchColour->currentText();
    emit sigSearchColour(colour);
}

void QuickSearch::cellarBtnPress()
{
    QString cellar = searchCellar->currentText();
    emit sigSearchCellar(cellar);
}

void QuickSearch::varietyBtnPress()
{
    QString variety = searchVariety->currentText();
    emit sigSearchVariety(variety);
}

void QuickSearch::nameBtnPress()
{
    QString name = searchName->currentText();
    emit sigSearchName(name);
}

void QuickSearch::clearPage()
{
    searchCellar->setCurrentIndex(0);
    searchColour->setCurrentIndex(0);
    searchName->setCurrentIndex(0);
    searchVariety->setCurrentIndex(0);
}
