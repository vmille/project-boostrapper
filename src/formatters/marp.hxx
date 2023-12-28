//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_MARP_HXX
#define PROJECT_BOOSTRAPPER_MARP_HXX

#include "formatters/generic.hxx"

namespace vm::formatters {

struct marp_tag { };

template <>
constexpr auto nix_shell_hook<marp_tag>() {
  return "npm install @marp-team/marp-cli";
}
}

#endif // PROJECT_BOOSTRAPPER_MARP_HXX
