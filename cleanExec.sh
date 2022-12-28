#!/bin/bash
for i in $(find . -mindepth 2 -type f -executable -not -path './.git/*'); do
    rm -v $i;
done
