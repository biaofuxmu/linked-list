#include "list_pro.h"

//获取链表长度
size_t list_len(Node* head)
{
    int len = 0;
    while(head)
    {
        head = head->next;
        len++;
    }
    return len;
}

//链表反转
Node* list_reverse(Node* list)
{
    if(list == NULL || list->next == NULL)
    {
         return list;
    }
    Node* p = list;
    Node* q = list->next;
    Node* r = q->next;

    p->next = NULL;
    while(r)
    {
        q->next = p;
        p = q;
        q = r;
        r = q->next;
    }
    q->next = p;

    return q;
}

//判断链表是否有环
//思路：先判断链表的长度是否>1
//定义两个指针，一个指向头结点slow，一个指向头结点的下一个结点fast，然后slow每次走一步，fast每次走两步，如果有环，则它们将会相遇
bool has_cycle(Node* list)
{
    if(list == NULL || list->next==NULL)
        return false;
    Node* slow = list;
    Node* fast = list->next;
    while(slow && fast->next)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

//查找环形入口
Node* cycle_entry(Node* list)
{
    if(list == NULL || list->next==NULL)
        return false;
    Node* slow = list;
    Node* fast = list->next;
    Node* meet = NULL;
    while(slow && fast->next)
    {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow && fast)
    {
        if(slow == list)
            return list;
        slow = list;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}

//查找公共结点
Node* list_public_1(Node* list1,Node* list2)
{
    if(list1 == NULL || list2 == NULL)
        return NULL;
    int len1 = list_len(list1);
    int len2 = list_len(list2);
    int length = 0;
    Node* long_list = NULL;
    Node* short_list = NULL;
    if(len1 > len2)
    {
        long_list = list1;
        short_list = list2;
        length = len1 - len2;
    }
    else
    {
        long_list = list2;
        short_list = list1;
        length = len2 - len1;
    }
    for(int i = 0;i < length; i++)
    {
        long_list = long_list->next;
    }
    while(short_list && long_list)
    {
        if(short_list == long_list)
            return short_list;
        short_list = short_list->next;
        long_list = long_list->next;
    }
    return NULL;
}

//查找公共结点
Node* list_public(Node* list1,Node* list2)
{
    if(list1 == NULL || list2 == NULL)
        return NULL;
    int len1 = list_len(list1);
    int len2 = list_len(list2);

    Node* long_list = len1 > len2 ? list1 : list2;
    Node* short_list = len1 > len2 ? list2 : list1;

    for(int i = 0;i < abs(len1 - len2); i++)
    {
        long_list = long_list->next;
    }
    while(short_list && long_list)
    {
        if(short_list == long_list)
            return short_list;
        short_list = short_list->next;
        long_list = long_list->next;
    }
    return NULL;
}

//合并两个有序链表(从小到大排列)
//先比较头结点 如果list1大，那么list1就是头结点，他下个节点就list1->next和list2的小的哪个节点，递归
Node* merge_two_list(Node* list1, Node* list2)
{
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->data < list2->data)
    {
        list1->next=merge_two_list(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next=merge_two_list(list1,list2->next);
        return list2;
    }
}

//查找倒数第K个结点
//两个指针
//时间复杂度O(n)
Node* last_k(Node* list, int k)
{
    if(list == NULL)
        return NULL;
    Node* src = list;
    Node* dst = list;
    for(int i=0;i<k-1;i++)
    {
        if(src)
            src = src->next;
        else
            return NULL;
    }
    while(src->next)
    {
        src = src->next;
        dst = dst->next;
    }
    return dst;
}

//删除重复结点
Node* del_repeat(Node* head)
{
    if(head == NULL || head->next==NULL)
        return head;
    Node* pre = NULL;
    Node* head_tmp = head;
    Node* cur = head;
    Node* sec = head->next;
    while(sec)
    {
        if(cur->data == sec->data)
        {
            sec = sec->next;
            while(sec && cur->data==sec->data)
            {
                sec = sec->next;
            }
            while(cur != sec)
            {
                Node* tmp = cur;
                cur = cur->next;
                free(tmp);
            }
            if(pre == NULL)
                head_tmp = cur;
            else
                pre->next=cur;
            if(sec)
                sec = sec->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
            sec = sec->next;
        }
    }
    return head_tmp;
}

//查找中间结点
//双指针法
Node* find_middle(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
