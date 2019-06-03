#include "double_list.h"

//创建结点
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

//初始化链表
void init_list(DoubleList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

//释放链表
void free_list(DoubleList* list)
{
    while(list->size)
    {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        tmp = NULL;
        list->size--;
    }
}

//获取链表长度
size_t get_size(DoubleList* list)
{
    return list->size;
}

//获取头结点
Node* get_head(DoubleList* list)
{
    return list->head;
}

//获取尾结点
Node* get_tail(DoubleList* list)
{
    return list->tail;
}

//遍历链表
void show_list(DoubleList* list)
{
    Node* node = list->head;
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

//插入一个头结点
void push_head(DoubleList* list, int data)
{
    Node* new_node = create_node(data);

    if(list->size == 0)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

//插入一个尾结点
void push_tail(DoubleList* list, int data)
{
    Node* new_node = create_node(data);
    if(list->size == 0)
    {
        list->tail = new_node;
        list->head = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
    
}

//任意位置插入一个结点
bool insert_node(DoubleList* list, int index, int data)
{ 
    if(index <0 || index > list->size)
        return false;
    if(index == 0)
    {
        push_head(list,data);
        return true;
    }
    else if(index == list->size)
    {
        push_tail(list,data);
        return true;
    }

    Node* tmp = NULL;
    if(index <= list->size / 2)
    {
        tmp = list->head;
        for(int i=0; i<index-1;i++)
        {
            tmp = tmp->next;
        }
    }
    else
    {
        tmp = list->tail;
        for (int i = 0; i < list->size - index; ++i)
        {
            tmp = tmp->prev;
        }
    }

    Node* new_node = create_node(data);

    tmp->next->prev = new_node;
    new_node->next = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
    list->size++;
    return true;
}

//删除头结点
void del_head(DoubleList* list)
{
    if(list->size == 0)
        return;
    if(list->size == 1)
    {
        free(list->head);
        init_list(list);
        return;
    }

    Node* tmp = list->head;
    list->head = tmp->next;
    list->head->prev = NULL;

    free(tmp);
    tmp = NULL;
    list->size--;
}

//删除尾结点
void del_tail(DoubleList* list)
{
    if(list->size == 0)
        return;
    if(list->size == 1)
    {
        free(list->tail);
        init_list(list);
        return;
    }

    Node* tmp = list->tail;
    list->tail = tmp->prev;
    list->tail->next = NULL;

    free(tmp);
    tmp = NULL;
    list->size--;
}

//删除任意位置结点
bool del_node(DoubleList* list, int index)
{
    if(index < 0 || index > list->size)
        return true;
    if(index == 0)
    {
        del_head(list);
        return true;
    }
    if(index == list->size)
    {
        del_tail(list);
        return true;
    }

    Node* tmp = NULL;
    if(index < list->size/2)
    {
        tmp = list->head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
    }
    else
    {
        tmp = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            tmp = tmp->prev;
        }
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    tmp = NULL;
    list->size--;
    return true;
}


//获取任意位置结点
Node* get_node(DoubleList* list, int index)
{
    if(index < 0 || index > list->size)
        return NULL;
    Node* node = NULL;
    if(index < list->size / 2)
    {
        node = list->head;
        for(int i =0; i < index ; i++)
        {
            node = node->next;
        }
    }
    else
    {
        node = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            node = node->prev;
        }
    }
    return node; 
}

//查找链表中指定的数据
Node* find_data(DoubleList* list, int data)
{
    if(list->size == 0)
        return NULL;
    Node* node = list->head;
    while(node)
    {
        if(node->data == data)
            return node;
        node = node->next;
    }
    return NULL;
}

//修改链表中指定结点的值
bool modify_node(DoubleList* list, int index, int data)
{
    Node* node = get_node(list,index);
    if(node)
    {
        node->data = data;
        return true;
    }
    return false;
}

//修改链表中指定数据的值
bool modify_data(DoubleList* list, int data, int val)
{
    Node* node = find_data(list,data);
    if(node)
    {
        node->data = val;
        return true;    
    }
    return false;
}
