#include <iostream>
#include <vector>

using namespace std;

const int NO_OF_BITS = 21;
vector <int> sum(NO_OF_BITS, 0);

int is_bit_set(long long &n, int position)
{
    return ( (n&(1LL << position)) != 0);
}

int at_most_one_bit_set()
{
    for(int i = 0; i < NO_OF_BITS; i++)
        if(sum[i] > 1)
            return false;

    return true;
}

void add(long long n)
{
    for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        if(is_bit_set(n, bit))
            sum[bit]++;
    }
}

void take_out(long long n)
{
   for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        if(is_bit_set(n, bit))
            sum[bit]--;
    }
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    int left = 0, right = 0;
    long long good_subarrays = 0;

    while(left < no_of_elements)
    {
        take_out(A[left]);
        left++;

        while(right < no_of_elements)
        {
            right++;
            add(A[right]);

            if(!at_most_one_bit_set())
            {
                take_out(A[right]);

                right--;

                break;
            }
        }

        good_subarrays += (right - (left - 1));
    }

    cout << good_subarrays;
    return 0;
}

