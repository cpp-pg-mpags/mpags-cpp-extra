cmake_minimum_required(VERSION 3.2)
project(mpags-cpp-extra)

set(cxx_features
  cxx_auto_type
  cxx_binary_literals
  )

foreach(_name regex random exceptions thread)
  add_executable(${_name} ${_name}.cpp)
  target_compile_features(${_name} PRIVATE ${cxx_features})
endforeach()
