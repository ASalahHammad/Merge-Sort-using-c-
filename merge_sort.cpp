#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> arr)
{
    int n = arr.size();
    if (n <= 1)
        return arr;
    // search left
    vector<int> arr_left;
    for (int i = 0; i < n / 2; i++)
    {
        arr_left.push_back(arr[i]);
    }
    vector<int> left = merge_sort(arr_left);
    // search right
    vector<int> arr_right;
    for (int i = n / 2; i < n; i++)
    {
        arr_right.push_back(arr[i]);
    }
    vector<int> right = merge_sort(arr_right);
    // merge
    vector<int> ans;
    for (int i = 0, j = 0; i <= n / 2 && j <= (n + 1) / 2;)
    {
        if (i != n / 2 && j != (n + 1) / 2) // Notice that the n+1 is just in case the right part of  the array has odd number of elements
        // example: if you compare [1] as left array and [2 3] as right array
        // Thank Allah the same code works for even numbers, the type of "j" is int...
        // So if I said there are 2 elements in the right array, that should evaluate to j = (2+1)/2 = 1
        {
            if (left[i] < right[j])
            {
                ans.push_back(left[i]);
                i++;
            }
            else
            {
                ans.push_back(right[j]);
                j++;
            }
        }
        else if (i == n / 2 && j != (n + 1) / 2)
        {
            ans.push_back(right[j]);
            j++;
        }
        else if (i != n / 2 && j == (n + 1) / 2)
        {
            ans.push_back(left[i]);
            i++;
        }
        else if (i == n / 2 && j == (n + 1) / 2)
            return ans;
    }
    return ans; // This is because VS code keeps showing a silly warning because I nested the return statement
    // it is also in case the program finishes the loop without returning anything (Theoretically impossible)
}

int main()
{
    vector<int> arr{5, 7, 2, 4, 3, 5, 9, 7, 6, 10, 8};
    vector<int> ans = merge_sort(arr);
    cout << "Array: [";
    int i=0;
    for (int a : arr)
    {
        if(i!=0)
            cout<<" ";
        cout << a;
        i++;
    }
    cout << "]\n";
    i = 0;
    cout << "Merge-Sorted: [";
    for (int a : ans)
    {
        if(i!=0)
            cout<<" ";
        cout << a;
        i++;
    }
    cout << "]\n";
    return 0;
}