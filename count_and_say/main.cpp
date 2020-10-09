#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string nextCS(string s) {
        string result = "";

        char d = s[0];
        int n = 1;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                n++;
            } else {
                result.push_back(n + '0');
                result.push_back(d);
                n = 1;
                d = s[i + 1];
            }
        }

        result.push_back(n + '0');
        result.push_back(d);

        return result;
    }

    string countAndSay(int n) {
        string result = "1";
        for (int i = 0; i < n - 1; i++) {
            result = nextCS(result);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    auto s = Solution();
    cout << s.countAndSay(5) << endl;
    return 0;
}

