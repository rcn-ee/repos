#
# Run this gnuplot script with the command line:
#
# gnuplot -e 'input_file="/path/to/input";output_file="/path/to/output.png";graph_title="title text"' /path/to/histo.gp
#
# where the input file is generated using latency option "-g"
#

set terminal png size 900,700
set output output_file

set title graph_title
set xlabel "user-space latency in microseconds"
set ylabel "occurrences + 1 (log)"
set logscale y
set key off
set grid

set bar 1.000000
set style fill  solid 1.00 border -1
set style rectangle back fc lt -3 fillstyle  solid 1.00 border -1
plot input_file w line
