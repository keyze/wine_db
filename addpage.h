#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>

class AddPage : public QWidget
{
public:
    AddPage(QWidget *parent=0);

private:
    QComboBox* addReds();
    QComboBox* addWhites();
    QComboBox* addRoses();

    QGroupBox *addWineParameters();

};

#endif // ADDPAGE_H
