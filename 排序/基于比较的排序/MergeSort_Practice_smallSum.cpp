// 小和问题

/*  在一个数组中，每个数左边比当前数小的数累加起来，叫做这个数组的小和  */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


int merge(vector<int>& vec, int L, int M, int R)
{
    vector<int> help(R-L+1); 
    int i =0; 
    int p1 = L; 
    int p2 =M + 1; 
    int sum = 0;
    
    while(p1 <= M && p2 <= R)
    {
        sum += vec[p1] < vec[p2] ? (R - p2 + 1) * vec[p1] : 0;  //(R - p2 + 1)是指，在右边数组中，此时有多少个数比p1所指的数大
        help[i++] = vec[p1] < vec[p2] ? vec[p1++] : vec[p2++];  //正常比较后拷贝进辅助空间help
    }
    while(p1 <= M)
    {
        help[i++] = vec[p1++];
    }
    while(p2 <= R)
    {
        help[i++] = vec[p2++];
    }
    for(int r = 0; r < (int)help.size(); r++)
    {
        vec[L + r] = help[r]; 
    }
    return sum;
}


 //arr[L...R]既要排好序，也要求小和(注意：排序操作不可省略，且必须先进行)
int process(vector<int>& vec, int L, int R)
{
    if(L == R) return 0;
    int mid = L + ((R - L) >> 1);
    return  process(vec, L, mid)  // 左侧排好序求小和的数量 (1)
           +process(vec, mid+1, R)  // 右侧排好序求小和的数量 (2)
           +merge(vec, L, mid, R);  // 左右排好,最终归并排序求小和的数量 (3)
    // 数组的小和 == (1) + (2) + (3)
}



int smallSum(vector<int>& vec)
{
    if(vec.size() < 2) return 0;
    return process(vec, 0, vec.size() - 1);
}




int main()
{
    vector<int> vec = {4,10,6,7,6,9};
    cout<<smallSum(vec)<<endl;
    return 0;
}







