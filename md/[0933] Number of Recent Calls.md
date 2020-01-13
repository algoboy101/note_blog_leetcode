---
title: "[0933] Number of Recent Calls"
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
date: 2020-01-01 00:15:33
---

## 题目描述

> 写一个 RecentCounter 类来计算最近的请求。 
> 
> 它只有一个方法：ping(int t)，其中 t 代表以毫秒为单位的某个时间。 
> 
> 返回从 3000 毫秒前到现在的 ping 数。 
> 
> 任何处于 [t - 3000, t] 时间范围之内的 ping 都将会被计算在内，包括当前（指 t 时刻）的 ping。 
> 
> 保证每次对 ping 的调用都使用比之前更大的 t 值。 
> 
> 
> 
> 示例： 
> 
> 输入：inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
> 输出：[null,1,2,3,3] 
> 
> 
> 
> 提示： 
> 
> 
> 每个测试用例最多调用 10000 次 ping。 
> 每个测试用例会使用严格递增的 t 值来调用 ping。 
> 每次调用 ping 都有 1 <= t <= 10^9。 
> 
> 
> 
> Related Topics 队列

## 题目代码

```cpp
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
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

