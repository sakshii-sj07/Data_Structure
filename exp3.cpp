#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in array : ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element for search : ";
    cin >> key;

    cout << "\n-----CHOICES-----" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter choice : ";

    int ch;
    cin >> ch;

    switch(ch)
    {
        case 1:
        {
            bool foundLinear = false;

            for(int i = 0; i < n; i++)
            {
                if(arr[i] == key)
                {
                    cout << "Element found at index : " << i << endl;
                    foundLinear = true;
                    break;
                }
            }

            if(!foundLinear)
            {
                cout << "Element not found" << endl;
            }
            break;
        }

        case 2:
        {
            int low = 0, high = n - 1;
            bool foundBinary = false;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(arr[mid] == key)
                {
                    cout << "Element found at index : " << mid << endl;
                    foundBinary = true;
                    break;
                }
                else if(arr[mid] < key)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if(!foundBinary)
            {
                cout << "Element not found" << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
