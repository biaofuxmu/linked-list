#include "list_pro.h"
//测试链表常见笔试题的各个函数

//创建结点
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));//申请内存
    node->data = data;
    node->next = NULL;
}

//创建长度为num的链表
Node* create_list(int num)
{
    Node* head = create_node(1);//创建头结点
    Node* tmp = head;//初始化tmp指针指向头结点,也表示头结点
    for (int i = 2; i <= num; ++i)
    {
        Node* node = create_node(i);//创建新结点
        tmp->next = node;//头结点的下一个结点等于新结点
        tmp = node;//tmp指针指向新结点
    }
    return head;
}

//显示链表的数据
void show_list(Node* head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void test_list_reverse()
{
    Node * head = create_list(10);
    show_list(head);
    printf("reverse list----------------------------------\n");
    head = list_reverse(head);
    show_list(head);
}


int main()
{
    test_list_reverse();

}