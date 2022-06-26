#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    static void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> n = {1, 2, 3, 4, 5, 6};
    Solution::rotate(n, 3);
    for(auto ele : n)
        cout << ele << ' ';
}