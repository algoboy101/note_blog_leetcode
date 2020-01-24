---
title: "[0019] Remove Nth Node From End of List"
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
date: 2020-01-01 00:00:19
---

## 题目描述

> 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 
> 
> 示例： 
> 
> 给定一个链表: 1->2->3->4->5, 和 n = 2.
> 
> 当删除了倒数第二个节点后，链表变为 1->2->3->5.
> 
> 
> 说明： 
> 
> 给定的 n 保证是有效的。 
> 
> 进阶： 
> 
> 你能尝试使用一趟扫描实现吗？ 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    }
};
```

## 解析

这道题让我们移除链表倒数第N个节点，限定n一定是有效的，即n不会大于链表中的元素总数。还有题目要求一次遍历解决问题，那么就得想些比较巧妙的方法了。比如首先要考虑的时，如何找到倒数第N个节点，由于只允许一次遍历，所以不能用一次完整的遍历来统计链表中元素的个数，而是遍历到对应位置就应该移除了。那么就需要用两个指针来帮助解题，pre 和 cur 指针。首先 cur 指针先向前走N步，如果此时 cur 指向空，说明N为链表的长度，则需要移除的为首元素，那么此时返回 head->next 即可，如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur 为最后一个元素时停止，此时 pre 指向要移除元素的前一个元素，再修改指针跳过需要移除的元素即可，参见代码如下：

### 方法一

```cpp

```

### 方法二

```cpp

```

### 方法三

```cpp

```

