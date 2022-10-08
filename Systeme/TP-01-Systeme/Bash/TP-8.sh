#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# Simuler un combat de jeu de carte de bataille
# Un paquet de carte est séparé entre deux joueurs de façon aléatoire:
# - À tour de rôle, chaque joueur pige la carte sur le dessus de sa pile de carte et les deux cartes s'affrontent:
# - La carte la plus élevée gagne et les deux cartes se
#   retrouvent en dessous de la pile du gagnant.
# - En cas d'égalité, chacun reprend sa carte.
# Dès qu'un joueur ne peut plus jouer (donc se retrouve sans carte), il perd.

declare -a playerOne
declare -a playerTwo
winned=$false
roundCount=0

deck=(1 2 3 4 5 6 7 8 9 10 11 12 13
    1 2 3 4 5 6 7 8 9 10 11 12 13
    1 2 3 4 5 6 7 8 9 10 11 12 13
1 2 3 4 5 6 7 8 9 10 11 12 13)
shuffledDeck=( $(shuf -e "${deck[@]}") )

for i in {0..25};
do
    playerOne+=(${shuffledDeck[$i]})
done

for i in {26..52};
do
    playerTwo+=(${shuffledDeck[$i]})
done

while [ true ]
do
    if [[ ${playerOne[0]} -eq ${playerTwo[0]} ]]
    then
        playerOne=("${playerOne[@]:1}")
        playerTwo=("${playerTwo[@]:1}")
        
    elif [[ ${playerOne[0]} -gt ${playerTwo[0]} ]]
    then
        playerOne+=(${playerTwo[0]})
        playerTwo=("${playerTwo[@]:1}")
        playerOne+=(${playerOne[0]})
        playerOne=("${playerOne[@]:1}")
        ((roundCount+=1))
    else
        playerTwo+=(${playerOne[0]})
        playerOne=("${playerOne[@]:1}")
        playerTwo+=(${playerTwo[0]})
        playerTwo=("${playerTwo[@]:1}")
        ((roundCount+=1))
    fi
    
    if [[ ${#playerOne[@]} -eq $null ]]
    then
        echo "Le joueur deux gagne la partie!"
        echo "Nombre de rondes: $roundCount"
        break
    elif [[ ${#playerTwo[@]} -eq $null ]]
    then
        echo "Le joueur un gagne la partie!"
        echo "Nombre de rondes: $roundCount"
        break
    fi
done