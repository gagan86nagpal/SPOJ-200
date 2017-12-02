#include <iostream>

using namespace std;
int ret_sum_Square(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+= (n%10)*(n%10);
        n/=10;
    }
    return sum;
}
int main()
{
    int i;
    cin>>i;
    int cnt=0;
    while(i!=1&& cnt<250)
    {
        i = ret_sum_Square(i);
        cnt++;
    }
    if(i==1)
        cout<<cnt<<"\n";
    else
        cout<<"-1\n";
    return 0;
}
