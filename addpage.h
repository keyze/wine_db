#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>
#include <QComboBox>

class AddPage : public QWidget
{
public:
    AddPage(QWidget *parent=0);

private:
    void addReds(QComboBox *redBox);
    void addWhites(QComboBox *whiteBox);
    void addRoses(QComboBox *roseBox);

};

#endif // ADDPAGE_H
