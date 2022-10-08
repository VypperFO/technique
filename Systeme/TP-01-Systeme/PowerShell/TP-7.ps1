# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31

# En PowerShell, rechercher dans les répertoires présent et enfants tous les fichiers avec le 
# même nom et les indiquer dans un fichier sortie.

#TODO
try {
    #Get-ChildItem -Depth 2 |  Select -ExpandProperty Name | Out-File sortie.txt
    Get-ChildItem -Recurse -File -ErrorAction Stop |
    Select-Object Name | sortie.txt
}
catch {
    Write-Output "Une erreur est survenu"
}