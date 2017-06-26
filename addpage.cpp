#include "addpage.h"

#include <QButtonGroup>
#include <QStackedWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QLabel>

AddPage::AddPage(QWidget *parent) :
    QWidget(parent)
{
    QComboBox *whiteBox = addWhites();
    QComboBox *redBox = addReds();
    QComboBox *roseBox = addRoses();

    variety = new QStackedWidget;
    variety->addWidget(whiteBox);
    variety->addWidget(redBox);
    variety->addWidget(roseBox);

    QGroupBox *colours = new QGroupBox(tr("Wine Colours"));

    QRadioButton *white = new QRadioButton(tr("White"));
    connect(white, SIGNAL(clicked(bool)), this, SLOT(setWineListWhite()));
    QRadioButton *red = new QRadioButton(tr("Red"));
    connect(red, SIGNAL(clicked(bool)), this, SLOT(setWineListRed()));
    QRadioButton *rose = new QRadioButton(tr("Rose"));
    connect(rose, SIGNAL(clicked(bool)), this, SLOT(setWineListRose()));

    white->setChecked(true);

    QVBoxLayout *radioLayout = new QVBoxLayout;
    radioLayout->addWidget(white, 1, Qt::AlignCenter);
    radioLayout->addWidget(red, 1, Qt::AlignCenter);
    radioLayout->addWidget(rose, 1, Qt::AlignCenter);


    colours->setLayout(radioLayout);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(variety, 0, 1);
    layout->addWidget(colours, 0, 0);
    layout->addWidget(addWineParameters(), 1, 0);
    setLayout(layout);

    connect(this, SIGNAL(setWineList(int)), this, SLOT(changeWineList(int)));

}

QComboBox *AddPage::addWhites()
{
    QComboBox *whiteBox = new QComboBox;
    whiteBox->insertItem(0, "Chardonay");
    return whiteBox;

}

QComboBox *AddPage::addReds()
{
    QComboBox *redBox = new QComboBox;
    redBox->insertItem(0, "Shiraz");
    return redBox;
}

QComboBox *AddPage::addRoses()
{
    QComboBox *roseBox = new QComboBox;
    roseBox->insertItem(0, "Rose");
    return roseBox;
}

QGroupBox *AddPage::addWineParameters()
{
    QGroupBox *params = new QGroupBox;
    QGridLayout *paramsLayout = new QGridLayout;

    QLineEdit *yearEdit = new QLineEdit;
    QLineEdit *regionEdit = new QLineEdit;
    QLineEdit *vineyardEdit = new QLineEdit;
    QLineEdit *priceEdit = new QLineEdit;

    QLabel *yearLabel = new QLabel(tr("Year:"));
    QLabel *regionLabel = new QLabel(tr("Region"));
    QLabel *vineyardLabel = new QLabel(tr("Vineyard"));
    QLabel *priceLabel = new QLabel(tr("Price"));

    paramsLayout->addWidget(yearLabel, 0, 0);
    paramsLayout->addWidget(yearEdit, 0, 1);
    paramsLayout->addWidget(regionLabel, 1, 0);
    paramsLayout->addWidget(regionEdit, 1, 1);
    paramsLayout->addWidget(vineyardLabel, 2, 0);
    paramsLayout->addWidget(vineyardEdit, 2, 1);
    paramsLayout->addWidget(priceLabel, 3, 0);
    paramsLayout->addWidget(priceEdit, 3, 1);

    params->setLayout(paramsLayout);
    return params;

}

void AddPage::setWineListRed()
{
    emit AddPage::setWineList(1);
}

void AddPage::setWineListWhite()
{
    emit AddPage::setWineList(0);
}

void AddPage::setWineListRose()
{
    emit AddPage::setWineList(2);
}

void AddPage::changeWineList(int wineList)
{
    variety->setCurrentIndex(wineList);
}

AddPage::~AddPage()
{
    this->close();
}
