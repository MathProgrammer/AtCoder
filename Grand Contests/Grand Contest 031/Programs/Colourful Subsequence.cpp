#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    const int NO_OF_ALPHABETS = 26, MOD = 1e9 + 7;;
    vector <long long> frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < length; i++)
        frequency[S[i] - 'a']++;

    long long colourful_sequences = 1;
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        colourful_sequences = ( (colourful_sequences*(frequency[alpha] + 1))%MOD );

    colourful_sequences = (colourful_sequences + MOD - 1)%MOD;

    cout << colourful_sequences;
    return 0;
}
