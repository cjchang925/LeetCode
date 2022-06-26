#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                i++;
            } else {
                return nums[i];
            }
        }
        return nums[size - 1];
    }
};

int singleNumber(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            i++;
        } else {
            return nums[i];
        }
    }
    return nums[size - 1];
}

int main() {
    cout << singleNumber({1});
}