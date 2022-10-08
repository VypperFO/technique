# Auteur : Félix-Olivier Latulippe
# DA : 2173242 
# Session : H2022 
# Date : 2022-03-31

# En PowerShell, on veut avoir plus de détail (nom, id, taille en mémoire centrale, nombre de 
# threads) sur un processus passé en ligne de commande.

$process = $args
try {
    if ($args[0].GetType() -eq [int]) {
        Get-Process -Id $process | Select-Object Id, ProcessName, WS,
        @{name = 'ThreadCount'; expression = { $_.Threads.Count } } -ErrorAction Stop
    }
    elseif ($args[0].GetType() -eq [string]) {
        Get-Process -ProcessName $process | Select-Object Id, ProcessName, WS,
        @{name = 'ThreadCount'; expression = { $_.Threads.Count } }  -ErrorAction Stop
    }
}
catch {
    Write-Output "Une erreur est survenue"
}


