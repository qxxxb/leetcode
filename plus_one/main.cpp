#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto res = digits;

        for (int i = res.size() - 1; i > 0; i--) {
            int d = res[i];
            if (d < 9) {
                res[i] = d + 1;
                return;
            } else {
                res[i] = 0;
                if (i == 0) {
                    res.push_back(1);
                    swap(res[0], res.back());
                }
            }
        }

        return res;
    }
};
