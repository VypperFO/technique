# Numéro 1

```mermaid
erDiagram
  Service ||--|{ ProduitService : ""
  Service ||--|{ FournisseurServiceAccepte : ""
  FournisseurServiceAccepte }|--|| Fournisseur : ""
  Service ||--o{ FournisseurServiceRefus : ""
  FournisseurServiceRefus }o--|| Fournisseur : ""
  Service ||--|| Autorisation : ""
  Service ||--|| ProduitService : ""
  Autorisation ||--|| ProduitFournisseur : ""
  Fournisseur ||--|| ProduitFournisseur : ""
  ProduitService ||--|| ProduitFournisseur : ""


  Service {
    ID numauto PK
    nom texte
    domaineActivite texte
  }
  Fournisseur{
    ID numauto PK
    nom texte
  }
  FournisseurServiceAccepte{
    fournisseurID integer "PK, FK"
    serviceID integer "PK,FK"
  }
  FournisseurServiceRefus{
    fournisseurID integer "PK, FK"
    serviceID integer "PK,FK"
    dateDemande integer
  }
  ProduitFournisseur{
    code integer PK
    nomCommercial texte
    description texte
    prixVente decimal "2,*"
  }
  ProduitService{
    code integer PK
    nom texte
    description texte
    quantiteStock int
  }
  Autorisation{
    serviceID integer "PK, FK"
    produitFournisseurID integer "PK, FK"
    qteAchat integer
    prixAchat decimal "2,*"
  }
```

# Question 2

```mermaid
erDiagram
  Paiement ||--{| FacturePaiment : ""
  FacturePaiement ||--{| Facture : ""
  Facture ||--|| Commande : ""
  Client ||--o| Commande : ""
  Commande ||--|| CompositionCommande : ""
  CompositionCommande ||--{| Article : ""
  Commande ||--{| CompositionLivraison : ""
  CompositionLivraison ||--{| Article : ""

  Paiement{
    ID numauto PK
    datePaiement integer
    montant decimal "*,2"
  }
  Facture{
    factureID integer PK
    total decimal "*,2"
  }
  FacturePaiement{
    factureNo integer "PK, FK"
    paiementID integer "PK, FK"
  }
  Client{
    clientID numauto PK
    nom texte
  }
  Commande{
    noCommande integer PK
    dateCommande date
    factureNO integer FK
    clientID integer FK
  }
  CompositionCommande{
    noCommande integer "PK, FK"
    articleID integer "PK, FK"
    qteCommandee integer
    prixVente decimal "*,2"
  }
  Article{
    articleID autonum PK
    nom texte
    prix decimal "*,2"
    qteStock integer
    qteSeuil integer
  }
  CompositionLivraison{
    ArticleID integer "PK, FK"
    CommandeNO integer "PK, FK"
    qteLibre integer
    dateLivraision date
  }
```
