#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* ptr = head;
        while (true) {
            if (ptr == NULL) return false;
            size_t prevSize = s.size();
            s.insert(ptr);
            if (prevSize == s.size()) return true;
        }
    }
};
