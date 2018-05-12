#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    const int LIMIT = 1015;
    vector <int> perfect_power(LIMIT, false);
 
    perfect_power[1] = true;
    for(int n = 2; n*n < LIMIT; n++)
    {
        int current_power = n*n;
 
        while(current_power < LIMIT)
        {
            perfect_power[current_power] = true;
            current_power *= n;
        }
    }
 
    int X;
    cin >> X;
 
    while(!perfect_power[X])
        X--;
 
    cout << X;
    return 0;
}
