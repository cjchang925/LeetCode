#include <string>

using namespace std;

bool canChange(string start, string target) {
    int s_ = 0;
    int t_ = 0;

    while (true) {
        while (s_ < start.size() && start[s_] == '_') {
            if (s_ == start.size() - 1) {
                break;
            }
            s_++;
        }
        while (t_ < target.size() && target[t_] == '_') {
            if (t_ == target.size() - 1) {
                break;
            }
            t_++;
        }
        if (s_ < start.size() && t_ < target.size() && start[s_] != target[t_]) return false;
        if (s_ < start.size() && t_ < target.size() && start[s_] == 'L' && s_ < t_) return false;
        if (s_ < start.size() && t_ < target.size() && start[s_] == 'R' && s_ > t_) return false;
        if (s_ >= start.size() - 1 && t_ >= target.size() - 1) break;
        s_++;
        t_++;
    }
    return true;
}