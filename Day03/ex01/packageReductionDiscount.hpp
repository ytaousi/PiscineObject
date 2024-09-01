#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
#define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscountCommand : public Command
{
    private:
        int discountValue;
    public:
        PackageReductionDiscountCommand();
        ~PackageReductionDiscountCommand();
        int getDiscountValue();
        float applyDiscount(float totalPrice);
};

#endif