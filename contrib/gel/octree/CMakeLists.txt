# gel/octree/CMakeLists.txt

INCLUDE_DIRECTORIES(${OXL_INCLUDE_DIR})

SET(octree_sources
 BaseCube.h            Cube.h
 VoxmapImagePoints.cxx VoxmapImagePoints.h
 OctreeLevel.cxx       OctreeLevel.h
 VoxmapPoints.cxx      VoxmapPoints.h
 ConvexHull.cxx        ConvexHull.h
 Voxel.cxx             Voxel.h
 main.cxx
)

ADD_EXECUTABLE(octree ${octree_sources})
INSTALL_TARGETS(/bin octree)
TARGET_LINK_LIBRARIES(octree mvl vil1 vgl vnl vbl vul)

IF( BUILD_TESTING )
  add_subdirectory(tests)
ENDIF( BUILD_TESTING )
