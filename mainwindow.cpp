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
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);


}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}


void MainWindow::createToolBar()
{
    QToolBar* myTools = this->addToolBar(tr("My tools"));
    QPixmap home(":/res/pictures/home-icon-73307.png");
    const QIcon homeIcon(home);
    QAction* goHome = new QAction(homeIcon, tr("&Home"), this);
    goHome->setStatusTip(tr("Go Home"));
    connect(goHome, &QAction::triggered, this,  &MainWindow::newFile);
    myTools->addAction(goHome);
    myTools->setMovable(false);
}



#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(newAct);
    menu.addAction(openAct);
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



MainWindow::~MainWindow()
{
    delete ui;
}
