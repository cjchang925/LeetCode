#include <iostream>
#include <map>
#include <vector>

using namespace std;

void recur(map<char, string>& numberToChar, string& digits, int index, string nowStr, vector<string>& res) {
    bool toReturn = false;
    if (index == digits.size() - 1)
        toReturn = true;
    for (auto& ele : numberToChar[digits[index]]) {
        nowStr.push_back(ele);
        if (toReturn) {
            res.push_back(nowStr);
        } else {
            recur(numberToChar, digits, index + 1, nowStr, res);
        }
        nowStr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    map<char, string> numberToChar = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    recur(numberToChar, digits, 0, "", res);
    return res;
}