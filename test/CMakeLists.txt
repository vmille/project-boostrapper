set(LIBRARY_NAME libproject-boostrapper)

set(LIBRARY_TEST_NAME ${LIBRARY_NAME}_test)
set(TEST_FILES formatter_tests.cxx)

add_executable(${LIBRARY_TEST_NAME} ${TEST_FILES})
target_include_directories(${LIBRARY_TEST_NAME} PRIVATE ${PUBLIC_INCLUDE_PATHS} ${PRIVATE_INCLUDE_PATHS})
target_link_libraries(${LIBRARY_TEST_NAME} ${LIBRARY_NAME} Catch2::Catch2WithMain fmt::fmt)
add_test(NAME ${LIBRARY_TEST_NAME} COMMAND ${LIBRARY_TEST_NAME})

file(COPY reference DESTINATION ${CMAKE_CURRENT_BINARY_DIR})