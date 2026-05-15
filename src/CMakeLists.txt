list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(AddSAMPPlugin)

add_samp_plugin(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/plugin.def

    ${CMAKE_SOURCE_DIR}/src/main.cc
    ${CMAKE_SOURCE_DIR}/src/main.h
    ${CMAKE_SOURCE_DIR}/src/plugin.cc
    ${CMAKE_SOURCE_DIR}/src/plugin.h
    ${CMAKE_SOURCE_DIR}/src/script.cc
    ${CMAKE_SOURCE_DIR}/src/script.h

    ${CMAKE_SOURCE_DIR}/libs/samp-ptl/ptl.h
    ${CMAKE_SOURCE_DIR}/libs/tis620.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/samp-ptl
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OMP-SDK
)