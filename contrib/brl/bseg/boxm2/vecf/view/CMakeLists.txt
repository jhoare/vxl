# boxm opencl opengl display
INCLUDE( ${VXL_CMAKE_DIR}/NewCMake/FindOpenCL.cmake )
IF(OPENCL_FOUND)
  ADD_DEFINITIONS(-DHAS_OPENCL=1)
  INCLUDE_DIRECTORIES( ${OPENCL_INCLUDE_PATH} )
  INCLUDE( ${BRL_MODULE_PATH}/FindGLEW.cmake )
IF(GLEW_FOUND)
  ADD_DEFINITIONS(-DHAS_GLEW=1)

IF(VGUI_FOUND)
  INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIR} )
  INCLUDE_DIRECTORIES( ${BRL_INCLUDE_DIR}/bpro )
  INCLUDE_DIRECTORIES( ${BRL_INCLUDE_DIR}/bseg )
  INCLUDE_DIRECTORIES( ${BRL_INCLUDE_DIR}/bbas )
  INCLUDE_DIRECTORIES( ${GEL_INCLUDE_DIR}/mrc/vpgl )
  INCLUDE_DIRECTORIES( ${GEL_INCLUDE_DIR}/mrc )
  INCLUDE_DIRECTORIES( ${BRL_INCLUDE_DIR}/bseg/boxm2 )
  LINK_DIRECTORIES(${OPENGL_LIBRARY_DIR})

  SET(boxm2_vecf_view_sources
      boxm2_ocl_articulated_render_tableau.h        boxm2_ocl_articulated_render_tableau.cxx
      boxm2_vecf_orbit_tableau.h                     boxm2_vecf_orbit_tableau.cxx
     )
  AUX_SOURCE_DIRECTORY(Templates boxm2_vecf_view_sources)

  ADD_LIBRARY(boxm2_vecf_view ${boxm2_vecf_view_sources} )

  #install the .h .txx and libs
  INSTALL_TARGETS(/lib boxm2_vecf_view)
  INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bseg/boxm2/vecf/view ${boxm2_vecf_view_sources})

  TARGET_LINK_LIBRARIES(boxm2_vecf_view bocl boxm2_pro boxm2_ocl_pro boxm2_cpp boxm2_cpp_pro vgui bprb vnl vnl_algo vbl_io vpgl vsph vgl vil vbl vul ${GLEW_LIBRARY} ${OPENCL_LIBRARIES} )

  #pro
#  add_subdirectory(pro)

  #tests
  IF( BUILD_TESTING )
    add_subdirectory(tests)
  ENDIF( BUILD_TESTING )
ENDIF(VGUI_FOUND)
ENDIF(GLEW_FOUND)
ENDIF(OPENCL_FOUND)
