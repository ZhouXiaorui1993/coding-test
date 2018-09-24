//
//  main.cpp
//  reverse_int
//  数字反序存放到一个数组中
//  Created by zhouxiaorui on 2018/9/24.
//  Copyright © 2018年 zhouxiaorui. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[10];
    int i;
    
    // 输入i
    cout<<"please enter a number:"<<endl;
    cin>>i;
    
    if(i==0)
        arr[0] = 0;
    else
    {
        // 存入arr
        int n = 0;
        while (i)
        {
            arr[n] = i%10;
            i = i/10;
            n++;
        }
        
        // 输出arr
        for (int j=0; j<=n; j++)
        {
            cout<<arr[j]<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
}
