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

// void test_insert_del_node()
// {
//     //为d_list申请内存，如果未申请，会出现段错误
//     DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
//     init_list(d_list);//初始化链表
//     printf("insert head and insert tail---------------------------------\n");
//     push_head(d_list, 5);
//     push_tail(d_list,15);
//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));

//     printf("insert nodes at any location---------------------------------\n");
//     insert_node(d_list,0,1);
//     insert_node(d_list,2,10);
//     insert_node(d_list,4,20);
//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));

//     printf("delete head and delete tail---------------------------------\n");
//     del_head(d_list);
//     del_tail(d_list);
//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));

//     printf("delete nodes at any location---------------------------------\n");
//     del_node(d_list,1);
//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));
// }

// void test_find_node()
// {
//     //为d_list申请内存，如果未申请，会出现段错误
//     DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
//     init_list(d_list);//初始化链表

//     printf("create a test double list----------------------------------\n");
//     for (int i = 1; i <= 10; ++i)
//     {
//         push_tail(d_list,i);
//     }

//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));

//     printf("get the node through the index------------------------------\n");
//     Node* node = get_node(d_list,7);
//     if(node)
//         printf("success, data: %d\n", node->data);
//     else
//         printf("index out of the range\n");

//     node = get_node(d_list,12);
//     if(node)
//         printf("success, data: %d\n", node->data);
//     else
//         printf("index out of the range\n");

//     printf("find the node through the data------------------------------\n");
//     Node* tmp = find_data(d_list,5);
//     if(tmp)
//         printf("success, data: %d\n", tmp->data);
//     else
//         printf("data not in the list!\n");

//     tmp = find_data(d_list,20);
//     if(tmp)
//         printf("success, data: %d\n", tmp->data);
//     else
//         printf("data not in the list!\n");

// }

// void test_modify_node()
// {
//     //为d_list申请内存，如果未申请，会出现段错误
//     DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
//     init_list(d_list);//初始化链表

//     printf("create a test double list----------------------------------\n");
//     for (int i = 1; i <= 10; ++i)
//     {
//         push_tail(d_list,i);
//     }

//     show_list(d_list);
//     printf("list length : %zd\n", get_size(d_list));

//     printf("modify the node through the index-----------------------------------------------\n");
//     bool res = modify_node(d_list,2,11);
//     if(res)
//     {
//         printf("modify node success\n");
//         show_list(d_list);
//         printf("list length : %zd\n", get_size(d_list));
//     }
//     else
//         printf("modify node fail! index out of the range!\n");

//     res = modify_node(d_list,11,11);
//     if(res)
//     {
//         printf("modify node success\n");
//         show_list(d_list);
//         printf("list length : %zd\n", get_size(d_list));
//     }
//     else
//         printf("modify node fail: index out of the range!\n");

//     printf("modify the node through the data------------------------------\n");
//     bool flag = modify_data(d_list,5,30);
//     if(flag)
//     {
//         printf("modify data success\n");
//         show_list(d_list);
//         printf("list length : %zd\n", get_size(d_list));
//     }
//     else
//         printf("modify data fail: data not in the list!!\n");

//     flag = modify_data(d_list,15,25);
//     if(flag)
//     {
//         printf("modify data success\n");
//         show_list(d_list);
//         printf("list length : %zd\n", get_size(d_list));
//     }
//     else
//         printf("modify data fail: data not in the list!!\n");
// }


int main()
{
    test_list_reverse();

}