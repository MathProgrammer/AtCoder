#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;						// n is the number of the cats
    cin>>n;
    int a[n+1];					// Array to take the input of the XOR values given in problem
    int ans=0;					// ans varibale and initialize it to zero
    for(int i=0;i<n;i++)		// For loop to take the input
    {
        cin>>a[i];
        ans^=a[i];				// Calculation of the XOR of all integers in the array remember that some number XOR with zero equals that number itself
    }
    for(int i=0;i<n;i++)
    {
        int x=ans^a[i];			// To find the indivial cat's scarf value one by take the XOR of the given XOR value withg= the total XOR value that is here our ans
        cout<<x<<" ";			// Output the correct answer
    }
    cout<<endl;
    return 0;
}
