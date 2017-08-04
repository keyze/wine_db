#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QStackedWidget>
#include <QRadioButton>
#include <QTextEdit>
#include "winebox.h"
#include "wine.h"
#include "database/dbmanager.h"

class AddPage : public QWidget
{
    Q_OBJECT
public:
    explicit AddPage(DbManager* db, QWidget *parent=0);
    ~AddPage();

private slots:
    void changeWineList(int);
    void setWineListRed();
    void setWineListWhite();
    void setWineListRose();
    void addWinetoDB();

signals:
    void setWineList(int);

private:

    Wine* createWine();
    WineBox* theBox;
    DbManager* theDB;

    QFont groupFont;
    QGroupBox *setUpColours();
    QStackedWidget *variety;

    QTextEdit* description;

    QRadioButton* red;
    QRadioButton* white;
    QRadioButton* rose;

    QComboBox* redBox;
    QComboBox* whiteBox;
    QComboBox* roseBox;

    QComboBox* addReds();
    QComboBox* addWhites();
    QComboBox* addRoses();

    QGroupBox *addWineParameters();

    QLineEdit *nameEdit;
    QLineEdit *vintageEdit;
    QLineEdit *regionEdit;
    QLineEdit *vineyardEdit;
    QLineEdit *priceEdit;
    QComboBox *locationEdit;
    QLineEdit *quantityEdit;

    void clearFields();
    bool isMinimum(Wine *theWine);
};

#endif // ADDPAGE_H
