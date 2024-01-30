#!/usr/bin/env ruby
# will search for specfic string
puts ARGV[0].scan(/(hb[^o]n|hbt{1,}n|hbn)/).join
