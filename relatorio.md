# Cuckoo Hash
Guiusepe Oneda Dal Pai

GRR20210572

## Implementação
Todas as funções usadas para manusear as tabelas hash foram implementadas como 
uma biblioteca, descrita e importada pelos arquivos hashlib.{h,c}.

A biblioteca inclui funções para alocar e inicializar os vetores usados nas 
tabelas hash t1 e t2, bem como para liberá-los no fim da execução. Também há 
funções para inclusão, exclusão e busca de elementos seguindo os algoritmos 
descritos no enunciado do trabalho.

Por fim, há uma função para imprimir a saída desejada, utilizando um outro tipo 
de struct (descrito em hashlib.h) para ordenar a saída corretamente, bem como 
uma rotina para debugar as tabelas, utilizada durante o desenvolvimento.

## Detalhes
### main.c
O arquivo main.c itera sobre as linhas do arquivo de entrada até encontrar EOF. 
Para cada linha, ele executa a inserção ou remoção com as rotinas implementadas 
pela biblioteca, e ao fim do laço imprime a saída de forma ordenada, bem como 
libera as estruturas em memória.

### macros
Para fins de legibilidade do código, foram usado alguns macros descritos em 
hashlib.c para os estados dos nodos {LIVRE,OCUPADO,EXCLUIDO}, bem como para os 
tipos booleanos {TRUE,FALSE}, usados pela função de comparação do qsort.

### Considerações Finais
Mais detalehs da implementação estão comentados no código da biblioteca.
