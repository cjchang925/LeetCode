#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    static int dp(vector<int>& nums, int index, unordered_map<int, int>& memo)
    {
        int size = nums.size();

        // pick this element
        int pick = nums[index] * count(nums.begin(), nums.end(), nums[index]);
        for(int i = index + 1; i < size; i++){
            if(nums[i] != nums[index] && nums[i] != nums[index] + 1){
                if(memo.find(nums[i]) == memo.end()){
                    memo.insert(pair<int, int>(nums[i], dp(nums, i, memo)));
                }
                pick += memo[nums[i]];
                break;
            }
        }

        // not pick
        int n = 0;
        for(int i = index + 1; i < size; i++){
            if(nums[i] != nums[index]){
                if(memo.find(nums[i]) == memo.end()){
                    memo.insert(pair<int, int>(nums[i], dp(nums, i, memo)));
                }
                n += memo[nums[i]];
                break;
            }
        }

        return max(pick, n);
    }
    static int deleteAndEarn(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> memo;
        return dp(nums, 0, memo);
    }
};

int main()
{
    vector<int> vec = {2,2,3,3,3,4};
    cout << Solution::deleteAndEarn(vec);
}