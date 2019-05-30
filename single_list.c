#include "single_list.h"

//创建结点
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

//创建长度为num的测试链表
Node* create_list(int num)
{
    Node* head = create_node(1);
    Node* tmp = head;
    for (int i = 2; i <= num; ++i)
    {
        Node* list = create_node(i);
        tmp->next = list;
        tmp = list;
    }
    return head;
}

//显示链表
void show_list(Node* list)
{
    while(list)
    {
        printf("  %d\n", list->data);
        list = list->next;
    }
}

//链表长度
size_t list_len(Node* list)
{
    int len = 0;
    while(list)
    {
        list = list->next;
        len++;
    }
    return len;
}


//在链表指定位置插入一个结点
Node* list_insert(Node* list, int index, int data)
{
    if(index > list_len(list) || index < 0)
        return NULL;
    else if(index == 0)
    {
        Node* node = create_node(data);
        node->next = list;
        list = node;
    }
    else
    {
        Node* tmp = list;
        for(int i=0; i<index-1; i++)
        {
            tmp = tmp->next;
        }
        Node* node = create_node(data);
        node->next = tmp->next;
        tmp->next = node;
    }
    return list;
}

//删除指定位置的一个结点
Node* list_delete(Node* list, int index)
{
    if(list == NULL || index > list_len(list) || index < 0)
        return NULL;
    else if(index == 0)
    {
        Node* tmp = list;
        list = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    else
    {
        Node* node = list;
        for(int i=0; i<index-1; i++)
        {
            node = node->next;
        }
        Node* tmp = node->next;

        node->next = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    return list;
}

//查找结点
Node* list_find(Node* list,int data)
{
    if(list == NULL)
        return NULL;
    Node* node = list;
    while(node)
    {
        if(node->data == data)
            return node;
        node = node->next;
    }
    return NULL;
}

//修改指定位置的结点值
bool modify_index(Node* list,int index, int data)
{
    if(index < 0)
        return false;
    Node* node = list;
    for (int i = 0; i < index; ++i)
    {
        if (node == NULL)
            return false;
        node = node->next;
    }
    node->data =  data;
    return true;
}

//修改指定数据的值
bool modify_data(Node* list, int data, int val)
{
    Node* node = list_find(list,data);
    if(node)
    {
        node->data = val;
        return true;
    }
    return false;
} 

int main()
{
	return 0;
}