#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# Un script qui va parcourir les fichiers images (.jpg ou .gif ou .png) du répertoire x. Pour chaque image, le script devra
# créer une image .png de taille dim dans le répertoire y.

cd $1

magick mogrify -format png *.png >> $2
magick mogrify -format png *.gif >> $2
magick mogrify -format png *.jpg >> $2

cd $2

magick mogrify -resize $3 *.png