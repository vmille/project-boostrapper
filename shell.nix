{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
    packages = [ pkgs.git pkgs.jetbrains.clion pkgs.cmake pkgs.ninja pkgs.vcpkg pkgs.clang_17 pkgs.pkg-config ];
}
