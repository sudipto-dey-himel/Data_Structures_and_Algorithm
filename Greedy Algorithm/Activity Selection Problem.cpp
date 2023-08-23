#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int start, finish;
};

bool compare(activity a, activity b)
{
    return (a.finish < b.finish);
}

void activitySelection(activity arr[], int size)
{
    sort(arr, arr + size, compare);
    int i = 0;
    cout << "After Activity Selection Sort :: " << endl;
    cout << arr[i].start << " " << arr[i].finish << endl;
    for (int j = 1; j < size; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << arr[j].start << " " << arr[j].finish << endl;
            i = j;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of Activities :: ";
    cin >> n;
    cout << "Enter the Activities :: " << endl;
    activity arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish;

    activitySelection(arr, n);

    return 0;
}

/*INPUT : 
Enter the number of Activities :: 3
Enter the Activities :: 
10 2
21 1
9 3

OUTPUT : 
After Activity Selection Sort :: 
21 1
10 2
9 3
*/
