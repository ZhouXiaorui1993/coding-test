#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
编译器版本: Python 2.7.6
请使用标准输出(sys.stdout)；已禁用图形、文件、网络、系统相关的操作，如Process , httplib , os；缩进可以使用tab、4个空格或2个空格，但是只能任选其中一种，不能多种混用；如果使用sys.stdin.readline，因为默认会带换行符，所以要strip(' ')进行截取；建议使用raw_input()
时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
输入数据包含两行，
第一行，实体列表，多种实体之间用分号隔开，实体名和实体值之间用下划线隔开，多个实体值之间用竖线隔开，所有标点都是英文状态下的，格式如下：
实体名称1_实体值1|实体值2|…;实体名称2_实体值1|实体值2|…;…
第二行，用户的自然语言指令
输出:
被标记了关键词的指令。指令中的关键词前后加一个空格被单独分出来，并在后面跟上"/"+实体名称来标记。如果一个实体值属于多个实体，将这些实体都标记出来，并按照实体名称的字符串顺序正序排列，并以逗号分隔。
输入范例:
singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪
请播放周杰伦的七里香给我听
输出范例:
请播放 周杰伦/actor,singer 的 七里香/song 给我听
"""

# user input
usr_input = []
for i in range(2):
    usr_input.append(raw_input())

shi_tis = usr_input[0].split(';')
usr_cmd = usr_input[1]

new_sts = {}

for st in shi_tis:
    st = st.split("|")
    st_name = st[0].split('_')[0]
    len_name = len(st_name)
    st[0] = st[0][len_name+1:]
    new_sts[st_name] = st


# for k, v in new_sts.items():
#     print("%s:" % k),
#     for i in v:
#         print i,
#     print "\n"

use_info = {}
class_info = set()

# 在用户指令中寻找
for k, v in new_sts.items():
    min_l = 0
    for n in v:
        res_index = usr_cmd.find(n)
        if res_index != -1:  # success find
            res = usr_cmd[res_index:res_index+len(n)]

            if len(use_info) > 0:
                all_keys = use_info.keys()
                for key in all_keys:
                    if key != res and key in res:  # 如果当前name更长，弹出原name
                        use_info.pop(key)
            if res in use_info:
                use_info[res].append(k)
                use_info[res].sort()
            else:
                use_info[res] = [k]
            # class_info.add(k)

# for k, v in use_info.items():
#     print("%s:" % k),
#     for i in v:
#         print i,
#     print "\n"

keys_use_info = use_info.keys()

for i in range(len(use_info)):
    key = keys_use_info[i]
    index = usr_cmd.find(key)
    class_str = ','.join(use_info[key])
    usr_cmd = usr_cmd[:index] + ' ' + str(key) + '/'+class_str + ' ' + usr_cmd[index+len(key):]
    # print usr_cmd

print usr_cmd

# print usr_input
