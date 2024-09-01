#include "packageReductionDiscount.hpp"


PackageReductionDiscountCommand::PackageReductionDiscountCommand()
{
    this->discountValue = 10;
}

PackageReductionDiscountCommand::~PackageReductionDiscountCommand()
{
    ;
}

int PackageReductionDiscountCommand::getDiscountValue()
{
    return this->discountValue;
}

float PackageReductionDiscountCommand::applyDiscount(float totalPrice)
{
    float priceAfterDiscount = 0;
    priceAfterDiscount = totalPrice - this->getDiscountValue();
    return priceAfterDiscount;
}