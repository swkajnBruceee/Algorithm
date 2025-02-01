// �鲢����
// ʱ�临�Ӷ�Ϊ��O(N*logN)
// ����ռ临�Ӷ�Ϊ��O(N))
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


void merge(vector<int>& vec, int L, int M, int R)
{
    vector<int> help(R-L+1); // ����һ�������ռ䣬�ռ��С�� L->R ��Сһ��
    int i =0; // ר��Ϊhelpʹ�õ��±����
    int p1 = L; // ��ಿ�ֵ��±�
    int p2 =M + 1; // �Ҳಿ�ֵ��±�
    
    //˭С����˭��ֱ��һ��Խ��(��1��while)����ʱֱ�ӽ���һ�࿽����������(��2��while)
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
        vec[L + r] = help[r]; // �����ռ��Ѿ������򣬴�ʱ����Ϣ������arr��
    }
}



void process(vector<int>& vec, int L, int R) //processΪ�鲢���������̣��ݹ鷽����
{
    if(L == R)
    {
        return;
    }
    int mid = L + ((R - L) >> 1); // ���е㣨 mid=(R+L)/2 �ķ�������Խ�磬������ mid=R+(R-L)/2 �ķ�����>>1��Ч�� /2,���ٶȸ��� ��
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

    cout << "���������飺"; 
    for(int r : vec)
    {
        cout << r << " ";
    }
    return 0;
}




