#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int no_of_tickets, no_of_discounts;
    cin >> no_of_tickets >> no_of_discounts;

    priority_queue <int> prices;
    for(int i = 1; i <= no_of_tickets; i++)
    {
        int price;
        cin >> price;

        prices.push(price);
    }

    while(no_of_discounts > 0 && prices.top() > 0)
    {
        int most_expensive = prices.top();

        prices.pop();

        prices.push(most_expensive/2);

        no_of_discounts--;
    }

    long long total_price = 0;
    while(!prices.empty())
    {
        total_price += prices.top();

        prices.pop();
    }

    cout << total_price;
    return 0;
}
