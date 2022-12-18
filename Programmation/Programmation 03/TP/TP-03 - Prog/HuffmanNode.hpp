/// @file HuffmanNode.hpp
/// @brief Classe HuffmanNode relier a la priority queue
/// @author Felix-Olivier Latulippe felixlatulip@gmail.com

/// @class HuffmanNode
/// @brief Classe permettant d'implementer le noeud huffannode
class HuffmanNode
{
public:
  unsigned char data; ///< La donnee a ajouter dans le noeud huffman
  HuffmanNode *left;  ///< Le noeud huffman de gauche
  HuffmanNode *right; ///< Le noeud huffman de droite

  HuffmanNode(unsigned char data, HuffmanNode *left = nullptr, HuffmanNode *right = nullptr)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
  HuffmanNode(HuffmanNode *left = nullptr, HuffmanNode *right = nullptr)
  {
    this->left = left;
    this->right = right;
  }
};