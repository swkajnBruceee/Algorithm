#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compator(int a,int b )
{
    return a > b;
}

int main()
{
    vector<int> vec = {1,2,3,5,9,7,5,4};
    sort(vec.begin(),vec.end(),compator);
    for(int r : vec)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}