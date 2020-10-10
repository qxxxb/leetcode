#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* p = nullptr;
        auto cur = head;
        while (cur) {
            auto n = cur->next;
            cur->next = p;
            p = cur;
            cur = n;
        }
        return p;
    }

    bool hasCycle(ListNode* head) {
        if (!head) return false;
        if (!head->next) return false;
        if (head->next == head) return true;

        auto h = head;
        auto hrev = rev(head);
        return h == hrev;
    }
};

int main(int argc, char *argv[])
{
    auto n1 = new ListNode(-4);
    auto n2 = new ListNode(0, n1);
    auto n3 = new ListNode(2, n2);
    auto n4 = new ListNode(3, n3);
    n1->next = n3;

    auto s = Solution();

    cout << s.hasCycle(n4) << endl;

    return 0;
}
