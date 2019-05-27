#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//结点结构体
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//创建结点
Node* create_node(int data);

//创建长度为num的测试链表
Node* create_list(int num);

//显示链表
void show_list(Node* list);

//链表长度
size_t list_len(Node* list);

//在链表指定位置插入一个结点
Node* list_insert(Node* list, int index, int data);

//删除指定位置的一个结点
Node* list_delete(Node* list, int index);

//查找结点
Node* list_find(Node* list,int data);

//修改指定位置的结点值
bool modify_index(Node* list,int index, int data);

//修改指定数据的值
bool modify_data(Node* list, int data, int val);