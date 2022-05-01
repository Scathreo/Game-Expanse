#ifndef HEADER_FILE_THING_ON_CELL_MOUNTAIN
#define HEADER_FILE_THING_ON_CELL_MOUNTAIN
#include <iostream>

#include "thing_on_cell.h"


using namespace std;


/*
 * Lorem
 */
class Mountain : public ThingOnCell {
  private:
        
  public:
    // Static attribute
    static const int _TYPE;
    // Constructor
    // Method
    inline int getType() { return _TYPE; };
    // Getter
    // Setter
    // Other
};

const int Mountain::_TYPE = 1;





/* ################################
 * ################################
 *           Constructor
 * ################################
 * ################################
 */





/* ################################
 * ################################
 *              Getter
 * ################################
 * ################################
 */





/* ################################
 * ################################
 *             Setter
 * ################################
 * ################################
 */





/* ################################
 * ################################
 *              Other
 * ################################
 * ################################
 */



#endif
