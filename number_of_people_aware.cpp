#include <iostream>
#include <vector>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> peopleKnowing(n + 1);
    peopleKnowing[1] = 1;
    for(int i = 1; i < n + 1; ++i) {
        // for each day
        for(int j = i - forget + 1; j <= i - delay; ++j) {
            if(j < 1)
                continue;
            peopleKnowing[i] += peopleKnowing[j];
        }
        peopleKnowing[i] %= int(1e9 + 7);
    }
    long long res = 0;
    for(int i = n - forget + 1; i < n + 1; ++i) {
        res += peopleKnowing[i];
    }
    return res % int(1e9 + 7);
}