**Antonio Claudio Teixeira Alves**

1. Utilizando os conceitos de grafo, defina uma árvore.
*Árvores são estruturas de dados não-lineares, pois cada elemento pode apontar para 1 ou mais elementos*
2. Escreva uma função que conta o número de nós de uma árvore binária.
`int quantidade_no(Arv *raiz) {
  if(raiz != NULL) {
    return 1 + quantidade_no(raiz->esq) + quantidade_no(raiz->dir);
  } else {
    return 0;
  }
}`
