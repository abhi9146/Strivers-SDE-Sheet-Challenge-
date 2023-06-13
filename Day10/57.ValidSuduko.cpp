

// Problem Statement

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells
*/

#include<bits/stdc++.h>
using namespace std;


bool find(vector<vector<char>>& board)
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]=='.'){
                for(char c='1';c<='9';c++){
                        if(is_valid(board,row,col,c)){
                            board[row][col]=c;
                            
                            if(find(board)==true)
                                return true;
                            else board[row][col]='.';
                        }
                }
                return false;
            }
        }
    }
    return true;
}

bool is_valid(vector<vector<char>>& board,int row,int col,char c)
{
    for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c) return false;
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    find(board);
}