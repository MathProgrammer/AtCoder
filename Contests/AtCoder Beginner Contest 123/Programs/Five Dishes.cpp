#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int NO_OF_DISHES = 5;
    vector <int> A(NO_OF_DISHES + 1);
    for(int i = 1; i <= NO_OF_DISHES; i++)
    {
        cin >> A[i];
    }

    int total_time = 0;
    int time_saved = 0;
    for(int i = 1; i <= NO_OF_DISHES; i++)
    {
        int remaining = (A[i]%10 != 0 ? 10 - A[i]%10 : 0);
        time_saved = max(time_saved, remaining);

        total_time += A[i] + remaining;
    }
    total_time -= time_saved;

    cout << total_time << "\n";

    return 0;
}
