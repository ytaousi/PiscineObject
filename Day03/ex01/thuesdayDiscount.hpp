#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscountCommand : public Command
{
    private:
        float discountPercentage;
    public:
        ThuesdayDiscountCommand();
        ~ThuesdayDiscountCommand();
        float getDiscountPercentage();
        float applyDiscount(float totalPrice);
};

#endif