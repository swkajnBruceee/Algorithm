/*��ֽ����
���һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±����Ϸ�����1�Σ�ѹ���ۺۺ�չ����
��ʱ�ۺ��ǰ���ȥ�ģ����ۺ�ͻ��ķ���ָ��ֽ���ı��档
�����ֽ�����±����Ϸ���������2�Σ�ѹ���ۺۺ�չ������ʱ�������ۺۣ�
���ϵ������������ۺۡ����ۺۺ����ۺۡ�
����һ���������N������ֽ�������±����Ϸ���������N�Ρ�
����ϵ��´�ӡ�����ۺ۵ķ���
���磺N=1ʱ����ӡ��down N=2ʱ����ӡ��down down up
*/
#include<iostream>
using namespace std;


void printAllFolds(int N);
void printProcess(int i, int N, bool down);


int main()
{
    int N = 3;
    printAllFolds(N);
    return 0;
}


void printAllFolds(int N)
{
    printProcess(1, N, true);  // ����������ʼ
}

// �ݹ���̣�������ĳһ�ڵ�
// i�ǽڵ�Ĳ�����N��һ���Ĳ����� down == true -> �� ��down == false -> ͹
// ����һ������������������ͷ�ڵ㶼�ǰ�����������ͷ�ڵ㶼��͹
void printProcess(int i, int N, bool down)
{
    if(i > N) return;
    printProcess(i + 1, N, true);   // ����������ʼ�ݹ�  
    cout<<(down ? "��" : "͹");     //                  -> ��������ʵ������������߼�һ��
    printProcess(i + 1, N, false);  // ����������ʼ�ݹ�  
}





