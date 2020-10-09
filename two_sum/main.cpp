#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value -> [ indices ]
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (m.count(diff) > 0) {
                auto ii = m[diff];
                return {i, ii};
            }

            m[nums[i]] = i;
        }

        throw new invalid_argument("No two sum provided");
    }
};

int main(int argc, char const *argv[])
{
    auto s = Solution();

    vector<int> a = {-3, 3, 2, 5, 9, 7, -1, 13};
    auto b = s.twoSum(a, 9);

    cout << b[0] << ", " << b[1] << endl;

    return 0;
}
