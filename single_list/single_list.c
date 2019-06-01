#include "single_list.h"

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


//在链表指定位置插入一个结点 返回头结点
Node* list_insert(Node* head, int index, int data)
{
    //判断链表是否为空以及插入的位置是否超出链表的范围
    if(head == NULL || index > list_len(head) || index < 0)
        return NULL;
    //插入0位置，即插入一个头结点
    else if(index == 0)
    {
        Node* node = create_node(data);
        node->next = head;//新结点的下一个结点等于头结点
        head = node;//头结点等于新结点
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
    //判断链表是否为空以及插入的位置是否超出链表的范围
    else if(index == 0)
    {
        Node* tmp = head;
        head = tmp->next;//头结点等于第二结点
        free(tmp);//释放删除结点的内存
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
        free(tmp);//释放删除结点的内存
        tmp = NULL;
    }
    return head;
}

//查找链表中指定的数据
Node* list_find(Node* head,int data)
{
    if(head == NULL)
        return NULL;
    Node* node = head;
    while(node)
    {
        if(node->data == data)
            return node;//返回该数据对应的结点
        node = node->next;
    }
    return NULL;//链表中不存在该数据，返回NULL
}

//修改链表中指定位置结点的值
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

//修改链表中指定数据的值
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
