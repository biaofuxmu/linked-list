#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

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

//显示链表的数据
void show_list(Node* head);

//链表长度
size_t list_len(Node* head);

//在链表指定位置插入一个结点 返回头结点
Node* list_insert(Node* head, int index, int data);

//删除指定位置的一个结点 返回头结点
Node* list_delete(Node* head, int index);

//根据值查找结点
Node* list_find(Node* head,int data);

//修改指定位置的结点值
bool modify_index(Node* head,int index, int data);

//修改指定数据的值
bool modify_data(Node* head, int data, int val);

#endif//__SINGLE_LIST_H__