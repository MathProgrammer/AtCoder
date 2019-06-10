#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add_1_to(string &L)
{
    int rightmost_zero = -1;
    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] == '0')
            rightmost_zero = i;
    }

    string answer;
    if(rightmost_zero == -1)
    {
        int no_of_ones = L.size();
        answer += '1';

        for(int i = 0; i < no_of_ones; i++)
            answer += '0';
    }
    else
    {
        answer = L;
        answer[rightmost_zero] = '1';

        for(int i = rightmost_zero + 1; i < L.size(); i++)
            answer[i] = '0';
    }

    return answer;
}

const int MOD = 1e9 + 7;
long long power_mod(long long x, long long power)
{
    long long answer = 1;

    while(power)
    {
        if(power%2)
            answer = (answer*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return answer;
}

int main()
{
    string L;
    cin >> L;

    L = add_1_to(L);

    vector <int> no_of_1s_till(L.size(), 0);
    no_of_1s_till[0] = (L[0] == '1');
    for(int i = 1; i < L.size(); i++)
        no_of_1s_till[i] = no_of_1s_till[i - 1] + (L[i] == '1');

    long long no_of_pairs = 0;
    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] == '0')
            continue;

        no_of_pairs += power_mod(2, no_of_1s_till[i] - 1)*power_mod(3, L.size() - i - 1);

        no_of_pairs %= MOD;
    }

    cout << no_of_pairs;
    return 0;
}
