#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

// 5 2 8 3 6 2 1 3 3 5 1 6 8 9
// 5 2 8 3 6 2 1 9 3 5 1 6 8

class Solution {
public:
    int singleNumber_set(vector<int>& nums) {
        unordered_set<int> h;
        for (auto num : nums) {
            if (h.count(num) > 0) {
                h.erase(num);
            } else {
                h.insert(num);
            }
        }

        assert(h.size() == 1);
        auto it = h.begin();
        return *it;
    }

    int singleNumber(vector<int>& nums) {
        unordered_set<int> h;
        while (nums.size() > 0) {
            int back = nums.back();
            nums.pop_back();
            if (h.count(back) > 0) {
                // Found second
                h.erase(back);
            } else {
                h.insert(back);
            }
        }

        assert(h.size() == 1);
        auto it = h.begin();
        return *it;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {5, 2, 8, 3, 6, 2, 1, 9, 3, 5, 1, 6, 8};
    auto s = Solution();
    cout << s.singleNumber(a) << endl;
    return 0;
}
