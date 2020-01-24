---
title: "[0083] Remove Duplicates from Sorted List"
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
date: 2020-01-01 00:01:23
---

## 题目描述

> 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
> 
> 示例 1: 
> 
> 输入: 1->1->2
> 输出: 1->2
> 
> 
> 示例 2: 
> 
> 输入: 1->1->2->3->3
> 输出: 1->2->3 
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
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};
```

## 解析

### 方法一

这道题让我们移除给定有序链表的重复项，那么可以遍历这个链表，每个结点和其后面的结点比较，如果结点值相同了，只要将前面结点的 next 指针跳过紧挨着的相同值的结点，指向后面一个结点。这样遍历下来，所有重复的结点都会被跳过，留下的链表就是没有重复项的了，代码如下：

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
```

### 方法二

我们也可以使用递归的方法来做，首先判断是否至少有两个结点，若不是的话，直接返回 head。否则对 head->next 调用递归函数，并赋值给 head->next。这里可能比较晕，先看后面一句，返回的时候，head 结点先跟其身后的结点进行比较，如果值相同，那么返回后面的一个结点，当前的 head 结点就被跳过了，而如果不同的话，还是返回 head 结点。可以发现了，进行实质上的删除操作是在最后一句进行了，再来看第二句，对 head 后面的结点调用递归函数，那么就应该 suppose 返回来的链表就已经没有重复项了，此时接到 head 结点后面，在第三句的时候再来检查一下 head 是否又 duplicate 了，实际上递归一直走到了末尾结点，再不断的回溯回来，进行删除重复结点，参见代码如下： 	

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return (head->val == head->next->val) ? head->next : head;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/83

 

类似题目：

Remove Duplicates from Sorted List II