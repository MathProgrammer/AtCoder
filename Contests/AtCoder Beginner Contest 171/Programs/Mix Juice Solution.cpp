#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;						// n is the kind of foods and k is the kind of food we need to choose such that the condition holds
    cin>>n>>k;						// Input take place
    int price[n+1];						// Array for the price
    for(int i=0;i<n;i++)
    cin>>price[i];
    sort(price,price+n);			// Sort the array
    int sum=0;						// Take sum and intialize it to zero
    for(int i=0;i<k;i++)
    sum+=price[i];						// Sum of first k kind of foods that costs minimum possible
    cout<<sum<<endl;				// Output the answer
    return 0;
}
