#include <iostream>

using namespace std;

typedef long long LL;

void set_bit(LL &n, int position)
{
    n |= (1LL << position);
}

LL no_of_set_bits(LL n, int position)
{
    LL set_bits = 0; 

    LL weight = (1LL << position);
    
    LL no_of_blocks = (n)/weight; 

    set_bits += (no_of_blocks/2)*weight;

    LL total_reached = no_of_blocks*weight; 

    if(no_of_blocks%2 == 1)
      set_bits += n - total_reached + 1;
  
    return set_bits;
}

int main()
{
    LL left, right;
    cin >> left >> right;

    LL xor_answer = 0;

    const int MAX_BITS = 63;
    for(int i = 0; i < MAX_BITS; i++)
    {
        LL no_of_set_bits_here = no_of_set_bits(right, i);

      	if(left != 0) 
          no_of_set_bits_here -= no_of_set_bits(left - 1, i);
      
        if(no_of_set_bits_here%2 == 1)
            set_bit(xor_answer, i);
    }

    cout << xor_answer;
    return 0;
}
