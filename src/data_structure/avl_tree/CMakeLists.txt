get_filename_component(TITLE ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(APP_NAME "${TYPE}-${TITLE}")
set(APP_STATIC "${APP_NAME}_static")
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
set(APP_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/avl_tree.h")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build")

add_library(${APP_STATIC} STATIC ${APP_SOURCES} ${APP_HEADERS})

target_include_directories(${APP_STATIC} PUBLIC include)
target_precompile_headers(${APP_STATIC} PUBLIC <string>)

target_link_libraries(${APP_STATIC} PUBLIC
)

include(BuildInfo)
BuildInfo(${APP_STATIC})

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${APP_STATIC})
