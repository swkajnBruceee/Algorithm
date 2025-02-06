// ʵ�����ǹ�������������

/*
  һ������г����룬����Ҫ���Ѻͳ�����ֵһ����ͭ��ġ����糤��Ϊ20�Ľ����������гɳ��ȶ������룬��Ҫ����20��ͭ�塣
  һȺ�������������������ô����ʡͭ�壿
  ���磬���������10��20,30��������һ�������ˣ������������Ϊ10+20+30=60��
  ����Ҫ�ֳ�10.20��30�������֡�����Ȱѳ���60�Ľ����ֳ�10��50������60��
  �ٰѳ���50�Ľ����ֳ�20��30������50��һ������110ͭ�塣
  ��������Ȱѳ���60�Ľ����ֳ�30��30������60���ٰѳ���30�����ֳ�10��20������30��һ������90ͭ�塣
  ����һ�����飬���طָ����С���ۡ�(LeeetCode_1547)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int lessMoney(vector<int>& arr)
{
    // ׼��һ��С����
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < (int)arr.size(); i++)
    {
        q.push(arr[i]);
    }
    int sum = 0;  // �����ܻ���
    int cur = 0;
    while(q.size() > 1)
    {
        // С���ѵ������������,�ٽ�����ӵ�С������ȥ
        cur = q.top();
        q.pop();
        cur = cur + q.top();
        q.pop();

        sum += cur;
        q.push(cur);
    }
    return sum;
}


int main()
{
    vector<int> arr = {1,1,5,1,1,1};
    cout<<lessMoney(arr);
    return 0;
}




         


