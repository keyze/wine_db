#include "wine.h"

Wine::Wine()
{
    colour = "";
    variety = "";
    description = "";
    name = "";
    region = "";
    vineyard = "";
    vintage = 0;
    quantity = 0;
    price = 0.00;
    location = "";
}

void Wine::setColour(QString &newColour)
{
    colour = newColour;
}

QString Wine::getColour()
{
    return colour;
}

void Wine::setVariety(QString &newVariety)
{
    variety = newVariety;
}

QString Wine::getVariety()
{
    return variety;
}

void Wine::setDescription(QString &newDescription)
{
    description = newDescription;
}

QString Wine::getDescription()
{
    return description;
}

void Wine::setVintage(int &newVintage)
{
    vintage = newVintage;
}

int Wine::getVintage()
{
    return vintage;
}

void Wine::setVineyard(QString &newVineyard)
{
    vineyard = newVineyard;
}

QString Wine::getVineyard()
{
    return vineyard;
}

void Wine::setRegion(QString &newRegion)
{
    region = newRegion;
}

QString Wine::getRegion()
{
    return region;
}

void Wine::setPrice(double &newPrice)
{
    price = newPrice;
}

double Wine::getPrice()
{
    return price;
}

void Wine::setLocation(QString &newLocation)
{
    location = newLocation;
}

QString Wine::getLocation()
{
    return location;
}

void Wine::setName(QString &newName)
{
    name = newName;
}

QString Wine::getName()
{
    return name;
}

void Wine::setQuantity(int &newQuantity)
{
    quantity = newQuantity;
}

int Wine::getQuantity()
{
    return quantity;
}

QString Wine::toString()
{
    return "";
}
