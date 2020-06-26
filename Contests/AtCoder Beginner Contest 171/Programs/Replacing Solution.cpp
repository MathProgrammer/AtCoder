#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,x,y;            	// n is number of integers in the array, q is querry and x and y are the intergers given in the query
    cin>>n;						// Take the input of the number that is n
    int a[n+1];					// Take an array with size n+1
    int freq[100001]={0};		// Our frequency array and as the maximum size is upto 1e5 so I take size one more that is 1e5 + 1
    long long int sum=0;		// Take a sum variable and initialize it to zero
    for(int i=0;i<n;i++)		// For loop take the input
    {
        cin>>a[i];
        freq[a[i]]++;
        sum+=a[i];
    }
    cin>>q;											// Input of number of queries
    for(int i=1;i<=q;i++)							// For loop for queries
    {
        cin>>x>>y;									// Input of the integer we need to replace and the integer we need to replace with
        sum+=((freq[x]*y)-(freq[x]*x));					// Update of the sum according to the query
        freq[y]+=freq[x];									// Update the freq of y
        freq[x]=0;										// Update the freq of x to zero
        cout<<sum<<endl;							// Output the sum
    }
    return 0;
}
