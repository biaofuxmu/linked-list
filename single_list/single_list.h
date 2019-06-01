#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

//结点结构体
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//创建结点
Node* create_node(int data);

//创建长度为num的链表
Node* create_list(int num);

//显示链表的数据
void show_list(Node* head);

//获取链表长度
size_t list_len(Node* head);

//在链表指定位置插入结点 返回头结点
Node* list_insert(Node* head, int index, int data);

//删除链表指定位置的结点 返回头结点
Node* list_delete(Node* head, int index);

//查找链表中指定的数据
Node* list_find(Node* head,int data);

//修改链表中指定位置结点的值
bool modify_index(Node* head,int index, int data);

//修改链表中指定数据的值
bool modify_data(Node* head, int data, int val);

#endif//__SINGLE_LIST_H__