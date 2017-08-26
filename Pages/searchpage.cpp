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

    QFont tabFont;
    tabFont.setPixelSize(20);
    tabFont.setBold(true);

    QTabWidget *searchTab = new QTabWidget;
    searchTab->setFont(tabFont);

    model = initialiseModel();

    qsearch = new QuickSearch(dbManager);
    asearch = new AdvancedSearch(dbManager);

    searchTab->addTab(qsearch, tr("Quick Search"));
    searchTab->addTab(asearch, tr("Advanced Search"));

    QFont viewFont;
    viewFont.setPixelSize(20);

    QTableView *view = new QTableView;
    view->setModel(model);
    view->setFont(viewFont);

    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    searchLayout->addWidget(searchTab);
    searchLayout->addWidget(view);
    view->show();
    this->setLayout(searchLayout);


    connect(qsearch, SIGNAL(sigSearchCellar(QString)), this, SLOT(quickSearchCellar(QString)));
    connect(qsearch, SIGNAL(sigSearchColour(QString)), this, SLOT(quickSearchColour(QString)));
    connect(qsearch, SIGNAL(sigSearchName(QString)), this, SLOT(quickSearchName(QString)));
    connect(qsearch, SIGNAL(sigSearchVariety(QString)), this, SLOT(quickSearchVariety(QString)));
    connect(asearch, SIGNAL(sigSearch(QString)), this, SLOT(advancedSearchQuery(QString)));
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
    sqlModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Cellar"));
    sqlModel->setHeaderData(7, Qt::Horizontal, QObject::tr("Quantity"));

    return sqlModel;
}

QTableView* SearchPage::createView(const QString &title, QSqlQueryModel *sqlModel)
{
    QTableView *view = new QTableView;
    view->setModel(sqlModel);
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
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cellar"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Quantity"));


}

void SearchPage::repopulateSearch()
{
    qsearch->populateSearch();
    asearch->populateSearch();
}

void SearchPage::quickSearchColour(QString colour)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where colour='" + colour + "'";
    searchDatabase(query);

}

void SearchPage::quickSearchCellar(QString cellar)
{
    QString query = "";
    if (cellar == "Home Cellar") {
        query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where location LIKE '" + cellar + "%'";
    } else {
        query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where location='" + cellar + "'";

    }
    searchDatabase(query);
}

void SearchPage::quickSearchVariety(QString variety)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where variety='" + variety + "'";
    searchDatabase(query);
}

void SearchPage::quickSearchName(QString name)
{
    QString query = "SELECT vineyard, name, vintage, variety, colour, region, location, quantity FROM wines where name='" + name + "'";
    searchDatabase(query);
}

void SearchPage::advancedSearchQuery(QString query)
{
    searchDatabase(query);
}

SearchPage::~SearchPage()
{
    this->close();
}
