#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pages.h"
#include "homepage.h"
#include "addpage.h"
#include "Pages/drink.h"
#include "Pages/searchpage.h"
#include "database/dbmanager.h"
#include "borderlayout.h"
#include <QVBoxLayout>
#include <QKeySequence>
#include <QMessageBox>
#include <QPalette>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DbManager *db = new DbManager;


    QWidget *widget = new QWidget;
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);

    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    setCentralWidget(widget);

    m_value = 0;

    QWidget *fakePage = new QWidget;
    pagesWidget = new QStackedWidget;
    //something is buggering up the indexing so throwing in a fakepage at index 0 and adding the real one at index 1
    pagesWidget->addWidget(fakePage);
    pagesWidget->addWidget(new Homepage(pagesWidget));
    pagesWidget->addWidget(new AddPage(db));
    pagesWidget->addWidget(new SearchPage(db));
    pagesWidget->addWidget(new Drink);


    pagesWidget->setCurrentIndex(1);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(pagesWidget);

    widget->setLayout(layout);


    menuBar()->setNativeMenuBar(false);
    createActions();
    createMenus();
    createToolBar();

    setWindowTitle(tr("Johnnys Wine Database!"));
    setMinimumSize(160, 160);
    resize(480, 320);
    setUnifiedTitleAndToolBarOnMac(true);
    this->statusBar()->setDisabled(true);

}

void MainWindow::createActions()
{
    QPixmap home(":/res/pictures/home.png");
    QPixmap addWine(":/res/pictures/transparent-wine.png");
    QPixmap drinkWine(":/res/pictures/drink-wine-512.png");
    QPixmap searchPic(":/res/pictures/search.png");
    const QIcon homeIcon(home);
    const QIcon wineIcon(addWine);
    const QIcon drinkIcon(drinkWine);
    const QIcon searchIcon(searchPic);
    goHome = new QAction(homeIcon, tr("&Home"), this);
    goAddWine = new QAction(wineIcon, tr("&Add Wine"), this);
    goDrinkWine = new QAction(drinkIcon, tr("&Drink Wine"), this);
    search = new QAction(searchIcon, tr("&Search"), this);
    exitAct = new QAction(tr("&Exit"), this);
    goHome->setStatusTip(tr("Go Home"));
    goAddWine->setStatusTip(tr("Add Wine"));
    goDrinkWine->setStatusTip(tr("Drink Wine"));
    search->setStatusTip(tr("Search"));
    connect(goHome, &QAction::triggered, this,  &MainWindow::ribbonHome);
    connect(goAddWine, &QAction::triggered, this, &MainWindow::ribbonAdd);
    connect(goDrinkWine, &QAction::triggered, this, &MainWindow::ribbonDrink);
    connect(search, &QAction::triggered, this, &MainWindow::ribbonSearch);
    connect(exitAct, &QAction::triggered, this, &QWidget::close);


}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(goHome);
    fileMenu->addAction(goAddWine);
    fileMenu->addAction(search);
    fileMenu->addAction(goDrinkWine);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}


void MainWindow::createToolBar()
{
    QToolBar* myTools = this->addToolBar(tr("My tools"));

    myTools->addAction(goHome);
    myTools->addAction(goAddWine);
    myTools->addAction(search);
    myTools->addAction(goDrinkWine);
    myTools->setMovable(false);
}



#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(goHome);
    menu.addAction(goAddWine);
    menu.addAction(search);
    menu.addAction(goDrinkWine);
    menu.exec(event->globalPos());

}
#endif // QT_NO_CONTEXTMENU

void MainWindow::changePage(int current)
{
    if (current != m_value) {
        pagesWidget->setCurrentIndex(current);
    }

}

void MainWindow::newFile()
{

    changePage(1);

}


void MainWindow::open()
{
    changePage(2);
}

void MainWindow::print()
{
    changePage(0);
}

void MainWindow::ribbonAdd()
{
    changePage(2);
}

void MainWindow::ribbonDrink()
{
    changePage(4);
}

void MainWindow::ribbonHome()
{
    changePage(1);
}

void MainWindow::ribbonSearch()
{
    changePage(3);
}



MainWindow::~MainWindow()
{
    delete ui;
}
