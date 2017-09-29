cmake_minimum_required(VERSION 3.0.2)
project(StringToIntBenchmark)

add_subdirectory(benchmark-google)	

find_package(Boost 1.55.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
endif()

set(sources
  StringToIntBenchmark.cpp
  fast_atoi.cpp
)

add_executable( StringToIntBenchmark ${sources})
target_link_libraries( StringToIntBenchmark benchmark)

target_compile_options(StringToIntBenchmark PRIVATE -std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")