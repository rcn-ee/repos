#-*- mode: ruby; coding: utf-8 -*-
require 'rake/testtask'
task :default => :test
Rake::TestTask.new do |t|
  t.libs << 'lib' << 'test'
  t.test_files = FileList['test/test_*.rb'].exclude(/.*tag.*|.*plugin.*|.*convertible.*/)
  t.verbose = true
end
