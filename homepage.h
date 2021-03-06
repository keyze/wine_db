#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>

class Homepage : public QWidget
{
    Q_OBJECT

public:
    Homepage(QStackedWidget *pages, QWidget *parent = 0);

private slots:
    void goToAddPage();
    void goToSearchPage();
    void goToDrinkPage();

signals:
    void goToPage(QString);

private:
    QStackedWidget *changePage;
};

#endif // HOMEPAGE_H
