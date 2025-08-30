#include <iostream>
#include <string>

int main()
{
    // C - Style Strings(Character Arrays)
    // Uses null - terminated character arrays('\0' at end).
    // Functions from<cstring>(strlen, strcpy, strcmp, etc.) are used.
    // ⚠️ Downside : Error - prone(buffer overflow, manual memory management).
    char char1[] = "Hello";      // array with null terminator
    char char2[10] = "World";    // fixed size array
    char *char3 = "Hello World"; // pointer to string literal

    // std::string(Modern C++ String Class)
    // Safe &easy to use(dynamic memory handling).
    // Provides rich member functions(.length(), .substr(), .find(), .replace(), etc.).
    std::string str1 = "Hello";           // direct initialization
    std::string str2("World");            // constructor style
    std::string str3(5, 'x');             // "xxxxx"
    std::string str4 = str1 + " " + str2; // concatenation

    // std::string_view (C++17 and later)
    std::string_view sv1 = "Hello"; // does not copy data

    // std::wstring, std::u16string, std::u32string
    // Used for Unicode / internationalization.
    std::wstring ws = L"Hello";     // wide characters (UTF-16 or UTF-32 depending on platform)
    std::u16string us = u"Hello";   // UTF-16
    std::u32string u32s = U"Hello"; // UTF-32

    // ✅ Best Way(Recommendation)
    //  - For general coding, DSA, interviews, and competitive programming → use std::string.
    //  - For high - performance read - only access(parsers, APIs, large text processing) → use std::string_view.
    //  - For low - level system programming / legacy C APIs → sometimes you’ll need C - style strings(char *),
    //    but wrap them in std::string whenever possible.
    //  - For Unicode - heavy apps → use std::wstring or std::u16string.

    //     | Feature / Type        | **C-Style String (`char[]` / `char*`)**                                           | **`std::string`**                                            | **`std::string_view` (C++17+)**                                                |
    // | --------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------------------------ |
    // | **Memory Management** | Manual (you allocate and manage null-terminated arrays). Risk of buffer overflow. | Automatic (handles dynamic allocation internally).           | No ownership → just points to an existing string.                              |
    // | **Mutability**        | Mutable (if not `const char*`).                                                   | Mutable (safe operations: `.append()`, `.erase()`).          | Read-only (cannot modify).                                                     |
    // | **Ease of Use**       | Hard (must use `<cstring>` functions).                                            | Easy (rich member functions, operator overloading).          | Very easy for read-only access (lightweight).                                  |
    // | **Performance**       | Fast, low-level (no overhead).                                                    | Slight overhead (dynamic allocation, copying).               | Extremely fast (no copy, only a pointer + length).                             |
    // | **Safety**            | Low (prone to errors, undefined behavior if not null-terminated).                 | High (automatic null-termination, bounds-checked functions). | High (but dangerous if original string is destroyed).                          |
    // | **Typical Use Cases** | Legacy C APIs, embedded systems, low-level memory handling.                       | General programming, DSA, competitive coding, interviews.    | Efficient parsing, read-only access, function args where copying isn’t needed. |
    // | **Unicode Support**   | Poor (just bytes, not aware of UTF).                                              | Supported via `std::wstring`, `u16string`, `u32string`.      | Works on top of any string type (UTF, ASCII, etc.).                            |

    std::cout << "char char1[] = 'Hello' > " << char1 << "\n";
    std::cout << "char char2[10] = 'World' > " << char2 << "\n";
    std::cout << "char *char3 = 'Hello World' > " << char3 << "\n";

    std::cout << "std::string str1 = 'Hello' > " << str1 << "\n";
    std::cout << "std::string str2('World') > " << str2 << "\n";
    std::cout << "std::string str3(5, 'x') > " << str3 << "\n";
    std::cout << "std::string str4 = str1 + ' ' + str2 > " << str4 << "\n";

    std::cout << "std::string_view sv1 = 'Hello' > " << sv1 << "\n";

    std::wcout << L"std::wstring ws = L'Hello' > " << ws << "\n";
    // For u16/u32string we need conversion, can't print directly in std::cout
    std::cout << "std::u16string us = u'Hello' > (UTF-16 string, not directly printable)\n";
    std::cout << "std::u32string u32s = U'Hello' > (UTF-32 string, not directly printable)\n";
}
