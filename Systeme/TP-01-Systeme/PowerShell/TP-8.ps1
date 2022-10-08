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

[System.Collections.ArrayList]$playerOne = @()
[System.Collections.ArrayList]$playerTwo = @()
$deck = @(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13)
[System.Collections.ArrayList]$shuffledDeck = $deck | Sort-Object { Get-Random }

$winned = $false
$roundCount = 0

$halfDeck = [int]($shuffledDeck.Count) / 2

for ($i = 0; $i -lt $halfDeck; $i++) {
    $playerOne += $shuffledDeck[$i]
    $shuffledDeck.RemoveAt($shuffledDeck[$i])
}
for ($i = 0; $i -lt $halfDeck; $i++) {
    $playerTwo += $shuffledDeck[$i]
    $shuffledDeck.RemoveAt($shuffledDeck[$i])
}

while (!$winned) {

    if ([int]$playerOne[0] -gt [int]$playerTwo[0]) {
        $playerOne += $playerTwo[0]
        $playerTwo.RemoveAt(0)
        $playerOne += $playerOne[0]
        $playerOne.RemoveAt(0)
        $roundCount++
    }
    elseif ([int]$playerTwo[0] -eq [int]$playerOne[0]) {
        $playerOne.RemoveAt(0)
        $playerTwo.RemoveAt(0)
        $roundCount++
    }
    else {
        $playerTwo += $playerOne[0]
        $playerOne.RemoveAt(0)
        $playerTwo += $playerTwo[0]
        $playerTwo.RemoveAt(0)
        $roundCount++
    }
    
    if ($playerOne.Count -eq 1) {
        Write-Output "Le joueur deux gagne la partie!"
        Write-Output "Nombre de rondes: $roundCount"
        $winned = $true
    }
    elseif ($playerTwo.Count -eq 1) {
        Write-Output "Le joueur un gagne la partie!"
        Write-Output "Nombre de rondes: $roundCount"
        $winned = $true
    }
}
