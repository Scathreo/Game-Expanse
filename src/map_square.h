#ifndef HEADER_FILE_MAP
#define HEADER_FILE_MAP

#include <iostream>
#include <string>

#include "cell_square.h"


using namespace std;

/* The map of the game.
 * Square grid with height and width.
 */
class MapSquare {

  private:
    int _height; // The height of the map (nb of square)
    int _width;  // The width  of the map (nb of square)
    CellSquare* _grid; // The map. A linear array of cells.
    
  public:
    // Constructor
    MapSquare();          // Quick but not settable
    MapSquare(int, int);  // Can input a height and width
    
    // Method
    CellSquare * getCell(int, int);     // Get a cell with given coordonates
    int setCell(int, int, CellSquare);  // Set a cell with given coordonates
    
    // Getter
    int getWidth();
    int getHeight();
};





/* ################################
 * ################################
 *           Constructor
 * ################################
 * ################################
 */
// Quickly create a MapSquare
MapSquare::MapSquare() : MapSquare(10, 10) {}

// Create a MapSquare with given height and width
MapSquare::MapSquare(int height, int width) {
  _height = height;
  _width = width;
  _grid = new CellSquare[_width * _height];
}





/* ################################
 * ################################
 *             Method
 * ################################
 * ################################
 */
// Get a cell with given coordonates
CellSquare * MapSquare::getCell(int x, int y) {
  //if (x < 0 || x >= width) return NULL;
  //if (y < 0 || y >= height) return NULL;
  return & _grid[y * _width + x];
}

// Set a cell with given coordonates
int MapSquare::setCell(int x, int y, CellSquare cell) {
  //if (x < 0 || x >= width) return -1;
  //if (y < 0 || y >= height) return -1;
  _grid[y * _width + x] = cell;
  return 0;
}





/* ################################
 * ################################
 *              Getter
 * ################################
 * ################################
 */
int MapSquare::getWidth()  { return _width; }
int MapSquare::getHeight() { return _height; }

#endif
