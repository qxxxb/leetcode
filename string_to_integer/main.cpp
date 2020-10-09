#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }

        int sign = 1;
        switch (s[i]) {
            case '-':
                sign = -1;
                i++;
                break;
            case '+':
                i++;
                break;
        }

        int result = 0;
        while (isdigit(s[i])) {
            if (result > INT_MAX / 10) return INT_MAX;
            else if (result < INT_MIN / 10) return INT_MIN;
            result *= 10;

            int d = sign * (s[i] - '0');

            if (d > 0 && result > INT_MAX - d) return INT_MAX;
            else if (d < 0 && result < INT_MIN - d) return INT_MIN;

            result += d;
            i++;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    string a = "-91283472332";
    auto s = Solution();
    cout << s.myAtoi(a) << endl;
    return 0;
}
