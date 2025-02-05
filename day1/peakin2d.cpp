// bruteforce

// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <vector>
// using namespace std;

// void findpeak(vector<vector<int>> &a, int m, int n) {
//     int count = 0;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
            
         
//             if (i == 0 && j == 0 && j + 1 < n && i + 1 < m && a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

//             if (i == m - 1 && j == n - 1 && i - 1 >= 0 && j - 1 >= 0 && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

        
//             if (i > 0 && j > 0 && i < m - 1 && j < n - 1 &&
//                 a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] &&
//                 a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

           
//             if (i == 0 && j > 0 && j < n - 1 && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

         
//             if (i == m - 1 && j > 0 && j < n - 1 && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

//             if (j == 0 && i > 0 && i < m - 1 && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }

           
//             if (j == n - 1 && i > 0 && i < m - 1 && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) {
//                 cout << i << " , " << j << " is the position of the peak" << endl;
//                 return;
//             }
//         }
//     }

//     cout << "No peak found" << endl;
// }

// int main()
// {

//     cout << "enter the values of the row and column " << endl;
//     int m, n;
//     cout << "row ?" << endl;
//     cin >> m;
//     cout << "column ?" << endl;
//     cin >> n;

//     vector<vector<int>> a(m, vector<int>(n));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     findpeak(a, m, n);

//     return 0;
// }
// the process of solving the above problem to tough but it is simple and cover all the possible cases which can be drawn to it 


//  complexity is lower 

#include<iostream>
#include<vector>

using namespace std;

int max(vector<vector<int>>& mat,int n,int m,int col){
    int maxval=0;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxval){
            maxval=mat[i][col];
            index=i;
        }
    }
    return index;
}
    void findPeak(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=max(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1]:-1;
            int right=mid+1<m ? mat[row][mid+1]: -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                cout<<row<<"  and  "<<mid <<"is the peak coordinates"<<endl;
                return ;
            }else if(mat[row][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
       cout<<"no peak found"<<endl;
    }

    int main(){
             cout << "enter the values of the row and column " << endl;
    int m, n;
    cout << "row ?" << endl;
    cin >> m;
    cout << "column ?" << endl;
    cin >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

findPeak(a);
    

        return 0;
    }


