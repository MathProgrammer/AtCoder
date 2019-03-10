#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct store
{
    long long price, cans;

    store(){}

    const int operator<(const store &S)
    {
        return (price < S.price);
    }
};

int main()
{
    int no_of_stores, no_of_cans;
    cin >> no_of_stores >> no_of_cans;

    vector <store> S(no_of_stores);
    for(int i = 0; i < no_of_stores; i++)
        cin >> S[i].price >> S[i].cans;

    sort(all(S));

    long long total_price = 0, remaining_cans = no_of_cans;
    for(int i = 0; i < no_of_stores; i++)
    {
        long long cans_here = min(S[i].cans, remaining_cans);

        total_price += cans_here*S[i].price;

        remaining_cans -= cans_here; 
    }

    cout << total_price;
    return 0;
}
