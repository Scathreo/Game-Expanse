#ifndef HEADER_FILE_CELL
#define HEADER_FILE_CELL

#include <iostream>
#include <sstream>
#include <string>

#include "thing_on_cell.h"


using namespace std;


/*
 * A cell from a square grid
 * Have a weight.
 * Can have something on it.
 */
class CellSquare {
  private:
    int _weight; // A cell have a weight. Used for moving on it.
    ThingOnCell * _thing;  // A cell can have something on it.
    
  public:
    // Constructor
    CellSquare(int);   // Create a cell with a given weight and nothing on it.
    CellSquare();      // Quick but not settable.
    CellSquare(int, ThingOnCell *);// Create a cell with a given weight and thing.
    // Method
    // Getter
    ThingOnCell * getThingOnCell();
    int getWeight();
    // Setter
    int setThingOnCell(ThingOnCell *);
    // Other
    string to_String(); // Create a string that describe the object.
};





/* ################################
 * ################################
 *           Constructor
 * ################################
 * ################################
 */
// Create a cell with a given weight and no item.
CellSquare::CellSquare(int weight) {
  _weight = weight;
  _thing = new ThingOnCell();
}

// Quickly create a CellSquare.
CellSquare::CellSquare() : CellSquare(1) {}

// Create a CellSquare with a given weight and ThingOnCell.
CellSquare::CellSquare(int weight, ThingOnCell * thing) : CellSquare(weight) {
  _thing = thing;
}





/* ################################
 * ################################
 *              Getter
 * ################################
 * ################################
 */
ThingOnCell * CellSquare::getThingOnCell() { return _thing; };

int           CellSquare::getWeight()      { return _weight; };





/* ################################
 * ################################
 *             Setter
 * ################################
 * ################################
 */
int CellSquare::setThingOnCell(ThingOnCell * thing) {
  _thing = thing;
  return 0;
};





/* ################################
 * ################################
 *              Other
 * ################################
 * ################################
 */
// Create a string that describe the object.
string CellSquare::to_String() {
  
  std::stringstream sstm;
  sstm << "Weight : " << _weight;
  return sstm.str();
};


inline std::ostream & operator<<(std::ostream & Str, CellSquare v) { 
  // print something from v to str, e.g: Str << v.getX();
  Str << "Weight : " << v.getWeight();
  return Str;
};



#endif
