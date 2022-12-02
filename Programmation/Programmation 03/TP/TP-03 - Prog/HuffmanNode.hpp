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
};