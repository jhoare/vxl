PROJECT( rpl )

doxygen_add_package(contrib/rpl "RPI Libraries")

SET( RPL_INCLUDE_DIR ${rpl_SOURCE_DIR} CACHE STATIC "RPI package include files" )
SET( RPL_INSTALL_INCLUDE_DIR
  ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/rpl
  CACHE INTERNAL "RPI package include files"
)

INCLUDE_DIRECTORIES( ${VXLCORE_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${RPL_INCLUDE_DIR} )

add_subdirectory(rrel)
add_subdirectory(rsdl)
IF (BUILD_MUL)
  add_subdirectory(rgrl)
ENDIF (BUILD_MUL)

OPTION(BUILD_RPL_RGTL "Build Rensselaer Generic Tree Library (rgtl)" OFF)
MARK_AS_ADVANCED(BUILD_RPL_RGTL)
IF(BUILD_RPL_RGTL)
  add_subdirectory(rgtl)

  OPTION(BUILD_RPL_RTVL "Build Rensselaer Tensor Voting Library (rtvl)" OFF)
  MARK_AS_ADVANCED(BUILD_RPL_RTVL)
  IF(BUILD_RPL_RTVL)
    add_subdirectory(rtvl)
  ENDIF(BUILD_RPL_RTVL)
ENDIF(BUILD_RPL_RGTL)
