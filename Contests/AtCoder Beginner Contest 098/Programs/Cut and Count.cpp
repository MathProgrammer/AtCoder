#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    int answer = 0;
    for(int i = 1; i < length - 1; i++)
    {
        const int NO_OF_ALPHABETS = 26;

        vector <int> X_has(NO_OF_ALPHABETS, false);
        for(int j = 0; j <= i; j++)
            X_has[S[j] - 'a'] = true;

        vector <int> Y_has(NO_OF_ALPHABETS, false);
        for(int j = i + 1; j < length; j++)
            Y_has[S[j] - 'a'] = true;

        int current_answer = 0;

        for(int alphabet = 0; alphabet < NO_OF_ALPHABETS; alphabet++)
            current_answer += (X_has[alphabet] && Y_has[alphabet]);

        answer = max(answer, current_answer);
    }

    cout << answer;
    return 0;
}
