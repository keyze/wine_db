#include "searchpage.h"
#include "quicksearch.h"
#include <QScopedPointer>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QDebug>

SearchPage::SearchPage(DbManager *dbManager, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *searchLayout = new QVBoxLayout;
    QPushButton *searchButton = new QPushButton("Search");
    QTabWidget *searchTab = new QTabWidget;

    model = initialiseModel();

    QuickSearch *qsearch = new QuickSearch(dbManager);
    searchTab->addTab(qsearch, tr("Quick Search"));
    QTableView *view = new QTableView;
    view->setModel(model);


    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    searchLayout->addWidget(searchTab);
    searchLayout->addWidget(searchButton);
    searchLayout->addWidget(view);
    view->show();
    this->setLayout(searchLayout);


    connect(qsearch, SIGNAL(sigSearchCellar(QString)), this, SLOT(quickSearchCellar(QString)));
    connect(qsearch, SIGNAL(sigSearchColour(QString)), this, SLOT(quickSearchColour(QString)));
    connect(qsearch, SIGNAL(sigSearchName(QString)), this, SLOT(quickSearchName(QString)));
    connect(qsearch, SIGNAL(sigSearchVariety(QString)), this, SLOT(quickSearchVariety(QString)));
}

QSqlQueryModel* SearchPage::initialiseModel()
{
    QSqlQueryModel* sqlModel = new QSqlQueryModel;

    sqlModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Colour"));
    sqlModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Variety"));
    sqlModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
    sqlModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Region"));
    sqlModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Vineyard"));
    sqlModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Vintage"));
    sqlModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Quantity"));


   // sqlModel->select();
    return sqlModel;
}

QTableView* SearchPage::createView(const QString &title, QSqlQueryModel *sqlModel)
{
    QTableView *view = new QTableView;
    view->setModel(sqlModel);
    //view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setWindowTitle(title);
    return view;
}

void SearchPage::searchDatabase(QString query)
{
    qDebug() << query;
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Vineyard"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Vintage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Variety"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Colour"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Region"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Quantity"));


}

void SearchPage::quickSearchColour(QString colour)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where colour='" + colour + "'";
    searchDatabase(query);

}

void SearchPage::quickSearchCellar(QString cellar)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where location='" + cellar + "'";
    searchDatabase(query);
}

void SearchPage::quickSearchVariety(QString variety)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where variety='" + variety + "'";
    searchDatabase(query);
}

void SearchPage::quickSearchName(QString name)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, quantity FROM wines where name='" + name + "'";
    searchDatabase(query);
}

SearchPage::~SearchPage()
{
    this->close();
}
