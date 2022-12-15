// constcast.cpp -- using const_cast<>
#include <iostream>
using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000;

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    // std::cin.get();
    return 0;
}

void change(const int * pt, int n)
{
    int * pc;
  
    pc = const_cast<int *>(pt);
    *pc += n;
 
}
�d+:�R�|C+=��'�B�:^�����2������O��ۈ��-���+�'�D�Cm� �+po�6��}�o����]͵�s�����!��>Ⱥ�S�}i��/�g���W��>��/ (eY)��F����9%�T�z�*��舧B)�,�+5���-]��o@�ٲ�6C�#���d���̼����\�2�S��;�L�P,�iB����j�7B��l|L��.eA�N?y6�Iu�Σ��o�����D�Ӽ,�VQ��B�|��3�3��J�%�g6���ET5b^SB�i���}p�^�v��E!����,�$�0��2��W�t�U�G��3�-x��<��X���]q�#�,p����(��A`�L
ݲ�o��"M�>)&�]�<�o:H/��'@�+ ��Ea�ekL
�7�AHT���+��*X*|����/ڡJe��{��|U��}�PbV�ih_$RWU��k�A�,ǩ�"�i �&U.����1�yi�