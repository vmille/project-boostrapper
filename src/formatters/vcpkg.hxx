//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_VCPKG_HXX
#define PROJECT_BOOSTRAPPER_VCPKG_HXX

#include "formatters/generic.hxx"

namespace vm::formatters {

struct vcpkg_tag { };

template <>
constexpr auto nix_package_name<vcpkg_tag>() {
  return "vcpkg";
}

template <>
constexpr auto file_formatter<vcpkg_tag>() {
  return "{{\n"
         "  \"$schema\" : \"https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json\",\n"
         "  \"dependencies\" : [ \"catch2\" ]\n"
         "}}";
}

}
#endif // PROJECT_BOOSTRAPPER_VCPKG_HXX
