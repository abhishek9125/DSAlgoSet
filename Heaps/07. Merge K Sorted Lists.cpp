#include<bits/stdc++.h>
using namespace std;

class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }

};

class Solution {
public:

    ListNode* mergeKSortedLists(vector<ListNode*> &head) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        if(head.size() == 0) return nullptr;

        for(int i = 0; i < head.size(); i++) {
            pq.push(head[i]);
        }

        ListNode* headMain = nullptr;
        ListNode* tail = nullptr;

        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            if(headMain == nullptr) {
                headMain = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }

            if(top->next) {
                pq.push(top->next);
            }

        }

        return headMain;

    }
};