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

INCLUDE_ONCE_MACRO(NETCDF)
if(MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
  message(STATUS "NETCDF deactivated on debug builds")
  return()
endif()

SETUP_SUPERBUILD(NETCDF)

# declare dependencies
ADDTO_DEPENDENCIES_IF_NOT_SYSTEM(NETCDF HDF5 ZLIB CURL HDF4 JPEG)

set(NETCDF_SB_CONFIG)

# this should not be needed but see Mantis-1457
if(UNIX)
  ADD_SUPERBUILD_CMAKE_VAR(NETCDF HDF5_INCLUDE_DIR)
  ADD_SUPERBUILD_CMAKE_VAR(NETCDF HDF5_C_LIBRARY)
  ADD_SUPERBUILD_CMAKE_VAR(NETCDF HDF5_HL_LIBRARY)
endif()

ExternalProject_Add(NETCDF
  PREFIX NETCDF
  URL "ftp://ftp.unidata.ucar.edu/pub/netcdf/netcdf-4.4.1.1.tar.gz"
  URL_MD5 503a2d6b6035d116ed53b1d80c811bda
  SOURCE_DIR ${NETCDF_SB_SRC}
  BINARY_DIR ${NETCDF_SB_BUILD_DIR}
  INSTALL_DIR ${SB_INSTALL_PREFIX}
  DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
  DEPENDS ${NETCDF_DEPENDENCIES}
  CMAKE_CACHE_ARGS
  ${SB_CMAKE_CACHE_ARGS}
    -DBUILD_TESTING:BOOL=OFF
    -DENABLE_CONVERSION_WARNINGS:BOOL=ON
    -DENABLE_DAP:BOOL=ON
    -DENABLE_DAP_GROUPS:BOOL=ON
    -DENABLE_DISKLESS:BOOL=ON
    -DENABLE_DOXYGEN:BOOL=OFF
    -DENABLE_DYNAMIC_LOADING:BOOL=ON
    -DENABLE_EXAMPLES:BOOL=ON
    -DENABLE_EXTREME_NUMBERS:BOOL=ON
    -DENABLE_FFIO:BOOL=OFF
    -DENABLE_FSYNC:BOOL=OFF
    -DENABLE_HDF4:BOOL=ON
    -DENABLE_HDF4_FILE_TESTS:BOOL=OFF
    -DENABLE_JNA:BOOL=OFF
    -DENABLE_LARGE_FILE_SUPPORT:BOOL=ON
    -DENABLE_LOGGING:BOOL=OFF
    -DENABLE_MMAP:BOOL=OFF
    -DENABLE_NETCDF4:BOOL=ON
    -DENABLE_NETCDF_4:BOOL=ON
    -DENABLE_PARALLEL4:BOOL=OFF
    -DENABLE_PNETCDF:BOOL=OFF
    -DENABLE_REMOTE_FORTRAN_BOOTSTRA:BOOL=OFF
    -DENABLE_RPC:BOOL=OFF
    -DENABLE_STDIO:BOOL=OFF
    -DENABLE_TESTS:BOOL=OFF
    -DENABLE_V2_API:BOOL=ON
    -DUSE_HDF5:BOOL=ON
    -DUSE_NETCDF4:BOOL=ON
    ${NETCDF_SB_CONFIG}
  CMAKE_COMMAND ${SB_CMAKE_COMMAND}
  LOG_DOWNLOAD 1
  LOG_CONFIGURE 1
  LOG_BUILD 1
  LOG_INSTALL 1
  )

SUPERBUILD_PATCH_SOURCE(NETCDF)
