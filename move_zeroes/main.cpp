#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    // My first attempt
    // Time: O(n^2) I think?
    // Space: O(1)
    void moveZeroes_mine(vector<int>& nums) {
        int tail = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                // continue
                if (tail != -1) {
                    // swap left until tail
                    for (int j = i; j < tail; j++) {
                        swap(nums[j], nums[j + 1]);
                    }
                    tail--;
                }
            } else {
                if (tail == -1) {
                    tail = i;
                }
            }
        }
    }

    // Stolen from solutions
    // Time: O(n)
    // Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int toRep = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[toRep++] = nums[i];
            }
        }

        memset(&nums[toRep], 0, (nums.size() - toRep) * sizeof(int));
    }
};

int main(int argc, char const *argv[])
{
    auto s = Solution();
    vector<int> a = {0, 1, 0, 3, 12};
    s.moveZeroes(a);
    for (auto x : a) cout << x << " ";
    cout << endl;
    return 0;
}
