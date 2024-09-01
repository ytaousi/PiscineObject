#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int Command::id = 0;

Command::Command()
{
    this->orderID = ++id;
    this->clientID = 0;
    this->orderDate = "";
    this->articles = NULL;
    this->totalPrice = 0;
}

Command::Command(int clientID, std::string orderDate, std::pair<int, std::pair<std::string, float> > *articles)
{
    this->orderID = ++id;
    this->clientID = clientID;
    this->orderDate = orderDate;
    this->articles = articles;
}

Command::~Command()
{
    ;
}

float Command::get_total_price()
{
    float priceAfterDiscount = 0;
    float totalPrice = 0;
    int numberOfOrders = 4;

    for (int i = 0; i < numberOfOrders; i++)
    {
        std::string articleName = this->articles[i].second.first;
        int quantity = this->articles[i].first;
        float price = this->articles[i].second.second;
        
        totalPrice += price * quantity;
    }
    priceAfterDiscount = totalPrice;
    if (this->orderDate == "Thuesday")
    {
        ThuesdayDiscountCommand thuesdayDiscount;
        priceAfterDiscount = thuesdayDiscount.applyDiscount(totalPrice);
    }
    if (priceAfterDiscount > 150)
    {
        PackageReductionDiscountCommand packageReductionDiscount;
        priceAfterDiscount = packageReductionDiscount.applyDiscount(priceAfterDiscount);
    }
    return priceAfterDiscount;
}


std::pair<int, std::pair<std::string, float> > *Command::getOrderList()
{
    return this->articles;
}

int Command::getOrderID()
{
    return this->orderID;
}

int Command::getClientID()
{
    return this->clientID;
}

std::string Command::getOrderDate()
{
    return this->orderDate;
}

void Command::setOrderID(int orderID)
{
    this->orderID = orderID;
}

void Command::setClientID(int clientID)
{
    this->clientID = clientID;
}

void Command::setOrderDate(std::string orderDate)
{
    this->orderDate = orderDate;
}

