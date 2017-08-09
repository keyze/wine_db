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
#include <QMessageBox>
#include <QDebug>

AddPage::AddPage(DbManager* db, QWidget *parent) :
    QWidget(parent), theDB(db)
{

    theBox = new WineBox;
    groupFont.setPixelSize(20);
    groupFont.setBold(true);
    groupFont.setItalic(true);

    QPushButton *addWine = new QPushButton(tr("Add Wine!"));
    addWine->setMaximumHeight(50);
    QFont wineFont;
    wineFont.setPixelSize(20);
    wineFont.setBold(true);

    addWine->setFont(wineFont);

    QGroupBox *varietyBox = new QGroupBox(tr("Variety:"));
    varietyBox->setFont(groupFont);

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
    colours->setFont(groupFont);

    QGroupBox *descriptionBox = new QGroupBox(tr("Description:"));
    descriptionBox->setFont(groupFont);

    QFont textFont;
    textFont.setPixelSize(20);
    textFont.setBold(false);
    textFont.setItalic(false);

    description = new QTextEdit;
    description->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    description->setLineWidth(2);
    description->setFont(textFont);

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
    connect(addWine, SIGNAL(clicked(bool)), this, SLOT(addWinetoDB()));
}

QComboBox *AddPage::addWhites()
{
    whiteBox = new QComboBox;
    whiteBox->setMaximumHeight(30);
    QFont whiteFont;
    whiteFont.setPixelSize(20);

    whiteBox->setFont(whiteFont);
    whiteBox->insertItem(0, "");
    whiteBox->addItem("Chardonay");
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
    redBox->insertItem(0, "");
    redBox->addItem("Shiraz");
    redBox->addItem("Merlot");
    redBox->addItem("Pinot Noir");
    return redBox;
}

QComboBox *AddPage::addRoses()
{
    roseBox = new QComboBox;
    roseBox->setMaximumHeight(30);

    QFont roseFont;
    roseFont.setPixelSize(20);

    roseBox->setFont(roseFont);
    roseBox->insertItem(0, "");
    roseBox->addItem("Grenache");
    roseBox->addItem("Tempranillo");
    return roseBox;
}

QGroupBox *AddPage::addWineParameters()
{
    QGroupBox *params = new QGroupBox(tr("Details:"));
    QVBoxLayout *paramsLayout = new QVBoxLayout;
    params->setFont(groupFont);

    QFont paramFont;
    paramFont.setPixelSize(20);
    paramFont.setBold(true);
    paramFont.setItalic(true);

    nameEdit = new QLineEdit;
    vintageEdit = new QLineEdit;
    regionEdit = new QLineEdit;
    vineyardEdit = new QLineEdit;
    priceEdit = new QLineEdit;
    priceEdit->setValidator(new QDoubleValidator(0.00, 20000.00, 2, priceEdit));

    quantityEdit = new QLineEdit;
    quantityEdit->setValidator(new QIntValidator(0, 200 , quantityEdit));

    locationEdit = new QComboBox;
    locationEdit->insertItem(0, "");
    locationEdit->addItem("Work Cellar");
    locationEdit->addItem("Home Cellar: Top Shelf");
    locationEdit->addItem("Home Cellar: Second Shelf");
    locationEdit->addItem("Home Cellar: Third Shelf");
    locationEdit->addItem("Home Cellar: Bottom Shelf");

    QLabel *nameLabel = new QLabel(tr("Name of Wine:"));
    nameLabel->setFont(paramFont);
    QLabel *vintageLabel = new QLabel(tr("Vintage:"));
    vintageLabel->setFont(paramFont);
    QLabel *regionLabel = new QLabel(tr("Denomination of Origin:"));
    regionLabel->setFont(paramFont);
    QLabel *vineyardLabel = new QLabel(tr("Vineyard:"));
    vineyardLabel->setFont(paramFont);
    QLabel *priceLabel = new QLabel(tr("Price:"));
    priceLabel->setFont(paramFont);
    QLabel *locationLabel = new QLabel(tr("Location:"));
    locationLabel->setFont(paramFont);
    QLabel *quantityLabel = new QLabel(tr("Quantity:"));
    quantityLabel->setFont(paramFont);

    paramsLayout->addWidget(nameLabel);
    paramsLayout->addWidget(nameEdit);

    paramsLayout->addWidget(regionLabel);
    paramsLayout->addWidget(regionEdit);

    paramsLayout->addWidget(vineyardLabel);
    paramsLayout->addWidget(vineyardEdit);

    paramsLayout->addWidget(vintageLabel);
    paramsLayout->addWidget(vintageEdit);

    paramsLayout->addWidget(priceLabel);
    paramsLayout->addWidget(priceEdit);

    paramsLayout->addWidget(locationLabel);
    paramsLayout->addWidget(locationEdit);

    paramsLayout->addWidget(quantityLabel);
    paramsLayout->addWidget(quantityEdit);

    params->setLayout(paramsLayout);
    return params;

}

QGroupBox *AddPage::setUpColours()
{
    QGroupBox *colours = new QGroupBox(tr("Colour:"));
    QFont radioFont;
    radioFont.setBold(true);
    radioFont.setPixelSize(20);

    white = new QRadioButton(tr("White"));
    white->setFont(radioFont);
    connect(white, SIGNAL(clicked(bool)), this, SLOT(setWineListWhite()));

    red = new QRadioButton(tr("Red"));
    red->setFont(radioFont);
    connect(red, SIGNAL(clicked(bool)), this, SLOT(setWineListRed()));

    rose = new QRadioButton(tr("Rose"));
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

bool AddPage::isMinimum(Wine* theWine)
{
    if (theWine->getColour() != "" && theWine->getName() != "" && theWine->getVariety() != "" &&
            QString::number(theWine->getVintage()) != "" && theWine->getQuantity() > 0) {
        return true;
    }
    return false;
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

Wine* AddPage::createWine()
{
    Wine* myWine = new Wine;
    if ( red->isChecked() ) {
        QString colour = "Red";
        myWine->setColour(colour);

        QString variety = redBox->currentText();
        myWine->setVariety(variety);
    } else if ( white->isChecked() ) {
        QString colour = "White";
        myWine->setColour(colour);

        QString variety = whiteBox->currentText();
        myWine->setVariety(variety);
    } else {
        QString colour = "Rose";
        myWine->setColour(colour);

        QString variety = roseBox->currentText();
        myWine->setVariety(variety);
    }

    QString region = regionEdit->text();
    myWine->setRegion(region);

    QString nameText = nameEdit->text();
    QString name = checkCase(nameText);
    myWine->setName(name);

    QString vineyard = vineyardEdit->text();
    myWine->setVineyard(vineyard);

    QString location = locationEdit->currentText();
    myWine->setLocation(location);

    int vintage = vintageEdit->text().toInt();
    myWine->setVintage(vintage);

    int quantity = quantityEdit->text().toInt();
    myWine->setQuantity(quantity);

    double price = priceEdit->text().toDouble();
    myWine->setPrice(price);

    QString theDescription = description->toPlainText();
    myWine->setDescription(theDescription);

    return myWine;
}

void AddPage::addWinetoDB()
{
    qDebug() << "Adding Wine";


    Wine* wine = createWine();
    if (isMinimum(wine)) {
        if (theDB->wineExists(wine)) {
            qDebug() << "Exists";
            theDB->incrementQuantity(wine->wineMap(), quantityEdit->text().toInt());
            theBox->setSuccessAdd();
        } else if ( theDB->addWine(wine) ) {
            qDebug() << "Success";
            theBox->setSuccessAdd();

        } else {
            qDebug() << "Failed";
            theBox->setFailAddGeneric();

        }

        clearFields();
    } else {
        theBox->setFailAddMinimum();

    }
    theBox->ok();

}

void AddPage::clearFields()
{
    nameEdit->setText("");
    vintageEdit->setText("");
    regionEdit->setText("");
    vineyardEdit->setText("");
    priceEdit->setText("");

    quantityEdit->setText("");
    description->setText("");

    locationEdit->setCurrentIndex(0);
    redBox->setCurrentIndex(0);
    whiteBox->setCurrentIndex(0);
    roseBox->setCurrentIndex(0);
}

QString AddPage::checkCase(QString &field)
{
    QStringList splitfield = field.split(" ");
    QString newField = "";

    foreach(QString part, splitfield) {
        QString lower = part.toLower();
        lower[0] = lower[0].toUpper();

        newField = newField + lower + " ";
    }

    return newField.remove(-1, 1);
}

AddPage::~AddPage()
{
    this->close();
}
