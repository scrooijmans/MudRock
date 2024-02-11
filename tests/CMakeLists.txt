find_library(MUDROCK_LIBRARY NAMES MudRock)
if(NOT MUDROCK_LIBRARY)
    message(FATAL_ERROR "Mudrock not found")
else()
    get_filename_component(MUDROCK_INCLUDE_DIR ${MUDROCK_LIBRARY} DIRECTORY)
    include_directories(${MUDROCK_INCLUDE_DIR}/../include/mudrock)
endif()

add_executable(mr_test mr_test.cpp)

target_link_libraries(mr_test PRIVATE ${MUDROCK_LIBRARY}
)
enable_testing()
add_test(NAME mr_test COMMAND mr_test)

include_directories(
    ${EIGEN_ROOT_DIR}
)
