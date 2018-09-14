#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""测试标准输入输出函数"""


import sys


# 输出函数
sys.stdout.write("hello" + "\n")  # 等价于print('hello')

sys.stdout.write("haha")  # 输出不会换行

sys.stdout.write("zzzz")

sys.stdout.write("\n")

# sys.stdout默认输出到控制台，如果把文件对象的引用赋给sys.stdout，则print调用的会是文件对象的write方法
file_handle = open('out.log', 'w')
sys.stdout = file_handle  # 下面的输出（print的输出也一样）会写入到log文件中

# 输入函数
in1 = input()  # input获取输入时，不包括末尾的换行符`\n`

sys.stdout.write(in1)
print('')  # 相当于sys.stdout.write("\n")
print(len(in1))

# sys.stdin.readline()会将标准输入全部获取，包括末尾的`\n`
# 因此在平时使用sys.stdin.readline()获取输入时，要记得去掉末尾的换行符，可以用strip()函数
in2 = sys.stdin.readline()
sys.stdout.write(in2)
print(len(in2))

# 去掉换行符
in2 = in2.strip('\n')
print(len(in2))
