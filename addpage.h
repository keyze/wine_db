#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QStackedWidget>

class AddPage : public QWidget
{
    Q_OBJECT
public:
    explicit AddPage(QWidget *parent=0);
    ~AddPage();

private slots:
    void changeWineList(int);
    void setWineListRed();
    void setWineListWhite();
    void setWineListRose();

signals:
    void setWineList(int);

private:

    QFont groupFont;
    QGroupBox *setUpColours();
    QStackedWidget *variety;
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
    QLineEdit *locationEdit;
    QLineEdit *quantityEdit;


};

#endif // ADDPAGE_H
