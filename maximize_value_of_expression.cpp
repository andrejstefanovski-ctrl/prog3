#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto& i:a)
    {
        cin >> i;
    }
    int first[n+1], second[n], third[n-1], fourth[n-2];
    for (int i=0; i<n-2; i++)
    {
        first[i]=second[i]=third[i]=fourth[i]=INT_MIN;
    }
    first[n-2]=second[n-2]=third[n-2]=INT_MIN;
    first[n-1]=second[n-1]=INT_MIN;
    first[n]=INT_MIN;
    for (int i=n-1; i>=0; i--)
    {
        first[i]=max(first[i+1], a[i]);
    }
    for (int i=n-2; i>=0; i--)
    {
        second[i]=max(second[i+1],first[i+1]-a[i]);
    }
    for (int i=n-3; i>=0; i--)
    {
        third[i]=max(third[i+1],second[i+1]+a[i]);
    }
    for (int i=n-4; i>=0; i--)
    {
        fourth[i]=max(fourth[i+1],third[i+1]-a[i]);
    }
    cout << fourth[0];
    return 0;
}
