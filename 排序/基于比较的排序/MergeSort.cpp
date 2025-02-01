// 归并排序
// 时间复杂度为：O(N*logN)
// 额外空间复杂度为：O(N))
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


void merge(vector<int>& vec, int L, int M, int R)
{
    vector<int> help(R-L+1); // 开辟一个辅助空间，空间大小和 L->R 大小一样
    int i =0; // 专门为help使用的下标变量
    int p1 = L; // 左侧部分的下标
    int p2 =M + 1; // 右侧部分的下标
    
    //谁小拷贝谁，直至一侧越界(第1个while)，此时直接将另一侧拷贝下来即可(后2个while)
    while(p1 <= M && p2 <= R)
    {
        help[i++] = vec[p1] <= vec[p2] ? vec[p1++] : vec[p2++]; 
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
        vec[L + r] = help[r]; // 辅助空间已经排完序，此时将信息拷贝到arr中
    }
}



void process(vector<int>& vec, int L, int R) //process为归并排序主过程（递归方法）
{
    if(L == R)
    {
        return;
    }
    int mid = L + ((R - L) >> 1); // 求中点（ mid=(R+L)/2 的方法容易越界，所以用 mid=R+(R-L)/2 的方法，>>1等效于 /2,且速度更快 ）
    process(vec, L, mid);
    process(vec, mid+1, R);
    merge(vec, L, mid, R);
}

void mergeSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    }
    process(vec,0,(int)vec.size() - 1);
}


int main()
{
    vector<int> vec = {1,9,6,5,7,4};
    mergeSort(vec);

    cout << "排序后的数组："; 
    for(int r : vec)
    {
        cout << r << " ";
    }
    return 0;
}




