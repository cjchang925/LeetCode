#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* res = new ListNode(0);
    ListNode* curr = res;
    while (true) {
        int min = INT_MAX;
        for (auto& ptr : lists) {
            if (ptr != NULL && ptr->val < min) min = ptr->val;
        }
        if (min == INT_MAX) break;
        curr->next = new ListNode(min);
        curr = curr->next;
        for (auto& ptr : lists) {
            if (ptr != NULL && ptr->val == min) {
                ptr = ptr->next;
                break;
            }
        }
    }
    return res->next;
}

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);
    
    vector<ListNode*> vec = {a, b, c};

    ListNode* res = mergeKLists(vec);

    return 0;
}