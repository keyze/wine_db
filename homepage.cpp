#include "homepage.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QListWidget>

Homepage::Homepage(QWidget *parent) :
    QWidget(parent)
{
    QGroupBox *wineGroup = new QGroupBox();
    QString styleSheet;
    styleSheet = "\
                 QGroupBox {\
                     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
                     stop: 0 #E0E0E0, stop: 1 #FFFFFF);\
                     border: 2px solid gray;\
                     border-radius: 5px;\
                     padding: 0px;\
                 }";


    this->setStyleSheet(styleSheet);

    QPushButton *addButton = new QPushButton(tr("Add Wine"));
    QPushButton *removeButton = new QPushButton(tr("Remove Wine"));
    QPushButton *searchButton = new QPushButton(tr("Search Wine"));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(searchButton);
    wineGroup->setLayout(buttonLayout);

    QListWidget *listing = new QListWidget();
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(wineGroup, 0, 0, 1, 2);
    mainLayout->addWidget(listing, 1, 0, 1, 2);

    setLayout(mainLayout);

}
