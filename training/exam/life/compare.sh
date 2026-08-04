#!/bin/bash

PROG1=./life
PROG2=./life2

tests=(
# Official examples
"5 5 0|sdxddssaaww"
"10 6 0|sdxssdswdxddddsxaadwxwdxwaa"
"3 3 0|dxss"
"3 3 1|dxss"
"3 3 2|dxss"

# Empty input
"1 1 0|"
"1 1 1|"
"2 2 0|"
"3 3 5|"
"10 10 10|"

# Toggle only
"3 3 0|x"
"3 3 0|xx"
"3 3 0|xxx"
"3 3 0|xxxx"
"5 5 2|xxxxxxxx"

# Single directions
"5 5 0|d"
"5 5 0|a"
"5 5 0|w"
"5 5 0|s"

# Draw after moving
"5 5 0|xd"
"5 5 0|xs"
"5 5 0|xa"
"5 5 0|xw"

# Long movements (border clamping)
"5 5 0|dddddddddddddddd"
"5 5 0|aaaaaaaaaaaaaaaa"
"5 5 0|wwwwwwwwwwwwwwww"
"5 5 0|ssssssssssssssss"

# Draw while moving
"5 5 0|xdddd"
"5 5 0|xssss"
"5 5 0|xaaaa"
"5 5 0|xwwww"

# Rectangle
"5 5 0|xddddssssaaaawwww"

# Zig-zag
"5 5 0|xdsawdsawdsaw"
"5 5 0|xsdwasdwasdwa"
"5 5 3|xdsawdsawdsaw"

# Toggle repeatedly
"5 5 0|xdxdxdxd"
"5 5 0|xsxsxsxs"
"5 5 0|xaxaxaxa"
"5 5 0|xwxwxwxw"

# Random paths
"4 4 0|sdxssdswdxddddsxaadwxwdxwaa"
"6 6 0|sdxssdswdxddddsxaadwxwdxwaa"
"8 8 2|sdxssdswdxddddsxaadwxwdxwaa"
"10 10 5|sdxssdswdxddddsxaadwxwdxwaa"

# Small boards
"1 1 5|xxxxxxxx"
"2 2 5|xdsaw"
"2 3 2|xddddssss"
"3 2 2|xaaaawwww"

# Large boards
"20 20 0|xddddddddddddssssssssssssaaaaaaaawwwwwwww"
"20 20 3|xdsawxdsawxdsawxdsaw"

# Lots of toggling
"10 10 0|xxxxxxxxxxxxxxxxxxxxxxxx"
"10 10 0|xdsawxxxxxxxxxdsaw"

# Long random sequences
"10 10 4|xdsawddssawwddssaawwddssaww"
"10 10 8|xxdssawwdsxawdsawxxddsaww"
"15 10 6|xddddssssaawwwddssaaawwwdddsss"

# Stress
"30 30 0|xddddddddddddddddddddddddddddssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaaaaaaaawwwwwwwwwwwwwwwwwwwwwwwwwwww"

# Your original test
"4 3 0|sdxssdswdxddddsxaadwxwdxwaa"
"4 3 1|sdxssdswdxddddsxaadwxwdxwaa"
"4 3 5|sdxssdswdxddddsxaadwxwdxwaa"
)

i=1

for test in "${tests[@]}"; do
    args="${test%%|*}"
    input="${test#*|}"

    out1=$(printf "%s" "$input" | $PROG1 $args | cat -e)
    out2=$(printf "%s" "$input" | $PROG2 $args | cat -e)

    if [ "$out1" != "$out2" ]; then
        echo "FAIL on test #$i"
        echo "Args : $args"
        echo "Input: '$input'"
        echo
        echo "--- life ---"
        echo "$out1"
        echo
        echo "--- life2 ---"
        echo "$out2"
        exit 1
    fi

    echo "Test #$i: OK"
    ((i++))
done

echo
echo "All tests OK."