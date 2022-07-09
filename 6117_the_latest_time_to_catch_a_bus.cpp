#include <vector>
#include <algorithm>

using namespace std;

struct Bus {
    int time;
    vector<int> passengers;
    int already;
};

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    vector<Bus> vec;
    for (auto& bus : buses) {
        vec.push_back(Bus{bus, vector<int>(), 0});
    }
    int v_index = 0;
    for (auto& pass : passengers) {
        for (; v_index < vec.size(); v_index++) {
            if (pass <= vec[v_index].time && vec[v_index].already < capacity) {
                vec[v_index].passengers.push_back(pass);
                vec[v_index].already++;
                break;
            }
        }
    }
    if (vec.back().already < capacity) {
        for (int i = vec.back().time; i >= 0; --i) {
            if (find(vec.back().passengers.begin(), vec.back().passengers.end(), i) == vec.back().passengers.end()) {
                return i;
            }
        }
    }
    for (int i = 0; i < passengers.size(); ++i) {
        if (passengers[i] == vec.back().passengers.back()) {
            for (int j = i; j > 0; j--) {
                if (passengers[j] != passengers[j - 1] + 1) {
                    return passengers[j] - 1;
                }
            }
            return passengers[0] - 1;
        }
    }
    return 0;
}