#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

cpp_int  dpSolution(int n,cpp_int dp[101])
{
    if(!dp[n])
    {
        int i=2;
        for(;i<=n;i++)
        if(!dp[i])
        break;
        for(;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    return dp[n];
}

int main()
{

    int t;
    cin >>t;
    cpp_int dp[101]={0};
    dp[0]=1;
    dp[1]=1;
    while(t--)
    {
        int n; cin >>n;
        cout << dpSolution(n,dp) << endl;
    }
    return 0;
}