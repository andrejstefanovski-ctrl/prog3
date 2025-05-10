#include <iostream>
#include <string>
#include <vector>
using namespace std;

int topDownLCS(string& a, string& b, int i, int j, vector<vector<int>>& dp)
{
    if (i==0 || j==0)
    {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i-1]==b[j-1]) return dp[i][j] = 1 + topDownLCS(a,b,i-1,j-1,dp);
    else return dp[i][j] = max(topDownLCS(a,b,i-1,j,dp),topDownLCS(a,b,i,j-1,dp));
}

vector<vector<int>> LCS(string& a, string& b)
{
    int m=a.size(), n=b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp;
}

void diff(string& a, string& b, vector<vector<int>>& dp, int i, int j)
{
    if (i>0 && j>0 && a[i-1]==b[j-1])
    {
        diff(a,b,dp,i-1,j-1);
        cout << " " << a[i-1];
    }
    else if (i>0 && (j==0 || dp[i][j-1] >= dp[i-1][j])) //ako od A imame uste ostanato a B e potroseno ili so trganje na bukva od B se dobiva podobar LCS
    {
        diff(a,b,dp,i,j-1);
        cout << " +" << b[j-1];
    }
    else if (j>0 && (i==0 || dp[i-1][j] >= dp[i][j-1])) //ako od B imame uste ostanato a A e potroseno ili so trganje na bukva od A se dobiva podobar LCS
    {
        diff(a,b,dp,i-1,j);
        cout << " -" << a[i-1];
    }
}

int main()
{
    string a,b;
    cin >> a >> b;
    vector<vector<int>> dp=LCS(a,b);
    diff(a,b,dp,a.size(),b.size());
    cout << endl;

    vector<vector<int>> dp1(a.size()+1, vector<int>(b.size()+1, -1));
    topDownLCS(a,b,a.size(),b.size(),dp1);
    diff(a,b,dp1,a.size(),b.size());
    return 0;
}