#include <vector>
#include <iostream>
using namespace std;

#define LEFT 98
#define RIGHT 99
#define UP 100
#define DOWN 101

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> map(m);
    for(auto& ele : map) {
        ele.resize(n);
        for(auto& e : ele) {
            e = -1;
        }
    }
    int x = 0, y = 0;
    int direction = RIGHT;

    while(head != NULL) {
        map[x][y] = head->val;
        head = head->next;
        if(direction == RIGHT) {
            if(y + 1 >= n || map[x][y + 1] != -1) {
                direction = DOWN;
                ++x;
                continue;
            }
            ++y;
        } else if(direction == DOWN) {
            if(x + 1 >= m || map[x + 1][y] != -1) {
                direction = LEFT;
                --y;
                continue;
            }
            ++x;
        } else if(direction == LEFT) {
            if(y - 1 < 0 || map[x][y - 1] != -1) {
                direction = UP;
                --x;
                continue;
            }
            --y;
        } else if(direction == UP) {
            if(x - 1 < 0 || map[x - 1][y] != -1) {
                direction = RIGHT;
                ++y;
                continue;
            }
            --x;
        }
    }
    return map;
}