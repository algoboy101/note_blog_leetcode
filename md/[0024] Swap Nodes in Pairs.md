---
title: "[0024] Swap Nodes in Pairs"
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
date: 2020-01-01 00:00:24
---

## 题目描述

> 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
> 
> 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
> 
> 
> 
> 示例: 
> 
> 给定 1->2->3->4, 你应该返回 2->1->4->3.
> 
> Related Topics 链表

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
    ListNode* swapPairs(ListNode* head) {
        
    }
};
```

## 解析

这道题不算难，是基本的链表操作题，我们可以分别用递归和迭代来实现。对于迭代实现，还是需要建立 dummy 节点，注意在连接节点的时候，最好画个图，以免把自己搞晕了，参见代码如下：

### 方法一

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};
```

### 方法二

递归的写法就更简洁了，实际上利用了回溯的思想，递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换：

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/24

 

类似题目：

Reverse Nodes in k-Group



