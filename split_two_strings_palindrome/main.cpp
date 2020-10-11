#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Solution {
public:
    int midPal(const string& s) {
        int mid = (s.length() - 1) / 2;
        int l = mid;
        int h = mid + 1;
        if (s.length() % 2 == 1) {
            l--;
        }
        cout << l << " " << h << endl;

        while (true) {
            if (l < 0) return -1;
            if (h > (int)s.length() - 1) return -1;
            if (s[l] != s[h]) break;
            l--;
            h++;
        }

        return mid - l;
    }

    bool checkPalSides(string_view a, string_view b) {
        int l = 0;
        int r = b.length() - 1;

        while (true) {
            if (l >= (int)a.length()) return true;
            if (r < 0) return true;
            if (a[l] != b[r]) return false;
            l++;
            r--;
        }
    }

    bool checkPal(const string& a, const string& b) {
        int amid = (a.length() - 1) / 2;

        int amp = midPal(a);
        cout << "midPal: " << amp << endl;
        if (amp == -1) return true;
        int al = amid - amp;
        int ar = amid + amp;
        if (a.length() % 2 == 0) {
            ar++;
        }

        cout << "al ar: " << al << " " << ar << endl;
        cout << "al ar: " << a[al] << " " << b[ar] << endl;

        string_view als(&a[0], al + 1);
        string_view ars(&a[ar], al + 1);
        string_view bls(&b[0], al + 1);
        string_view brs(&b[ar], al + 1);

        return checkPalSides(als, brs) || checkPalSides(ars, bls);
    }

    bool checkPalindromeFormation(string a, string b) {
        return checkPal(a, b) || checkPal(b, a);
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
