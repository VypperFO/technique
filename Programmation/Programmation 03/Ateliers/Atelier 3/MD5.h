/// \file MD5.h
/// \brief Algorithme de hachage MD5.
/// \author Patrick Singcaster (singcaster@clogik.io)

/// \struct MD5_CTX
/// \brief Contexte MD5.
typedef struct {
  unsigned long state[4];   ///< État
  unsigned long count[2];   ///< Compte
  unsigned char buffer[64]; ///< Tampon
} MD5_CTX;

/// \brief Initialisation d'un contexte MD5.
/// \param context Contexte MD5
void MD5Init(MD5_CTX* context);

/// \brief Processus de hachage.
/// \param context Contexte MD5
/// \param input Données à hacher
/// \param length Taille des données à hacher
void MD5Update(MD5_CTX* context, unsigned char* input, unsigned int length);

/// \brief Finalisation du hachage.
/// \param context Contexte MD5
/// \param digest Résultat final de 16 caractères
void MD5Final(MD5_CTX* context, unsigned char* digest);