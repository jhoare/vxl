#include <vcl_string.h>
#include <vbl/vbl_array_3d.txx>
#include <vgl/io/vgl_io_point_3d.h>
#include <boxm2/boxm_block.txx>
#include <boxm2/sample/boxm_rt_sample.h>
#include <boct/boct_tree.h>

typedef boct_tree<short, boxm_rt_sample<float> > tree_type;
VBL_ARRAY_3D_INSTANTIATE(boxm_block<tree_type>*);
