#include <iostream>
#include <vector>
#include <iostream>
#include <vector>

void markRow(std::vector<std::vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(std::vector<std::vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void setMatrixZero2(std::vector<std::vector<int>>&  matrix)
{

    ///complexity of 2(N*M) + (N+M)

    std::vector<std::pair<int,int>>  markedrc;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j]==0)
            {
                markRow(matrix,matrix.size(),matrix[i].size(),i);
                markCol(matrix,matrix.size(),matrix[i].size(),j);
            }
        }
    }
    
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j]==-1)
                matrix[i][j]=0;
        }
    }
}



void setMatrixZero(std::vector<std::vector<int>>&  matrix)
{

    ///complexity of N*M + N^2
    // space complexity N

    

    std::vector<std::pair<int,int>>  markedrc;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j]==0)
                markedrc.push_back({i,j});
        }
    }

    for (size_t i = 0; i < markedrc.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            matrix[markedrc[i].first][j] = 0;
            matrix[j][markedrc[i].second] = 0;
        }
        
    }
}

int main(int, char**){
    std::cout << "Hello, from MatrixZero!\n";

    std::vector<std::vector<int>> matrix{{1,1,1},{1,0,1}, {1,1,0}};
    std::vector<std::vector<int>> matrix1{{1,1,1},{1,0,1}, {1,1,1}};
    for(auto i=0;i<matrix.size();++i)
    {
        for (auto j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
        
    }
    setMatrixZero(matrix);
    std::cout << "after setting matrix to 0" << std::endl;
    for(auto i=0;i<matrix.size();++i)
    {
        for (auto j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
        
    }
    std::cout << "after setting matrix to 0 optimized approach" << std::endl;
    matrix = matrix1;
    setMatrixZero2(matrix);
    for(auto i=0;i<matrix.size();++i)
    {
        for (auto j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
        
    }
}
