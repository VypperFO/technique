# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31

# Demander à l'utilisateur un chiffre, créer un tableau de x éléments random (de 0 à 65536).  
# Par la suite, on parcourt le tableau créé, pour chaque élément, on recherche si un processus
# existant a le même numéro de processus (PID):
# - Si oui, afficher le # et le nom, 
# - Si non, affiche le # et indique qu'il n'y a aucun processus ayant ce #.



try {
    $nbInput = Read-Host -Prompt "Entrer un chiffre: "
    $list = @(1..65536 | Get-Random -Count $nbInput) 
    $list
    
    Write-Output "--------------------------------------"

    for ($i = 0; $i -lt $list.Count; $i++) {
        if (-not (Get-Process -Id $list[$i] -ErrorAction SilentlyContinue)) {
            Write-Host "$($list[$i]), aucun processus a ce numero"
        }
        else {
            $nameOfProcess = Get-Process -ErrorAction Stop -Id $($list[$i]) | Select-Object -ExpandProperty Name
            Write-Output "$nameOfProcess a ce numero"
        }
    }
}
catch {
    Write-Output "Une erreur est survenu"
}
