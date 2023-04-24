#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
typedef long long LL;
using namespace std;

int ceil(LL numerator, LL denominator)
{
    int quotient = numerator/denominator;
    int remainder_exists = (numerator%denominator != 0);

	return (quotient + remainder_exists);
}

int possible(vector <LL> H, LL A, LL B, LL explosions)
{
	for(int i = 1; i < H.size(); i++)
	{
		H[i] -= (explosions*B);
	}

	LL explosions_used = 0;
	for(int i = H.size() - 1; i > 0 && H[i] > 0; i--)
	{
		explosions_used += ceil(H[i], A - B);
	}

	return (explosions_used <= explosions);
}

int main()
{
    int no_of_monsters, A, B;
    cin >> no_of_monsters >> A >> B;

    vector <LL> health(no_of_monsters + 1);
    for(int i = 1; i <= no_of_monsters; i++)
    	cin >> health[i];

    sort(all(health));

    int left_explosions = 1, right_explosions = 1e9;
    while(left_explosions <= right_explosions)
    {
    	int mid_explosions = (left_explosions + right_explosions) >> 1;

    	if(possible(health, A, B, mid_explosions))
    	{
    		if(mid_explosions == left_explosions || !possible(health, A, B, mid_explosions - 1))
    		{
    			cout << mid_explosions;
    			break;
    		}
    		else
    		{
    			right_explosions = mid_explosions - 1;
    		}
    	}
    	else
    	{
    		left_explosions = mid_explosions + 1;
    	}
    }
	return 0;
}

