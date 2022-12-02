#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    int size = s.size();
    vector<vector<bool>> dp(size);
    for (auto& vec : dp) vec.resize(size);
    int max = -1;
    string res;
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (i > j) break;
            else if (s[i] == s[j] && (i == j || j - i == 1 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (j - i + 1 > max) {
                    max = j - i + 1;
                    res = string(s.begin() + i, s.begin() + j + 1);
                }
            }
        }
    }
    return res;
}

int main() {
    cout << longestPalindrome("");
}