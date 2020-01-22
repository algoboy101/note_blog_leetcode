---
title: "[0002] Add Two Numbers"
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
date: 2020-01-01 00:00:02
---

## 题目描述

> 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
> 
> 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
> 
> 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
> 
> 示例： 
> 
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807
> 
> Related Topics 链表 数学

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};
```

## 解析

这道并不是什么难题，算法很简单，链表的数据类型也不难，就是建立一个新链表，然后把输入的两个链表从头往后撸，每两个相加，添加一个新节点到新链表后面。为了避免两个输入链表同时为空，我们建立一个 dummy 结点，将两个结点相加生成的新结点按顺序加到 dummy 结点之后，由于 dummy 结点本身不能变，所以用一个指针 cur 来指向新链表的最后一个结点。好，可以开始让两个链表相加了，这道题好就好在最低位在链表的开头，所以可以在遍历链表的同时按从低到高的顺序直接相加。while 循环的条件两个链表中只要有一个不为空行，由于链表可能为空，所以在取当前结点值的时候，先判断一下，若为空则取0，否则取结点值。然后把两个结点值相加，同时还要加上进位 carry。然后更新 carry，直接 sum/10 即可，然后以 sum%10 为值建立一个新结点，连到 cur 后面，然后 cur 移动到下一个结点。之后再更新两个结点，若存在，则指向下一个位置。while 循环退出之后，最高位的进位问题要最后特殊处理一下，若 carry 为1，则再建一个值为1的结点，代码如下：



### 方法一

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};
```



在 CareerCup 上的这道题还有个 Follow Up，把链表存的数字方向变了，原来是表头存最低位，现在是表头存最高位，请参见我的另一篇博客 2.5 Add Two Numbers 两个数字相加 。

 

Github 同步地址：

https://github.com/grandyang/leetcode/issues/2

 

类似题目：

Multiply Strings

Add Binary

Sum of Two Integers 

Add Strings 

Add Two Numbers II  

