include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


add_executable(binary_search_test binary_search_test.cpp)

target_link_libraries(binary_search_test
 PRIVATE
  GTest::GTest
  binarySearch)

add_test(binary_search_gtests binary_search_test)