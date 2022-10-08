#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# un script qui parcourt tous les fichiers txt d'un répertoire donné en argument et qui affiche les 10 premières lignes de chacun de
# ces fichiers de façon suivante dans le fichier entêtes.txt

cd "$1"
head -10 *.txt > entete.txt