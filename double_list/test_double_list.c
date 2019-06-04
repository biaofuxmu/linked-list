#include "double_list.h"
//测试双向链表的各个函数

void test_insert_del_node()
{
    //为d_list申请内存，如果未申请，会出现段错误
    DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
    init_list(d_list);//初始化链表
    printf("insert head and insert tail---------------------------------\n");
    push_head(d_list, 5);
    push_tail(d_list,15);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("insert nodes at any location---------------------------------\n");
    insert_node(d_list,0,1);
    insert_node(d_list,2,10);
    insert_node(d_list,4,20);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("delete head and delete tail---------------------------------\n");
    del_head(d_list);
    del_tail(d_list);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("delete nodes at any location---------------------------------\n");
    del_node(d_list,1);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));
}

void test_find_modify_node()
{
    //为d_list申请内存，如果未申请，会出现段错误
    DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
    init_list(d_list);//初始化链表

    printf("create a test double list----------------------------------\n");
    for (int i = 1; i <= 10; ++i)
    {
        push_tail(d_list,i)
    }

    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("find data-------------------------------------------------\n");
    Node* node = find_data(d_list,5);
    printf("data: %d\n", node->data);

    printf("modify node-----------------------------------------------\n");
    
}


int main()
{
    test_insert_node();
    
}