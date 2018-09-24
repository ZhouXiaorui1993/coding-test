//
//  main.cpp
//  bin_search
// 二分查找-
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//

#include <iostream>
#include "bin_search.h"
using namespace std;


int main(int argc, const char * argv[]) {
    // 数组
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int key1 = 11;
    int key2 = 4;
    
    // 非递归二分查找
    int len_a = sizeof(a)/sizeof(a[0]);
    int key1_index = bin_search_non_rec(a, len_a, key1);
    
    if (key1_index != -1)
        cout<<"key " <<key1<< " in index "<<key1_index<<endl;
    else
        cout<<"not found key1 in array."<<endl;
    
    // 递归二分查找
    int key2_index = bin_search_rec(a, 0, len_a-1, key2);
    if (key2_index != -1)
        cout<<"key " <<key2<< " in index "<<key2_index<<endl;
    else
        cout<<"not found key2 in array."<<endl;
    
    
    return 0;
}
