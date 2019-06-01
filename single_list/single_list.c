#include "single_list.h"

//创建结点
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
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

//链表长度
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


//在链表指定位置插入一个结点 返回头结点
Node* list_insert(Node* head, int index, int data)
{
    if(index > list_len(head) || index < 0)
        return NULL;
    else if(index == 0)
    {
        Node* node = create_node(data);
        node->next = head;
        head = node;
    }
    else
    {
        Node* tmp = head;
        for(int i=0; i<index-1; i++)
        {
            tmp = tmp->next;
        }
        Node* node = create_node(data);
        node->next = tmp->next;
        tmp->next = node;
    }
    return head;
}

//删除指定位置的一个结点 返回头结点
Node* list_delete(Node* head, int index)
{
    if(head == NULL || index >= list_len(head) || index < 0)
        return NULL;
    else if(index == 0)
    {
        Node* tmp = head;
        head = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    else
    {
        Node* node = head;
        for(int i=0; i<index-1; i++)
        {
            node = node->next;
        }
        Node* tmp = node->next;

        node->next = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    return head;
}

//根据值查找结点
Node* list_find(Node* head,int data)
{
    if(head == NULL)
        return NULL;
    Node* node = head;
    while(node)
    {
        if(node->data == data)
            return node;
        node = node->next;
    }
    return NULL;
}

//修改指定位置的结点值
bool modify_index(Node* head,int index, int data)
{
    if(head == NULL || index < 0)
        return false;
    Node* node = head;
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
bool modify_data(Node* head, int data, int val)
{
    Node* node = list_find(head,data);
    if(node)
    {
        node->data = val;
        return true;
    }
    return false;
} 
