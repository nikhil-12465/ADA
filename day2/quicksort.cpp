// here we go the with best/avgcase 

// #include <cstdlib>
// #include <iostream>
// #include<vector>

// #include <chrono>
// using namespace std;
// using namespace std::chrono;


// int partition(vector<int> &a, int low, int high)
// {
//     int p = a[low];
//     int i = low;
//     int j = high + 1;

//     while (i < j)
//     {

//         do
//         {
//             i = i + 1;
//         } while (i <= high && a[i] <= p);
//         do
//         {
//             j = j - 1;
//         } while (j >= low && a[j] > p);
//         if (i < j)
//         {
//             swap(a[i], a[j]);
//         }
//     }

//     swap(a[low], a[j]);
//     return j;
// }

// void quick_sort(vector<int> &a, int low, int high)
// {
//     if (low < high)
//     {
//         int z = partition(a, low, high);
//         quick_sort(a, low, z-1);
//         quick_sort(a, z + 1, high);
//     }
// }
// int main()
// {

//     long size = 10;
//     int N=10000;


//     while (size != 10000000)
//     {
//         vector<int> a(size);
    
//     for (int i = 0; i < size; i++)
//     {
//          a[i] = rand() % N;
//     }

//     int low = 0;
//     int high = size- 1;
        
//         auto start = high_resolution_clock::now();

//       quick_sort(a, low, high);

//         auto end = high_resolution_clock::now();
//         auto duration = duration_cast<nanoseconds>(end - start);
//         cout << "size= " << size << "      " << "time= " << duration.count() << endl;

//         size *= 10;
//     }

//     return 0;
// }


// worstcase complexity :

#include <cstdlib>
#include <iostream>
#include<vector>

#include <chrono>
using namespace std;
using namespace std::chrono;


int partition(vector<int> &a, int low, int high)
{
    int p = a[low];
    int i = low;
    int j = high + 1;

    while (i < j)
    {

        do
        {
            i = i + 1;
        } while (i <= high && a[i] <= p);
        do
        {
            j = j - 1;
        } while (j >= low && a[j] > p);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[j]);
    return j;
}

void quick_sort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int z = partition(a, low, high);
        quick_sort(a, low, z-1);
        quick_sort(a, z + 1, high);
    }
}
int main()
{

    long size = 125;
    int N=size;


    while (size != 100000)
    {
        vector<int> a(size);
    
    for (int i = 0; i < size; i++)
    {
         a[i] =  N;
         N--;
    }

    int low = 0;
    int high = size- 1;
        
        auto start = high_resolution_clock::now();

      quick_sort(a, low, high);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "size= " << size << "      " << "time= " << duration.count() << endl;

        size *= 5;
    }

    return 0;
}