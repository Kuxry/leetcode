#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // 判断是否有环
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // 相遇，表示有环
                // 从头结点和相遇点同时查找，直至相遇
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口点
            }
        }
        
        return NULL; // 没有环
    }
};

// 测试代码
int main() {
    // 创建一个有环的链表
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // 形成环
    
    Solution sol;
    ListNode* cycleEntry = sol.detectCycle(head);
    
    if (cycleEntry != NULL) {
        std::cout << "环的入口点值为: " << cycleEntry->val << std::endl;
    } else {
        std::cout << "链表中没有环." << std::endl;
    }
    
    return 0;
}
