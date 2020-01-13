---
title: "[0635] Design Log Storage System"
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
date: 2020-01-01 00:10:35
---

## 题目描述

> 你将获得多条日志，每条日志都有唯一的 id 和 timestamp，timestamp 是形如 Year:Month:Day:Hour:Minute:Second 的字符串，例如 2017:01:01:23:59:59，所有值域都是零填充的十进制数。 
> 
> 设计一个日志存储系统实现如下功能： 
> 
> void Put(int id, string timestamp)：给定日志的 id 和 timestamp，将这个日志存入你的存储系统中。 
> 
> 
> 
> int[] Retrieve(String start, String end, String granularity)：返回在给定时间区间内的所有日志的 id。start 、 end 和 timestamp 的格式相同，granularity 表示考虑的时间级。比如，start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day" 代表区间 2017 年 1 月 1 日到 2017 年 1 月 2 日。 
> 
> 
> 
> 
> 
> 样例 1 ： 
> 
> put(1, "2017:01:01:23:59:59");
> put(2, "2017:01:01:22:59:59");
> put(3, "2016:01:01:00:00:00");
> retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // 返回值 [1,2,3]，返回从 2016 年到 2017 年所有的日志。
> retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // 返回值 [1,2], 返回从 2016:01:01:01 到 2017:01:01:23 区间内的日志，日志 3 不在区间内。
> 
> 
> 
> 
> 注释 ： 
> 
> 
> Put 和 Retrieve 的指令总数不超过 300。 
> 年份的区间是 [2000,2017]，小时的区间是 [00,23]。 
> Retrieve 的输出顺序不作要求。 
> 
> 
> 
> Related Topics 设计 字符串

## 题目代码

```cpp
class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
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

