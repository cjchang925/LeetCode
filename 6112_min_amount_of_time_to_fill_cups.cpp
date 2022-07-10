#include <vector>
#include <algorithm>

using namespace std;

int fillCups(vector<int>& amount) {
    size_t size = amount.size();
    int total = 0;
    while (true) {
        auto max = max_element(amount.begin(), amount.end());
        int max_tmp = *max;
        if (max_tmp == 0) break;
        amount.erase(max);
        auto second = max_element(amount.begin(), amount.end());
        if (*second == 0) {
            return total + max_tmp;
        }
        amount.push_back(max_tmp - 1);
        (*second)--;
        total++;
    }
    return total;
}