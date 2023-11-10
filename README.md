# C Learning

## Introduction 介绍

This is a record of learning C language.

Programming is kind of new to me.

But I don't like posting very serious and boring scripts online. Instead I love to look into interesting gizmos.

So here are what I've coded.

Enjoy!

这是我学习C语言编程的一些记录。我目前是编程的新手。

但我不喜欢在这里放很严肃、很死板的教科书式代码；相反地，我喜欢研究简单的代码写成的小玩意。

我也把它们的源代码放在了这里。

如果喜欢的话，就给一个Star吧！😊

## Contents 内容

### Play7.c

A twitching progress bar to test whether you're lucky or not this time. Sure, you can inject vitality into it with your own understandings.

一个“抽搐”的进度条，测测你的运气。当然，你也可以赋予它其他含义。

### Stopwatch.c  Stopwatch2.c

A simple stopwatch. The second program displays more specific time, but it shows a significant error.

一个简单的秒表程序。第二个程序精确到了后两位，但它的误差很大。

### sound.c

A program to play sounds whose pitch are equal to those on the piano.

一个能播放音阶的小程序。

### xy2polar.c

A small calculator to convert rectangular coordinate system to polar coordinate system. Actually it is meant to solve a PTA puzzle.

一个把直角坐标转换为极坐标的计算器。实际上是一个PTA平台的练习题。

![Screenshot](https://img.kylemao.link/file/aafd8bc8e7fa27ebd795f.png)

### Encoder v4_1.c

**My greatest project up to now!**

**目前为止最大的项目！**

Encrypt text using bitwise XOR algorithm. ASCII of clear text and password characters match one by one with scrolling calculation.

Until version 4.1, almost all garbled code situations have been fixed;  Spaces and Chinese are supported;  Enhanced encryption algorithms are used to recalculate the actual password and solve the problem of low password discrimination.
Although the program is not suitable for professional encryption purposes, it is a great practice for C language arrays and strings.

使用按位异或算法对文本进行加密。明文和密码字符ASCII一一对应、滚动计算。

直到版本4.1，已修复几乎所有乱码情况；支持空格、支持中文；使用增强的加密算法，重算实际密码，解决密码区分度不高的问题。

虽然不适合专业加密用途，但却是对C语言数组、字符串很好的一个练习。
