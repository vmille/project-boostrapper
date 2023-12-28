//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_CMAKE_ROOT_HXX
#define PROJECT_BOOSTRAPPER_CMAKE_ROOT_HXX
#include "formatters/generic.hxx"

namespace vm::formatters {

struct cmake_tag { };

template <>
constexpr auto nix_package_name<cmake_tag>() {
  return "cmake";
}

template <>
constexpr auto file_formatter<cmake_tag>() {
  return "cmake_minimum_required(VERSION 3.18)\n"
         "project({project_name})\n"
         "set(CMAKE_CXX_STANDARD 23)\n"
         "\n"
         "find_package(catch2 CONFIG REQUIRED)\n"
         "\n"
         "add_subdirectory(src)\n"
         "add_subdirectory(test)\n";
}

}
#endif // PROJECT_BOOSTRAPPER_CMAKE_ROOT_HXX
