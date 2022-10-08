# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31 

# Ce script parcourt tous les fichiers txt d'un répertoire donné en argument et qui affiche 
# les 10 premières lignes de chacun de ces fichiers de façon suivante dans le fichier entêtes.txt


$repertoire = $args

try {
    foreach ($i in (get-childitem $repertoire -File -ErrorAction Stop)) {
        $fichier = [System.IO.Path]::GetFileName("$i")
        "$fichier" + " " + (Get-Content $i.fullname | Select -First 10) | Add-Content entete.txt -ErrorAction Stop
    }
}
catch {
    Write-Output "Une erreur est survenue"
}