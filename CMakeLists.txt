cmake_minimum_required (VERSION 3.8)

project(cft_test_task)

#add_executable (task_1 ./source/stepic_1.cpp)
#add_executable (task_2 ./source/stepic_2.cpp)
#add_executable (test_google ./test/test_google.cpp)
add_executable (test_geometry  ./src/test/google_test.cpp)

add_library(point ./src/geometry/point.cpp)
add_library(triangle ./src/geometry/triangle.cpp)
#add_library(StringLib ./source/functionsString.cpp)

#target_link_libraries(task_1 StringLib)
#target_link_libraries(task_2 StringLib)
#target_link_libraries(test_comparison NaiveLib)

#include_directories(./include)

target_compile_features(point PUBLIC cxx_std_11)
target_compile_features(triangle PUBLIC cxx_std_11)
#target_compile_features(NaiveLib PUBLIC cxx_std_11)

find_package(GTest REQUIRED)
target_include_directories(test_geometry PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_geometry PRIVATE ${GTEST_LIBRARIES} pthread point)
target_link_libraries(test_geometry PRIVATE ${GTEST_LIBRARIES} pthread triangle)
