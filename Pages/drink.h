#ifndef DRINK_H
#define DRINK_H

#include <QObject>
#include <QWidget>

class Drink : public QWidget
{
    Q_OBJECT
public:
    explicit Drink(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // DRINK_H