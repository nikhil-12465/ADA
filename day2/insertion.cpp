// worst case :

#include <cstdlib>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{

    long size = 5;

    while (size != 100000000)
    {
        long arr[size];
        int p=size;

        for (int i = 0; i < size; i++)
        {
            arr[i] = p;
            p--;
        }
        
        
        auto start = high_resolution_clock::now();

     

        
        for (int i = 0; i < size; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0; j--)
            {
                if (arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j + 1] = temp;
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "size= " << size << "      " << "time= " << duration.count() << endl;

        size *= 5;
    }

    return 0;
}


// #include <cstdlib>
// #include <iostream>
// #include <chrono>
// using namespace std;
// using namespace std::chrono;
// int main()
// {

//     long size = 1000;

//     while (size != 1000000)
//     {
//         auto start = high_resolution_clock::now();

//         long N = 100;
//         long arr[size];

//         for (int i = 0; i < size; i++)
//         {
//             arr[i] = rand() % N;
//         }
//         for (int i = 0; i < size; i++)
//         {
//             int temp = arr[i];
//             int j = i - 1;
//             for (; j >= 0; j--)
//             {
//                 if (arr[j] > temp)
//                 {
//                     arr[j + 1] = arr[j];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             arr[j + 1] = temp;
//         }

//         auto end = high_resolution_clock::now();
//         auto duration = duration_cast<nanoseconds>(end - start);
//         cout << "size= " << size << "      " << "time= " << duration.count() << endl;

//         size *= 10;
//     }

//     return 0;
// }


// best CASE


// #include <cstdlib>
// #include <iostream>
// #include <chrono>
// using namespace std;
// using namespace std::chrono;
// int main()
// {

//     long size = 1000;

//     while (size != 1000000000)
//     {
//            long N = 100;
//         long arr[size];

//         for (int i = 0; i < size; i++)
//         {
//             arr[i] = N;
//             N++;
//         }
        
        
//         auto start = high_resolution_clock::now();

     

        
//         for (int i = 0; i < size; i++)
//         {
//             int temp = arr[i];
//             int j = i - 1;
//             for (; j >= 0; j--)
//             {
//                 if (arr[j] > temp)
//                 {
//                     arr[j + 1] = arr[j];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             arr[j + 1] = temp;
//         }

//         auto end = high_resolution_clock::now();
//         auto duration = duration_cast<nanoseconds>(end - start);
//         cout << "size= " << size << "      " << "time= " << duration.count() << endl;

//         size *= 10;
//     }

//     return 0;
// }



