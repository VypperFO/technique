class HuffmanNode
{
  unsigned char data;
  HuffmanNode *left;
  HuffmanNode *right;

public:
  HuffmanNode(unsigned char data, HuffmanNode *left = nullptr, HuffmanNode *right = nullptr)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  // INFORMATION GENERAL
  // 1. recensement
  // 2. file se prioriter
  // 3. construction de larbre de huffman
  // 4. encodage
  // 5. chiffrement
};