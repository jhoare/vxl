// This is oxl/vgui/vgui_clear_tableau.h
#ifndef vgui_clear_tableau_h_
#define vgui_clear_tableau_h_
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma interface
#endif
//:
// \file
// \author Philip C. Pritchett, Robotics Research Group, University of Oxford
// \date   11 Nov 99
// \brief  Tableau performing OpenGL clearing.
//
//  Contains classes:  vgui_clear tableau   vgui_clear_tableau_new
//
// \verbatim
//  Modifications:
//    11-NOV-1999 P.Pritchett - Initial version.
//    26-APR-2002 K.Y.McGaul - Added some doxygen style comments.
// \endverbatim

#include "vgui_clear_tableau_sptr.h"
#include <vgui/vgui_gl.h>
#include <vgui/vgui_tableau.h>
class vgui_menu;

//: Tableau performing OpenGL clearing.
//
// vgui_clear_tableau is a tableau that performs OpenGL clearing upon
// receipt of a vgui_DRAW event. It passes all events to its single child.
class vgui_clear_tableau : public vgui_tableau
{
 public:
  //: Constructor - don't use this, use vgui_clear_tableau_new.
  vgui_clear_tableau();

  //: Returns the type of this tableau ('vgui_clear_tableau').
  vcl_string type_name() const;

  //: Set colour of clear_tableau to the given red, green, blue values.
  void set_colour(float r, float g, float b, float a=1);

  //: Set the given GLbitfield as the mask.
  void set_mask(GLbitfield);
 
  //: Toggle clearing on and off.
  void toggle_clearing();

  //: Make the given menu the default pop-up menu.
  void add_popup(vgui_menu &menu);

  //: Display a dialog box to get data (colour, etc) for the clear tableau.
  void config_dialog();

 protected:
  virtual ~vgui_clear_tableau();
  virtual bool handle(const vgui_event&);

 private:
  GLbitfield mask;

  float colour[4]; // rgba
  float accum[4];  // rgba
  GLclampd depth;
  GLint stencil;

  bool clearing_;
};

//: Create a smart-pointer to a vgui_clear_tableau.
struct vgui_clear_tableau_new : public vgui_clear_tableau_sptr
{
  typedef vgui_clear_tableau_sptr base;
  vgui_clear_tableau_new() : base(new vgui_clear_tableau()) { }
};

#endif // vgui_clear_tableau_h_
