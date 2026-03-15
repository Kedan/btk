cmake_minimum_required(VERSION 3.23)

add_executable(btk_unit_tests
	src/btk_test.cpp
)

target_link_libraries(
	btk_unit_tests
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(btk_unit_tests)
