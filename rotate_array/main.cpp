#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // int imod(int x, int y) {
    //     if (x > 0) return x % y;
    //     else return (x % y) + y;
    // }

    // // Not working
    // void rotate_divs(vector<int>& nums, int k) {
    //     int n_sets = ((nums.size() - 1) / k) + 1;

    //     for (int ki = 0; ki < k; ki++) {
    //         int i = ki;
    //         int first = nums[i];
    //         for (int set = 0; set < n_sets - 1; set++) {
    //             int left_i = imod(i - k, nums.size());
    //             nums[i] = nums[left_i];
    //             i = left_i;
    //         }

    //         nums[i] = first;
    //     }
    // }

    // Cyclic replacements
    // Time: O(n)
    // Space: O(1)
    void rotate_cyclic(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;

        int n_reps = 0;
        int inner_start = 0;

        while (true) {
            int prev = inner_start;
            int prev_val = nums[prev];
            while (true) {
                int cur = (prev + k) % nums.size();
                swap(nums[cur], prev_val);
                n_reps++;
                if (cur == inner_start) break;
                prev = cur;
            }

            if (n_reps == nums.size()) return;
            inner_start++;
        }
    }

    // Reverse numbers in range [start, end]
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Rotate by reversing part of the array
    // Time: O(n)
    // Space: O(1)
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a(14, 0);
    for (int i = 0; i < a.size(); i++) {
        a[i] = i;
    }

    auto s = Solution();
    for (int k = 0; k < a.size(); k++) {
        auto b = a;
        s.rotate(b, k);
        cout << k << ": ";
        for (auto x : b) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
