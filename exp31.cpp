#include <iostream>
using namespace std;

// -------- Merge Sort Methods --------
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// -------- Quick Sort Methods --------
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// -------- Main --------
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];

    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n----- SORTING MENU -----" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Enter choice: ";

    int ch;
    cin >> ch;

    switch (ch)
    {
        case 1: // Bubble Sort
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        int temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
            break;

        case 2: // Selection Sort
            for (int i = 0; i < n - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] < a[min])
                        min = j;
                }
                int temp = a[min];
                a[min] = a[i];
                a[i] = temp;
            }
            break;

        case 3: // Insertion Sort
            for (int i = 1; i < n; i++)
            {
                int key = a[i];
                int j = i - 1;

                while (j >= 0 && a[j] > key)
                {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = key;
            }
            break;

        case 4: // Merge Sort
            mergeSort(a, 0, n - 1);
            break;

        case 5: // Quick Sort
            quickSort(a, 0, n - 1);
            break;

        default:
            cout << "Invalid choice";
            return 0;
    }

    cout << "\nSorted Array:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
