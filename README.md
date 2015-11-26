mpags-cpp-extra
===============
Additional code examples for Day 6 of course

How to build
============
You'll need:

- CMake 3.2 or better
- C++14 compatible compiler (GNU/Clang/MSVC19) with multithreading
support in the standard library.

To build, simply do

```
$ ls
CMakeLists.txt exceptions.cpp regex.cpp
README.txt     random.cpp     thread.cpp
$ mkdir build
$ cd build
$ cmake ..
...
$ make
```

The applications will be built in the `build` directory and can be
run directly.

