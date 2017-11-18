#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>
#include <QContextMenuEvent>
#include <QStackedWidget>
#include "Pages/searchpage.h"
#include "addpage.h"
#include "Pages/drink.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void changePage(int);
    void ribbonAdd();
    void ribbonDrink();
    void ribbonHome();
    void ribbonSearch();
    void clearPage(QString page);

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

signals:
    void valueChanged(int newValue);

private:
    Ui::MainWindow *ui;
    SearchPage* sp;
    AddPage *ap;
    Drink *dp;

    void createActions();
    void createMenus();
    void createToolBar();

    int m_value;

    QStackedWidget *pagesWidget;
    QMenu *fileMenu;
    QMenu *editMenu;


    QAction* goHome;
    QAction* goAddWine;
    QAction* goDrinkWine;
    QAction* search;
    QAction* exitAct;
    QAction* settingsAct;

};

#endif // MAINWINDOW_H
