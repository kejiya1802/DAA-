#include <iostream>
using namespace std;

void merge(int a[], int small, int mid, int large)
{
    int x = small;
    int y = mid + 1;
    int temp[100];
    int z = 0;

    while (x <= mid && y <= large)
    {
        if (a[x] < a[y])
        {
            temp[z++] = a[x++];
        }
        else
        {
            temp[z++] = a[y++];
        }
    }

    while (x <= mid)
    {
        temp[z++] = a[x++];
    }

    while (y <= large)
    {
        temp[z++] = a[y++];
    }

    for (int i = small, k = 0; i <= large; i++, k++)
    {
        a[i] = temp[k];
    }
}

void divide(int a[], int small, int large)
{
    if (small < large)
    {
        int mid = (small + large) / 2;

        divide(a, small, mid);
        divide(a, mid + 1, large);
        merge(a, small, mid, large);
    }
}

int main()
{
    int a[] = {5, 2, 9, 1, 3};
    int n = 5;

    divide(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
