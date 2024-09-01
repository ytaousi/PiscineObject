#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int main()
{
    std::pair<int, std::pair<std::string, float> > orderList1[] = {
        std::make_pair(4, std::make_pair("GPU RTX 3090", 1500)),
        std::make_pair(3, std::make_pair("CPU i9 10900K", 500)),
        std::make_pair(1, std::make_pair("RAM 32GB", 200)),
        std::make_pair(1, std::make_pair("SSD 1TB", 100))
    };

    std::pair<int, std::pair<std::string, float> > orderList2[] = {
        std::make_pair(4, std::make_pair("Monitor", 300)),
        std::make_pair(3, std::make_pair("Headset", 150)),
        std::make_pair(1, std::make_pair("Desk", 100)),
        std::make_pair(2, std::make_pair("PS5 Controller", 50))
    };

    std::pair<int, std::pair<std::string, float> > orderList3[] = {
        std::make_pair(4, std::make_pair("PS5 Console", 3500)),
        std::make_pair(3, std::make_pair("item2", 25)),
        std::make_pair(1, std::make_pair("item3", 25)),
        std::make_pair(5, std::make_pair("PS5 Network+ Subscription", 50))
    };

    Command command1(1, "Monday", orderList1);
    Command command2(2, "Saturday", orderList2);
    Command command3(3, "Friday", orderList3);
    Command command4(3, "Thuesday", orderList1);


    std::cout << "------Prices------" << std::endl;

    std::cout << "Command 1 Done by Client with ID " <<  command1.getClientID() << "\n Cost: " << command1.get_total_price() << std::endl;
    std::cout << "Command 2 Done by Client with ID " <<  command2.getClientID() << "\n Cost: " << command2.get_total_price() << std::endl;
    std::cout << "Command 3 Done by Client with ID " <<  command3.getClientID() << "\n Cost: " << command3.get_total_price() << std::endl;
    std::cout << "Command 4 Done by Client with ID " <<  command4.getClientID() << "\n Cost: " << command4.get_total_price() << std::endl;


    return (0);
}