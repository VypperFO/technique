class HuffmanNode
{
public:
  unsigned char data;
  HuffmanNode *left;
  HuffmanNode *right;

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