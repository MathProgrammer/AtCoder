#include <iostream>

using namespace std;

int main()
{
    int no_of_operations, A, B;
    cin >> no_of_operations >> A >> B;

    long long max_biscuits = 0;

    if(B <= A + 2)
    {
        max_biscuits = no_of_operations + 1;
    }
    else if(B > A)
    {
        if(no_of_operations <= A)
        {
            max_biscuits = no_of_operations + 1;
        }
        else
        {
            max_biscuits = B;
            no_of_operations -= (A + 1);

            int no_of_cycles = no_of_operations/2;
            long long gain = B - A;

            max_biscuits += no_of_cycles*gain;

            no_of_operations %= 2;

            while(no_of_operations > 0)
            {
                max_biscuits++;

                no_of_operations--;
            }
        }
    }

    cout << max_biscuits;
    return 0;
}
