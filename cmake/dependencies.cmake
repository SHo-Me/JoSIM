include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

CPMAddPackage(
  NAME CMakeSuiteSparse
  GITHUB_REPOSITORY JoeyDelp/CMakeSuiteSparse
  VERSION 0.1.0
  GIT_TAG 96c16fab251376f1496fedf0a05274e7d058fe3c
)

CPMAddPackage(
  NAME CMakeSuperLU
  GITHUB_REPOSITORY JoeyDelp/CMakeSuperLU
  VERSION 0.1.0
  GIT_TAG 30b8ef4db1e8d8729f4a1cd53029da69653f7bd6
)

CPMAddPackage(
  NAME CMakeCBLAS
  GITHUB_REPOSITORY JoeyDelp/CMakeCBLAS
  VERSION 0.1.0
  GIT_TAG 8ee64086a8ab012595744c4a97a49cdfc73b81ab
)