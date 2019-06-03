#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//结点结构体
typedef struct Node
{
    int data;
    struct Node* prev;//前驱指针
    struct Node* next;//后继指针
}Node;

//双向链表结构体
typedef struct DoubleList
{
    Node* head;
    Node* tail;
    size_t size;
}DoubleList;

//创建结点
Node* create_node(int data);
//初始化链表
void init_list(DoubleList* list);
//释放链表
void free_list(DoubleList* list);
//获取链表长度
size_t get_size(DoubleList* list);
//遍历链表
void show_list(DoubleList* list);
//插入头结点
void push_head(DoubleList* list, int data);
//插入尾结点
void push_tail(DoubleList* list, int data);
//任意位置插入结点 
bool insert_node(DoubleList* list, int index, int data);
//删除头结点
void del_head(DoubleList* list);
//删除尾结点
void del_tail(DoubleList* list);
//删除任意位置结点
bool del_node(DoubleList* list, int index);
//获取头结点
Node* get_head(DoubleList* list);
//获取尾结点
Node* get_tail(DoubleList* list);
//获取任意位置结点
Node* get_node(DoubleList* list, int index);
//查找链表中指定的数据
Node* find_data(DoubleList* list, int data);
//修改链表中指定结点的值
bool modify_node(DoubleList* list, int index, int data);
//修改链表中指定数据的值
bool modify_data(DoubleList* list, int data, int val);

#endif//__DOUBLE_LIST_H__