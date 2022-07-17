#include <vector>
#include <algorithm>

using namespace std;

vector<int> numberOfPairs(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<int> res(2);
    int i = 0;
    for (; i < size - 1;) {
        if (nums[i] == nums[i + 1]) {
            res[0]++;
            i += 2;
        } else {
            res[1]++;
            i++;
        }
    }
    if (i == size - 1) {
        res[1]++;
    }
    return res;
}