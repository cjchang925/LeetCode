#include <vector>
#include <algorithm>

using namespace std;

int calculate(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

int maximumSum(vector<int>& nums) {
    vector<pair<int, int>> res;
    int numsize = nums.size();
    for (int i = 0; i < numsize; ++i) {
        res.push_back({calculate(nums[i]), nums[i]});
    }
    sort(res.begin(), res.end(), compare);
    vector<int> v;
    int nowFirst = res[0].first;
    vector<int> tmp;
    for (int i = 0; i < numsize; ++i) {
        if (res[i].first == nowFirst) {
            tmp.push_back(res[i].second);
        } else {
            if (tmp.size() >= 2) {
                auto max = max_element(tmp.begin(), tmp.end());
                int m = *max;
                tmp.erase(max);
                auto sec = max_element(tmp.begin(), tmp.end());
                v.push_back(m + (*sec));
            }
            tmp.clear();
            nowFirst = res[i].first;
            tmp.push_back(res[i].second);
        }
    }
    if (tmp.size() >= 2) {
        auto max = max_element(tmp.begin(), tmp.end());
        int m = *max;
        tmp.erase(max);
        auto sec = max_element(tmp.begin(), tmp.end());
        v.push_back(m + (*sec));
    }
    if (!v.empty()) {
        return *max_element(v.begin(), v.end());
    }
    return -1;
}