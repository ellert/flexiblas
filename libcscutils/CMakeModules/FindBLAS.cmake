# - Find BLAS library
# This module finds an installed fortran library that implements the BLAS
# linear-algebra interface (see http://www.netlib.org/blas/).
# The list of libraries searched for is taken
# from the autoconf macro file, acx_blas.m4 (distributed at
# http://ac-archive.sourceforge.net/ac-archive/acx_blas.html).
#
# This module sets the following variables:
#  BLAS_FOUND - set to true if a library implementing the BLAS interface
#    is found
#  BLAS_LINKER_FLAGS - uncached list of required linker flags (excluding -l
#    and -L).
#  BLAS_LIBRARIES - uncached list of libraries (using full path name) to
#    link against to use BLAS
#  BLAS95_LIBRARIES - uncached list of libraries (using full path name)
#    to link against to use BLAS95 interface
#  BLAS95_FOUND - set to true if a library implementing the BLAS f95 interface
#    is found
#  BLA_STATIC  if set on this determines what kind of linkage we do (static)
#  BLA_VENDOR  if set checks only the specified vendor, if not set checks
#     all the possibilities
#  BLA_F95     if set on tries to find the f95 interfaces for BLAS/LAPACK
##########
# List of vendors (BLA_VENDOR) valid in this module:
# - Goto
# - OpenBLAS
# - SunPerf
# - SCSL
# - SGIMATH
# - IBMESSL
# - Intel (search a default one)
# - Intel_32 (IA 32, parallel)
# - Intel_32_seq (IA 32, sequential)
# - Intel_64lp   (Intel64, parallel, 4Byte Int, 8 Byte Long+Pointer)
# - Intel_64lp_seq (Intel64, sequential)
# - ACML
# - ACML_MP
# - Apple
# - Generic
# C/CXX should be enabled to use Intel mkl
#########
# In order to use the ACML two additional CMAKE Variables can be set
#  - ACML_BASE sets the base directory where cmake should search for ACML
#              directories. Per default this will be "/opt"
#  - ACML_ROOT If you want to search for a special ACML version you can set
#              the absolute path to your ACML installation. If this variable is
#              set not other paths except of LD_LIBRARY_PATH will be searched.
#
#=============================================================================
# Copyright 2007-2009 Kitware, Inc.
# Copyright 2013 Martin Köhler, MPI Magdeburg
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# lint_cmake: -package/consistency

include(CheckFunctionExists)
include(CheckFortranFunctionExists)

set(_blas_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})

# Check the language being used
get_property( _LANGUAGES_ GLOBAL PROPERTY ENABLED_LANGUAGES )
if( _LANGUAGES_ MATCHES Fortran )
    set( _CHECK_FORTRAN TRUE )
elseif((_LANGUAGES_ MATCHES C) OR (_LANGUAGES_ MATCHES CXX))
    set( _CHECK_FORTRAN FALSE )
else()
    if(BLAS_FIND_REQUIRED)
        message(FATAL_ERROR "FindBLAS requires Fortran, C, or C++ to be enabled.")
    else()
        message(STATUS "Looking for BLAS... - NOT found (Unsupported languages)")
        return()
    endif()
endif()

macro(Check_Fortran_Libraries LIBRARIES _prefix _name _flags _list _thread)
    # This macro checks for the existence of the combination of fortran libraries
    # given by _list.  If the combination is found, this macro checks (using the
    # Check_Fortran_Function_Exists macro) whether can link against that library
    # combination using the name of a routine given by _name using the linker
    # flags given by _flags.  If the combination of libraries is found and passes
    # the link test, LIBRARIES is set to the list of complete library paths that
    # have been found.  Otherwise, LIBRARIES is set to FALSE.

    # N.B. _prefix is the prefix applied to the names of all cached variables that
    # are generated internally and marked advanced by this macro.

    unset(_libdir)

    set(_libraries_work TRUE)
    set(${LIBRARIES})
    set(_combined_name)
    if(NOT _libdir)
        if(WIN32)
            set(_libdir ENV LIB ${ARGN})
        elseif(APPLE)
            set(_libdir ENV DYLD_LIBRARY_PATH ${ARGN})
        else()
            set(_libdir ENV LD_LIBRARY_PATH ${ARGN})
        endif()
    endif()
    foreach(_library ${_list})
        set(_combined_name ${_combined_name}_${_library})
        if(_libraries_work)
            if(BLA_STATIC)
                if(WIN32)
                    set(CMAKE_FIND_LIBRARY_SUFFIXES .lib ${CMAKE_FIND_LIBRARY_SUFFIXES})
                endif()
                if(APPLE)
                    set(CMAKE_FIND_LIBRARY_SUFFIXES .lib ${CMAKE_FIND_LIBRARY_SUFFIXES})
                else()
                    set(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
                endif()
            else()
                if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
                    # for ubuntu's libblas3gf and liblapack3gf packages
                    set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES} .so.3gf .so.0)
                endif()
            endif()
            find_library(${_prefix}_${_library}_LIBRARY
                NAMES ${_library}
                HINTS ${_libdir}
                PATHS ${_libdir}
                NO_DEFAULT_PATH
                )
            find_library(${_prefix}_${_library}_LIBRARY
                NAMES ${_library}
                HINTS ${_libdir}
                PATHS ${_libdir}
                )
            mark_as_advanced(${_prefix}_${_library}_LIBRARY)
            set(${LIBRARIES} ${${LIBRARIES}} ${${_prefix}_${_library}_LIBRARY})
            set(_libraries_work ${${_prefix}_${_library}_LIBRARY})
        endif()
    endforeach()
    if(_libraries_work)
        # Test this combination of libraries.
        set(CMAKE_REQUIRED_LIBRARIES ${_flags} ${${LIBRARIES}} ${_thread})
        #  message("DEBUG: CMAKE_REQUIRED_LIBRARIES = ${CMAKE_REQUIRED_LIBRARIES}")
        if(_CHECK_FORTRAN)
            check_fortran_function_exists("${_name}" ${_prefix}${_combined_name}_WORKS)
        else()
            check_function_exists("${_name}_" ${_prefix}${_combined_name}_WORKS)
        endif()
        set(CMAKE_REQUIRED_LIBRARIES)
        mark_as_advanced(${_prefix}${_combined_name}_WORKS)
        set(_libraries_work ${${_prefix}${_combined_name}_WORKS})
    endif()
    if(NOT _libraries_work)
        set(${LIBRARIES} FALSE)
    endif()
    #message("DEBUG: ${LIBRARIES} = ${${LIBRARIES}}")
endmacro()


#
# PREPARATION
#
set(BLAS_LINKER_FLAGS)
set(BLAS_LIBRARIES)
set(BLAS95_LIBRARIES)
if($ENV{BLA_VENDOR} MATCHES ".+")
    set(BLA_VENDOR $ENV{BLA_VENDOR})
else()
    if(NOT BLA_VENDOR)
        set(BLA_VENDOR "All")
    endif()
endif()

# Check for a generic BLAS first. This enables us to use the system wide
# default setting on systems which provide the BLAS implementation via
# the updates-alternatives system or similar techniques.
if(BLA_VENDOR STREQUAL "Generic" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "blas"
            ""
            )
    endif()
    if(BLAS_LIBRARIES)
        set(BLA_VENDOR "Generic")
    endif()
endif()

#
# Search for the FlexiBLAS
#
if(BLA_VENDOR STREQUAL "FlexiBLAS" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "flexiblas"
            ""
            )
    endif()
    if(BLAS_LIBRARIES)
        set(BLA_VENDOR "FlexiBLAS")
    endif()
endif()

#
# Find GotoBLAS2
#
if(BLA_VENDOR STREQUAL "GotoBLAS" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        # gotoblas (http://www.tacc.utexas.edu/tacc-projects/gotoblas2)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "goto2"
            ""
            )
        if(BLAS_LIBRARIES)
            set(BLA_VENDOR "Goto")
        endif()
    endif()
endif()

#
# Find OpenBLAS
#
if(BLA_VENDOR MATCHES "OpenBLAS.*" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        set(BLAS_SEARCH_LIBS "")
        find_package(OpenMP)
        find_package(Threads)
        if(BLA_VENDOR STREQUAL "OpenBLAS")
            list(APPEND BLAS_SEARCH_LIBS "openblas")
            set(XVENDOR "OpenBLAS")
        endif()
        if(BLA_VENDOR MATCHES "OpenBLAS-P.*")
            list(APPEND BLAS_SEARCH_LIBS "openblasp")
            set(XVENDOR "OpenBLAS-Pthreads")
        endif()
        if(BLA_VENDOR STREQUAL "OpenBLAS-OpenMP" OR BLA_VENDOR STREQUAL "OpenBLAS-OpenMP")
            list(APPEND BLAS_SEARCH_LIBS "openblaso")
            set(XVENDOR "OpenBLAS-OpenMP")
        endif()

        foreach(IT ${BLAS_SEARCH_LIBS})
            string(REPLACE " " ";" SEARCH_LIBS ${IT})
            if(BLAS_LIBRARIES)
            else()
                check_fortran_libraries(
                    BLAS_LIBRARIES
                    BLAS
                    sgemm
                    "${OpenMP_LD_FLAGS}"
                    "${SEARCH_LIBS}"
                    "${OpenMP_C_FLAGS};${CMAKE_THREAD_LIBS_INIT};${LM}"
                    )
            endif()
        endforeach()

        if(BLAS_LIBRARIES)
            set(BLA_VENDOR ${XVENDOR})
        endif()
    endif()
endif()


#
# Atlas BLAS
#
if(BLA_VENDOR MATCHES "ATLAS.*" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        if(NOT WIN32)
            set(LM "-lm")
        endif()

        find_package(Threads)

        set(BLAS_SEARCH_LIBS "")

        list(APPEND BLAS_SEARCH_LIBS "f77blas tatlas")
        list(APPEND BLAS_SEARCH_LIBS "ptf77blas tatlas")
        list(APPEND BLAS_SEARCH_LIBS "tatlas")
        list(APPEND BLAS_SEARCH_LIBS "ptf77blas atlas")
        list(APPEND BLAS_SEARCH_LIBS "satlas")
        list(APPEND BLAS_SEARCH_LIBS "f77blas satlas")
        list(APPEND BLAS_SEARCH_LIBS "f77blas atlas")

        foreach(IT ${BLAS_SEARCH_LIBS})
            string(REPLACE " " ";" SEARCH_LIBS ${IT})
            if(BLAS_LIBRARIES)
            else()
                check_fortran_libraries(
                    BLAS_LIBRARIES
                    BLAS
                    sgemm
                    ""
                    "${SEARCH_LIBS}"
                    "${CMAKE_THREAD_LIBS_INIT};${LM}"
                    "/usr/lib/atlas-base/"
                    "/usr/lib/atlas/"
                    "/usr/lib64/atlas"
                    )
            endif()
        endforeach()
        if(BLAS_LIBRARIES)
            set(BLA_VENDOR "ATLAS")
            set(BLAS_LIBRARIES "${BLAS_LIBRARIES};${CMAKE_THREAD_LIBS_INIT};${LM}")
        endif()
    endif()
endif()

# BLAS in Sun Performance library?
if(BLA_VENDOR STREQUAL "SunPerf" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            "-xlic_lib=sunperf"
            "sunperf;sunmath"
            ""
            )
        if(BLAS_LIBRARIES)
            set(BLAS_LINKER_FLAGS "-xlic_lib=sunperf")
            set(BLA_VENDOR "SunPerf")
        endif()
    endif()
endif()

# BLAS in SCSL library?  (SGI/Cray Scientific Library)
if(BLA_VENDOR STREQUAL "SCSL" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "scsl"
            ""
            )
    endif()
    if(BLAS_LIBRARIES)
        set(BLA_VENDOR "SCSL")
    endif()
endif()

# BLAS in SGIMATH library?
if(BLA_VENDOR STREQUAL "SGIMATH" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "complib.sgimath"
            ""
            )
    endif()
    if(BLAS_LIBRARIES)
        set(BLA_VENDOR "SGIMATH")
    endif()
endif()

# BLAS in IBM ESSL library? (requires generic BLAS lib, too)
if(BLA_VENDOR STREQUAL "IBMESSL" OR BLA_VENDOR STREQUAL "ESSL" OR BLA_VENDOR STREQUAL "All")
    if(NOT BLAS_LIBRARIES)
        set(BLAS_SEARCH_LIBS "")

        list(APPEND BLAS_SEARCH_LIBS "esslsmp")
        list(APPEND BLAS_SEARCH_LIBS "essl")

        foreach(IT ${BLAS_SEARCH_LIBS})
            string(REPLACE " " ";" SEARCH_LIBS ${IT})
            if(BLAS_LIBRARIES)
            else()
                check_fortran_libraries(
                    BLAS_LIBRARIES
                    BLAS
                    sgemm
                    ""
                    "${SEARCH_LIBS}"
                    ""
                    )
            endif()
        endforeach()
        if(BLAS_LIBRARIES)
            set(BLA_VENDOR "IBMESSL")
            set(BLAS_LIBRARIES "${BLAS_LIBRARIES}")
        endif()
    endif()

    if(NOT BLAS_LIBRARIES)
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "essl;blas"
            ""
            )
    endif()
    if(BLAS_LIBRARIES)
        set(BLA_VENDOR "IBMESSL")
    endif()

endif()

#BLAS in acml library?
if(BLA_VENDOR MATCHES "ACML.*" OR BLA_VENDOR STREQUAL "All")
    if(((BLA_VENDOR STREQUAL "ACML") AND (NOT BLAS_ACML_LIB_DIRS)) OR
        ((BLA_VENDOR STREQUAL "ACML_MP") AND (NOT BLAS_ACML_MP_LIB_DIRS)) OR
        ((BLA_VENDOR STREQUAL "ACML_GPU") AND (NOT BLAS_ACML_GPU_LIB_DIRS))
        )
    # try to find acml in "standard" paths
    if(NOT DEFINED ACML_ROOT)
        if(DEFINED ACML_BASE)
            set(_ACML_SEARCH_BASE ${ACML_BASE})
        else()
            set(_ACML_SEARCH_BASE "/opt")
        endif()
        if( WIN32 )
            file( GLOB _ACML_ROOT "C:/AMD/acml*/ACML-EULA.txt" )
        else()
            file( GLOB _ACML_ROOT "${_ACML_SEARCH_BASE}/acml*/ACML-EULA.txt" )
        endif()
        message(STATUS "ACML Roots: ${_ACML_ROOT}")
        if(_ACML_ROOT)
            list(GET _ACML_ROOT 0 _ACML_ROOT)
            get_filename_component( _ACML_ROOT ${_ACML_ROOT} PATH )
        endif()
    else()
        set(_ACML_ROOT ${ACML_ROOT})
    endif()

    if(_ACML_ROOT)
        if( SIZEOF_INTEGER EQUAL 8 )
            set( _ACML_PATH_SUFFIX "_int64" )
        else()
            set( _ACML_PATH_SUFFIX "" )
        endif()

        if( CMAKE_Fortran_COMPILER_ID STREQUAL "Intel" )
            set( _ACML_COMPILER32 "ifort32" )
            set( _ACML_COMPILER64 "ifort64" )
        elseif( CMAKE_Fortran_COMPILER_ID STREQUAL "SunPro" )
            set( _ACML_COMPILER32 "sun32" )
            set( _ACML_COMPILER64 "sun64" )
        elseif( CMAKE_Fortran_COMPILER_ID STREQUAL "PGI" )
            set( _ACML_COMPILER32 "pgi32" )
            if( WIN32 )
                set( _ACML_COMPILER64 "win64" )
            else()
                set( _ACML_COMPILER64 "pgi64" )
            endif()
        elseif( CMAKE_Fortran_COMPILER_ID STREQUAL "Open64" )
            # 32 bit builds not supported on Open64 but for code simplicity
            # We'll just use the same directory twice
            set( _ACML_COMPILER32 "open64_64" )
            set( _ACML_COMPILER64 "open64_64" )
        elseif( CMAKE_Fortran_COMPILER_ID STREQUAL "NAG" )
            set( _ACML_COMPILER32 "nag32" )
            set( _ACML_COMPILER64 "nag64" )
        else()
            set( _ACML_COMPILER32 "gfortran32" )
            set( _ACML_COMPILER64 "gfortran64" )
        endif()

        if(BLA_VENDOR STREQUAL "ACML_MP")
            set(_ACML_MP_LIB_DIRS
                "${_ACML_ROOT}/${_ACML_COMPILER32}_mp${_ACML_PATH_SUFFIX}/lib"
                "${_ACML_ROOT}/${_ACML_COMPILER64}_mp${_ACML_PATH_SUFFIX}/lib")
        else()
            set(_ACML_LIB_DIRS
                "${_ACML_ROOT}/${_ACML_COMPILER32}${_ACML_PATH_SUFFIX}/lib"
                "${_ACML_ROOT}/${_ACML_COMPILER64}${_ACML_PATH_SUFFIX}/lib")
        endif()
    endif()
elseif(BLAS_${BLA_VENDOR}_LIB_DIRS)
    set(_${BLA_VENDOR}_LIB_DIRS ${BLAS_${BLA_VENDOR}_LIB_DIRS})
endif()

if(BLA_VENDOR STREQUAL "ACML_MP")
    find_package(OpenMP REQUIRED)
    foreach(BLAS_ACML_MP_LIB_DIRS ${_ACML_MP_LIB_DIRS})
        set(__CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "acml_mp;acml_mv;"
            "${OpenMP_C_FLAGS};${OpenMP_LD_FLAGS}"
            ${BLAS_ACML_MP_LIB_DIRS}
            )
        set(CMAKE_FIND_LIBRARY_SUFFIXES ${__CMAKE_FIND_LIBRARY_SUFFIXES})

        if(BLAS_LIBRARIES)
            set(BLAS_LIBRARIES ${BLAS_LIBRARIES} ${OpenMP_LD_FLAGS})
            break()
        endif()

        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "acml_mp"
            "${OpenMP_C_FLAGS};${OpenMP_LD_FLAGS}"
            ${BLAS_ACML_MP_LIB_DIRS}
            )
        if(BLAS_LIBRARIES)
            set(BLAS_LIBRARIES ${BLAS_LIBRARIES} ${OpenMP_LD_FLAGS})
            break()
        endif()
    endforeach()
else()
    foreach( BLAS_ACML_LIB_DIRS ${_ACML_LIB_DIRS} )
        set(__CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "acml;acml_mv;"
            ""
            ${BLAS_ACML_LIB_DIRS}
            )
        set(CMAKE_FIND_LIBRARY_SUFFIXES ${__CMAKE_FIND_LIBRARY_SUFFIXES})
        if(BLAS_LIBRARIES)
            break()
        endif()

        check_fortran_libraries(
            BLAS_LIBRARIES
            BLAS
            sgemm
            ""
            "acml"
            ""
            ${BLAS_ACML_LIB_DIRS}
            )
        if(BLAS_LIBRARIES)
            break()
        endif()
    endforeach()
endif()

# Either acml or acml_mp should be in LD_LIBRARY_PATH but not both
if(NOT BLAS_LIBRARIES)
    check_fortran_libraries(
        BLAS_LIBRARIES
        BLAS
        sgemm
        ""
        "acml_mp;acml_mv"
        "${OpenMP_C_FLAGS};${OpenMP_LD_FLAGS}"
        )
endif()

if(NOT BLAS_LIBRARIES)
    check_fortran_libraries(
        BLAS_LIBRARIES
        BLAS
        sgemm
        ""
        "acml;acml_mv"
        ""
        )
endif()
if(BLAS_LIBRARIES)
    if(BLA_VENDOR STREQUAL "ACML_MP")
        set(BLAS_LINKER_FLAGS "${OpenMP_LD_FLAGS} ${OpenMP_C_FLAGS}")
    endif()
    set(BLA_VENDOR "ACML")
endif()
endif() # ACML

# Apple BLAS library?
 if(BLA_VENDOR STREQUAL "Apple" OR BLA_VENDOR STREQUAL "All")
     if(NOT BLAS_LIBRARIES)
         check_fortran_libraries(
             BLAS_LIBRARIES
             BLAS
             dgemm
             ""
             "Accelerate"
             ""
             )
     endif()
     if(BLAS_LIBRARIES)
         set(BLA_VENDOR "Apple")
     endif()
 endif()
#
# BLAS in Intel MKL
#
if(BLA_VENDOR MATCHES "Intel*" OR BLA_VENDOR STREQUAL "All")
    if(NOT WIN32)
        set(LM "-lm")
    endif()
    if(_LANGUAGES_ MATCHES C OR _LANGUAGES_ MATCHES CXX)
        find_package(Threads REQUIRED)
        find_package(OpenMP)

        set(BLAS_SEARCH_LIBS "")

        if(BLA_F95)
            set(BLAS_mkl_SEARCH_SYMBOL SGEMM)
            set(_LIBRARIES BLAS95_LIBRARIES)
            if(WIN32)
                list(APPEND BLAS_SEARCH_LIBS
                    "mkl_blas95 mkl_intel_c mkl_intel_thread mkl_core libguide40")
            else() # WIN32
                if(BLA_VENDOR STREQUAL "Intel_32" OR BLA_VENDOR STREQUAL "All")
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_blas95 mkl_intel mkl_intel_thread mkl_core")
                    if(CMAKE_C_COMPILER_ID MATCHES ".*GNU.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95 mkl_gf mkl_gnu_thread mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95 mkl_intel mkl_intel_thread mkl_core iomp5")
                    endif()
                endif() #Intel32

                if(BLA_VENDOR STREQUAL "Intel_32_seq" OR BLA_VENDOR STREQUAL "All")
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_blas95 mkl_intel mkl_sequential mkl_core")
                    if(CMAKE_C_COMPILER MATCHES ".+gcc.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95 mkl_gf mkl_sequential mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95 mkl_intel mkl_sequential mkl_core")
                    endif()
                endif() #Intel32_seq

                if(BLA_VENDOR STREQUAL "Intel_64lp" OR BLA_VENDOR STREQUAL "All")
                    # old version
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_blas95 mkl_intel_lp64 mkl_intel_thread mkl_core guide")
                    # mkl >= 10.3
                    if(CMAKE_C_COMPILER MATCHES ".+gcc.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95_lp64 mkl_gf_lp64 mkl_gnu_thread mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95_lp64 mkl_intel_lp64 mkl_intel_thread mkl_core iomp5")
                    endif()
                endif() #Intel64_lp

                if(BLA_VENDOR STREQUAL "Intel_64lp_seq" OR BLA_VENDOR STREQUAL "All")
                    # old version
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_blas95 mkl_intel_lp64 mkl_sequential mkl_core")
                    # mkl >= 10.3
                    if(CMAKE_C_COMPILER MATCHES ".+gcc.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95_lp64 mkl_gf_lp64 mkl_sequential mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_blas95_lp64 mkl_intel_lp64 mkl_sequential mkl_core")
                    endif()
                endif() # Intel64_lp_seq
            endif() # Win32
        else() # BLA 95
            set(BLAS_mkl_SEARCH_SYMBOL sgemm)
            set(_LIBRARIES BLAS_LIBRARIES)
            if(WIN32)
                list(APPEND BLAS_SEARCH_LIBS
                    "mkl_intel_c mkl_intel_thread mkl_core libguide40")
            else() #WIN32
                if(BLA_VENDOR STREQUAL "Intel_32" OR BLA_VENDOR STREQUAL "All")
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_intel mkl_intel_thread mkl_core guide")

                    if(CMAKE_C_COMPILER_ID MATCHES ".*GNU.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_gf mkl_gnu_thread mkl_core")

                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_intel mkl_intel_thread mkl_core iomp5")
                    endif()

                endif() #Intel32

                if(BLA_VENDOR STREQUAL "Intel_32_seq" OR BLA_VENDOR STREQUAL "All")
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_intel mkl_sequential mkl_core guide")
                    if(CMAKE_C_COMPILER_ID MATCHES ".*GNU.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_gf mkl_sequential mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_intel mkl_sequential mkl_core")
                    endif()
                endif() #Intel32_seq

                if(BLA_VENDOR STREQUAL "Intel_64lp" OR BLA_VENDOR STREQUAL "All")
                    # old version
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_intel_lp64 mkl_intel_thread mkl_core guide")
                    # mkl >= 10.3
                    if(CMAKE_C_COMPILER_ID MATCHES ".*GNU.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_solver_lp64 mkl_gf_lp64 mkl_gnu_thread mkl_core pthread")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_gf_lp64 mkl_gnu_thread mkl_core pthread")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_solver_lp64 mkl_intel_lp64 mkl_intel_thread mkl_core iomp5")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_intel_lp64 mkl_intel_thread mkl_core iomp5")
                    endif()
                endif() #Intel64_lp

                if(BLA_VENDOR STREQUAL "Intel_64lp_seq" OR BLA_VENDOR STREQUAL "All")
                    # old version
                    list(APPEND BLAS_SEARCH_LIBS
                        "mkl_intel_lp64 mkl_sequential mkl_core")
                    # mkl >= 10.3
                    if(CMAKE_C_COMPILER_ID MATCHES ".*GNU.*")
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_gf_lp64 mkl_sequential mkl_core")
                    else()
                        list(APPEND BLAS_SEARCH_LIBS
                            "mkl_intel_lp64 mkl_sequential mkl_core")
                    endif()
                endif() # Intel64_lp_seq
            endif() # Win32
        endif() # BLA95

        foreach(IT ${BLAS_SEARCH_LIBS})
            string(REPLACE " " ";" SEARCH_LIBS ${IT})
            if(${_LIBRARIES})
            else()
                check_fortran_libraries(
                    ${_LIBRARIES}
                    BLAS
                    ${BLAS_mkl_SEARCH_SYMBOL}
                    "${OpenMP_LD_FLAGS}"
                    "${SEARCH_LIBS}"
                    "${OpenMP_C_FLAGS};${CMAKE_THREAD_LIBS_INIT};${LM}"
                    )
            endif()
        endforeach()
        if( BLAS_LIBRARIES OR BLAS95_LIBRARIES )
            set(BLA_VENDOR "Intel")
            set(BLAS_LIBRARIES "${BLAS_LIBRARIES}" ${OpenMP_C_FLAGS} ${CMAKE_THREAD_LIBS_INIT} ${LM})
            set(BLAS_LINKER_FLAGS "${OpenMP_LD_FLAGS}")
        endif()
    endif() # LANGUAGE Matches C
endif()


if(BLAS_LIBRARIES)
    set(CHECK_FUNCTION_EXISTS_ADD_LIBRARIES "-DLINK_LIBRARIES:STRING=${BLAS_LIBRARIES}")
    file(WRITE
        ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/testBLAS64.f90
        "
        program main
        integer*8 n,nn(3)
        real s,a(1),b(1),sdot
        a(1) = 1.0
        b(1) = 1.0
        ! Generate -2**33 + 1, if possible
        n = 2
        n = -4 * (n ** 30)
        write(*,*) n

        n = n + 1
        write(*,*) n
        if(n >= 0) stop 1
            ! This means we're on 64-bit integers. Check whether the BLAS is, too.
            s = sdot(n,a,1,b,1)
            write(*,*) 'S1 = ', s
            if(s .ne. 0.0) stop 1
                end
                ")
                try_run(RUN_RESULT COMPILE_RESULT
                    ${CMAKE_BINARY_DIR}
                    ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/testBLAS64.f90
                    CMAKE_FLAGS "${CHECK_FUNCTION_EXISTS_ADD_LIBRARIES}")
                # MESSAGE(STATUS "Check for BLAS64 interface: ${RUN_RESULT} ${COMPILE_RESULT}")
                if(RUN_RESULT EQUAL 0)
                    message(STATUS "BLAS Library ${BLA_VENDOR} works with 64bit integers")
                    set(BLAS_INTERFACE64 TRUE)
                else()
                    message(STATUS "BLAS Library ${BLA_VENDOR} works with 32bit integers")
                    set(BLAS_INTERFACE64 FALSE)
                endif()
            endif()


            if(BLAS_LIBRARIES)
                set(BLAS_FOUND TRUE)
            else()
                set(BLAS_FOUND FALSE)
            endif()
            set(BLAS_LIBRARIES      ${BLAS_LIBRARIES}       CACHE STRING "BLAS LIBRARIES")
            set(BLAS_LINKER_FLAGS   ${BLAS_LINKER_FLAGS}    CACHE STRING "BLAS Linker Flags")
            set(BLAS_FOUND          ${BLAS_FOUND}           CACHE BOOL "Found BLAS Libary")
            set(BLA_VENDOR          ${BLA_VENDOR}           CACHE STRING "BLAS Vendor")

            if(NOT BLAS_FIND_QUIETLY)
                if(BLAS_FOUND)
                    message(STATUS "Found BLAS: ${BLA_VENDOR} (${BLAS_LIBRARIES})")
                else()
                    if(BLAS_FIND_REQUIRED)
                        message(FATAL_ERROR "A required library with BLAS API not found. Please specify library location.")
                    else()
                        message(STATUS   "A library with BLAS API not found. Please specify library location.")
                    endif()
                endif()
            endif()
            set(CMAKE_FIND_LIBRARY_SUFFIXES ${_blas_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES})

