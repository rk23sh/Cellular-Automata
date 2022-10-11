/*
Conway's game of life uses the following set of rules to produce simulation :-
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/



#include<iostream>
#include<chrono>
#include<thread>
#include<vector>

using namespace std;

// size of host that hosts the evolving organisms
int x = 30;
int y = 30;

int alive(vector<vector<char>> matrix,int i,int j){
    if((0<=i and i<x) and (0<=j and j<y)){
        return (matrix[i][j]=='X')?1:0;
    }
    return 0;
}

int countNeighbours(vector<vector<char>> matrix, int i, int j){
    int count = alive(matrix, i - 1, j - 1) + alive(matrix, i - 1, j) + alive(matrix, i - 1, j + 1) + alive(matrix, i,j - 1)+
            alive(matrix, i, j + 1) + alive(matrix, i + 1, j - 1) + alive(matrix, i + 1, j) + alive(matrix, i + 1,j + 1);

    return count;
}

void cglife(){
    // "matrix" produces the first generation of organisms
    vector<vector<char>> matrix(x,vector<char>(y,'.'));
    matrix[10][10] = matrix[10][11] = matrix[11][10] = matrix[12][10] = matrix[11][9] = 'X';
    
    while(true){
        
        // "mat" produces the next generation of organisms
        vector<vector<char>> mat(x,vector<char>(y,'.'));
        
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                bool alive = (matrix[i][j] == 'X')? true:false;
                int count = countNeighbours(matrix, i, j);
                
                if (alive and count > 3) mat[i][j] = '.';
                else if (alive and count < 2) mat[i][j] = '.';
                else if (not alive and count == 3) mat[i][j] = 'X';
                else mat[i][j] = matrix[i][j];

                cout<<matrix[i][j]<<" ";
            }
            printf("\n");
        }
        
        matrix = mat;
        
        // slowing down the simulation for human eye to observe changes in generation properly
        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main(){
    cglife();
    return 0;
}
