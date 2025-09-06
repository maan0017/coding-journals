#include <iostream>
#include <memory> // for smart pointers

struct ListNode
{
public:
    int value;
    std::unique_ptr<ListNode> next;

    // constructors
    ListNode() : value(0), next(nullptr) {}
    ListNode(int v) : value(v), next(nullptr) {}
    ListNode(int v, std::unique_ptr<ListNode> nxt) : value(v), next(std::move(nxt)) {}

    // utility function
    void print() const
    {
        const ListNode *curr = this;
        while (curr)
        {
            std::cout << curr->value;
            if (curr->next)
                std::cout << " -> ";
            else
            {
                std::cout << " [END] ";
            }
            curr = curr->next.get();
        }
        std::cout << std::endl;
    }

    void getCount() const
    {
        int count = 0;
        const ListNode *curr = this;

        while (curr != nullptr)
        {
            count++;
            curr = curr->next.get();
        }

        std::cout << "List Node Length : " << count << std::endl;
    }
};

int main()
{
    auto head = std::make_unique<ListNode>(10);
    head->next = std::make_unique<ListNode>(20);
    head->next->next = std::make_unique<ListNode>(30);

    head->print();
    head->getCount();
    return 0;
}