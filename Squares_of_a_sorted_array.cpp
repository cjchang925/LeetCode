#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int> sortedSquares(vector<int> nums) {
        int start_index = 0;
        int size = nums.size();
        for(int i = 0; i < size - 1; i++){
            if (nums[i] <= 0 && nums[i + 1] >= 0){
                int a = abs(nums[i]);
                int b = abs(nums[i + 1]);
                start_index = (a > b ? i + 1 : i);
                break;
            }
        }
        if (start_index == 0 && nums.back() < 0){
            start_index = size - 1;
        }
        int front = start_index + 1;
        int rear = start_index - 1;
        vector<int> res = {int(pow(abs(nums[start_index]), 2))};
        while(true){
            if(front < size && rear >= 0){
                int a = abs(nums[front]);
                int b = abs(nums[rear]);
                if(a > b){
                    res.push_back(b * b);
                    rear--;
                }
                else{
                    res.push_back(a * a);
                    front++;
                }
            }
            else if(front < size){
                int a = abs(nums[front]);
                res.push_back(a * a);
                front++;
            }
            else if(rear >= 0){
                int a = abs(nums[rear]);
                res.push_back(a * a);
                rear--;
            }
            else{
                break;
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec = Solution::sortedSquares({-1, 2, 2});
    int i = 0;
}