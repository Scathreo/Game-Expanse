#ifndef HEADER_FILE_MODEL
#define HEADER_FILE_MODEL

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "map_square.h"
#include "thing_on_cell.h"
#include "mountain.h"
#include "structure.h"
#include "tree.h"

using namespace std;




class Model {
  private:
    MapSquare _map;
    
  public:
    // Constructor
    Model();  // Quick but not settable
    
    //Method
    static int  getRandomNumber(int, int);
    
    // Getter
    MapSquare * getMap();
};





/* ################################
 * ################################
 *           Constructor
 * ################################
 * ################################
 */
// Quickly create a model
Model::Model() {

  _map = MapSquare(100, 100);
  
  int x, y;
  int count = 0;
  for (x = 0; x < _map.getWidth(); x ++) {
    for (y = 0; y < _map.getHeight(); y ++) {
    
      switch ( Model::getRandomNumber(0.0, 4.0) ) {
      
        case Mountain::_TYPE:
        count++;
          _map.getCell(x, y)->setThingOnCell(new Mountain());
          break;
          
        case Structure::_TYPE:
          _map.getCell(x, y)->setThingOnCell(new Structure());
          break;
          
        case Tree::_TYPE:
          _map.getCell(x, y)->setThingOnCell(new Tree());
          break;
          
        default:
          break;
      
      }
    }
  }
  
  
};





/* ################################
 * ################################
 *             Method
 * ################################
 * ################################
 */
int Model::getRandomNumber(int lower, int upper) { 
  return (rand() % (upper - lower + 1)) + lower;
}



/* ################################
 * ################################
 *              Getter
 * ################################
 * ################################
 */
MapSquare * Model::getMap() { return & _map; }

#endif
