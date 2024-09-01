#include "personnel.hpp"

Secretary::~Secretary()
{
    ;
}

void Secretary::createForm(FormType formType)
{
    (void)formType;
    std::cout << "Creating form " << std::endl;
}

HeadMaster::~HeadMaster()
{
    ;
}

void HeadMaster::signForm(FormType formType)
{
    (void)formType;
    std::cout << "Signing form " << std::endl;
}