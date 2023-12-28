//
// Created by Vivien Mille on 28/12/2023.
//

#ifndef PROJECT_BOOSTRAPPER_GENERIC_HXX
#define PROJECT_BOOSTRAPPER_GENERIC_HXX

namespace vm::formatters {

template <typename tag_t>
constexpr auto file_formatter() {
  return "";
}

template <typename tag_t>
constexpr auto nix_package_name() {
  return "";
}

template <typename tag_t>
constexpr auto nix_shell_hook() {
  return "";
}

}

#endif // PROJECT_BOOSTRAPPER_GENERIC_HXX
