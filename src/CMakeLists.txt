set(LIBRARY_NAME libproject-boostrapper)

set(SOURCE_FILES package.cxx
        formatters/envrc.hxx
        formatters/generic.hxx
        formatters/nix.hxx
        formatters/npm.hxx
        formatters/marp.hxx
        formatters/vcpkg.hxx
        formatters/cmake_root.hxx)
set(PUBLIC_INCLUDE_PATHS .)

add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${PUBLIC_INCLUDE_PATHS})
target_link_libraries(${LIBRARY_NAME} fmt::fmt)
install(TARGETS ${LIBRARY_NAME} RUNTIME DESTINATION lib)

set(EXECUTABLE_NAME project-boostrapper)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
