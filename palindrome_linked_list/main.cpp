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
    ListNode* rev(ListNode* h) {
        auto cur = h;
        ListNode* prev = nullptr;
        while (cur) {
            auto n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow is now the middle node (odd number) or
        // pre-middle node (even number)
        auto rhalf = rev(slow->next);
        slow->next = rhalf;

        {
            auto p = head;
            while (p) {
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;
        }

        auto l = head;
        auto r = slow->next;
        while (r) {
            cout << l->val << " " << r->val << endl;
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(3, n1);
    auto n3 = new ListNode(5, n2);
    auto n4 = new ListNode(6, n3);
    auto n5 = new ListNode(7, n4);
    auto n6 = new ListNode(6, n5);
    auto n7 = new ListNode(5, n6);
    auto n8 = new ListNode(3, n7);
    auto n9 = new ListNode(1, n8);

    auto s = Solution();

    cout << s.isPalindrome(n9) << endl;

    return 0;
}
