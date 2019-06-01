#ifndef __LIST_PRO_H_
#define __LIST_PRO_H_

//结点结构体
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//链表反转
Node* list_reverse(Node* list);

//判断链表是否有环
//思路：先判断链表的长度是否>1
//定义两个指针，一个指向头结点slow，一个指向头结点的下一个结点fast，然后slow每次走一步，fast每次走两步，如果有环，则它们将会相遇
bool has_cycle(Node* list);

//查找环形入口
Node* cycle_entry(Node* list);

//查找公共结点
Node* list_public(Node* list1,Node* list2);

//查找公共结点
Node* list_public(Node* list1,Node* list2);

Node* merge_two_list(Node* list1, Node* list2);

//查找倒数第K个结点
//两个指针
//时间复杂度O(n)
Node* last_k(Node* list, int k);

//删除重复结点
Node* del_repeat(Node* head);

//查找中间结点
//双指针法
Node* find_middle(Node* head);

#endif//__LIST_PRO_H_