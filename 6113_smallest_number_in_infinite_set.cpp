#include <vector>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        inf = vector<int>(1000);
        for (int i = 0; i < 1000; i++) {
            inf[i] = i + 1;
        }
    }
    
    int popSmallest() {
        for (auto& ele : inf) {
            if (ele != -1) {
                int tmp = ele;
                ele = -1;
                return tmp;
            }
        }
        return 0;
    }
    
    void addBack(int num) {
        inf[num - 1] = num;
    }
    vector<int> inf;
};