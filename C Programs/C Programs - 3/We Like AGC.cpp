#include <iostream>
#include <vector>

using namespace std;

const int N = 100 + 5, NO_OF_LETTERS = 4, MOD = 1e9 + 7, T_INDEX = 3;
long long no_of_strings[N][NO_OF_LETTERS][NO_OF_LETTERS][NO_OF_LETTERS];
char letter[NO_OF_LETTERS] = {'A', 'C', 'G', 'T'};

int ok(int last_1, int last_2, int last_3, int last_4)
{
    char l1 = letter[last_1], l2 = letter[last_2], l3 = letter[last_3], l4 = letter[last_4];

    if(l1 == 'A' && l2 == 'G' && l4 == 'C')
        return false;
    if(l1 == 'A' && l3 == 'G' && l4 == 'C')
        return false;
    if(l1 == 'A' && l2 == 'G' && l3 == 'C')
        return false;
    if(l2 == 'A' && l3 == 'G' && l4 == 'C')
        return false;
    if(l1 == 'G' && l2 == 'A' && l3 == 'C')
        return false;
    if(l2 == 'G' && l3 == 'A' && l4 == 'C')
        return false;
    if(l1 == 'A' && l2 == 'C' && l3 == 'G')
        return false;
    if(l2 == 'A' && l3 == 'C' && l4 == 'G')
        return false;

    return true;
}

int main()
{
    int length;
    cin >> length;

    vector <long long> total(length + 1, 0);

    for(int i = 1; i <= length; i++)
    {
        for(int last_1 = 0; last_1 < NO_OF_LETTERS; last_1++)
        {
            for(int last_2 = 0; last_2 < NO_OF_LETTERS; last_2++)
            {
                for(int last_3 = 0; last_3 < NO_OF_LETTERS; last_3++)
                {
                    no_of_strings[i][last_1][last_2][last_3] = 0;

                    for(int last_4 = 0; last_4 < NO_OF_LETTERS; last_4++)
                    {
                        if(i == 1)
                        {
                            no_of_strings[i][last_1][T_INDEX][T_INDEX] = 1;
                        }
                        else if(i == 2)
                        {
                            no_of_strings[i][last_1][last_2][T_INDEX] = 1;
                        }
                        else if(i == 3)
                        {
                            if(ok(T_INDEX, last_3, last_2, last_1))
                            {
                                no_of_strings[i][last_1][last_2][last_3] = 1;
                            }
                        }
                        else if(ok(last_4, last_3, last_2, last_1))
                        {
                            no_of_strings[i][last_1][last_2][last_3] += no_of_strings[i - 1][last_2][last_3][last_4];
                        }
                    }

                    no_of_strings[i][last_1][last_2][last_3] %= MOD;

                    total[i] = (total[i] + no_of_strings[i][last_1][last_2][last_3])%MOD;
                }
            }
        }
    }

    cout << total[length];
    return 0;
}
