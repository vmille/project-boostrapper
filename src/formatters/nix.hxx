//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_NIX_HXX
#define PROJECT_BOOSTRAPPER_NIX_HXX

#include "fmt/core.h"
#include "formatters/generic.hxx"
#include <fmt/format.h>

namespace vm::formatters {

struct nix_tag { };

template <typename... tags_t>
constexpr auto nix_package_names_format() {
  auto names = {fmt::format("    pkgs.{}", nix_package_name<tags_t>())...};
  return fmt::format("{}", fmt::join(names, "\n"));
}

template <typename... tags_t>
constexpr auto nix_hooks_format() {
  auto names = {fmt::format("    {}", nix_shell_hook<tags_t>())...};
  return fmt::format("{}", fmt::join(names, "\n"));
}

template <>
constexpr auto file_formatter<nix_tag>() {
  return "{{ pkgs ? import <nixpkgs> {{}}}}:\n"
         "\n"
         "pkgs.mkShell {{\n"
         "  packages = [\n"
         "{packages}\n"
         "  ];\n"
         "  shellHook = ''\n"
         "{hooks}\n"
         "  '';\n"
         "}}\n";
}
}

#endif // PROJECT_BOOSTRAPPER_NIX_HXX
