#ifndef STUFF_H
#define STUFF_H

#include <QObject>

class stuff : public QObject
{
    Q_OBJECT
public:
    explicit stuff(QObject *parent = 0);

signals:

public slots:
};

#endif // STUFF_H