#!/usr/bin/ruby

require 'fileutils'

include FileUtils::Verbose

src_package = "lib#{ENV.fetch('SOURCE')}"
dst_package = "#{ENV.fetch('SOURCE')}-tcltk"

ruby_api_version = ENV.fetch('RUBY_API_VERSION')

# .so files
tk_so_files = Dir.glob("debian/#{src_package}/usr/lib/*/ruby/**/{tcltklib,tkutil}.so")
tk_so_files.each do |f|
  dst = f.sub(/^debian\/#{src_package}/, "debian/#{dst_package}")
  mkdir_p File.dirname(dst)
  mv f, dst
end

# .rb files
tk_lib_files = Dir.chdir('ext/tk/lib') { Dir.glob('*').select { |f| File.directory?(f) || f =~ /\.rb$/ } }

mkdir_p "debian/#{dst_package}/usr/lib/ruby/#{ruby_api_version}"
tk_lib_files.each do |f|
  src = File.join("debian/#{src_package}/usr/lib/ruby/#{ruby_api_version}/#{f}")
  dst = File.join("debian/#{dst_package}/usr/lib/ruby/#{ruby_api_version}/#{f}")
  mv src, dst
end

