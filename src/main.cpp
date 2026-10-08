#include "app/application.h"

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        Application application;
        return application.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        return 1;
    }
}