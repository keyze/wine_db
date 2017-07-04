#include "searchpage.h"
#include <QScopedPointer>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

SearchPage::SearchPage(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *searchLayout = new QVBoxLayout;
    QPushButton *searchButton = new QPushButton("Search");
    QTabWidget *searchTab = new QTabWidget;

    model = initialiseModel();
   // model->setQuery("SELECT name FROM wines");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));

   // initialiseModel(&model);

  //  QTableView* view = createView(QObject::tr("Relation Table Model"),
    //                                           &model);
  //  view->show();
    QTableView *view = new QTableView;
    view->setModel(model);


    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    view->show();
    searchLayout->addWidget(searchButton);
    searchLayout->addWidget(view);
    this->setLayout(searchLayout);

    connect(searchButton, SIGNAL(clicked(bool)), this, SLOT(searchDatabase()));
}

QSqlQueryModel* SearchPage::initialiseModel()
{
    QSqlQueryModel* sqlModel = new QSqlQueryModel;
  //  sqlModel->setQuery("SELECT colour, variety, name, region, vineyard, vintage FROM wines");
    sqlModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Colour"));
    sqlModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Variety"));
    sqlModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
    sqlModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Region"));
    sqlModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Vineyard"));
    sqlModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Vintage"));

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

void SearchPage::searchDatabase()
{
    model->setQuery("SELECT colour, variety, name, region, vineyard, vintage FROM wines");
}

SearchPage::~SearchPage()
{
    this->close();
}
