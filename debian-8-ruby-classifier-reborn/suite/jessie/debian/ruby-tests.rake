require 'gem2deb/rake/testtask'
Gem2Deb::Rake::TestTask.new do |t|
  t.test_files = FileList['test/*_test.rb']
end
