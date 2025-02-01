// С������

/*  ��һ�������У�ÿ������߱ȵ�ǰ��С�����ۼ�������������������С��  */

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
        sum += vec[p1] < vec[p2] ? (R - p2 + 1) * vec[p1] : 0;  //(R - p2 + 1)��ָ�����ұ������У���ʱ�ж��ٸ�����p1��ָ������
        help[i++] = vec[p1] < vec[p2] ? vec[p1++] : vec[p2++];  //�����ȽϺ󿽱��������ռ�help
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


 //arr[L...R]��Ҫ�ź���ҲҪ��С��(ע�⣺�����������ʡ�ԣ��ұ����Ƚ���)
int process(vector<int>& vec, int L, int R)
{
    if(L == R) return 0;
    int mid = L + ((R - L) >> 1);
    return  process(vec, L, mid)  // ����ź�����С�͵����� (1)
           +process(vec, mid+1, R)  // �Ҳ��ź�����С�͵����� (2)
           +merge(vec, L, mid, R);  // �����ź�,���չ鲢������С�͵����� (3)
    // �����С�� == (1) + (2) + (3)
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







