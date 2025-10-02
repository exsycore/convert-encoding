list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

include(AddSAMPPlugin)

add_samp_plugin(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/plugin.def

    ${CMAKE_SOURCE_DIR}/Source/main.cc
    ${CMAKE_SOURCE_DIR}/Source/main.h
    ${CMAKE_SOURCE_DIR}/Source/plugin.cc
    ${CMAKE_SOURCE_DIR}/Source/plugin.h
    ${CMAKE_SOURCE_DIR}/Source/script.cc
    ${CMAKE_SOURCE_DIR}/Source/script.h

    ${CMAKE_SOURCE_DIR}/Libs/samp-ptl/ptl.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/Libs
    ${CMAKE_SOURCE_DIR}/Libs/samp-ptl
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OMP-SDK
)