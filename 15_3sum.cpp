#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int size = nums.size();

    for (int i = 0; i < size; ++i) {
        int target = -nums[i];
        int front = i + 1;
        int back = size - 1;

        while (front < back) {
            int tempsum = nums[front] + nums[back];
            if (tempsum < target) {
                front++;
            } else if (tempsum > target) {
                back--;
            } else {
                vector<int> v = {nums[i], nums[front], nums[back]};
                res.push_back(v);
                front++;
                while (front < back && front - 1 >= 0 && nums[front] == v[1]) {
                    front++;
                }
                back--;
                while (front < back && back + 1 < size && nums[back] == v[2]) {
                    back--;
                }
            }
        }

        while (i + 1 < size && nums[i] == nums[i + 1]) {
            i++;
        }
    }
    
    return res;
}