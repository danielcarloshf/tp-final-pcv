#Modelagem para o Problema de Cobertura de Vértices Mínima
**Disciplina: DCC035 - Pesquisa Operacional**

**Data: 16/06/2015.**

##Alunos##

* Álvaro Antônio Fonseca de Souza: [alvaro.souza@dcc.ufmg.br](mailto://alvaro.souza@dcc.ufmg.br) 
* Daniel Carlos Hovadick Félix: [dfelix@dcc.ufmg.br](mailto://dfelix@dcc.ufmg.br)
* Guilherme Gonzaga Barbosa: [guilhermegb@dcc.ufmg.br](mailto://guilhermegb@dcc.ufmg.br)  


##Compilação##

Para compilar o código utilize o Makefile:

`$ make`

##Testes##

A geração de testes é feita com o script python *pcmv_input.py*. Num terminal:

`$ python pcvm_input.py`
    
##Heurística##

O executável com a heurística fica disponível no diretório *bin* após a compilação e recebe dois parâmetros:

`$  bin/./tp.exec [arquivo_de_entrada] [arquivo_de_saída]`

##Solver##

Para executar o solver GLPK. Num terminal linux:

`$ glpsol -m pcvm.model -d [arquivo_de_entrada]`