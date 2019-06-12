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
//
Node* list_reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
         return head;
    }
    Node* p = head;
    Node* q = head->next;
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
//思路：定义两个指针slow和fast，初始时都指向头结点，然后slow每次走一步，fast每次走两步，如果他们能够相遇在同一结点，则链表有环
bool has_cycle(Node* head)
{
    if(head == NULL || head->next==NULL)
        return false;
    Node* slow = head;
    Node* fast = head;
    while(slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

//查找环形入口
//思路：使用两个指针先判断是否有环
//设头结点到环形入口的距离为a，环形入口到两个指针相遇结点的距离为b，环的长度为c
//设两指针相遇时，慢指针走的路程为s，则快指针走的路程为2s
//那么有s = a+b+m*c，2s = a+b+n*c
//2(a+b+m*c)=a+b+n*c -> a=(n-2*m)c-b
//再次化解得a=(n-2m-1)c + (c-b)
//由上述公式我们可以的得出
//如果让一个指针从头结点出发，一个指针从他们上次相遇结点出发，速度一样致，
//那么他们再次相遇的地方就是环形链表的入口
Node* cycle_entry(Node* head)
{
    if(head == NULL || head->next==NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* meet = NULL;
    while(slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow && fast)
    {
        if(slow == head)
            return head;
        slow = head;
        //fast = fast->next;
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
Node* list_public(Node* head1,Node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    Node* long_list = len1 > len2 ? head1 : head2;
    Node* short_list = len1 > len2 ? head2 : head1;

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
Node* merge_two_list(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data < head2->data)
    {
        head1->next=merge_two_list(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=merge_two_list(head1,head2->next);
        return head2;
    }
}

//查找倒数第K个结点
//两个指针
//时间复杂度O(n)
Node* last_k(Node* head, int k)
{
    if(head == NULL)
        return NULL;
    Node* src = head;
    Node* dst = head;
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

//查找中间结点, 如果中间结点为两个，返回较小的那个
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

//删除有序链表重复结点
//删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
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


