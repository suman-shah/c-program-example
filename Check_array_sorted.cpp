#include <iostream>
using namespace std;

bool check_sorted(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << check_sorted(a, n);

    return 0;
}