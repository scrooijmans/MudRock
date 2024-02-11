find_library(PETROPHYSICS_LIBRARY NAMES petrophysics)
if(NOT PETROPHYSICS_LIBRARY)
    message(FATAL_ERROR "petrophysics not found")
else()
    get_filename_component(PETROPHYSICS_INCLUDE_DIR ${PETROPHYSICS_LIBRARY} DIRECTORY)
    include_directories(${PETROPHYSICS_INCLUDE_DIR}/../include/petrophysics)
endif()

add_executable(pp_test pp_test.cpp)

target_link_libraries(pp_test PRIVATE ${PETROPHYSICS_LIBRARY}
)
enable_testing()
add_test(NAME pp_test COMMAND pp_test)

include_directories(
    ${EIGEN_ROOT_DIR}
)
