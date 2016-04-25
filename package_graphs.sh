#!/bin/bash

run_graph () {
	debtree --with-suggests ${pkg} >./graph/${pkg}.dot
	dot -T png -o ./graph/${pkg}.png ./graph/${pkg}.dot
	rm -rf ./graph/${pkg}.dot
}

pkg="jekyll" ; run_graph
