//
//  bin_search_rec.cpp
//  bin_search
//
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//

#include "bin_search.h"

int bin_search_rec(int arr[], int low_index, int high_index, int key)
{
    if(low_index <= high_index)
    {
        int mid_index = (low_index + high_index)/2;
        
        if(key == arr[mid_index])
            return mid_index;
        
        else if(key < arr[mid_index])
            return bin_search_rec(arr, low_index, mid_index-1, key);
        
        else if (key > arr[mid_index])
        {
            return bin_search_rec(arr, mid_index+1, high_index, key);
        }
    }
    return -1;
}
