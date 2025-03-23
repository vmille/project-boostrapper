project('tutorial', 'cpp')
catch2dep = dependency('catch2-with-main')
fmtdep = dependency('fmt')
include_dirs = include_directories('src')
formater_tests = executable('formater_tests', 'test/formatter_tests.cxx', dependencies: [fmtdep, catch2dep], include_directories: include_dirs)
test('formater_tests', formater_tests)

