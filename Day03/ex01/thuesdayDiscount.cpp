#include "thuesdayDiscount.hpp"

ThuesdayDiscountCommand::ThuesdayDiscountCommand() 
{
    this->discountPercentage = 0.1;
}

ThuesdayDiscountCommand::~ThuesdayDiscountCommand()
{
    ;
}

float ThuesdayDiscountCommand::getDiscountPercentage()
{
    return this->discountPercentage;
}

float ThuesdayDiscountCommand::applyDiscount(float totalPrice)
{
    float priceAfterDiscount = 0;
    priceAfterDiscount = totalPrice - (totalPrice * this->getDiscountPercentage());
    return priceAfterDiscount;
}