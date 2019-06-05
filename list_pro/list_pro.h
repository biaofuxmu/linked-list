#ifndef __LIST_PRO_H_
#define __LIST_PRO_H_

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

//链表反转
Node* list_reverse(Node* list);

//判断链表是否有环
bool has_cycle(Node* list);

//查找环形入口
Node* cycle_entry(Node* list);

//查找公共结点
Node* list_public(Node* list1,Node* list2);

//查找公共结点
Node* list_public(Node* list1,Node* list2);

//合并两个有序链表
Node* merge_two_list(Node* list1, Node* list2);

//查找倒数第K个结点
Node* last_k(Node* list, int k);

//删除重复结点
Node* del_repeat(Node* head);

//查找中间结点
Node* find_middle(Node* head);

#endif//__LIST_PRO_H_