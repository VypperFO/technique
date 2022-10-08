# Introduction

Je prends le temps ici pour vous expliquer ce que je souhaite comme réponse. La plupart des réponses dans le TP ne se solutionnent pas en une ligne, il vous faudra tester vos réponses, vous aurez à créer vos réponses dans un éditeur de texte initialement pour les tester. À la fin, vous ne devez me remettre que les scripts, aucun autre répertoire ou fichiers de tests.

Pour toutes réponses où le script ne fonctionne pas, la note sera de 0.

De plus, je demande qu'à chaque question, vous ayez une entête de commentaire pour expliquer ce que fait votre script. Ceci doit être présent comme si vous aviez copié le fichier.

Finalement dans le cas où l'utilisateur entre des données, assurez-vous que même si de mauvaises données sont entrées, les scripts ne plantent pas. (fiabilité 20%)

Les scripts devront être nommés ainsi: TP1-1.sh ou TP1-1.ps1 pour la question 1 de chaque langage

## Bash

1.  Indiquez le nombre le plus grand et le nombre le plus petit parmi les arguments reçus. Les seuls arguments à comparer sont les nombres, tous les autres arguments sont ignorés. Votre script doit pouvoir recevoir plus que 2 arguments. 

2. En bash, créer un script qui offre les opérations suivantes dans un menu, l'utilisateur ne choisit qu'une seule option à la fois. **Les scripts s'exécutent avec les options nécessaires pour éviter les interractions utilisateurs**. Tant que l'utilisateur ne choisit le e, le script réaffiche le menu.

  - a. sudo apt-get update
  - b. sudo apt-get upgrade
  - c. sudo apt-get dist-upgrade
  - d. sudo apt-get clean
  - e. quitter
 
3. En bash, créer un script qui parcourt tous les fichiers txt d'un répertoire donné en argument et qui affiche les 10 premières lignes de chacun de ces fichiers de façon suivante dans le fichier entêtes.txt:

test1.txt:
```
<html>
<head>
  <title>J'aime le chocolat</title>
</head>
<body>
...
```
 
test2.txt:
```
chaton
zèbre
chien
```

4. En bash, demander à l'utilisateur un chiffre, créer un tableau de x éléments random (de 0 à 65536). 
 
Par la suite, on parcourt le tableau créé, pour chaque élément, on recherche si un processus existant a le même numéro de processus (PID):
- Si oui, afficher le # et le nom, 
- Si non, affiche le # et indique qu'il n'y a aucun processus ayant ce #.

Si l'utilisateur entre 5, votre tableau pourrait avoir les données suivantes, par exemple:

```
5843
238
12122
2332
5445

# La réponse pourrait ressembler à ceci:

5843, aucun processus a ce numéro de processus
238, aucun processus a ce numéro  de processus
12122, chrome a ce numéro de processus
2332, aucun processus a ce numéro de processus
5445, visual studio code a ce numéro de processus
```
 
5. En bash, rechercher tous les fichiers dans le répertoire et les sous-répertoires enfants  et inscrire en ordre décroissant (du plus gros au plus petit), le nom et la taille du fichier. Je veux une seule liste, pas une liste par sous-répertoire.

6. En bash, créer un script qui va parcourir les fichiers images (.jpg ou .gif ou .png) du répertoire x. Pour chaque image, le script devra créer une image .png de taille dim dans le répertoire y. Je vous recommande d'utiliser le programme imagemagick pour le faire.

Le script sera appelé de la façon suivante, par exemple: 

6.sh x y dim
 
7. En bash, rechercher dans le répertoire présent et les enfants, les fichiers ayant le même nom et les indiquer dans un fichier sortie qui affichera l'information de la façon suivante:

```
nom_de_fichier.txt:
nom_de_fichier.txt
exemple1/nom_de_fichier.txt
exemple2/exemple3/nom_de_fichier.txt

nom2.txt:
exemple2/nom2.txt
exemple3/nom2.txt
```
 
8. Simuler un combat de jeu de carte de bataille

Un paquet de carte est séparé entre deux joueurs de façon aléatoire:
  
- À tour de rôle, chaque joueur pige la carte sur le dessus de sa pile de carte et les deux cartes s'affrontent:

  - La carte la plus élevée gagne et les deux cartes se 
  retrouvent en dessous de la pile du gagnant.

  - En cas d'égalité, chacun reprend sa carte.

Dès qu'un joueur ne peut plus jouer (donc se retrouve sans carte), il perd.

 ## Powershell

 1. En PowerShell, créez un script qui parcourt tous les fichiers txt d'un répertoire donné en argument et qui affiche les 10 premières lignes de chacun de ces fichiers de façon suivante dans le fichier entêtes.txt:

```
test1.txt:

<html>
<head>
  <title>J'aime le chocolat</title>
</head>
<body>
...
 
test2.txt:
chaton
poil
chien
```

2. En PowerShell, votre script doit recevoir deux arguments DateDebut, DateFin. Ce sont deux paramètres nommés obligatoires:
-DateDebut, date
-DateFin, date 
 
Voir la liste des logs d’application qui se situe entre les deux dates (debut et fin) passées par aguments et retourner les résultats dans un fichier nommé sortie.csv (sous le format csv).

3. En PowerShell, on veut avoir plus de détail (nom, id, taille en mémoire centrale, nombre de threads) sur un processus passé en ligne de commande.
 
Par exemple, si on fait:
 
script.ps1 1290, il s'agit d'une recherche sur le processus id 1290.
script.ps1 explorer, il s'agit d'une recherche pour le processus nommé explorer
 
Si plusieurs processus sont ainsi recherché par le nom, on retourne l'information de chacun.

4. En PowerShell, demander à l'utilisateur un chiffre, créer un tableau de x éléments random (jusqu'à 65536). 
 
Par la suite, on parcoure le tableau de x éléments:
 
Pour chaque élément, on recherche si un processus existant a le même numéro de processus (ID):
 - Si oui, afficher le # et le nom, 
 - Si non, affiche le # et indique qu'il n'y a aucun processus ayant ce #.

```
Si l'utilisateur entre 5, votre tableau pourrait avoir les données suivantes (par exemple):

5843
238
12122
2332
5445

Par exemple:

5843, aucun processus a ce numéro
238, aucun processus a ce numéro
12122, chrome a ce numéro
2332, aucun processus a ce numéro
5445, visual studio code a ce numéro
```

5. En PowerShell, rechercher dans le répertoire en cours et enfant tous les fichiers et inscrire en ordre décroissant (du plus gros au plus petit), le nom et la taille du fichier. Je veux une seule liste, pas une liste par sous-répertoire.

6. En PowerShell, lister les disques, l'espace disponible, l'espace utilisé, le pourcentage d'utilisation et la capacité maximale totale pour chacun d'eux. Exporter le résultat dans un fichier HTML nommé fichier.html.

7. En PowerShell, rechercher dans les répertoires présent et enfants tous les fichiers avec le même nom et les indiquer dans un fichier sortie qui indiquera de la façon suivante:
 
```
nom_de_fichier.txt:
nom_de_fichier.txt
exemple1/nom_de_fichier.txt
exemple2/exemple3/nom_de_fichier.txt
...
nom2.txt:
exemple2/nom2.txt
exemple3/nom2.txt
```

8. Simuler un combat de jeu de carte de bataille

Un paquet de carte est séparé entre deux joueurs de façon aléatoire:
  
- À tour de rôle, chaque joueur pige la carte sur le dessus de sa pile de carte et les deux cartes s'affrontent:

  - La carte la plus élevée gagne et les deux cartes se 
  retrouvent en dessous de la pile du gagnant.

  - En cas d'égalité, chacun reprend sa carte.

Dès qu'un joueur ne peut plus jouer (donc se retrouve sans carte), il perd.
 