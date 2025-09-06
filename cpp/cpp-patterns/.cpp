#include <bits/stdc++.h> // includes almost everything (works with g++)

int main()
{
    std::ios::sync_with_stdio(false); // fast IO
    std::cin.tie(nullptr);

    // your code here
    int rows = 10;
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}