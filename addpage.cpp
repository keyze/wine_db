#include "addpage.h"

#include <QButtonGroup>
#include <QStackedWidget>
#include <QGridLayout>

AddPage::AddPage(QWidget *parent) :
    QWidget(parent)
{
    QComboBox *whiteBox = addWhites();
    QComboBox *redBox = addReds();
    QComboBox *roseBox = addRoses();

    QStackedWidget *variety = new QStackedWidget;
    variety->addWidget(whiteBox);
    variety->addWidget(redBox);
    variety->addWidget(roseBox);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(variety, 0, 0, 1, 2);
    setLayout(layout);

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
