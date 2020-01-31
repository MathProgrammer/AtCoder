#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    
    const int NO_OF_ALPHABETS = 26;
    vector <vector <int> > locations(NO_OF_ALPHABETS);
    for(int i = 0; i < S.size(); i++)
    {
        locations[S[i] - 'a'].push_back(i);
    }
    
    int no_of_concatenations = 1, matched_prefix = -1;
    for(int i = 0; i < T.size(); i++)
    {
        if(locations[T[i] - 'a'].size() == 0)
        {
            cout << "-1\n";
            
            return 0;
        }
        
        auto it = upper_bound(locations[T[i] - 'a'].begin(), locations[T[i] - 'a'].end(), matched_prefix);
        
        if(it == locations[T[i] - 'a'].end())
        {
            no_of_concatenations++;
            
            matched_prefix = locations[T[i] - 'a'][0];
        }
        else
        {
            matched_prefix = *it;
        }
    }
    
    long long final_length = (no_of_concatenations - 1)*1LL*S.size() + (matched_prefix + 1);
    cout << final_length << "\n";
    
    return 0;
}
