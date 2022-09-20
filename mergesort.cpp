#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
extern "C" {
    #include "write.h"
}
using namespace std;

typedef double data_type; // change this if you want to read data of different type

vector<data_type> mergesort(vector<data_type> arr);

int main(int argc, char *argv[])
{
    FILE *sorted = NULL;
    if(argc>2)
    {
        cout<<"Usage: ./mergesort [filename]\n";
        return 1;
    }
    vector<data_type> arr;
    if(argc==2)
    {
        if(strcmp(argv[1], "nums.dat")==0)
        {
            if(!generate_random())
            {
                cout<<"generate_random failed\n";
                return 1;
            }
        }
        FILE *f = fopen(argv[1], "r");
        if(f==NULL)
        {
            cout<<"Couldn't open file: "<<argv[1]<<"\n";
            return 1;
        }
        data_type *read_num = (data_type*) malloc(sizeof(data_type));
        while(fread(read_num, sizeof(data_type), 1, f)>0)
        {
            arr.push_back(*read_num);
        }
        fclose(f);
        free(read_num);
        sorted = fopen("sorted.dat", "w");
    }
    else
    {
        cout<<"This is an array defined in the code, you can type ./mergesort [filename] to try sorting numbers in a file (written in binary), or you can type ./mergesort \"nums.dat\" instead, which shall generate a file called \"nums.dat\" with random numbers in it and sort them\n";
        arr = {5, 7, 2, 4, 3, 5, 9, 7, 6, 10, 8};
    }
    vector<data_type> ans = mergesort(arr);
    cout << "\nArray: [";
    int i=0;
    for (data_type a : arr)
    {
        if(i!=0)
            cout<<" ";
        cout << a;
        i++;
    }
    cout << "]\n\n";
    i = 0;
    cout << "Merge-Sorted: [";
    for (data_type a : ans)
    {
        if(sorted!=NULL)
        {
            fwrite(&a, sizeof(data_type), 1, sorted);
        }
        if(i!=0)
            cout<<" ";
        cout << a;
        i++;
    }
    cout << "]\n\n";
    if(sorted!=NULL)
    {
        fclose(sorted);
    }
    return 0;
}

vector<data_type> mergesort(vector<data_type> arr)
{
    int n = arr.size();
    if (n <= 1)
        return arr;
    // search left
    vector<data_type> arr_left;
    for (int i = 0; i < n / 2; i++)
    {
        arr_left.push_back(arr[i]);
    }
    vector<data_type> left = mergesort(arr_left);
    // search right
    vector<data_type> arr_right;
    for (int i = n / 2; i < n; i++)
    {
        arr_right.push_back(arr[i]);
    }
    vector<data_type> right = mergesort(arr_right);
    // merge
    vector<data_type> ans;
    for (int i = 0, j = 0; i <= n / 2 && j <= (n + 1) / 2;)
    {
        if (i != n / 2 && j != (n + 1) / 2) // Notice that the n+1 is just in case the right part of the array has odd number of elements
        // example: if you compare [1] as left array and [2 3] as right array
        // Thank Allah the same code works for even numbers, the type of "j" is int...
        // So if there are 2 elements in the right array, that should evaluate to:j = (2+1)/2 = 1
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