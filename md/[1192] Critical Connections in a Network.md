---
title: "[1192] Critical Connections in a Network"
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
date: 2020-01-01 00:19:52
---

## 题目描述

> 力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。 
> 
> 它们之间以「服务器到服务器」点对点的形式相互连接组成了一个内部集群，其中连接 connections 是无向的。 
> 
> 从形式上讲，connections[i] = [a, b] 表示服务器 a 和 b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。 
> 
> 「关键连接」是在该集群中的重要连接，也就是说，假如我们将它移除，便会导致某些服务器无法访问其他服务器。 
> 
> 请你以任意顺序返回该集群内的所有 「关键连接」。 
> 
> 
> 
> 示例 1： 
> 
> 
> 
> 输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
> 输出：[[1,3]]
> 解释：[[3,1]] 也是正确的。 
> 
> 
> 
> 提示： 
> 
> 
> 1 <= n <= 10^5 
> n-1 <= connections.length <= 10^5 
> connections[i][0] != connections[i][1] 
> 不存在重复的连接 
> 
> Related Topics 深度优先搜索

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
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

