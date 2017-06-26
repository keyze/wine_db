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

    QGroupBox *colours = new QGroupBox(tr("Wine Colours"));

    QRadioButton *white = new QRadioButton(tr("White"));
    QRadioButton *red = new QRadioButton(tr("Red"));
    QRadioButton *rose = new QRadioButton(tr("Rose"));

    white->setChecked(true);

    QVBoxLayout *radioLayout = new QVBoxLayout;
    radioLayout->addWidget(white, 0, Qt::AlignCenter);
    radioLayout->addWidget(red, 0, Qt::AlignCenter);
    radioLayout->addWidget(rose, 0, Qt::AlignCenter);

    colours->setLayout(radioLayout);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(variety, 0, 1);
    layout->addWidget(colours, 0, 0);
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
