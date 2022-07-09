#include <iostream>
#include <vector>

using namespace std;

void run(vector<vector<int>>& result, const vector<int>& candidates, vector<int> nowVec, const size_t& size, size_t index, int nowSum, const int& target) {
    if (nowSum == target) {
        result.push_back(move(nowVec));
        return;
    }
    if (nowSum > target)
        return;
    for (size_t i = index; i < size; ++i) {
        if (nowSum + candidates[i] <= target) {
            nowVec.push_back(candidates[i]);
            run(result, candidates, nowVec, size, i, nowSum + candidates[i], target);
            nowVec.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    run(result, candidates, {}, candidates.size(), 0, 0, target);
    return result;
}