#include <raylib.h>
#include<iostream>
#include<vector>
#include<raylib.h>
#include<map>

//****************************************************DECLARING COLOURS TO USE****************************************

extern const Color darkGret;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;


//**********************************************STORING VALUES OF COLORS******************************************************
    const Color darkGrey={26,31,40,255};
    const Color green={47,230,23,255};
    const Color red={232,18,18,255};
    const Color orange={226,116,17,255};
    const Color yellow={237,234,4,255};
    const Color purple={166,0,247,255};
    const Color cyan={21,204,209,255};
    const Color blue={13,64,216,255};

std::vector<Color> GetCellColors()
{
   return{darkGrey,green,red,orange,yellow,purple,cyan,blue};  
}


//******************************************MAKING GRID ********************************************************
class Grid{
private:

int numRows;
int numCols;
int cellSize;
std::vector<Color> colors;

public:
Grid();
void Intialize();
int grid[20][10];
void print();
void Draw();
};

//************************************************IMPIMENTATION*****************************************************************************************************
Grid::Grid()
{
    numRows=20;
    numCols=10;
    cellSize=30;
    Intialize();
    colors=GetCellColors();
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
           
        }
        std::cout<<std::endl;
    }
}


void Grid::Draw()
{
for(int row=0; row <numRows;row++)
{
    for(int column=0; column < numCols; column++)
    {
        int cellValue = grid[row][column];
        DrawRectangle(column*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);
    }
}
}
//***********************************************************POSITIONS**********************************************************************************

class Position
{
    public:
    Position(int row , int column);
    int row ;
    int column ;
};


//*************************************************************BOLCKS************************************************************************************
class Block
{
    public:
    Block();
    void Draw();
    void Move(int rows , int columns);
    std::vector<Position>  GetCellPosition();
    int id;
    std::map<int,std::vector<Position>> cells;
    
    private:
    int cellSize;
    int rotationState;
    std::vector<Color>colors;
    int rowOffset;
    int columnOffset;
};

//*******************************************************BLOKS TYPES***************************************************************************

Block::Block()
{
    cellSize=30;
    rotationState=0;
    colors = GetCellColors();
    rowOffset=0;
    columnOffset=0;


}
void Block:: Draw()
{
 std::vector<Position>tiles = GetCellPosition();
 for(Position item: tiles)
 {
    DrawRectangle(item.column*cellSize, item.row* cellSize, cellSize-1,cellSize-1, colors[id]);
 }
}


//***************************************************types of blocks*********************************************************************************

class LBlock: public Block{
public:
LBlock(){
    id=1;
    cells[0]={Position(0,2), Position(1,0), Position(1,1),Position(1,2)};
    cells[1]={Position(0,1), Position(1,1), Position(2,1),Position(2,2)};
    cells[2]={Position(1,0), Position(1,1), Position(1,2),Position(2,0)};
    cells[3]={Position(0,0), Position(0,1), Position(1,1),Position(2,1)};
    Move(0,3);
}
};

class JBlock: public Block{
public:
JBlock(){
    id=2;
    cells[0]={Position(0,0), Position(1,0), Position(1,1),Position(1,2)};
    cells[1]={Position(0,1), Position(0,2), Position(1,1),Position(2,1)};
    cells[2]={Position(1,0), Position(1,1), Position(1,2),Position(2,2)};
    cells[3]={Position(0,1), Position(1,1), Position(2,0),Position(2,1)};
     Move(0,3);
}
};

class IBlock: public Block{
public:
IBlock(){
    id=3;
    cells[0]={Position(1,0), Position(1,1), Position(1,2),Position(1,3)};
    cells[1]={Position(0,2), Position(1,2), Position(2,2),Position(3,2)};
    cells[2]={Position(2,0), Position(2,1), Position(2,2),Position(2,3)};
    cells[3]={Position(0,1), Position(1,1), Position(2,1),Position(3,1)};
     Move(-1,3);
}
};

class OBlock: public Block{
public:
OBlock(){
    id=4;
    cells[0]={Position(0,0), Position(0,1), Position(1,0),Position(1,1)};

     Move(0,4);
}
};


class SBlock: public Block{
public:
SBlock(){
    id=5;
    cells[0]={Position(0,1), Position(0,2), Position(1,0),Position(1,1)};
    cells[1]={Position(0,1), Position(1,1), Position(1,2),Position(2,2)};
    cells[2]={Position(1,1), Position(1,2), Position(2,0),Position(2,1)};
    cells[3]={Position(0,0), Position(1,0), Position(1,1),Position(2,1)};
     Move(0,3);
}
};


class TBlock: public Block{
public:
TBlock(){
    id=6;
    cells[0]={Position(0,1), Position(1,0), Position(1,1),Position(1,2)};
    cells[1]={Position(0,1), Position(1,1), Position(1,2),Position(2,1)};
    cells[2]={Position(1,0), Position(1,1), Position(1,2),Position(2,1)};
    cells[3]={Position(0,1), Position(1,0), Position(1,1),Position(2,1)};
     Move(0,3);
}
};


class ZBlock: public Block{
public:
ZBlock(){
    id=7;
    cells[0]={Position(0,0), Position(0,1), Position(1,1),Position(1,2)};
    cells[1]={Position(0,2), Position(1,1), Position(1,2),Position(2,1)};
    cells[2]={Position(1,0), Position(1,1), Position(2,1),Position(2,2)};
    cells[3]={Position(0,1), Position(1,0), Position(1,1),Position(2,0)};
     Move(0,3);
}
};

//******************************************MOVING BLOCKS*********************************************************************************
void Block::Move(int rows , int columns)
{
rowOffset+= rows;
columnOffset+= columns;
}

std::vector<Position> Block:: GetCellPosition()
{
 std:: vector<Position>tiles = cells[rotationState];
 std::vector<Position> movedTiles;
 for(Position item: tiles)
 {
    Position newPos = Position(item.row + rowOffset, item.column+ columnOffset);
    movedTiles.push_back(newPos);
 }
return movedTiles;
}

//****************************************************game class*****************************




//****************************************************IMPLITATION OF POSITION****************************************************************************

Position::Position(int row ,int column)
{
this -> row = row;
this -> column = column;
}




//************************************************************************************************************************************
int main()
{
    Color blue = {44, 44, 127, 255};
    InitWindow(300, 600, "kuldeep");
    SetTargetFPS(60);
    
Grid grid=Grid();

grid.print();
IBlock block= IBlock();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(blue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }
    CloseWindow();
}