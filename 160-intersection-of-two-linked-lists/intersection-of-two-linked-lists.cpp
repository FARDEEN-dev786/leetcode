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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *pa = headA;
    ListNode *pb = headB;
    if(pa==pb) return pa;
    if(pa->next==pb) return pb;
    if(pa == pb->next) return pa;
    int k = 0;
    int c = 0;
    bool papath = false;
    bool pbpath = false;
    while (pa!=nullptr)
    {
        pa = pa->next;
        k++;
    }
    while (pb!=nullptr)
    {
        pb = pb->next;
        c++;
    }
    k = max(c,k);
    pb = headB;
    pa = headA;
    for (int i = 0; i < k; i++)
    {
        while(pa!=nullptr&& pb!=nullptr){
            if(pa==pb){
                return pa;
            }
            pa=pa->next;
            pb = pb->next;
        }
        if(pa==nullptr &&papath==true){
            pa = headA;
            papath=false;
        }
        else if(pa==nullptr && papath==false){
            pa = headB;
            papath=true;
        }
        else if(pb == nullptr && pbpath==true){
            pb = headB;
            pbpath=false;
        }
        else if(pb== nullptr&& pbpath==false){
            pb = headA;
            pbpath=true;
        }
    }
    return nullptr;
}
};