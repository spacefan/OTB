#
# Copyright (C) 2005-2019 Centre National d'Etudes Spatiales (CNES)
#
# This file is part of Orfeo Toolbox
#
#     https://www.orfeo-toolbox.org/
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

INCLUDE_ONCE_MACRO(OSSIM)

SETUP_SUPERBUILD(OSSIM)

# declare dependencies
ADDTO_DEPENDENCIES_IF_NOT_SYSTEM(OSSIM TIFF GEOTIFF GEOS JPEG OPENTHREADS FREETYPE)

set(OSSIM_CXX_FLAGS  -D__STDC_CONSTANT_MACROS)

if(MSVC)
  set(OSSIM_CXX_FLAGS "/EHsc /DNOMINMAX")
endif()

# archive version
ExternalProject_Add(OSSIM
  PREFIX OSSIM
  URL "http://download.osgeo.org/ossim/source/ossim-1.8.20/ossim-1.8.20-3.tar.gz"
  URL_MD5 eb2265db0d4d9201e255b92317121cfd
  BINARY_DIR ${OSSIM_SB_BUILD_DIR}
  INSTALL_DIR ${SB_INSTALL_PREFIX}
  DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
  CMAKE_CACHE_ARGS
  ${SB_CMAKE_CACHE_ARGS}
  -DProject_WC_REVISION:STRING=23665
  -DCMAKE_CXX_FLAGS:STRING=${OSSIM_CXX_FLAGS}
  -DBUILD_OSSIM_MPI_SUPPORT:BOOL=OFF
  -DBUILD_OSSIM_FREETYPE_SUPPORT:BOOL=ON
  -DBUILD_OSSIM_APPS:BOOL=OFF
  -DBUILD_OSSIM_TESTS:BOOL=OFF
  -DBUILD_OSSIM_TEST_APPS:BOOL=OFF
  -DBUILD_OSSIM_FRAMEWORKS:BOOL=OFF
  -DBUILD_BUILD_OSSIMQT4:BOOL=OFF
  -DINSTALL_ARCHIVE_DIR:STRING=lib
  -DINSTALL_LIBRARY_DIR:STRING=lib
  ${OSSIM_SB_CONFIG}
  DEPENDS ${OSSIM_DEPENDENCIES}
  CMAKE_COMMAND ${SB_CMAKE_COMMAND}
  LOG_DOWNLOAD 1
  LOG_CONFIGURE 1
  LOG_BUILD 1
  LOG_INSTALL 1
  )

ExternalProject_Add_Step(OSSIM patch_no_cmakelists
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/patches/OSSIM/CMakeLists.txt
  ${OSSIM_SB_SRC}
  DEPENDEES patch
  DEPENDERS configure )

SUPERBUILD_PATCH_SOURCE(OSSIM)

