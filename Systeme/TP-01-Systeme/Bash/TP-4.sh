#!/bin/bash

# Auteur : Félix-Olivier Latulippe
# DA : 2173242
# Session : H2022
# Date : 2022-03-31

# Demander à l'utilisateur un chiffre, créer un tableau de x éléments random (de 0 à 65536).
# Par la suite, on parcourt le tableau créé, pour chaque élément, on recherche si un processus
# existant a le même numéro de processus (PID):
# - Si oui, afficher le # et le nom,
# - Si non, affiche le # et indique qu'il n'y a aucun processus ayant ce #.

echo -n "Entrer le nombre de processus: "
read nbInput

re='^[0-9]+$'

if [[ $nbInput =~ $re ]] ; then
    entries=$(shuf -i 1-65536 -n$nbInput)
    echo "${entries[@]}"
    
    echo "-------------------------------"
    
    
    for i in ${entries[@]}; do
        if ps -W -p $i > /dev/null;
        then
            nomPID=(ps -W -p $i -o comm=)
            echo "$i, $nomPID a ce numero"
        else
            echo "$i, aucun processus"
        fi
    done
fi
