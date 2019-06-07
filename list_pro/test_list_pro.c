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
    Node* head = create_list(10);
    show_list(head);
    printf("reverse list----------------------------------\n");
    head = list_reverse(head);
    show_list(head);
}

void test_cycle_list()
{
    Node* head1 = create_node(1);
    Node* head2 = create_node(2);
    Node* head3 = create_node(3);
    Node* head4 = create_node(4);
    Node* head5 = create_node(5);
    Node* head6 = create_node(6);
    Node* head7 = create_node(7);
    Node* head8 = create_node(8);
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;
    head6->next = head7;
    head7->next = head8;

    //设置head4结点为环形入口
    head8->next = head4;

    bool res = has_cycle(head1);
    if(res)
        printf("has cycle!\n");
    else
        printf("no cycle\n");

    Node* entry = cycle_entry(head1);
    if(entry)
        printf("cycle entry : %d\n", entry->data);
    else
        printf("no cycle!\n");
}

void test_list_public()
{
    Node* head1 = create_node(1);
    Node* head2 = create_node(2);
    Node* head3 = create_node(3);
    Node* head4 = create_node(4);
    Node* head5 = create_node(5);
    Node* head6 = create_node(6);
    Node* head7 = create_node(7);
    Node* head8 = create_node(8);
    Node* head9 = create_node(9);
    Node* head10 = create_node(10);
    Node* head11 = create_node(11);
    Node* head12 = create_node(12);
    Node* head13 = create_node(13);

    //链表head1, 1->3->5->7->9->11->13
    head1->next = head3;
    head3->next = head5;
    head5->next = head7;

    head7->next = head9;
    head9->next = head11;
    head11->next = head13;

    printf("list 1:\n");
    show_list(head1);

    //链表head2, 2->4->6->8->10->12->9->11->13
    head2->next = head4;
    head4->next = head6;
    head6->next = head8;
    head8->next = head10;
    head10->next = head12;

    head12->next = head9;

    printf("list 2:\n");
    show_list(head2);

    Node* public = list_public(head1,head2);
    if(public)
        printf("public node : %d\n", public->data);
    else
        printf("no public node !\n");
}

void tese_merge_list()
{
    Node* head1 = create_node(1);
    Node* head2 = create_node(2);
    Node* head3 = create_node(3);
    Node* head4 = create_node(4);
    Node* head5 = create_node(5);
    Node* head6 = create_node(6);
    Node* head7 = create_node(7);
    Node* head8 = create_node(8);
    Node* head9 = create_node(9);
    Node* head10 = create_node(10);
    Node* head11 = create_node(11);
    Node* head12 = create_node(12);
    Node* head13 = create_node(13);

    //链表head1, 1->3->5->7->9->11->13
    head1->next = head3;
    head3->next = head5;
    head5->next = head7;

    head7->next = head9;
    head9->next = head11;
    head11->next = head13;

    printf("list 1:\n");
    show_list(head1);

    //链表head2, 2->4->6->8->10->12
    head2->next = head4;
    head4->next = head6;
    head6->next = head8;
    head8->next = head10;
    head10->next = head12;

    printf("list 2:\n");
    show_list(head2);

    Node* new_head = merge_two_list(head1,head2);
    if(new_head)
    {
        printf("new list after merge:\n");
        show_list(new_head);
    }
}

void test_last_k_middle()
{
    Node* head = create_list(10);
    printf("test list:\n");
    show_list(head);

    Node* k_node = last_k(head,2);
    printf("last k node : %d\n", k_node->data);

    Node* mid_node = find_middle(head);
    printf("middle node : %d\n",mid_node->data);
}

void test_del_repeat()
{
    Node* head1 = create_node(1);
    Node* head2 = create_node(3);
    Node* head3 = create_node(3);
    Node* head4 = create_node(4);
    Node* head5 = create_node(5);
    Node* head6 = create_node(6);
    Node* head7 = create_node(7);
    Node* head8 = create_node(8);
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;
    head6->next = head7;
    head7->next = head8;

    printf("test list:\n");
    show_list(head1);

    Node* new_head = del_repeat(head1);
    printf("delete repeat :\n");
    show_list(new_head);

}

int main()
{
    //test_list_reverse();
    //test_cycle_list();
    //test_list_public();
    //tese_merge_list();
    //test_last_k_middle();
    test_del_repeat();
}