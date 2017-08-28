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
    void clearFields();
    ~AddPage();

private slots:
    void changeWineList(int);
    void setWineListRed();
    void setWineListWhite();
    void setWineListRose();
    void setWineListDessert();
    void setWineListSparkling();
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
    QRadioButton* dessert;
    QRadioButton* sparkling;

    QComboBox* redBox;
    QComboBox* whiteBox;
    QComboBox* roseBox;
    QComboBox* dessertBox;
    QComboBox* sparklingBox;

    void addReds();
    void addWhites();
    void addRoses();
    void addDessert();
    void addSparkling();

    QGroupBox *addWineParameters();

    QLineEdit *nameEdit;
    QLineEdit *vintageEdit;
    QLineEdit *regionEdit;
    QLineEdit *vineyardEdit;
    QLineEdit *priceEdit;
    QComboBox *locationEdit;
    QLineEdit *quantityEdit;


    QString checkCase(QString &field);
    bool isMinimum(Wine *theWine);
};

#endif // ADDPAGE_H
