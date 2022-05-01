#ifndef HEADER_FILE_DRAWINGAREANEW
#define HEADER_FILE_DRAWINGAREANEW

#include <iostream>
#include <string>

#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>

#include "model.h"
#include "tree.h"

using namespace std;
using namespace Gtk;

class DrawingAreaNew : public DrawingArea {
  private: 
    Model * _model;
  public:
    DrawingAreaNew();
    DrawingAreaNew(Model *);
  
  protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  
};


DrawingAreaNew::DrawingAreaNew() : DrawingArea() {}

DrawingAreaNew::DrawingAreaNew(Model * model) : DrawingAreaNew() {
  _model = model;
}





bool DrawingAreaNew::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  const int model_grid_width  = _model->getMap()->getWidth();
  const int model_grid_height = _model->getMap()->getHeight();

  Gtk::Allocation allocation  = get_allocation();
  const int width             = allocation.get_width();
  const int height            = allocation.get_height();

  const double width_of_cell     = (double) width  / (double) model_grid_width;
  const double height_of_cell    = (double) height / (double) model_grid_height;
  
  int x, y;

  // Set Color depending on thing_on_cell - BEGIN
  for (x = 0; 
       x < model_grid_width; 
       x ++) {
    
    for (y = 0; 
         y < model_grid_height; 
         y ++) {
          
      switch (_model->getMap()->getCell(x, y)->getThingOnCell()->getType()) {
      
        case Mountain::_TYPE:
          cr->set_source_rgb(0.1, 0.1, 0.1);
          cr->rectangle(x * width_of_cell, 
                        y * height_of_cell,
                        width_of_cell, 
                        height_of_cell);
          cr->fill();
          break;
          
        case Structure::_TYPE:
          cr->set_source_rgb(0.7, 0.4, 0.0);
          cr->rectangle(x * width_of_cell, 
                        y * height_of_cell,
                        width_of_cell, 
                        height_of_cell);
          cr->fill();
          break;
          
        case Tree::_TYPE:
          cr->set_source_rgb(0.2, 0.5, 0.0);
          cr->rectangle(x * width_of_cell, 
                        y * height_of_cell,
                        width_of_cell, 
                        height_of_cell);
          cr->fill();
          break;
          
        default:
          break;
          
      }      
    }
  }
  cr->set_source_rgb(0.0, 0.0, 0.0);
  // Set Color depending on thing_on_cell - END
  

  // Print GridSquare - BEGIN
  for (x = 0; 
       x < model_grid_width; 
       x ++) {
           
    y = 0;
    
    cr->move_to(x * width_of_cell, 0);
    cr->line_to(x * width_of_cell, height);
    
  }
    
  for (y = 0; 
       y < model_grid_height; 
       y ++) {
        
    cr->move_to(0, y * height_of_cell);
    cr->line_to(width, y * height_of_cell);
    
  }
  cr->stroke();
  // Print GridSquare - END
  

  return true;
}

#endif


