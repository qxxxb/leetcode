#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }

        return i >= j;
    }

    bool check(string& a, string& b) {
        int i = 0;
        int j = a.length() - 1;

        while (i < j && a[i] == b[j]) {
            i++;
            j--;
        }

        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    // Stolen from discussion
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};

int main(int argc, char *argv[])
{
    // string a = "abcdefe7890";
    // string b = "0123456dcba";

    // string a = "1";
    // string b = "2";

    // string a = "ulacfd";
    // string b = "jizalu";

    string a = "pvhmupgqeltozftlmfjjde";
    string b = "yjgpzbezspnnpszebzmhvp";

    auto s = Solution();
    cout << s.checkPalindromeFormation(a, b) << endl;
    return 0;
}
