# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31

# Rechercher tous les fichiers dans le répertoire et les sous-répertoires enfants  et inscrire
# en ordre décroissant (du plus gros au plus petit), le nom et la taille du fichier. Je veux une
# seule liste, pas une liste par sous-répertoire.

try {
    $repertoirePresent = Get-Location -ErrorAction Stop
    
    Get-ChildItem -Path $repertoirePresent -Depth 1 | Sort-Object Length -Descending | 
    Select-Object Length, Name, Directory | 
    Format-Table -AutoSize -ErrorAction Stop
}
catch {
    Write-Output "Une erreur est survenu"
}
