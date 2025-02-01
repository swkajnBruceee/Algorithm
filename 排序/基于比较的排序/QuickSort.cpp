// 快速排序
// 时间复杂度：O(N*logN)
// 额外空间复杂度：O(logN)
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



// 这是一个处理arr[L...R]的函数
// 默认以arr[R]做划分，arr[R] 与 随机p 互换，然后分出三个区：  <p   ==p   >p
//返回值是一个长度为2的数组p，2个数据分别表示 '==区域' 的左边界和右边界
vector<int> partition(vector<int>& vec, int L, int R)
{
    int less = L - 1;  // '<区'右边界
    int more = R;      // '>区'左边界
    while(L < more)    // L表示当前位置
    {
        if(vec[L] < vec[R])  // 当前数 < 划分值
        {
            swap(vec[++less],vec[L++]); // 此处要注意
        }
        else if(vec[L] > vec[R])  // 当前数 > 划分值
        {
            swap(vec[--more], vec[L]);
        }
        else
        {
            L++;
        }
    }
    swap(vec[more], vec[R]);
    vector<int> p = {less+1,more};
    return p;
}



    // arr[L...R]排好序

void quickSort(vector<int>& vec,int L,int R)
{
    if(L < R)
    {
        swap(vec[L + rand()%(R-L+1)], vec[R]);  // 等概率随机选一个数，把它和最右位置的数交换
        vector<int> p = partition(vec,L,R);  // 返回的数组p长度一定为2，表示'划分值'等于区域的左边界和右边界 
        quickSort(vec,L,p[0]-1);  // p[0]-1 为'<区'的右边界
        quickSort(vec,p[1]+1,R);  // p[1]+1 为'>区'的左边界
    }
}


void quickSort(vector<int>& vec)
{
    if(vec.size() <2)
    {
        return;
    }
    quickSort(vec,0,vec.size()-1);
}



int main()
{
    srand(time(nullptr));  // 初始化随机种子

    vector<int> vec = {10, 7, 2, 9, 1, 5, 3, 2, 4, 5};
    quickSort(vec, 0, vec.size() - 1);
    cout << "排序后的数组："; 
    for(int r : vec)
    {
        cout << r << " ";
    }
    return 0;
}


