#include <boxm2/boxm_scene.txx>
#include <boct/boct_tree.h>
#include <boxm2/sample/boxm_sample.h>

typedef boct_tree<short, boxm_sample<BOXM_APM_SIMPLE_GREY> >  tree_type;
BOXM_SCENE_INSTANTIATE(tree_type);

// scene with appearance 
typedef boxm_apm_traits<BOXM_APM_SIMPLE_GREY>::apm_datatype apm_datatype;
typedef boct_tree<short,apm_datatype >  apm_tree_type;
BOXM_SCENE_INSTANTIATE(apm_tree_type);
