############################################################
# 4. Setting, unsetting, and getting environment variables
############################################################
echo "=== 4) Environment Variables ==="
# Example: Setting and exporting a new variable
export MY_ENV_VAR="Shell Demo Env Var"
echo "MY_ENV_VAR is now: $MY_ENV_VAR"

# Unsetting the variable
unset MY_ENV_VAR
echo "MY_ENV_VAR after unset: '$MY_ENV_VAR' (should be empty)"
echo

# Printing all environment + shell variables:
echo "=== Printing variables using 'set' (this can be quite long) ==="
# NOTE: If you only want environment variables, you can use `env` or `printenv`.
# `set` displays all variables (including shell-local variables).
# set
echo