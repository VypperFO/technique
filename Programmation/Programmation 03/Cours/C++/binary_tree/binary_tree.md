# Search Binary Tree

## Terme

1. Racine : le premier noeud
2. Noeud
3. Feuille : les noeud au bout

## UML

| BSTree \<T>                         |
| ----------------------------------- |
| -root: DLNode\<T>\*                 |
| -count: size_t                      |
| -add(data T, node: DLNode\<T>\*)    |
| -search(data T, node: DLNode\<T>\*) |
| ----------------------------        |
| +add(data: T)                       |
| +search(data: T): bool              |
| +remove(data: T)                    |

# Ajout

search : si data > noeud --> droite | si data < noeud --> gauche

# Recursiviter

Une fonction/methode qui se rappelle elle-meme

-   remplace une boucle
-   necessite un parametre comme iterateur

# Parcours
- Prefixe (Preorder)
1. Ajouter la donnee au parcours
2. Aller a gauche
3. Aller a droite
- Infixe (Inorder)
1. Aller a gauche
2. Ajouter la donnee au parcours
3. Aller a droite
- Postfixe (Postorder)
1. Aller a gauche
2. Aller a droite
3. Ajouter la donnee au parcours
- Largeur (Breathfirst)
