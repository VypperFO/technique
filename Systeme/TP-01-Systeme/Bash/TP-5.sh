#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# Recherche tous les fichiers dans le répertoire et les sous-répertoires enfants  et inscrire en ordre décroissant
# (du plus gros au plus petit), le nom et la taille du fichier. Je veux une seule liste, pas une liste par sous-répertoire.

find . -type f -follow -printf "%s\t%p\n" | find .. -type f -follow -printf "%s\t%p\n" |sort -n -r
