#include <iostream>

int main()
{
    std::string str = "carfootceatdangeroudlynowayhellokctscanwowshutthefuckupcoolerwaterrainglassrubberok";

    size_t pos = str.find("foot");
    size_t fromLastpos = str.rfind("ok"); // finds last occurrence

    if (pos != std::string::npos)
    {
        std::cout << "Found at index: " << pos << std::endl;
    }
    else
    {
        std::cout << "Not found!" << std::endl;
    }
    if (fromLastpos != std::string::npos)
    {
        std::cout << "Found at index from last position: " << fromLastpos << std::endl;
    }
    else
    {
        std::cout << "Not found!" << std::endl;
    }

    return 0;
}