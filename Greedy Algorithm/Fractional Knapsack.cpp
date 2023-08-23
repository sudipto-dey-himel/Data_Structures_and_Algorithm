#include <bits/stdc++.h>
using namespace std;

struct Item
{
    double profit, weight;
};

bool compare(Item a, Item b)
{
    double pw1 = a.profit / a.weight;
    double pw2 = b.profit / b.weight;

    return (pw1 > pw2);
}

double fractional_Knapsack(Item arr[], int size, double Capacity)
{
    sort(arr, arr + size, compare);
    double totalProfit = 0.0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].weight <= Capacity)
        {
            Capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else
        {
            totalProfit += Capacity * arr[i].profit / arr[i].weight;
            Capacity = 0.0;
        }
    }

    return totalProfit;
}

int main()
{
    int n;
    cout << "Enter the number of Items :: ";
    cin >> n;
    Item arr[n];
    cout << "Enter the Items :: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i].profit >> arr[i].weight;

    int bag_capacity;
    cout << "Enter the Capacity :: ";
    cin >> bag_capacity;

    cout << "Profit = " << fractional_Knapsack(arr, n, bag_capacity);

    return 0;
}


/*INPUT : 
Enter the number of Items :: 3
Enter the Items :: 
10 50
100 20
120 30

OUTPUT : 
Enter the Capacity :: 50
Profit = 220
*/
