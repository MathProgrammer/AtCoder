#include <iostream>
#include <string>

using namespace std;

int main()
{
    string steps;
    cin >> steps;

    int easily_playable = true;
    for(int i = 0; i < steps.size(); i++)
    {
        if( ((i%2 == 0) && steps[i] == 'L') || ((i%2 == 1) && steps[i] == 'R') )
        {
            easily_playable = false;
        }
    }

    cout << (easily_playable ? "Yes\n" : "No\n");
    return 0;
}
