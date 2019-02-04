#include <iostream>
#include <vector>

using namespace std;

const int MAX_BITS = 63;
int no_of_numbers;
vector <int> no_of_1s(MAX_BITS, 0);

int is_bit_set(long long n, int position)
{
    return ( (n & (1LL << position)) != 0);
}

long long get_mask_with_prefix_till(long long n, int replaced_one)
{
    long long mask = 0;

    for(int bit = MAX_BITS; bit >= 0; bit--)
    {
        if(bit > replaced_one)
        {
            if(is_bit_set(n, bit))
            {
                mask |= (1LL << bit);
            }
        }
        else if(bit == replaced_one)
        {
            continue;
        }
        else
        {
            if(2*no_of_1s[bit] < no_of_numbers)
            {
                mask |= (1LL << bit);
            }
        }
    }

    return mask;
}

long long get_value(vector <long long> &A, long long mask)
{
    long long sum = 0;

    for(int i = 1; i <= no_of_numbers; i++)
        sum += (A[i]^mask);

    return sum;
}

int main()
{
    long long K;
    cin >> no_of_numbers >> K;

    vector <long long> A(no_of_numbers + 1);
    for(int i = 1; i <= no_of_numbers; i++)
        cin >> A[i];

    for(int i = 1; i <= no_of_numbers; i++)
    {
        for(int bit = 0; bit <= MAX_BITS; bit++)
        {
            if(is_bit_set(A[i], bit))
            {
                no_of_1s[bit]++;
            }
        }
    }

    vector <long long> masks;
    masks.push_back(K);
    masks.push_back(0);

    for(int bit = MAX_BITS; bit >= 0; bit--)
    {
        if(is_bit_set(K, bit))
        {
            long long mask = get_mask_with_prefix_till(K, bit);

            masks.push_back(mask);
        }
    }

    long long maximum_value = 0;
    for(int m = 0; m < masks.size(); m++)
    {
        maximum_value = max(maximum_value, get_value(A, masks[m]));
    }

    cout << maximum_value;
    return 0;
}
