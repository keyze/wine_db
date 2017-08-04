#ifndef WINEBOX_H
#define WINEBOX_H

#include <QObject>
#include <QWidget>
#include <QMessageBox>

class WineBox : public QMessageBox
{
public:
    explicit WineBox(QMessageBox* parent=nullptr);
    void setSuccessAdd();
    void setFailAddGeneric();
    void setSuccessDrink();
    void setFailDrink();
    void setNoQuantityDrink();
    void setFailAddMinimum();
    void ok();
    void setNoWineSelectedtoDrink();
    void setFailNotEnoughDrink();
};

#endif // WINEBOX_H
