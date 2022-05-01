#ifndef HEADER_FILE_ITEM
#define HEADER_FILE_ITEM

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Item {
  private:
    string _name;
    int _value;
  public:
    Item();
    Item(string, int);
    int getValue();
    string getName();
    string to_String();
};


Item::Item() {
  _name = "";
  _value = 0;
};

Item::Item(string name, int value) {
  _name = name;
  _value = value;
};


int Item::getValue() {
  return _value;
};
string Item::getName() {
  return _name;
};


string Item::to_String() {
  
  std::stringstream sstm;
  sstm << "Name : " << _name << " Value : " << _value;
  return sstm.str();
};


inline std::ostream & operator<<(std::ostream & Str, Item v) { 
  // print something from v to str, e.g: Str << v.getX();
  Str << "Name : " << v.getName() << " Value : " << v.getValue();
  return Str;
}

#endif
