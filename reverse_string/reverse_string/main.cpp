//
//  main.cpp
//  reverse_string
//  反转字符串
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;  // 用string类也需要使用该命名空间


int main(int argc, const char * argv[]) {
    // 输入字符串
    string test_str1 = "zhouxiaorui";
    unsigned long len_str1;
    
    len_str1 = test_str1.size();
    char* out_str = new char [len_str1];
    
    for(int i=0; i<len_str1; i++)
    {
        out_str[i] = test_str1[len_str1-1-i];
    }
    
    cout<<"原字符串："<<test_str1<<endl;
    
    cout<<"反转后的字符串："<<out_str<<endl;
    
    delete [] out_str; // 释放new分配的内存
    return 0;
}
