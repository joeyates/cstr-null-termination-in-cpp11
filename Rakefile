require 'rake/builder'

Rake::Builder.new do | builder |
  builder.target               = 'cstr-null-termination-in-cpp11'
  builder.architecture         = 'x86_64'
  builder.compilation_options  = ['-std=c++0x', '-DDEBUG']
  builder.logger.level         = ::Logger::DEBUG
end
