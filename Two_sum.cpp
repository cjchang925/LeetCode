#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> org(nums);
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(nums[i] + nums[j] == target) {
                vector<int> v = {-1, -1};
                for(int k = 0; k < size; k++) {
                    if(org[k] == nums[i]) {
                        v[0] = k;
                        nums[i] = -1000000;
                    }
                    else if(org[k] == nums[j]) {
                        v[1] = k;
                        nums[j] = -1000000;
                    }
                }
            }
            if(nums[i] + nums[j] > target) {
                break;
            }
        }
    }
    return {};
}

int main()
{
    vector<int> v = twoSum({3, 3}, 6);
    for(auto& ele : v) {
        cout << ele << ' ';
    }
}

