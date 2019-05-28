#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

typedef struct DoubleList
{
	Node* head;
	Node* tail;
	size_t size;
}DoubleList;

//创建结点
Node* create_node(data);
//初始化链表
void init_list(DoubleList list);
//释放链表
void free_list(DoubleList list);
//获取链表长度
void get_size(DoubleList list);
//遍历链表
void show_list(DoubleList list);
//插入一个头结点
//插入一个尾结点
//随机任意插入一个结点
//删除头结点
//删除尾结点
//删除任意位置结点
//获取头结点
//获取尾结点
//获取任意位置结点
//查找结点
//修改任意结点的值
//更新结点的值

#endif//DOUBLE_LIST_H