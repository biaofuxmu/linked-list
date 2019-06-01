#include "single_list.h"
//测试单链表的各个函数

void test_create_list()
{
    Node* head = create_list(10);

    show_list(head);

    printf("list length : %zd\n", list_len(head));
}

void test_list_insert()
{
    printf("test 1---------------------------------\n");
    Node* head = NULL;
    show_list(head);
    printf("list length : %zd\n", list_len(head));

    printf("test 2---------------------------------\n");
    Node* list = list_insert(head,0,1);
    printf("insert data 1 to index 0\n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 3---------------------------------\n");
    list = list_insert(list,1,3);
    printf("insert data 3 to index 1\n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 4---------------------------------\n");
    list = list_insert(list,0,5);
    printf("insert data 5 to index 0\n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 5---------------------------------\n");
    list = list_insert(list,2,7);
    printf("insert data 7 to index 2\n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));
}

void test_list_delete()
{
    printf("test 1---------------------------------\n");
    Node* node = NULL;
    Node* list = list_delete(node,0);
    if(list == NULL)
    {
        printf("list is NULL: \n");
    }
    
    printf("generate list--------------------------\n");
    Node* head = create_list(10);
    show_list(head);
    printf("list length : %zd\n", list_len(head));

    printf("test 2---------------------------------\n");
    list = list_delete(head,0);
    printf("delete index 0: \n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 3---------------------------------\n");
    list = list_delete(list,8);
    printf("delete index 8: \n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 4---------------------------------\n");
    list = list_delete(list,5);
    printf("delete index 5: \n");
    show_list(list);
    printf("list length : %zd\n", list_len(list));

    printf("test 5---------------------------------\n");
    list = list_delete(list,10);
    printf("delete index 10: \n");
    if (list == NULL)
    {
        printf("ERROR : index out of range\n");
    }
    else
    {
        show_list(list);
        printf("list length : %zd\n", list_len(list));
    }
}

void test_list_find()
{
    printf("generate list--------------------------\n");
    Node* head = create_list(10);
    show_list(head);
    printf("list length : %zd\n", list_len(head));

    printf("test 1---------------------------------\n");
    Node* list = list_find(head,1);
    printf("find data 1: \n");
    show_list(list);

    printf("test 2---------------------------------\n");
    list = list_find(head,6);
    printf("find data 6: \n");
    show_list(list);

    printf("test 3---------------------------------\n");
    list = list_find(head,10);
    printf("find data 10: \n");
    show_list(list);

    printf("test 4---------------------------------\n");
    list = list_find(head,12);
    printf("find data 6: \n");
    if(list == NULL)
    {
        printf("can't find !\n");
    }
    else
    {
        show_list(list);
    }
}

void test_modify_index()
{
    printf("generate list--------------------------\n");
    Node* head = create_list(10);
    show_list(head);
    printf("list length : %zd\n", list_len(head));

    printf("test 1---------------------------------\n");
    bool res = modify_index(head,0,5);
    if(res)
    {
        printf("modify index 0 to 5 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify index 0 to 5 : fail\n");
    }

    printf("test 2---------------------------------\n");
    res = modify_index(head,9,5);
    if(res)
    {
        printf("modify index 9 to 5 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify index 9 to 5 : fail\n");
    }

    printf("test 3---------------------------------\n");
    res = modify_index(head,5,10);
    if(res)
    {
        printf("modify index 5 to 10 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify index 5 to 10 : fail\n");
    }

    printf("test 4---------------------------------\n");
    res = modify_index(head,15,10);
    if(res)
    {
        printf("modify index 15 to 10 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify index 15 to 10 : fail\n");
    }
    
}

void test_modify_data()
{
    printf("generate list--------------------------\n");
    Node* head = create_list(10);
    show_list(head);
    printf("list length : %zd\n", list_len(head));

    printf("test 1---------------------------------\n");
    bool res = modify_data(head,3,5);
    if(res)
    {
        printf("modify the first 3 to 5 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify the first 3 to 5 : fail\n");
    }

    printf("test 2---------------------------------\n");
    res = modify_data(head,20,5);
    if(res)
    {
        printf("modify the first 20 to 5 : success\n");
        show_list(head);
    }
    else
    {
        printf("modify the first 20 to 5 : fail\n");
    }
}

int main()
{
    //test_create_list();
    //test_list_insert();
    //test_list_delete();
    //test_list_find();
    //test_modify_index();
    test_modify_data();
    
}