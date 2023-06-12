//Problem Statement :
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

*/

#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix){
	int n=matrix.size(),m=matrix[0].size();

	vector<int>row(n,1),col(m,1);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0) {
				row[i]=0;col[j]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			matrix[i][j] = matrix[i][j]*row[i]*col[j];
		}
	}
}

int main(){
   
   int n,m;cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0)); ;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         cin>>matrix[i][j];

    setZeros(matrix);
    cout << "The Final matrix is: \n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}