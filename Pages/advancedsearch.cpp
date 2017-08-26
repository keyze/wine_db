#include "advancedsearch.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

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
    QFont boxFont;
    boxFont.setPixelSize(20);
    cellarBox = new QComboBox;
    colourBox = new QComboBox;
    nameBox = new QComboBox;
    vintageBox = new QComboBox;
    varietyBox = new QComboBox;
    vineyardBox = new QComboBox;

    cellarBox->setFont(boxFont);
    colourBox->setFont(boxFont);
    nameBox->setFont(boxFont);
    vintageBox->setFont(boxFont);
    varietyBox->setFont(boxFont);
    vineyardBox->setFont(boxFont);

    connect(cellarBox, SIGNAL(currentTextChanged(QString)), this, SLOT(repopulate()));
    connect(colourBox, SIGNAL(currentTextChanged(QString)), this, SLOT(repopulate()));

    QGroupBox* theBox = new QGroupBox;
    theBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    QFont lblFont;
    lblFont.setPixelSize(20);
    lblFont.setBold(true);

    QVBoxLayout* layout = new QVBoxLayout;
    QPushButton* searchBtn = new QPushButton(tr("Search"));
    searchBtn->setFont(lblFont);
    connect(searchBtn, SIGNAL(clicked(bool)), this, SLOT(searchBtnPress()));

    QLabel *cellarlbl = new QLabel(tr("Cellar:"));
    QLabel *colourlbl = new QLabel(tr("Colour:"));
    QLabel *namelbl = new QLabel(tr("Name:"));
    QLabel *vintagelbl = new QLabel(tr("Vintage:"));
    QLabel *varietylbl = new QLabel(tr("Variety:"));
    QLabel *vineyardlbl = new QLabel(tr("Vineyard:"));

    cellarlbl->setFont(lblFont);
    colourlbl->setFont(lblFont);
    namelbl->setFont(lblFont);
    vintagelbl->setFont(lblFont);
    varietylbl->setFont(lblFont);
    vineyardlbl->setFont(lblFont);

    mainLayout->addWidget(cellarlbl, 0, 0, 1, 1, Qt::AlignHCenter);
    mainLayout->addWidget(cellarBox, 0, 1, 1, 1, Qt::AlignHCenter);

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

    theBox->setLayout(mainLayout);
    layout->addWidget(theBox, 1, Qt::AlignHCenter);
    setLayout(layout);
}

void AdvancedSearch::searchBtnPress()
{
    if (!isEmpty()) {
        emit sigSearch(constructQuery());
    }
}

void AdvancedSearch::repopulate()
{
    QString where = "";
    if (cellarBox->currentText() != "") {
        where = "Where location='" + cellarBox->currentText() + "' ";
        if (colourBox->currentText() != "") {
            where = where + "AND colour='" + colourBox->currentText() + "'";
        }
    } else if (colourBox->currentText() != "") {
        where = "Where colour='" + colourBox->currentText() + "'";
    }

    populateName(where);
    populateVineyard(where);
    populateVariety(where);
    populateVintage(where);
}

void AdvancedSearch::populateSearch()
{
    QString where = "";
    populateCellar();
    populateColour();
    populateName(where);
    populateVineyard(where);
    populateVariety(where);
    populateVintage(where);
}

void AdvancedSearch::populateCellar()
{
    QString search = "SELECT location FROM wines";
    QStringList cellarWines = db->searchQuery(search);
    cellarWines.removeDuplicates();

    cellarBox->clear();
    cellarBox->insertItem(0, "");
    foreach(QString s, cellarWines) {
        cellarBox->addItem(s);
    }


}

void AdvancedSearch::populateColour()
{
    QString search = "SELECT colour FROM wines";
    QStringList colourWines = db->searchQuery(search);
    colourWines.removeDuplicates();

    colourBox->clear();
    colourBox->insertItem(0, "");
    foreach(QString s, colourWines) {
        colourBox->addItem(s);
    }

}

void AdvancedSearch::populateName(QString where)
{
    QString search = "SELECT name FROM wines " + where;
    QStringList nameWines = db->searchQuery(search);
    nameWines.removeDuplicates();

    nameBox->clear();
    nameBox->insertItem(0, "");
    foreach(QString s, nameWines) {
        nameBox->addItem(s);
    }

}

void AdvancedSearch::populateVineyard(QString where)
{
    QString search = "Select vineyard From wines " + where;
    QStringList vineyardWines = db->searchQuery(search);
    vineyardWines.removeDuplicates();

    vineyardBox->clear();
    vineyardBox->insertItem(0, "");
    foreach(QString s, vineyardWines) {
        vineyardBox->addItem(s);
    }

}

void AdvancedSearch::populateVariety(QString where)
{
    QString search = "SELECT variety FROM wines " + where;
    QStringList varietyWines = db->searchQuery(search);
    varietyWines.removeDuplicates();

    varietyBox->clear();
    varietyBox->insertItem(0, "");
    foreach(QString s, varietyWines) {
        varietyBox->addItem(s);
    }

}

void AdvancedSearch::populateVintage(QString where)
{
    QString search = "Select vintage from wines " + where;
    QStringList vintageWines = db->searchQuery(search);
    vintageWines.removeDuplicates();

    vintageBox->clear();
    vintageBox->insertItem(0, "");
    foreach(QString s, vintageWines) {
        vintageBox->addItem(s);
    }

}

QString AdvancedSearch::constructQuery()
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where quantity>=0 ";
    if (cellarBox->currentText() != "") {
        query = query + "AND location='" + cellarBox->currentText() +"' ";
    }
    if (colourBox->currentText() != "") {
        query = query + "AND colour='" + colourBox->currentText() + "' ";
    }
    if (nameBox->currentText() != "") {
        query = query + "AND name='" + nameBox->currentText() + "' ";
    }
    if (vineyardBox->currentText() != "") {
        query = query + "AND vineyard='" + vineyardBox->currentText() + "' ";
    }
    if (varietyBox->currentText() != "") {
        query = query + "AND variety='" + varietyBox->currentText() + "' ";
    }
    if (vintageBox->currentText() != "") {
        query = query + "And vintage='" + vintageBox->currentText() + "' ";
    }
    qDebug() << "Advanced Query" << query;
    return query;
}

bool AdvancedSearch::isEmpty()
{
    if (cellarBox->currentText() == "" && colourBox->currentText() == "" && nameBox->currentText() == "" &&
            vineyardBox->currentText() == "" && varietyBox->currentText() == "" && vintageBox->currentText() == "") {
        return true;
    }
    return false;
}
