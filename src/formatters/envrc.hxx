//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_ENVRC_HXX
#define PROJECT_BOOSTRAPPER_ENVRC_HXX

#include "formatters/generic.hxx"
#include "fmt/core.h"

namespace vm::formatters {

struct envrc_tag { };

template <>
constexpr auto file_formatter<envrc_tag>() {
  return "use nix\n";
}

}

#endif // PROJECT_BOOSTRAPPER_ENVRC_HXX
