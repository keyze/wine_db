#include "winebox.h"
#include <QDebug>

WineBox::WineBox(QMessageBox *parent) : QMessageBox(parent)
{

}

void WineBox::setSuccessAdd()
{
    this->setWindowTitle(tr("Success!!!"));
    this->setText(tr("You have successfully added the wine to your collection!!!"));
}

void WineBox::setFailAddGeneric()
{
    this->setWindowTitle(tr("Failure"));
    this->setText(tr("I'm sorry you have failed to add the wine to your collection."));
}

void WineBox::setFailAddMinimum()
{
    this->setWindowTitle(tr("Failure"));
    this->setText(tr("I'm sorry you have failed to add the wine to your collection."));
    this->setInformativeText("Please include a minimum of Name, Vintage, Colour and Variety to add your wine.");
}

void WineBox::setSuccessDrink()
{
    this->setWindowTitle(tr("Success!!!"));
    this->setText(tr("Enjoy your wine."));
}

void WineBox::setFailDrink()
{
    this->setWindowTitle(tr("Failure"));

}

void WineBox::setFailNotEnoughDrink()
{
    this->setWindowTitle(tr("Not Enough"));
    this->setText(tr("You don't have enough in your cellar to take this many."));
}

void WineBox::setNoQuantityDrink()
{
    this->setWindowTitle("Enter Quantity");
    this->setText("Please enter number of bottles of wine to drink.");
}

void WineBox::setNoWineSelectedtoDrink()
{
    this->setWindowTitle("No Wine Selected");
    this->setText("Please select a wine to drink.");
}

void WineBox::ok()
{
    int ret = this->exec();
    switch(ret) {
    case QMessageBox::Ok :
        this->setText("");
        this->setInformativeText("");
        break;
    default :
        qDebug() << "Something went wrong";
        break;
    }

}
