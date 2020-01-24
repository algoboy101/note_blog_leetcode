---
title: "[0086] Partition List"
tags:
  - leetcode
categories:
  - leetcode
author: 张学志
comments: true
updated: false
permalink:
mathjax: false
top: false
description: ...
date: 2020-01-01 00:01:26
---

## 题目描述

> 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。 
> 
> 你应当保留两个分区中每个节点的初始相对位置。 
> 
> 示例: 
> 
> 输入: head = 1->4->3->2->5->2, x = 3
> 输出: 1->2->2->4->3->5
> 
> Related Topics 链表 双指针

## 题目代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
    }
};
```

## 解析

### 方法一

这道题要求我们划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变，相当于一个局部排序的问题。那么可以想到的一种解法是首先找到第一个大于或等于给定值的节点，用题目中给的例子来说就是先找到4，然后再找小于3的值，每找到一个就将其取出置于4之前即可，代码如下：

 	

```cpp
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```

### 方法二

这种解法的链表变化顺序为：

1 -> 4 -> 3 -> 2 -> 5 -> 2 

1 -> 2 -> 4 -> 3 -> 5 -> 2 

1 -> 2 -> 2 -> 4 -> 3 -> 5

 

此题还有一种解法，就是将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后即可，代码如下：	

```cpp
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
}; 	
```

此种解法链表变化顺序为：

Original: 1 -> 4 -> 3 -> 2 -> 5 -> 2 

New:

 

Original: 4 -> 3 -> 2 -> 5 -> 2 

New:　  1

 

Original: 4 -> 3 -> 5 -> 2 

New:　  1 -> 2

 

Original: 4 -> 3 -> 5 

New:　  1 -> 2 -> 2

 

Original: 

New:　  1 -> 2 -> 2 -> 4 -> 3 -> 5 

