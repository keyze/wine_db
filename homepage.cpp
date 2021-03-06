#include "homepage.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>

Homepage::Homepage(QStackedWidget *pages, QWidget *parent) :
    QWidget(parent)
{
    changePage = pages;

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
    wineGroup->setAlignment(Qt::AlignHCenter);
    QFont buttonFont;
    buttonFont.setBold(true);
    buttonFont.setPixelSize(50);

    QPushButton *addButton = new QPushButton(tr("Add Wine"));
    addButton->setFont(buttonFont);
    QPushButton *removeButton = new QPushButton(tr("Taken to Drink!"));
    removeButton->setFont(buttonFont);
    QPushButton *searchButton = new QPushButton(tr("Search Wine"));
    searchButton->setFont(buttonFont);

    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(goToAddPage()));
    connect(searchButton, SIGNAL(clicked(bool)), this, SLOT(goToSearchPage()));
    connect(removeButton, SIGNAL(clicked(bool)), this, SLOT(goToDrinkPage()));

    addButton->setFixedHeight(200);
    addButton->setFixedWidth(1100);

    removeButton->setFixedHeight(200);
    removeButton->setFixedWidth(1100);

    searchButton->setFixedHeight(200);
    searchButton->setFixedWidth(1100);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addWidget(removeButton);

    wineGroup->setLayout(buttonLayout);

    QSize wineSize(1000, 1000);
    QPixmap wine(":/res/pictures/1e5f7a1f88eef2f6ff842c442bdcd2eb--wine-bottle-glasses-wine-bottles.jpg");
    wine.scaled(wineSize, Qt::KeepAspectRatio );
    QLabel *winePicture = new QLabel;
    winePicture->setPixmap(wine);
    QTextEdit *text = new QTextEdit();
    text->setText("Johnny's");
    text->append("Wine");

    QFont maFont;
    maFont.setBold(true);
    maFont.setPixelSize(100);
    QLabel *lbl = new QLabel("Johnny's Wine Collection!");
    lbl->setFont(maFont);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lbl, 0, 0, 1, 2);
    layout->addWidget(winePicture, 1, 0);
    layout->addWidget(wineGroup, 1, 1);

    layout->setAlignment(lbl, Qt::AlignHCenter);
    layout->setAlignment(winePicture, Qt::AlignCenter);
    layout->setAlignment(wineGroup, Qt::AlignHCenter);

    setLayout(layout);

}

void Homepage::goToAddPage()
{
    changePage->setCurrentIndex(2);
    emit goToPage("Add");
}

void Homepage::goToSearchPage()
{
    changePage->setCurrentIndex(3);
    emit goToPage("Search");
}

void Homepage::goToDrinkPage()
{
   changePage->setCurrentIndex(4);
   emit goToPage("Drink");
}
