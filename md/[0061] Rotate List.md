---
title: "[0061] Rotate List"
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
date: 2020-01-01 00:01:01
---

## 题目描述

> 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 
> 
> 示例 1: 
> 
> 输入: 1->2->3->4->5->NULL, k = 2
> 输出: 4->5->1->2->3->NULL
> 解释:
> 向右旋转 1 步: 5->1->2->3->4->NULL
> 向右旋转 2 步: 4->5->1->2->3->NULL
> 
> 
> 示例 2: 
> 
> 输入: 0->1->2->NULL, k = 4
> 输出: 2->0->1->NULL
> 解释:
> 向右旋转 1 步: 2->0->1->NULL
> 向右旋转 2 步: 1->2->0->NULL
> 向右旋转 3 步: 0->1->2->NULL
> 向右旋转 4 步: 2->0->1->NULL 
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
    ListNode* rotateRight(ListNode* head, int k) {
        
    }
};
```

## 解析

### 方法一

这道旋转链表的题和之前那道 Rotate Array 旋转数组 很类似，但是比那道要难一些，因为链表的值不能通过下表来访问，只能一个一个的走，我刚开始拿到这题首先想到的就是用快慢指针来解，快指针先走k步，然后两个指针一起走，当快指针走到末尾时，慢指针的下一个位置是新的顺序的头结点，这样就可以旋转链表了，自信满满的写完程序，放到OJ上跑，以为能一次通过，结果跪在了各种特殊情况，首先一个就是当原链表为空时，直接返回NULL，还有就是当k大于链表长度和k远远大于链表长度时该如何处理，我们需要首先遍历一遍原链表得到链表长度n，然后k对n取余，这样k肯定小于n，就可以用上面的算法了，代码如下:



```cpp
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k; ++i) {
            if (fast) fast = fast->next;
        }
        if (!fast) return head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
};
```

### 方法二

这道题还有一种解法，跟上面的方法类似，但是不用快慢指针，一个指针就够了，原理是先遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，在往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可，代码如下:



```cpp
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *cur = head;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }
        cur->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        ListNode *newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
};
```

### 方法三

```cpp

```

