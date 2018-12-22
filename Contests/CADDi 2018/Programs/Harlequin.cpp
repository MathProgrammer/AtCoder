#include <iostream>

using namespace std;

int main()
{
    int no_of_piles;
    cin >> no_of_piles;
    
    int all_even = true;
    
    while(no_of_piles--)
    {
        int pile;
        cin >> pile;
        
        if(pile%2 == 1)
            all_even = false;
    }
    
    cout << (all_even ? "second\n" : "first\n");
    return 0;
}
