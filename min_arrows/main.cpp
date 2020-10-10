#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto f = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), f);

        int result = 0;
        size_t i = 0;

        while (i < points.size()) {
            int arrow = points[i][1];
            cout << arrow << endl;
            result++;

            // pop balloons
            while (true) {
                i++;
                if (i >= points.size()) break;

                if (points[i][0] > arrow) {
                    // can't pop anymore, pick next arrow
                    break;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> ps = {
        {0, 2},
        {1, 2},
        {2, 4},
        {3, 5},
        {3, 5},
    };

    // vector<vector<int>> ps = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};

    auto s = Solution();
    cout << s.findMinArrowShots(ps) << endl;
    return 0;
}
