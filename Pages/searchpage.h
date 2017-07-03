#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>

class SearchPage : public QWidget
{
    Q_OBJECT
public:
    SearchPage(QWidget *parent=0);
    ~SearchPage();

private slots:
    void searchDatabase();

private:
    QSqlQueryModel *initialiseModel();
    QTableView *createView(const QString &title, QSqlQueryModel *sqlModel);

    QSqlQueryModel* model;
};

#endif // SEARCHPAGE_H
