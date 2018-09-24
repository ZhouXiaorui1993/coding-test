//
//  main.cpp
//  quick_sort
//  快速排序——递归实现
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int arr[], int st, int ed);
void quick_sort(int arr[], int st, int ed);
void print_arr(const int arr[], int len_arr);


int main(int argc, const char * argv[]) {
    // 数组
    int arr[] = {2, 12, 3, 1, 23, 10, 6, 2, 8};
    // 计算数组的长度
    int len_arr = sizeof(arr)/sizeof(arr[0]);
    // 打印输出当前数组
    cout<<"before sort:"<<endl;
    print_arr(arr, len_arr);
    
    // 排序
    quick_sort(arr, 0, len_arr-1);
    
    // 打印当前数组
    cout<<"after sort:"<<endl;
    print_arr(arr, len_arr);
    
    return 0;
}

// 分组函数，返回基准元素的索引
int partition(int arr[], int st, int ed)
{
    // 选取第一个元素作为基准元素
    int pivot = arr[st];
    // 左右指针
    int left = st;
    int right = ed;
    int tmp;
    
    while (left<right)
    {
        // 从右边开始比较
        while (left<right && arr[right]>=pivot)
            right--;
        // 遇到大的，交换
        if (left<right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
        
        // 从左边开始比较
        while (left<right && arr[left] <= pivot) {
            left++;
        }
        // 遇到小的交换
        if(left<right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    return left;
}

void quick_sort(int arr[], int st, int ed)
{
    if(st < ed)
    {
        int pivot_index = partition(arr, st, ed);
        // 左边
        quick_sort(arr, st, pivot_index-1);
        quick_sort(arr, pivot_index+1, ed);
    }
}

// 打印数组
void print_arr(const int arr[], int len_arr)
{
    for(int i=0; i<len_arr; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
