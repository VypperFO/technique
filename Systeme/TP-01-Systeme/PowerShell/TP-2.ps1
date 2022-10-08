# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-04-01

# En PowerShell, votre script doit recevoir deux arguments DateDebut, DateFin. Ce sont deux 
# paramètres nommés obligatoires:
# -DateDebut, date
# -DateFin, date 
# Voir la liste des logs d’application qui se situe entre les deux dates (debut et fin) passées
# par aguments et retourner les résultats dans un fichier nommé sortie.csv (sous le format csv).


$dateDebut = $args[0]
$dateFin = $args[1]

try {
    [Datetime]::ParseExact($dateDebut, 'MM/dd/yyyy', $null)
    [Datetime]::ParseExact($dateFin, 'MM/dd/yyyy', $null)
    
    $logs = Get-WinEvent -ErrorAction Stop -FilterHashtable @{LogName = 'Application'; StartTime = "$dateDebut"; EndTime = "$dateFin"; } | 
    ConvertTo-Csv -NoTypeInformation

    New-Item sortie.csv
    Add-Content sortie.csv $logs
}
catch {
    Write-Output "Une erreur est survenue"
}