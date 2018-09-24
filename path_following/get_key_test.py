#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""获取按键并进行处理"""


import tty
import sys
import termios


print("waiting for input from keyboard...")


def get_key():
    tty_fd = sys.stdin.fileno()  # 获取标准输入的文件描述符，每个进程都有一个文件描述符表，fd就是这张表的索引
    tty_old_settings = termios.tcgetattr(tty_fd)  # 获取标准输入（终端）的设置
    try:
        tty.setraw(tty_fd)  # 利用tty模块的setraw函数，设置标准输入为raw模式
        ch = sys.stdin.read(1)  # 每次读取一个字符进行处理
    finally:
        termios.tcsetattr(tty_fd, termios.TCSADRAIN, tty_old_settings)  # 还原终端设置
    return ch


while True:
    input_ch = get_key()

    if input_ch == "Q":
        break
    elif ord(input_ch) == 0x3:  # 表示⌃+c
        print("shut down")
        break
    print("velocity is set to %s" % input_ch)




