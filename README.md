#Modelagem para o Problema de Cobertura de Vértices Mínima
**Disciplina: DCC035 - Pesquisa Operacional **
**
Alunos: Álvaro Antônio Fonseca de Souza, 
        Daniel Carlos Hovadick Félix,
        Guilherme Gonzaga Barbosa.
**   
**Data: 16/06/2015. **

##COMPILAÇÃO

Para compilar o código utilize o Makefile:
    `$ make`

##TESTES

A geração de testes é feita com o script python 'pcmv_input.py'. Num terminal:
    `$ python pcvm_input.py`
    
HEURISTICA
O executável com a heurística fica disponível no diretório "bin" após a compilação e recebe dois parâmetros:
    `$  bin/tp.exec [arquivo_de_entrada] [arquivo_de_saída]`

##SOLVER

Para executar o solver GLPK. Num terminal linux:
    `$ glpsol -m pcvm.model -d [arquivo_de_entrada]`