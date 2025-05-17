#!/bin/bash

for size in 10 20 50 100 200 500; do
	ARG=$(seq 1 $size | shuf | tr '\n' ' ')
	OPS=$(./push_swap $ARG | tee /tmp/ops.txt | ./checker_linux $ARG)
	COUNT=$(wc -l < /tmp/ops.txt)
	echo "Size: $size → $OPS (Instructions: $COUNT)"
done
