//
// Created by Vivien Mille on 26/12/2023.
//


#include <catch2/catch_all.hpp>

#include <formatters/envrc.hxx>
#include <formatters/nix.hxx>
#include <formatters/marp.hxx>
#include <formatters/vcpkg.hxx>

#include <iterator>
#include <fstream>

TEST_CASE("envrc", "[formatter][nix]") {
  constexpr auto f = vm::formatters::file_formatter<vm::formatters::envrc_tag>();
  REQUIRE("use nix\n" == fmt::format(f));
}

TEST_CASE("shell.nix / base content", "[formatter][nix]") {
  using namespace Catch::Matchers;
  constexpr auto f = vm::formatters::file_formatter<vm::formatters::nix_tag>();
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", ""), fmt::arg("hooks", "")), StartsWith("{ pkgs ? import <nixpkgs> {}}:"));
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", ""), fmt::arg("hooks", "")), Matches("[\\s\\S]*pkgs\\.mkShell \\{[\\s\\S]*packages = \\[\\n[\\s\\S]*\\];[\\s\\S]*\\}\\n"));
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", ""), fmt::arg("hooks", "")), Matches("[\\s\\S]*shellHook = ''\\n[\\s\\S]*'';[\\s\\S]*\\n"));
}

namespace vm::formatters {

struct my_app_tag { };

template <>
constexpr auto nix_package_name<my_app_tag>() {
  return "my-app";
}

template <>
constexpr auto nix_shell_hook<my_app_tag>() {
  return "install my-app";
}
}

TEST_CASE("shell.nix / package name", "[formatter][nix]") {
  using namespace Catch::Matchers;
  auto constexpr f = vm::formatters::file_formatter<vm::formatters::nix_tag>();
  const auto p = vm::formatters::nix_package_names_format<vm::formatters::my_app_tag>();
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", p), fmt::arg("hooks", "")), Matches("[\\S\\s]*packages = \\[[\\s]*pkgs\\.my-app[\\s]*\\][\\S\\s]*"));
}

TEST_CASE("shell.nix / package hook", "[formatter][nix]") {
  using namespace Catch::Matchers;
  auto constexpr f = vm::formatters::file_formatter<vm::formatters::nix_tag>();
  const auto h = vm::formatters::nix_hooks_format<vm::formatters::marp_tag>();
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", ""), fmt::arg("hooks", h)), Matches("[\\s\\S]*shellHook = ''[\\s]*npm install @marp-team\\/marp-cli[\\s]*'';[\\s\\S]*\\n"));
}

TEST_CASE("shell.nix / package hooks", "[formatter][nix]") {
  using namespace Catch::Matchers;
  auto constexpr f = vm::formatters::file_formatter<vm::formatters::nix_tag>();
  const auto h = vm::formatters::nix_hooks_format<vm::formatters::marp_tag, vm::formatters::my_app_tag>();
  REQUIRE_THAT(fmt::format(f, fmt::arg("packages", ""), fmt::arg("hooks", h)), Matches("[\\s\\S]*shellHook = ''[\\s]*npm install @marp-team\\/marp-cli[\\s]*install my-app[\\s]*'';[\\s\\S]*\\n"));
}

TEST_CASE("vcpkg", "[formatter][vcpkg]") {
  auto constexpr f = vm::formatters::file_formatter<vm::formatters::vcpkg_tag>();
  std::string res = fmt::format(f);
  std::ifstream ifs("reference/vcpkg.json");
  REQUIRE(ifs.is_open());
  std::string ref{std::istreambuf_iterator(ifs), std::istreambuf_iterator<char>()};
  REQUIRE(ref == res);
}