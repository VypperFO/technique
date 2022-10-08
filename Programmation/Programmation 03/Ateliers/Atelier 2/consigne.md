# Atelier 2

Le 3e tome des « Récréations mathématiques » est publié en 1892 et contient un problème proposé par Édouard Lucas.

## Tours de Hanoï

Le jeu consiste à déplacer des étages, de diamètres différents, du premier socle vers le dernier, en passant par un socle intermédiaire, tout en respectant les 2 règles suivantes:

- Déplacer un étage à la fois.
- Déplacer un étage sur un socle vide ou un étage de diamètre supérieur.

### Preuve

Par preuve mathématique, le nombre de mouvements minimum nécessaire pour résoudre ce problème est:

2 <sup>nombre d'étages</sup> - 1

Le travail pratique consiste à démontrer la véracité de cette preuve.

## Algorithme

L'algorithme afin de trouver la solution optimale est relativement simple:

- Déplacer le plus petit étage vers un socle adjacent.
- Déplacer, si possible, un autre étage.

<br>![Tours de Hanoï](Images/Hanoi.png)

### Déplacements

Par contre, le socle adjacent dépend du nombre d'étages total:

- Pair: Socle suivant.
- Impair: Socle précédent.

## Résultat

Votre programme doit demander à l'utilisateur de saisir le nombre d'étages désiré, effectuer l'algorithme, et afficher le nombre de mouvements effectués par celui-ci:

```
Saisissez le nombre d'étages: 4
Nombre de mouvements: 15
```

_Dans le cadre de ce travail, un maximum de 10 étages sera utilisé lors de sa correction._

## Barème

| Évaluation             | Pondération |
| ---------------------- | ----------- |
| Utilisation de la pile | / 5         |
| Résolution du problème | / 5         |
|                        | / 10        |

_\*&nbsp;&nbsp;&nbsp;-1 pour chaque non respect des normes._<br>
_\*\* -1 pour chaque fuite ou gaspillage de mémoire._

# Noted

Ne pas faire de if\
Longueur des socles: int\
Tours: piles\
Piles sont dans un tableau\

struct ArrayStack socles[3];\
vers la droite: i + 1 % 3\
vers la gauche: i + 2 % 3\

# Scan en C

```c
int main (){
  printf("saissisez le nombre d'etages: ");
  int nbEtages:
  scanf("%i", &nbEtages);

  return 0;
}
```
