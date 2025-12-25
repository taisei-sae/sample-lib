cmake_minimum_required(VERSION 3.15)
project(sample-lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sample-lib src/calc.cpp include/sample-lib/calc.cpp)

target_include_directories(sample-lib PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install(TARGETS sample-lib EXPORT sample-lib-config)

install(EXPORT sample-lib-config
	NAMESPACE sample-lib::	
	DESTINATION share/sample-lib
)

install(DIRECTORY include/ DESTINATION .)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests tests/test_calc.cpp)
target_link_libraries(unit_tests PRIVATE sample-lib GTest::gtest_main) # gtest_mainÇÕmainä÷êîÇé©ìÆê∂ê¨ÇµÇƒÇ≠ÇÍÇÈ

include(GoogleTest)
gtest_discover_tests(unit_tests)
