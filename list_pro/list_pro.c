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
//时间复杂度O(n)
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
//思路：
//定义两个指针slow和fast，初始时都指向头结点，然后slow每次走一步，fast每次走两步，
//如果他们能够相遇在同一结点，则链表有环
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
//思路：
//使用两个指针先判断是否有环
//设头结点到环形入口的距离为a，环形入口到两个指针相遇结点的距离为b，环的长度为c
//设两指针相遇时，慢指针走的路程为s，则快指针走的路程为2s
//那么有s = a+b+m*c，2s = a+b+n*c
//2(a+b+m*c)=a+b+n*c -> a=(n-2*m)c-b
//再次化解得a=(n-2m-1)c + (c-b)
//由上述公式我们可以的得出
//如果让一个指针从头结点出发，一个指针从他们上次相遇结点出发，速度一样致，
//那么他们再次相遇的地方就是环形链表的入口
//所以步骤为：
//1.双指针找到相遇的结点
//2.让其中一个指针回到头结点
//3.两个指针以同样的速度同时出发
//4.相遇的结点就是环的入口
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
//思路一：通过双循环嵌套遍历每个结点，但双循环嵌套，效率较低。
//思路二：求差法
//l1:       _ _ _ _ _ _ 
//l2: _ _ _ _ _ _ _ _ _>— — — — — — —
//由上图我们可以简单的看出，如果让两个指针分别从两个链表的头结点移动，那么到达公共结点l2比l1多走了l2-l1。
//如果让l2先走l2-l1,然后一起以同样的速度移动，两个指针相遇的结点就是公共结点。
//所以步骤为：
//1：先找出长度较长的链表
//2：让较长的链表先移动两链表长度之差的长度
//3：两链表以同样的速度同时出发，相遇的结点就是公共结点
Node* list_public(Node* head1,Node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    // 计算链表的长度
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    // 找出长度较长的链表
    Node* long_list = len1 > len2 ? head1 : head2;
    Node* short_list = len1 > len2 ? head2 : head1;

    //较长的链表先移动两链表长度之差的长度
    for(int i = 0;i < abs(len1 - len2); i++)
    {
        long_list = long_list->next;
    }

    //两链表以同样的速度同时出发，相遇的结点就是公共结点
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
//写递归我们要有框架思维，不用管一层一层是什么样的，找出规律最重要
//这里的规律就是比较两个结点的大小，然后让上一个已经排好序的结点的下一个结点等于刚刚比较的较小的结点
//写成公式：l->next = func(l1,l2)
//我们在从两个头结点分析
//两个头结点head1，head2，先要比较谁大谁小，才知道谁放前面
//所以两种情况
//head1小，继续比较接下来的两个结点，即套用上面的公式。将head1指向小的，所以我们可以知道最后返回的是小的结点，对于head1和head2来说，head1小，所以return head1;
//head2小，同理
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
//思路一：先遍历整个链表，获取链表的长度n，然后从头再次遍历到n-k个结点
//思路二：查找倒数第K个结点，其实就是查找第n-k个结点，那有没有方法不计算n而查找出n-k呢
//我们先看已知数k，那我们先来试试让一个指针从头结点移动到第k个结点，那么从第k个结点到尾结点就是n-k了
//所以步骤为：
//1.使用两个指针，开始都指向头结点
//2.接着让第一个指针先移动到第k个结点
//3.让两个指针同时移动，当第一个指针移到尾结点时，第二个指针也就指向了倒数第K个结点
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
//思路一：先遍历整个链表，获取链表的长度n，然后从头再次遍历到n/2个结点
//思路二：
//1.两个指针slow和fast指针都先指向头结点，
//2.slow指针每次移动一个结点，fast指针每次移动两个结点，当fast指针移到尾结点的时候，slow刚好移到中间结点
//注意：考虑链表长度的可能是奇数也可能是偶数
//链表长度为奇数时，fast结点移到尾结点时，slow移到中间结点
//链表长度偶数时，中间结点有两个，fast结点移到倒数第二个结点时，slow结点移到较小的中间结点
//时间复杂度O(n)
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
//删除重复的结点，需要判断结点中的数据是否相等，显然需要两个结点，一个指向当前结点cur，一个指向后面的结点sec，然后判断结点上的数据是否相等
//还要考虑重复的数据从头结点开始，如果删了，新的头结点在哪，所以要一个指针备份头结点head_tmp，一个指针pre指向当前结点cur的上一个结点，所以这里需要四个指针
//1.先判断链表是否为空或者是否只含一个结点
//2.定义四个指针head_tmp备份头结点，pre为NULL，cur指向头结点，sec指向头结点的下一个结点
//3.如果cur->data等于sec->data,让sec往后移，直到两个指针指向结点的数据不相等，然后将cur,sec之间的结点都删掉,并将cur指向sec指向的结点。
//  如果第一次即cur指向头结点的时候就执行了这个操作那么pre就是NULL，所以我们需要将head_tmp指向新的头结点cur,否则就将pre->next=cur。
//  但是还没完，先看下pre,cur,sec三个结点的指向，pre->next=cur,cur和sec指向了同一个结点，和最开始的状态不一样，所以要将sec的指向往后移一个结点
//4如果cur->data不等于sec->data，将pre,cur,sec指针都往后移一个结点
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


