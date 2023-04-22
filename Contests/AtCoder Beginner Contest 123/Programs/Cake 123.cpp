#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
typedef long long LL;

using namespace std;

void read_and_sort(vector <LL> &A, int n)
{
    A[0] = 1e15;

    for(int i = 1; i <= n; i++)
        cin >> A[i];

    sort(all(A), greater <LL>());
}

int main()
{
    int no_of_1_candles, no_of_2_candles, no_of_3_candles, no_of_chosen_cakes;
    cin >> no_of_1_candles >> no_of_2_candles >> no_of_3_candles >> no_of_chosen_cakes;

    vector <LL> cake_1(no_of_1_candles + 1, 0);
    read_and_sort(cake_1, no_of_1_candles);

    vector <LL> cake_2(no_of_2_candles + 1, 0);
    read_and_sort(cake_2, no_of_2_candles);

    vector <LL> cake_3(no_of_3_candles + 1, 0);
    read_and_sort(cake_3, no_of_3_candles);

    vector <LL> chosen_cakes;
    for(int i = 1; i <= no_of_1_candles; i++)
    {
        for(int j = 1; j <= no_of_2_candles; j++)
        {
            for(int k = 1; k <= no_of_3_candles; k++)
            {
                if(i*j*k > no_of_chosen_cakes)
                    break;

                chosen_cakes.push_back(cake_1[i] + cake_2[j] + cake_3[k]);
            }
        }
    }

    sort(all(chosen_cakes), greater <LL>());

    for(int i = 0; i < no_of_chosen_cakes; i++)
        cout << chosen_cakes[i] << "\n";

    return 0;
}
