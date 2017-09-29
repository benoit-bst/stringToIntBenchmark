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

Required tools and library

* cmake >= 3.0.2
* gcc >= 4.9.2
* clang >= 3.5.0
* libboost-all-dev >= 1.55.0

debian installation 

```
apt-get install cmake g++ clang libboost-all-dev
```

## Source recovery

```
git clone StringtoIntBenchmark
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

* gcc 4.9.2 and clang 3.5.0
* arch : x86_64-linux-gnu
* Run on (8 X 3900 MHz CPU s)
* gcc flag   : release -O3 / debug -O0
* clang flag : release -O3 / debug -O0

## Tests Results

```
atoi reference

1. GCC 4.9.2 RELEASE

------------------------------
Benchmark                  CPU
------------------------------
BM_fast_atoi             25 ns    
BM_atoi                  80 ns
BM_stoi                 333 ns       
BM_sstream             2261 ns    
BM_lexicalCast          201 ns       
BM_qiParse                2 ns       


2. CLANG 3.5.0 RELEASE

------------------------------
Benchmark                  CPU
------------------------------
BM_fast_atoi             26 ns         
BM_atoi                   2 ns
BM_stoi                 352 ns        
BM_sstream             2281 ns      
BM_lexicalCast          193 ns       
BM_qiParse               24 ns         

3. GCC 4.9.2 DEBUG

------------------------------
Benchmark                  CPU
------------------------------
BM_fast_atoi            116 ns        
BM_atoi                 130 ns
BM_stoi                 500 ns        
BM_sstream             2329 ns       
BM_lexicalCast          572 ns        
BM_qiParse             1345 ns       

4. CLANG 3.5.0 DEBUG

------------------------------
Benchmark                  CPU
------------------------------
BM_fast_atoi            115 ns        
BM_atoi                 135 ns
BM_stoi                 493 ns        
BM_sstream             2313 ns       
BM_lexicalCast          538 ns        
BM_qiParse             1119 ns       

```

## Conclusion

Whitout O3 optimization gcc et clang results are the same. Naive implementation is the better way.

But with O3 optimization, there are not the same results. Clang compiler seems to make better optimization for atoi function (2 ns) than gcc compiler.
With gcc compiler, the best result is given by spirit::qi::parse (2 ns). 

Boost spirit::qi::parse probably uses Gcc's 03 optimizations better, while Clang seems to completely optimize the atoi function.

Note : 2 ns seems to be the minimum measurement.