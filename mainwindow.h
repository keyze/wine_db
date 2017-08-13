#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>
#include <QContextMenuEvent>
#include <QStackedWidget>
#include "Pages/searchpage.h"

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
    void newFile();
    void open();
    void print();
    void ribbonAdd();
    void ribbonDrink();
    void ribbonHome();
    void ribbonSearch();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

signals:
    void valueChanged(int newValue);

private:
    Ui::MainWindow *ui;
    SearchPage* sp;
    void createActions();
    void createMenus();
    void createToolBar();

    int m_value;

    QStackedWidget *pagesWidget;
    QMenu *fileMenu;

    QAction* goHome;
    QAction* goAddWine;
    QAction* goDrinkWine;
    QAction* search;
    QAction* exitAct;

};

#endif // MAINWINDOW_H
