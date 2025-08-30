#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

// Using std::reverse(Best & Optimized ✅)
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place)
// Uses iterators, very optimized at the library level.
// Best choice for competitive programming and real-world use.
void reverse_string(std::string *str)
{
    // it uses the -> In-place, two-pointer swapping technique

    // ``` cpp
    // template <class BidirectionalIterator>
    // void reverse(BidirectionalIterator first, BidirectionalIterator last)
    // {
    //     while ((first != last) && (first != --last))
    //     {
    //         std::iter_swap(first, last);
    //         ++first;
    //     }
    // }
    // ```

    // Steps:
    //      1. Put one iterator at the beginning(first) and one at the end(last - 1).
    //      2. Swap elements.
    //      3. Move first++ and last--.
    //      4.Repeat until they cross.

    std::reverse(str->begin(), str->end());
}

// Not Good to use.
// Performance issue(O(n)) ,
void reverse_string_raw_power(std::string *str)
{
    std::string reversed_string;
    reversed_string.reserve(str->length()); // pre-allocate memory (avoids O(n²) problem)

    for (int i = str->length() - 1; i >= 0; i--)
    {
        reversed_string += (*str)[i]; // correctly access characters
    }

    *str = reversed_string; // update original string
}

void reverse_string_reserve_copy(std::string *str)
{
    std::string rev(str->rbegin(), str->rend()); // copy reversed
}

void reverse_string_two_pointers_approch(std::string *str)
{
    // Equivalent to what std::reverse does internally.
    // Useful if you want to avoid<algorithm>.
    int left = 0, right = str->size() - 1;

    while (left < right)
    {
        std::swap((*str)[left], (*str)[right]);
        left++;
        right--;
    }
}

int main()
{
    std::string str = "random string ok";
    str.reserve();
    reverse_string(&str);
    // reverse_string_raw_power(&str);
    // reverse_string_two_pointers_approch(&str);
    std::cout << "reversed string >" << str << "\n";
    return 0;
}