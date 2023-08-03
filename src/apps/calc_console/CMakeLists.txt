set(APP_NAME "calc_console")
set(APP_STATIC "calc_console_static")
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tui.cpp")

add_library(${APP_STATIC} STATIC ${APP_SOURCES})
target_include_directories(${APP_STATIC} PUBLIC include)
target_precompile_headers(${APP_STATIC} PUBLIC <string>)

target_link_libraries(${APP_STATIC} PUBLIC
    calc_shared
    ftxui::screen ftxui::dom ftxui::component
)

include(BuildInfo)
BuildInfo(${APP_STATIC})


add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${APP_STATIC})
