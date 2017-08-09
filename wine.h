#ifndef WINE_H
#define WINE_H

#include <QString>
#include <QMap>

class Wine
{
public:
    Wine();
    ~Wine();

    QMap<QString, QString> wineMap();

    void setColour(QString &newColour);
    QString getColour();

    void setVariety(QString &newVariety);
    QString getVariety();

    void setDescription(QString &newDescription);
    QString getDescription();

    void setVintage(int &newVintage);
    int getVintage();

    void setVineyard(QString &newVineyard);
    QString getVineyard();

    void setRegion(QString &newRegion);
    QString getRegion();

    void setPrice(double &newPrice);
    double getPrice();

    void setLocation(QString &newLocation);
    QString getLocation();

    void setName(QString &newName);
    QString getName();

    void setQuantity(int &newQuantity);
    int getQuantity();

    QString toString();

private:


    QString colour;
    QString variety;
    QString description;
    QString name;
    QString region;
    QString vineyard;
    int vintage;
    int quantity;
    double price;
    QString location;

};

#endif // WINE_H
