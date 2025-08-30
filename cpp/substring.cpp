#include <iostream>

int main()
{
    std::string str = "abcdefghijklmnopqrstuvwxyz";
    std::string sub_string = str.substr(1, 1); // substr(excluded,included)

    std::cout << "substring >" << sub_string << "\n";
    return 0;
}