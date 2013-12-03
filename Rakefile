require 'rake/builder'

Rake::Builder.new do | builder |
  builder.logger.level         = ::Logger::DEBUG
  builder.target               = 'cstr-null-termination-in-cpp11'
  builder.architecture         = 'x86_64'
  builder.compilation_options  = ['-std=c++0x', '-DDEBUG', '-pthread']
  builder.library_dependencies = ['gtest', 'pthread']
end
