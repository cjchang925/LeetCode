#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        for(int i = 2; i < size; i++){
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[size - 1], cost[size - 2]);
    }
};

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << Solution::minCostClimbingStairs(cost);
}