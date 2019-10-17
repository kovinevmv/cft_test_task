cmake_minimum_required (VERSION 3.8)

project(cft_test_task)

add_executable (main ./src/main.cpp)

option(BUILD_TESTS "Build GTests and generate datasets for testing" OFF)

add_library(point ./src/geometry/point.cpp)
add_library(triangle ./src/geometry/triangle.cpp)
add_library(finder ./src/finder/finder.cpp)

target_link_libraries(finder triangle)
target_link_libraries(triangle point)

target_link_libraries(main point)
target_link_libraries(main triangle)
target_link_libraries(main finder)

include_directories(./include)

target_compile_features(point PUBLIC cxx_std_11)
target_compile_features(triangle PUBLIC cxx_std_11)
target_compile_features(finder PUBLIC cxx_std_11)

target_compile_features(main PUBLIC cxx_std_11)

if(BUILD_TESTS)
    add_executable (tests ./src/test/google_test.cpp)
    find_package(GTest REQUIRED)
    target_include_directories(tests PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread point)
    target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread triangle)
    target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread finder)

    execute_process (
        COMMAND bash -c "../example_tests/generator_input_files.sh ../example_tests/test_0.txt 10"
        COMMAND bash -c "../example_tests/generator_input_files.sh ../example_tests/test_1.txt 1000"   
    )

endif(BUILD_TESTS)



