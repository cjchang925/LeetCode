#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    int left = 0;
    int right = 0;
    int max = -2147483647;
    unordered_set<char> se;

    while (right < size) {
        if (se.find(s[right]) == se.end()) {
            se.insert(s[right]);
            if (max < right - left + 1) max = right - left + 1;
        }
        else {
            while (s[left] != s[right]) {
                se.erase(se.find(s[left]));
                left++;
            }
            left++;
        }
        right++;
    }

    return max;
}

int main() {
    cout << lengthOfLongestSubstring("pwwkew");
}