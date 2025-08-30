#include <iostream>
#include <algorithm>

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r\f\v"); // skip leading spaces
    if (start == std::string::npos)
        return ""; // all spaces

    size_t end = s.find_last_not_of(" \t\n\r\f\v"); // skip trailing spaces
    return s.substr(start, end - start + 1);
}

void trim_inplace(std::string &s)
{
    // left trim
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
    // right trim
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

int main()
{
    return 0;
}