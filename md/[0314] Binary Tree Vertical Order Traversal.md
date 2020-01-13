---
title: "[0314] Binary Tree Vertical Order Traversal"
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
date: 2020-01-01 00:05:14
---

## 题目描述

> 给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。 
> 
> 如果两个结点在同一行和列，那么顺序则为 从左到右。 
> 
> 示例 1： 
> 
> 输入: [3,9,20,null,null,15,7]
> 
> 3
> /\
> /  \
> 9   20
> /\
> /  \
> 15   7 
> 
> 输出:
> 
> [
> [9],
> [3,15],
> [20],
> [7]
> ]
> 
> 
> 示例 2: 
> 
> 输入: [3,9,8,4,0,1,7]
> 
> 3
> /\
> /  \
> 9    8
> /\   /\
> /  \ /  \
> 4   0 1   7 
> 
> 输出:
> 
> [
> [4],
> [9],
> [3,0,1],
> [8],
> [7]
> ]
> 
> 
> 示例 3: 
> 
> 输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）
> 
> 3
> /\
> /  \
> 9   8
> /\  /\
> /  \/  \
> 4  01   7
> /\
> /  \
> 5   2
> 
> 输出:
> 
> [
> [4],
> [9,5],
> [3,0,1],
> [8,2],
> [7]
> ]
> 
> Related Topics 哈希表

## 题目代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
    }
};
```

## 解析

### 方法一

```cpp

```

### 方法二

```cpp

```

### 方法三

```cpp

```

