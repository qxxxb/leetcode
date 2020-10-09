#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;

        int i = 0;

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] == needle[j]) {
                    if (j == needle.length() - 1) {
                        return i;
                    }
                } else {
                    break;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cerr << "Invalid number of arguments" << endl;
        return 1;
    }

    auto s = Solution();
    cout << s.strStr(argv[1], argv[2]) << endl;
    return 0;
}
