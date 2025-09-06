#include <bits/stdc++.h>
#include <conio.h>

void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

struct Player
{
    int x, y;
};

void print_vector(const std::vector<std::vector<int>> &vt, const Player &player)
{
    // top border
    for (size_t i = 0; i < vt[0].size(); i++)
        std::cout << "---";
    std::cout << "\n";

    // grid with player
    for (size_t i = 0; i < vt.size(); i++)
    {
        std::cout << "|";
        for (size_t j = 0; j < vt[i].size(); j++)
        {
            if (i == player.y && j == player.x)
                std::cout << "P|"; // Player
            else
                std::cout << vt[i][j] << "|";
        }
        std::cout << "\n";
    }

    // bottom border
    for (size_t i = 0; i < vt[0].size(); i++)
        std::cout << "---";
    std::cout << "\n";
}

int main()
{
    std::vector<std::vector<int>> matrix(10, std::vector<int>(10, -1));

    Player m_player = {0, 0};

    while (true)
    {
        clear_screen();                 // clear first
        print_vector(matrix, m_player); // then draw

        int button = _getch();

        if (button == 27) // ESC
            break;
        else if (button == 72 && m_player.y > 0)
            m_player.y--; // UP
        else if (button == 80 && m_player.y < matrix.size() - 1)
            m_player.y++; // DOWN
        else if (button == 75 && m_player.x > 0)
            m_player.x--; // LEFT
        else if (button == 77 && m_player.x < matrix[0].size() - 1)
            m_player.x++; // RIGHT
    }
    return 0;
}
