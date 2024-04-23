#pragma once
class Grid{
private:
int numRows;
int numCols;
int cellSize;
public:
Grid();
void Intialize();
int grid[20][10];
void print();
};