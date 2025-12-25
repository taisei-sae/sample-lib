cmake_minimum_required(VERSION 3.15)
project(sample-lib LANGUAGES CXX)

add_library(sample-lib src/calc.cpp)

target_include_directories(sample-lib PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install(TARGETS sample-lib EXPORT sample-lib-config)
install(EXPORT sample-lib-config DESTINATION share/sample-lib)
install(DIRECTORY include/ DESTINATION include)