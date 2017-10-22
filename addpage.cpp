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

    addWhites();
    addReds();
    addRoses();
    addSparkling();
    addDessert();

    variety = new QStackedWidget;
    variety->addWidget(whiteBox);
    variety->addWidget(redBox);
    variety->addWidget(roseBox);
    variety->addWidget(sparklingBox);
    variety->addWidget(dessertBox);

    variety->setCurrentIndex(1);

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

void AddPage::addWhites()
{
    whiteBox = new QComboBox;
    whiteBox->setMaximumHeight(30);
    QFont whiteFont;
    whiteFont.setPixelSize(20);

    whiteBox->setFont(whiteFont);
    whiteBox->insertItem(0, "");
    whiteBox->addItem("Chardonnay");
    whiteBox->addItem("Gewurztraminer");
    whiteBox->addItem("Marsanne");
    whiteBox->addItem("Pinot Blanc");
    whiteBox->addItem("Pinot Gris/Pinot Grigio");
    whiteBox->addItem("Riesling");
    whiteBox->addItem("Sauvignon Blanc");
    whiteBox->addItem("Sauvignon Blanc Semillon");
    whiteBox->addItem("Semillon");
    whiteBox->addItem("Verdelho");
    whiteBox->addItem("Viognier");
    whiteBox->addItem("Viognier Nouveau");



}

void AddPage::addReds()
{
    redBox = new QComboBox;
    redBox->setMaximumHeight(30);

    QFont redFont;
    redFont.setPixelSize(20);

    redBox->setFont(redFont);
    redBox->insertItem(0, "");
    redBox->addItem("Areni Noir");
    redBox->addItem("Ballinderry");
    redBox->addItem("Barbera");
    redBox->addItem("Bordeaux");
    redBox->addItem("Barolo");
    redBox->addItem("Cabernet");
    redBox->addItem("Cabernet Franc");
    redBox->addItem("Cabernet Merlot");
    redBox->addItem("Cabernet Sauvignon");
    redBox->addItem("Cabernet Sauvignon Merlot");
    redBox->addItem("Cabernet Sauvignon Shiraz");
    redBox->addItem("Ceoltoiri");
    redBox->addItem("Frappato di Vittoria");
    redBox->addItem("Feteasca Neagra");
    redBox->addItem("Grenache");
    redBox->addItem("Grenache Shiraz");
    redBox->addItem("G.S.M");
    redBox->addItem("Malbec");
    redBox->addItem("Malbec Cabernet Sauvignon");
    redBox->addItem("Merlot");
    redBox->addItem("Nebbiolo");
    redBox->addItem("Nero d'Avola");
    redBox->addItem("Petit Verdot");
    redBox->addItem("Pinot Noir");
    redBox->addItem("Quintet");
    redBox->addItem("Sangiovese");
    redBox->addItem("Saperavi");
    redBox->addItem("Shiraz");
    redBox->addItem("Shiraz Cabernet");
    redBox->addItem("Shiraz Viognier");
    redBox->addItem("Syrah");
    redBox->addItem("Tempranillo");  
    redBox->addItem("Volnay");
    redBox->addItem("Xino Mavro");

}

void AddPage::addRoses()
{
    roseBox = new QComboBox;
    roseBox->setMaximumHeight(30);

    QFont roseFont;
    roseFont.setPixelSize(20);

    roseBox->setFont(roseFont);
    roseBox->insertItem(0, "");
    roseBox->addItem("Grenache");
    roseBox->addItem("Pinot Noir");
    roseBox->addItem("Muscat");
    roseBox->addItem("Tempranillo");


}

void AddPage::addDessert()
{
    dessertBox = new QComboBox;
    dessertBox->setMaximumHeight(30);

    QFont dessertFont;
    dessertFont.setPixelSize(20);

    dessertBox->setFont(dessertFont);
    dessertBox->insertItem(0, "");
    dessertBox->addItem("Muscat");
    dessertBox->addItem("Port");
    dessertBox->addItem("Sherry");   
    dessertBox->addItem("Tokay");



}

void AddPage::addSparkling()
{
    sparklingBox = new QComboBox;
    sparklingBox->setMaximumHeight(30);

    QFont sparklingFont;
    sparklingFont.setPixelSize(20);

    sparklingBox->setFont(sparklingFont);
    sparklingBox->insertItem(0, "");
    sparklingBox->addItem("Champagne");   
    sparklingBox->addItem("Sparkling Red");
    sparklingBox->addItem("Sparkling Rose");
    sparklingBox->addItem("Sparkling White");


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
    locationEdit->addItem("Work Shelf 1");
    locationEdit->addItem("Work Shelf 2");
    locationEdit->addItem("Work Shelf 3");
    locationEdit->addItem("Work Shelf 4");
    locationEdit->addItem("Work Shelf 5");
    locationEdit->addItem("Work Shelf 6");
    locationEdit->addItem("Work Shelf 7");
    locationEdit->addItem("Work Shelf 8");
    locationEdit->addItem("Adams Shelf 1");
    locationEdit->addItem("Adams Shelf 2");
    locationEdit->addItem("Adams Shelf 3");
    locationEdit->addItem("Adams Shelf 4");
    locationEdit->addItem("Johnny Vintec Shelf 1");
    locationEdit->addItem("Johnny Vintec Shelf 2");
    locationEdit->addItem("Johnny Vintec Shelf 3");
    locationEdit->addItem("Johnny Vintec Shelf 4");
    locationEdit->addItem("Johnny Vintec Shelf 5");
    locationEdit->addItem("Johnny Vintec Shelf 6");
    locationEdit->addItem("Johnny Vintec Shelf 7");
    locationEdit->addItem("Johnny Vintec Shelf 8");
    locationEdit->addItem("Johnny Vintec Shelf 9");
    locationEdit->addItem("Johnny Vintec Shelf 10");
    locationEdit->addItem("Johnny Vintec Shelf 11");
    locationEdit->addItem("Johnny White Shelf 1");
    locationEdit->addItem("Johnny White Shelf 2");
    locationEdit->addItem("Johnny White Shelf 3");
    locationEdit->addItem("Johnny White Shelf 4");
    locationEdit->addItem("Johnny White Shelf 5");


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

    sparkling = new QRadioButton(tr("Sparkling"));
    sparkling->setFont(radioFont);
    connect(sparkling, SIGNAL(clicked(bool)), this, SLOT(setWineListSparkling()));

    dessert = new QRadioButton(tr("Fortified/Dessert"));
    dessert->setFont(radioFont);
    connect(dessert, SIGNAL(clicked(bool)), this, SLOT(setWineListDessert()));

    red->setChecked(true);

    QVBoxLayout *radioLayout = new QVBoxLayout;
    radioLayout->addWidget(white, 1, Qt::AlignHCenter);
    radioLayout->addWidget(red, 1, Qt::AlignHCenter);
    radioLayout->addWidget(rose, 1, Qt::AlignHCenter);
    radioLayout->addWidget(sparkling, 1, Qt::AlignHCenter);
    radioLayout->addWidget(dessert, 1, Qt::AlignHCenter);


    colours->setLayout(radioLayout);
    colours->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    return colours;

}

bool AddPage::isMinimum(Wine* theWine)
{
    qDebug() << theWine->toString();
    if (theWine->getColour() != "" && theWine->getName() != "" && theWine->getVariety() != "" &&
            QString::number(theWine->getVintage()) != "" && theWine->getLocation() != "" && theWine->getQuantity() > 0) {
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

void AddPage::setWineListSparkling()
{
    emit AddPage::setWineList(3);
}

void AddPage::setWineListDessert()
{
    emit AddPage::setWineList(4);
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
    } else if (rose->isChecked()){
        QString colour = "Rose";
        myWine->setColour(colour);

        QString variety = roseBox->currentText();
        myWine->setVariety(variety);
    } else if (sparkling->isChecked()) {
        QString colour = "Sparkling";
        myWine->setColour(colour);

        QString variety = sparklingBox->currentText();
        myWine->setVariety(variety);
    } else if (dessert->isChecked()) {
        QString colour = "Fortified/Dessert";
        myWine->setColour(colour);

        QString variety = dessertBox->currentText();
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
    qDebug() << location;
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
    dessertBox->setCurrentIndex(0);
    sparklingBox->setCurrentIndex(0);
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
