project('flush_6502', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

subdir('src')
inc_dirs = include_directories('src/headers')

executable('flush_6502',
           sources,
           include_directories : inc_dirs,
           install : true)
