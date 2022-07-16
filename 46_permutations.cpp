#include <vector>
#include <iostream>
using namespace std;

vector<int> permutation(vector<int> A) {
    int length = A.size();
    int j = 0, j_max = 0, k = 0, k_max = 0;
    vector<int> res(A);
    for (j = 0; j < length - 1; j++) {
        if (res[j] < res[j + 1]) {
            j_max = j;
        }
    }
    for (k = 0; k < length; k++) {
        if (res[k] > res[j_max]) {
            k_max = k;
        }
    }
    int temp = res[j_max];
    res[j_max] = res[k_max];
    res[k_max] = temp;
    for (int n = 1; j_max + n <= length - n; n++) {
        int temp = res[j_max + n];
        res[j_max + n] = res[length - n];
        res[length - n] = temp;
    }
    return res;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    int length = nums.size();
    int times = 1;
    for (int i = 2; i <= length; ++i) {
        times *= i;
    }
    for (int i = 0; i < times; ++i) {
        res.push_back(nums);
        nums = permutation(nums);
    }
    return res;
}

int main() {
    vector<int> vec = {1, 2, 3};
    auto res = permute(vec);
    for (auto& v : res) {
        for (auto& ele : v) {
            cout << ele << ' ';
        }
        cout << endl;
    }
}