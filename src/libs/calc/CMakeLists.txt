set(LIBRARY_OBJECT "calc_obj")
set(LIBRARY_SHARED "calc_shared")
set(LIBRARY_STATIC "calc_static")

set(LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/calc.cpp"
)
set(LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/calc/calc.h"
)
set(LIBRARY_INCLUDES
    "./" "${CMAKE_BINARY_DIR}/configured_files/include"
)

add_library(${LIBRARY_OBJECT} OBJECT ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_OBJECT} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set_target_properties(${LIBRARY_OBJECT} PROPERTIES
    PUBLIC_HEADER ${LIBRARY_HEADERS}
    POSITION_INDEPENDENT_CODE 1
)

add_library(${LIBRARY_SHARED} SHARED)
target_link_libraries(${LIBRARY_SHARED} ${LIBRARY_OBJECT})

add_library(${LIBRARY_STATIC} STATIC)
target_link_libraries(${LIBRARY_STATIC} ${LIBRARY_OBJECT})

target_set_warnings(
    TARGET
    ${LIBRARY_OBJECT}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

add_linter_tool_to_target(${LIBRARY_OBJECT})

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_OBJECT} optimized)
endif()

add_clang_tidy_msvc_to_target(${LIBRARY_OBJECT})
