#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> alist(n);
        for (auto road : roads) {
            alist[road[0]].insert(road[1]);
            alist[road[1]].insert(road[0]);
        }

        for (size_t i = 0; i < alist.size(); ++i) {
            cout << i << ": ";
            for (auto x : alist[i]) {
                cout << x << " ";
            }
            cout << endl;
        }

        // TODO: sort and Do not check lower values

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int deg = alist[i].size() + alist[j].size();
                if (alist[i].count(j) > 0) deg--;
                result = max(result, deg);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    auto s = Solution();
    cout << s.maximalNetworkRank(4, roads) << endl;
    return 0;
}
