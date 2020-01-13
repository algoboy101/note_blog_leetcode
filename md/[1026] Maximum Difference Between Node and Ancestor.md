---
title: "[1026] Maximum Difference Between Node and Ancestor"
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
date: 2020-01-01 00:17:06
---

## 题目描述

> 给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。 
> 
> （如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先） 
> 
> 
> 
> 示例： 
> 
> 
> 
> 输入：[8,3,10,1,6,null,14,null,null,4,7,13]
> 输出：7
> 解释： 
> 我们有大量的节点与其祖先的差值，其中一些如下：
> |8 - 3| = 5
> |3 - 7| = 4
> |8 - 1| = 7
> |10 - 13| = 3
> 在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
> 
> 
> 
> 
> 提示： 
> 
> 
> 树中的节点数在 2 到 5000 之间。 
> 每个节点的值介于 0 到 100000 之间。 
> 
> Related Topics 树 深度优先搜索

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
    int maxAncestorDiff(TreeNode* root) {
        
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

