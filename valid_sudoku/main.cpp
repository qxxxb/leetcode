#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> h;

        for (int i = 0; i < board.size(); i++) {
            auto& row = board[i];
            for (char x : row) {
                if (x == '.') continue;
                if (h.count(x) > 0) return false;
                h.insert(x);
            }
            h.clear();
        }

        for (int col = 0; col < board[0].size(); col++) {
            for (int row = 0; row < board.size(); row++) {
                char x = board[row][col];
                if (x == '.') continue;
                if (h.count(x) > 0) return false;
                h.insert(x);
            }
            h.clear();
        }

        for (int sq = 0; sq < 9; sq++) {
            int row_start = (sq / 3) * 3;
            int col_start = (sq % 3) * 3;
            for (int sq_row = 0; sq_row < 3; sq_row++) {
                for (int sq_col = 0; sq_col < 3; sq_col++) {
                    int row = row_start + sq_row;
                    int col = col_start + sq_col;
                    char x = board[row][col];
                    if (x == '.') continue;
                    if (h.count(x) > 0) return false;
                    h.insert(x);
                }
            }
            h.clear();
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','2','5'},
        {'.','.','.','.','8','.','1','7','9'},
    };

    auto s = Solution();
    cout << s.isValidSudoku(board) << endl;
    cout << s.isValidSudoku(board1) << endl;

    return 0;
}

