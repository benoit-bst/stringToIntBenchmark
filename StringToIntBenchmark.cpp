#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <boost/lexical_cast.hpp>
#include "fast_atoi.h"
#include <boost/spirit/include/qi.hpp>

#include <benchmark/benchmark.h>

using namespace std;
static const std::vector<std::string> stringV = {"1","10","100","1000","10000", "100000", "1000000"};
static const int listSize = 7;

// naive atoi
static void BM_fast_atoi(benchmark::State& state){
  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      benchmark::DoNotOptimize(a = fast_atoi(stringV[i].c_str()));
    }
  }
}
BENCHMARK(BM_fast_atoi) -> Arg(listSize);

// atoi in <cstdlib>
static void BM_atoi(benchmark::State& state){

  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      benchmark::DoNotOptimize(a = atoi(stringV[i].c_str()));
    }
  }
}
BENCHMARK(BM_atoi) -> Arg(listSize);

// c++11 std::stoi in <string>
static void BM_stoi(benchmark::State& state){

  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      benchmark::DoNotOptimize(a = stoi(stringV[i].c_str()));
    }
  }
}
BENCHMARK(BM_stoi) -> Arg(listSize);

// stringstream in <sstream>
static void BM_sstream(benchmark::State& state){

  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      istringstream ss(stringV[i]);
      benchmark::DoNotOptimize(ss >> a);
    }
  }
}
BENCHMARK(BM_sstream) -> Arg(listSize);

// lexical_cast in <boost/lexical_cast.hpp>
static void BM_lexicalCast(benchmark::State& state){

  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      benchmark::DoNotOptimize(a = boost::lexical_cast<int>(stringV[i]));
    }
  }
}
BENCHMARK(BM_lexicalCast) -> Arg(listSize);

// qi::parse in <boost/spirit/qi.hpp>
static void BM_qiParse(benchmark::State& state){

  namespace qi = boost::spirit::qi;
  using qi::int_;
  int a = 0;
  while (state.KeepRunning()){
    for (int i = 0; i < state.range(0); ++i){
      benchmark::DoNotOptimize(qi::parse(stringV[i].begin(), stringV[i].end(), int_, a));
    }
  }
} 
BENCHMARK(BM_qiParse) -> Arg(listSize);

BENCHMARK_MAIN();
