# std::string to int benchmark

we compare different technics to convert std::string to int :
 * naive atoi
 * atoi
 * std::stoi
 * std::stringstream
 * boost::lexical_cast
 * boost::spirit::qi::parse

For measuring speed, google benchmark is used (https://github.com/google/benchmark)
Only the difference between functions are significant

## Environment

Required tools and libraries

* cmake >= 3.5.1
* gcc >= 5.4.0
* clang >= 3.8.0
* libboost-all-dev >= 1.58.0

debian installation 

```
apt-get install cmake g++ clang libboost-all-dev
```

## Source recovery

```
git clone https://github.com/benoit-bst/stringToIntBenchmark
cd StringtoIntBenchmark 
git submodule update --init
```

## Compilation

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RELEASE ..
make
```

if you want to compile with clang, add -DCMAKE_CXX_COMPILER="/usr/bin/clang++" option

## Run benchmark

for each function, we test 7 sizes of string (1->7)

```
./StringToIntBenchmark --benchmark_out=results --benchmark_out_format=csv
```

./StringToIntBenchmark --help for benchmark options

## Tests configuration

* gcc 5.4.0 and clang 3.8.0
* arch : x86_64
* cpu : I7-2640M
* gcc flag   : -O3
* clang flag : -O3

## Tests Results

```
atoi reference

1. GCC 4.9.2

--------------------------------------------------------
Benchmark                 Time           CPU Iterations
--------------------------------------------------------
BM_fast_atoi/7           34 ns         34 ns   16566159
BM_atoi/7               161 ns        161 ns    4321834
BM_stoi/7               164 ns        164 ns    4242043
BM_sstream/7           2942 ns       2941 ns     239618
BM_lexicalCast/7        225 ns        225 ns    3117588
BM_qiParse/7             42 ns         42 ns   16581565    


2. CLANG 3.5.0

--------------------------------------------------------
Benchmark                 Time           CPU Iterations
--------------------------------------------------------
BM_fast_atoi/7           33 ns         33 ns   17135422
BM_atoi/7               162 ns        162 ns    4318101
BM_stoi/7               161 ns        161 ns    4318646
BM_sstream/7           2742 ns       2742 ns     253361
BM_lexicalCast/7        324 ns        324 ns    2163453
BM_qiParse/7             67 ns         67 ns   10338957 

```

## Conclusion

Whether with Gcc or Clang, the naive function offers the best performance.
So use your own atoi function.