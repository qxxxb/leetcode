#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& m) {
        for (int coli = 0; coli < m.size(); coli++) {
            for (int rowi = coli; rowi < m[coli].size(); rowi++) {
                if (coli != rowi) {
                    swap(m[rowi][coli], m[coli][rowi]);
                }
            }
        }
    }

    void reverse(vector<int>& v) {
        int l = 0;
        int h = v.size() - 1;
        while (l < h) {
            swap(v[l], v[h]);
            l++;
            h--;
        }
    }

    void reverse_rows(vector<vector<int>>& m) {
        for (int i = 0; i < m.size(); i++) {
            reverse(m[i]);
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_rows(matrix);
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> m = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> m(4, vector<int>(4, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = (i * 4) + j;
        }
    }

    auto s = Solution();
    s.rotate(m);

    for (auto row : m) {
        for (auto x : row) {
            cout.width(2);
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

