############################################################
# 3. Arithmetic expressions (integer + float simulation)
############################################################
echo "=== 3) Arithmetic operations ==="
# (A) Integer arithmetic using double parentheses:
num1=5
num2=3
sum=$((num1 + num2))
diff=$((num1 - num2))
prod=$((num1 * num2))
div=$((num1 / num2))    # Integer division; remainder is dropped
echo "num1=$num1, num2=$num2"
echo "sum = $sum"
echo "diff = $diff"
echo "prod = $prod"
echo "div (integer) = $div"
echo
# (B) Floating-point arithmetic usually requires an external tool (like `bc`) in shell:
float1=5.5
float2=3.2
float_sum=$(echo "$float1 + $float2" | bc)
float_mult=$(echo "$float1 * $float2" | bc)
echo "float1=$float1, float2=$float2"
echo "float sum = $float_sum"
echo "float multiplication = $float_mult"
echo