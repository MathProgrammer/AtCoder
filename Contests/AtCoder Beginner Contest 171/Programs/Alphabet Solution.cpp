#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;						// c is character variable
    cin>>c;						// Take the input
    if(isupper(c))				// Check if the value is in uppercase or not
    cout<<'A'<<endl;			// If the condition holds true output A
    else
    cout<<'a'<<endl;			// If the condition is false then output a
    return 0;
}
