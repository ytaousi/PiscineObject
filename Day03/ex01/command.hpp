#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Command
{
    private:
        static int                                  id;
        int                                         orderID;
        int                                         clientID;
        std::string                                 orderDate;
        std::pair<int, std::pair<std::string, float> > *articles; // <quantity, <name, price>>
        float                                       totalPrice;

    public:
        Command();
        Command(int clientID, std::string orderDate, std::pair<int, std::pair<std::string, float> > *articles);
        ~Command();
        float get_total_price();
        std::pair<int, std::pair<std::string, float> > *getOrderList();
        int getOrderID();
        int getClientID();
        std::string getOrderDate();
        void setOrderID(int orderID);
        void setClientID(int clientID);
        void setOrderDate(std::string orderDate);
};

#endif