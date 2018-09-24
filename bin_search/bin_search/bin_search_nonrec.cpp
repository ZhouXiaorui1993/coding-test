//
//  bin_search_nonrec.cpp
//  bin_search_non_rec
//  二分查找——非递归实现
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//
#include "bin_search.h"


int bin_search_non_rec(int arr[], int len_arr, int key)
{
    int low_index = 0;
    int high_index = len_arr-1;
    int mid_index;
    
    while (low_index<=high_index)
    {
        mid_index = (low_index+high_index)/2;
        if (key == arr[mid_index])
            return mid_index;
        if (key < arr[mid_index])
        {
            high_index = mid_index-1;
        }
        if (key > arr[mid_index])
        {
            low_index = mid_index+1;
        }
    }
    return -1;  // 没找到，返回-1
}
