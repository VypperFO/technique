#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# Recherche dans le répertoire présent et les enfants, les fichiers ayant le même nom et les indiquer dans un fichier sortie

find . -type f -follow -printf "%s\t%p\n" | find .. -type f -follow -printf "%s\t%p\n" | 
while read path ; do
    filename="${*/##}"
    echo "$path" >> sortie.txt
done