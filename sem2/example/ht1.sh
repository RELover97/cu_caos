#!/bin/bash

read N M
read -a a

while IFS= read x; do
    result=0

    for ((i = 0; i < N; ++i)); do
        result=$(( (result * x + a[i]) % M ))
    done

    printf '%d\n' "$result"
done