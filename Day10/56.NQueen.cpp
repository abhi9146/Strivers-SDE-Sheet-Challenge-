// Problem Statement

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int row,int col,int n,vector<string>&board){
        int i=row,j=col;

        while(j>=0) if(board[row][j--]=='Q') return false;
        j=col;
        while(row>=0 && col>=0) if(board[row--][col--]=='Q') return false;
        while(j>=0 && i<n) if(board[i++][j--]=='Q') return false;

        return true;
    }

    void fun(int col,int n,vector<string>&board,vector<vector<string>>&res){
           if(col==n){
               res.push_back(board);
               return;
           }
           for(int row=0;row<n;row++){
              if(check(row,col,n,board)){
                  board[row][col]='Q';
                  fun(col+1,n,board,res);
                  board[row][col]='.';
              }
           }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        string s(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        } 
         
        fun(0,n,board,res);
        return res;
    }