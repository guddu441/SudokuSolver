#include <iostream>
# define n 9
using namespace std;

bool isEmptySudoku(int sudoku[n][n],int &i,int &j){
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
         if(sudoku[i][j]==0){
            return true;
         }
       }
    }
    return false;
}

bool isPresentInRow(int sudoku[n][n],int r,int num){
    for(int i=0;i<n;i++){
        if(sudoku[r][i]==num)
            return true;
    }
    return false;
}

bool isPresentInCol(int sudoku[n][n],int c,int num){
    for(int i=0;i<n;i++){
        if(sudoku[i][c]==num)
            return true;
    }
    return false;
}

bool isPresentInBox(int sudoku[n][n],int r,int c,int num){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[r+i][c+j]==num)
                return true;
        }
    }
    return false;
}

bool isSafe(int sudoku[n][n],int i,int j, int num){
    return !isPresentInRow(sudoku,i,num) && !isPresentInCol(sudoku,j,num) && !isPresentInBox(sudoku,i-i%3,j-j%3,num);
}

bool SolveSudoku(int sudoku[n][n]){

    int row, col;
    if(!isEmptySudoku(sudoku,row,col)){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(isSafe(sudoku,row,col,i)){
            sudoku[row][col]=i;
            if(SolveSudoku(sudoku))
                return true;        //success
            sudoku[row][col]=0;     //failure....So revert back and check again
        }
    }
    return false;
}

int main()
{
    int sudoku[n][n];
    cout<<"Enter the sudoku array (3x3) (Put 0 in empty spaces):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sudoku[i][j];
        }
    }
    cout<<endl;
    if(SolveSudoku(sudoku)){
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                 cout<<sudoku[i][j]<<" ";
           }
            cout<<endl;
        }
    }
    else
         cout<<"No solution exists";
    return 0;
}
