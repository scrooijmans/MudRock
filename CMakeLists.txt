cmake_minimum_required(VERSION 3.14)

project(MudRock LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Add armadillo library
find_package(Armadillo REQUIRED)

# Add Boost
find_package(Boost REQUIRED)

option(BUILD_TEST "Build the test" ON)

# Check if armadillo is found otherwise terminate
if(NOT ARMADILLO_FOUND)
    message(FATAL_ERROR "Armadillo library not found")
else()
    set(MUDROCK_LIBRARY ${MUDROCK_LIBRARY} ${ARMADILLO_LIBRARIES})
    message("Armadillo library was found")
    include_directories(${ARMADILLO_INCLUDE_DIRS})
endif()


if(NOT BOOST_FOUND)
    message(FATAL_ERROR "Boost library not found")
else()
    set(MUDROCK_LIBRARY ${MUDROCK_LIBRARY} ${BOOST_LIBRARIES})
    message("Boost library was found")
    include_directories(${BOOST_INCLUDE_DIRS})
endif()

# Add Eigen
set(EIGEN_ROOT_DIR "/usr/local/include/eigen/3.4.0_1/include/eigen3/")

# add_library( armadillo ${PROJECT_SOURCE_DIR}/src/wrapper1.cpp ${PROJECT_SOURCE_DIR}/src/wrapper2.cpp )
add_library(MudRock STATIC
    mudrock.h
    mudrock.cpp
)

set_target_properties(MudRock PROPERTIES
    PUBLIC_HEADER "mudrock.h"
)

target_link_libraries(MudRock
    PUBLIC # PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    ${MUDROCK_LIBRARY}
    ${ARMADILLO_LIBRARIES}
)

target_compile_definitions(MudRock PUBLIC MUDROCK_LIBRARY) # PRIVATE / INTERFACE
install(TARGETS MudRock
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include/MudRock
)

if(BUILD_TEST)
  message(STATUS "*** configuring test")
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(petrophysics)
