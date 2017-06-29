#include "addpage.h"

#include <QButtonGroup>
#include <QStackedWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QPushButton>
#include <QDoubleValidator>

AddPage::AddPage(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *addWine = new QPushButton(tr("Add Wine!"));
    QFont wineFont;
    wineFont.setPixelSize(30);
    wineFont.setBold(true);

    addWine->setFont(wineFont);

    QGroupBox *varietyBox = new QGroupBox(tr("Variety:"));
    QComboBox *whiteBox = addWhites();
    QComboBox *redBox = addReds();
    QComboBox *roseBox = addRoses();

    variety = new QStackedWidget;
    variety->addWidget(whiteBox);
    variety->addWidget(redBox);
    variety->addWidget(roseBox);

    QVBoxLayout *varietyLayout = new QVBoxLayout;
    varietyLayout->addWidget(variety);
    varietyLayout->addStretch();
    varietyLayout->addStretch();
    varietyLayout->addStretch();
    varietyLayout->addStretch();
    varietyBox->setLayout(varietyLayout);

    QGroupBox *colours = setUpColours();

    QGroupBox *descriptionBox = new QGroupBox(tr("Description:"));
    QTextEdit *description = new QTextEdit;
    description->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    description->setLineWidth(2);

    QHBoxLayout *descriptionLayout = new QHBoxLayout;
    descriptionLayout->addWidget(description);
    descriptionBox->setLayout(descriptionLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(varietyBox, 0, 1);
    layout->addWidget(colours, 0, 0);
    layout->addWidget(addWineParameters(), 1, 0);
    layout->addWidget(descriptionBox, 1, 1);
    layout->addWidget(addWine, 2, 0, 1, 2);

    setLayout(layout);

    connect(this, SIGNAL(setWineList(int)), this, SLOT(changeWineList(int)));
}

QComboBox *AddPage::addWhites()
{
    whiteBox = new QComboBox;
    whiteBox->setMaximumHeight(30);
    QFont whiteFont;
    whiteFont.setPixelSize(20);

    whiteBox->setFont(whiteFont);
    whiteBox->insertItem(0, "Chardonay");
    whiteBox->addItem("Riesling");
    return whiteBox;

}

QComboBox *AddPage::addReds()
{
    redBox = new QComboBox;
    redBox->setMaximumHeight(30);

    QFont redFont;
    redFont.setPixelSize(20);

    redBox->setFont(redFont);
    redBox->insertItem(0, "Shiraz");
    redBox->addItem("Merlot");
    return redBox;
}

QComboBox *AddPage::addRoses()
{
    roseBox = new QComboBox;
    roseBox->setMaximumHeight(30);

    QFont roseFont;
    roseFont.setPixelSize(20);

    roseBox->setFont(roseFont);
    roseBox->insertItem(0, "Grenache");
    roseBox->addItem("Tempranillo");
    return roseBox;
}

QGroupBox *AddPage::addWineParameters()
{
    QGroupBox *params = new QGroupBox(tr("Details:"));
    QGridLayout *paramsLayout = new QGridLayout;

    yearEdit = new QLineEdit;
    regionEdit = new QLineEdit;
    vineyardEdit = new QLineEdit;
    priceEdit = new QLineEdit;
    priceEdit->setValidator(new QDoubleValidator(0.00, 20000.00, 2, priceEdit));

    locationEdit = new QLineEdit;
    quantityEdit = new QLineEdit;

    QLabel *yearLabel = new QLabel(tr("Year:"));
    QLabel *regionLabel = new QLabel(tr("Region:"));
    QLabel *vineyardLabel = new QLabel(tr("Vineyard:"));
    QLabel *priceLabel = new QLabel(tr("Price:"));
    QLabel *locationLabel = new QLabel(tr("Location:"));
    QLabel *quantityLabel = new QLabel(tr("Quantity:"));

    paramsLayout->addWidget(yearLabel, 0, 0);
    paramsLayout->addWidget(yearEdit, 0, 1);
    paramsLayout->addWidget(regionLabel, 1, 0);
    paramsLayout->addWidget(regionEdit, 1, 1);
    paramsLayout->addWidget(vineyardLabel, 2, 0);
    paramsLayout->addWidget(vineyardEdit, 2, 1);
    paramsLayout->addWidget(priceLabel, 3, 0);
    paramsLayout->addWidget(priceEdit, 3, 1);
    paramsLayout->addWidget(locationLabel, 4, 0);
    paramsLayout->addWidget(locationEdit, 4, 1);
    paramsLayout->addWidget(quantityLabel, 5, 0);
    paramsLayout->addWidget(quantityEdit, 5, 1);
    params->setLayout(paramsLayout);
    return params;

}

QGroupBox *AddPage::setUpColours()
{
    QGroupBox *colours = new QGroupBox(tr("Colour:"));
    QFont radioFont;
    radioFont.setBold(true);
    radioFont.setPixelSize(20);

    QRadioButton *white = new QRadioButton(tr("White"));
    white->setFont(radioFont);
    connect(white, SIGNAL(clicked(bool)), this, SLOT(setWineListWhite()));
    QRadioButton *red = new QRadioButton(tr("Red"));
    red->setFont(radioFont);
    connect(red, SIGNAL(clicked(bool)), this, SLOT(setWineListRed()));
    QRadioButton *rose = new QRadioButton(tr("Rose"));
    rose->setFont(radioFont);
    connect(rose, SIGNAL(clicked(bool)), this, SLOT(setWineListRose()));

    white->setChecked(true);

    QVBoxLayout *radioLayout = new QVBoxLayout;
    radioLayout->addWidget(white, 1, Qt::AlignHCenter);
    radioLayout->addWidget(red, 1, Qt::AlignHCenter);
    radioLayout->addWidget(rose, 1, Qt::AlignHCenter);


    colours->setLayout(radioLayout);
    colours->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    return colours;

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
