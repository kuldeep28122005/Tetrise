#include "grid.h"
#include<iostream>
Grid::Grid()
{
    numRows=20;
    numCols=10;
    cellSize=30;
    Intialize();
}
void Grid::Intialize()
{
    for(int row=0; row<numRows; row++)
    {
        for(int colum=0; colum<numCols;colum++)
        {
            grid[row][colum]=0;
        }
    }
}

void Grid::print()
{
for(int row=0; row<numRows; row++)
    {
        for(int colum=0; colum<numCols;colum++)
        {
           std::cout<<grid[row][colum]<<" ";
           std::cout<<std::endl;
        }
    }
}