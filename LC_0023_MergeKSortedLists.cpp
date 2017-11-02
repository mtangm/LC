/*
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    class NodeCompare
    {
    public:
        bool operator()(const ListNode* n1, const ListNode* n2)
        {
            return n1->val > n2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> heap;
        
        ListNode dummy(0);
        ListNode *prev = &dummy;
        
        for (const auto& n : lists)
        {
            if (n) heap.push(n);
        }
        
        while (!heap.empty())
        {
            ListNode* curr = heap.top();
            heap.pop();
            prev->next = curr;
            prev = curr;
            
            if (curr->next) heap.push(curr->next);
        }
        
        return dummy.next;
    }
    
    
};
