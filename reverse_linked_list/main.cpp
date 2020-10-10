#include <stack>
#include <tuple>

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
    ListNode* reverseList_iter_shit(ListNode* head) {
        stack<int> s;
        auto p = head;
        while (p != nullptr) {
            s.push(p->val);
            p = p->next;
        }

        ListNode* result = new ListNode(0);
        ListNode* tail = result;
        while (s.size() > 0) {
            tail->next = new ListNode(s.top());
            s.pop();
            tail = tail->next;
        }

        auto toDelete = result;
        result = result->next;
        delete toDelete;

        return result;
    }

    tuple<ListNode*, ListNode*> reverseList_recur_shit_impl(ListNode* head) {
        ListNode* n = new ListNode(head->val);

        if (head->next == nullptr) {
            // delete makes it a lot slower for some reason
            delete head;
            return {n, n};
        }

        auto [rhead, rtail] = reverseList_recur_shit_impl(head->next);
        delete head;

        rtail->next = n;
        return {rhead, rtail->next};
    }

    // Iterative version (stolen from solutions)
    // Time: O(n)
    // Space: O(1)
    ListNode* reverseList_iter(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            auto n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }

    // Recursive version (stolen from solutions)
    // Time: O(n)
    // Space: O(n)
    ListNode* reverseList(ListNode* head) {
        // Why is this faster than the iterative version?
        if (head == nullptr || head->next == nullptr) return head;
        auto rev = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rev;
    }
};
