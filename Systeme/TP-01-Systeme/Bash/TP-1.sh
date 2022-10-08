#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31 

# Indique le nombre le plus grand et le nombre le plus petit parmi les arguments reçus.

if [ "$#" = 0 ]
then
    echo "No arguments passed."
    exit 1
fi
 
maxEle=$1
minEle=$1
  
for arg in "$@"
do
    if [ "$arg" -gt "$maxEle" ]
    then
        maxEle=$arg
    fi
done

for arg in "$@"
do
    if [ "$arg" -lt "$minEle" ]
    then
        minEle=$arg
    fi
done

echo "Le plus grand nombre est: $maxEle"
echo "Le plus petit nombre est: $minEle"