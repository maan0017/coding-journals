#include <iostream>
#include <string>

void findAndReplace(std::string *str, const std::string *word, const std::string *replace)
{
    size_t pos = 0;
    while ((pos = str->find(*word, pos)) != std::string::npos)
    {
        str->replace(pos, word->length(), *replace);
        pos += replace->length(); // move past the replacement
    }
}

void normal_replace(std::string str)
{
    str.replace(0, 1, "ooo"); // Using std::string::replace (Direct Replace by Index) ✅
}

int main()
{
    std::string str = "carfootceatdangeroudlynowayhellokctscanwowshutthefuckupcoolerwaterrainglassrubberok";
    std::string find = "car";
    std::string replaceWith = "busSTAND";

    findAndReplace(&str, &find, &replaceWith);
    std::cout << str << "\n";

    return 0;
}