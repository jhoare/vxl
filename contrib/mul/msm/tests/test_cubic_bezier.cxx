// This is mul/msm/tests/test_bezier.cxx
//=======================================================================
//
//  Copyright: (C) 2015 The University of Manchester
//
//=======================================================================
#include <testlib/testlib_test.h>
//:
// \file
// \author Tim Cootes
// \brief test msm_cubic_bezier

#include <msm/msm_cubic_bezier.h>
#include <vcl_sstream.h>
#include <vcl_iostream.h>

//=======================================================================

void test_cubic_bezier()
{
  vcl_cout << "***********************\n"
           << " Testing msm_cubic_bezier\n"
           << "***********************\n";

  // Create an open curve
  vcl_vector<vgl_point_2d<double> > pts(4);
  
  pts[0].set(0,0);
  pts[1].set(1,0.3);
  pts[2].set(2,0.3);
  pts[3].set(3,0);
  
  msm_cubic_bezier bezier(pts,false);

  vcl_vector<vgl_point_2d<double> > new_pts;
  vcl_vector<vgl_vector_2d<double> > new_normals;
  vcl_vector<unsigned> control_pt_index;
  
  bezier.get_extra_points(0.5,new_pts,new_normals,control_pt_index);
  
  TEST("Number of points",new_pts.size(),7);
  for (unsigned i=0;i<4;++i) 
  {
    TEST("Control pt index",control_pt_index[i],2*i);
  }
  
  vcl_cout<<"Pt 5: "<<new_pts[5]<<" normal: "<<new_normals[5]<<vcl_endl;
  vcl_cout<<"Last pt: "<<new_pts[6]<<" Last normal: "<<new_normals[6]<<vcl_endl;
  
  bezier.get_extra_points(0.33,new_pts,new_normals,control_pt_index);
  TEST("Number of points",new_pts.size(),10);

  
  // Create a square
  pts[1].set(1,0);
  pts[2].set(1,1);
  pts[3].set(0,1);
  msm_cubic_bezier closed_bezier(pts,true);
  closed_bezier.get_extra_points(0.5,new_pts,new_normals,control_pt_index);
  TEST("Number of points in closed.",new_pts.size(),8);
  for (unsigned i=0;i<4;++i) 
  {
    TEST("Control pt index",control_pt_index[i],2*i);
  }

}

TESTMAIN(test_cubic_bezier);
