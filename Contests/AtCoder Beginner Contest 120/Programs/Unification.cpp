#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string S;
    cin >> S;

    const int MAX_ELEMENTS = 2;
    vector <int> frequency(MAX_ELEMENTS, 0);
    for(int i = 0; i < S.size(); i++)
        frequency[S[i] - '0']++;

    int minimum_frequency = min(frequency[0], frequency[1]);
    int answer = 2*minimum_frequency;

    cout << answer;
    return 0;
}
