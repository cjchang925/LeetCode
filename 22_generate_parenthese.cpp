#include <vector>
#include <string>
using namespace std;

void recur(const int& totalCounter, int leftCounter, int rightCounter, string nowStr, vector<string>& res) {
    if (leftCounter == totalCounter && rightCounter == totalCounter) {
        res.push_back(nowStr);
        return;
    }
    if (leftCounter > totalCounter || rightCounter > totalCounter)
        return;
    if (leftCounter > rightCounter) {
        recur(totalCounter, leftCounter, rightCounter + 1, nowStr + ")", res);
    }
    recur(totalCounter, leftCounter + 1, rightCounter, nowStr + "(", res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    recur(n, 0, 0, "", res);
    return res;
}