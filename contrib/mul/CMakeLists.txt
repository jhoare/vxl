# ./mul/CMakeLists.txt

PROJECT( mul )

doxygen_add_book(contrib/mul
  "Manchester University Library overview documentation")

doxygen_add_package(contrib/mul "Manchester University Libraries")

SET( VXL_MUL_INCLUDE_DIR ${mul_SOURCE_DIR} CACHE STATIC "Manchester University package include files" )
SET( MUL_INCLUDE_DIR ${VXL_MUL_INCLUDE_DIR} CACHE STATIC "Deprecated variable giving Manchester University package include files" )
SET( MUL_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/mul CACHE INTERNAL "Manchester University package includes install path" )

INCLUDE_DIRECTORIES( ${VXLCORE_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${VXL_MUL_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${vxl_BINARY_DIR}/contrib/mul )


add_subdirectory(mbl)
add_subdirectory(vpdfl)
add_subdirectory(pdf1d)
add_subdirectory(clsfy)
add_subdirectory(vimt)
add_subdirectory(ipts)
add_subdirectory(vil3d)
add_subdirectory(vimt3d)
add_subdirectory(mvl2)
add_subdirectory(m23d)
add_subdirectory(mmn)
add_subdirectory(mcal)

add_subdirectory(mipa)
add_subdirectory(msm)
add_subdirectory(msdi)
add_subdirectory(mfpf)
add_subdirectory(fhs)

IF (BUILD_UNMAINTAINED_LIBRARIES)
  add_subdirectory(mil)
  add_subdirectory(mil3d)
ENDIF (BUILD_UNMAINTAINED_LIBRARIES)

OPTION(BUILD_MUL_TOOLS "Build the MUL tools?" YES)

IF ( BUILD_MUL_TOOLS )
  add_subdirectory(tools)
ENDIF ( BUILD_MUL_TOOLS )
