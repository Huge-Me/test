/* 给你两个 非空 的链表，表示两个非负的整数。
它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 1;
        int n2 = 1;
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != nullptr)
        {
            n1 ++;
            p = p->next;
        }
        while(q->next != nullptr){
            n2 ++;
            q = q->next;
        }
        if(n1 > n2){
            for(int i = 1;i <= n1 - n2;i ++){
                ListNode *q1 = new ListNode(0);
                q->next = q1;
                q = q->next;
            }
        }
        else{
            for(int i = 1;i <= n2 - n1;i ++){
                ListNode *p1 = new ListNode(0);
                p->next = p1;
                p = p->next;
            }
        }
        p = l1;
        q = l2;
        ListNode *l3 = new ListNode(-1);
        ListNode *bt = l3;
        bool count = false;
        int i = 0;
        while(p != nullptr && q != nullptr){
            i = count + p->val + q->val;
            bt->next = new ListNode(i % 10);
            if(i >= 10){
                count = true;
            }
            else
                count = false;
            bt = bt->next;
            p = p->next;
            q = q->next;
        }
        if(count){
            bt->next = new ListNode(1);
            bt = bt->next;
        }
        return l3->next;
    }
};