/*Collision Resolution using Open Addressing/Closed Hashing - Linear Probing Technique*/
#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    int a[n];
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        h[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        k=a[i]%n;
        while (h[k]!=-1)
        {
            k++;
            if(k>=n)
                k=0;
        }
        h[k]=a[i];
    }
    for(int i=0;i<n;i++)
    { 
        cout<<h[i]<<" ";
    }
    return 0;
}

/*
or
/*Hashing - Collision Resolution Technique - Linear Probing*/
#include<iostream>
using namespace std;
int main()
{
    int n, x, k;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)
    {
        h[i]=-1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        k = x % n;
        while ( h[k] != -1 )
        {
            k++;
            if(k >= n)
            {
               k = 0; 
            }
        }
        h[k] = x;
    }
    for(int i = 0; i < n; i++)
    {
        cout << h[i] << " ";
    }
    return 0;
}
*/
