# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31

# En PowerShell, lister les disques, l'espace disponible, l'espace utilisé, le pourcentage 
# d'utilisation et la capacité maximale totale pour chacun d'eux. Exporter le résultat dans 
# un fichier HTML nommé fichier.html.

try {
    $myDisks = Get-WmiObject -Class Win32_logicaldisk -Filter "DriveType = '3'" | 
    Select-Object -Property Name, 
    @{L = 'FreeSpaceGB'; E = { "{0:N2}" -f ($_.FreeSpace / 1GB) } },
    @{L = "Capacity"; E = { "{0:N2}" -f ($_.Size / 1GB) } },
    @{L = "Utilisation"; E = { "{0:N2}" -f (($_.FreeSpace / $_.Size) * 100 ) } } -ErrorAction Stop
    
    ConvertTo-Html -InputObject $myDisks | Out-File fichier.html
}
catch {
    Write-Output "Une erreur est survenue"
}


