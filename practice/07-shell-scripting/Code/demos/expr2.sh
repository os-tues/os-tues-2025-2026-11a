#!/bin/bash

# Demonstrating expr for arithmetic
x=5
y=10

sum=$(expr $x + $y)      # Addition
diff=$(expr $x - $y)     # Subtraction
product=$(expr $x \* $y) # Multiplication requires escaping '*'
quotient=$(expr $y / $x) # Integer division (remainder is discarded)

echo "x = $x, y = $y"
echo "sum = $sum"
echo "diff = $diff"
echo "product = $product"
echo "quotient (integer) = $quotient"

# Demonstrating expr for string handling
my_string="Hello Shell"
length=$(expr length "$my_string")
sub_str=$(expr substr "$my_string" 7 5)  # Start at position 7 (1-based), length 5

echo
echo "my_string: '$my_string'"
echo "length of my_string = $length"
echo "substring = '$sub_str'"