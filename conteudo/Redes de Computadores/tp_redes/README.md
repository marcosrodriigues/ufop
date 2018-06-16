# Simulador da Redes
## Design Pattern
Os imports são feitos de ordem alfabética e os imports da bibliotecas são sempre os últimos
```python
import random
import socket

from random import choice, randint, random

from simulador import CamadaEnlace
from simulador import CamadaFisica
```

Nome para funções e variáveis:
```python
def nome_da_funcao():  
    nome_da_variavel = None
```
Nome para classes(CamelCase): 
```python
class NomeDaClasse(object):
```
Variáveis e Funções por escopo:
Escopo global:
```python
class Exemplo(object):
    def funcao_de_escopo_global(self):
        self.variavel_de_escopo_global = 'Variáveis e funções de escopo global não possuem _, ou __'
```
Escopo protegido:
```python
class Exemplo(object):
    def _funcao_de_escopo_protegido(self):
        self._variavel_de_escopo_protegido = 'Variáveis e funções de escopo protegido possuem apenas um underscore'
```
Escopo privado:
```python
class Exemplo(object):
    def __funcao_de_escopo_privado(self):
        self.__variavel_de_escopo_privado = 'Variáveis e funções de escopo privado possuem dois underscores'
```
### Code cleaner, don't use else, use functions instead
Não use "else", "elif", evite ao máximo usar, use funções para isso.  
Exemplo:
Com else
```python
a = raw_input()
b = raw_input()
if b == 0:
    print("Não é possível dividir por zero")
else:
    print("O resultado da divisão {}/{}={}".format(a,b,a/float(b)))
```
Sem else
```python
a = raw_input()
b = raw_input()

def divisao(a,b):
    if b == 0:
        print("Não é possível dividir por zero")
        return
    print("O resultado da divisão {}/{}={}".format(a,b,a/float(b)))
```
## Como contribuir
Dê um fork no repositório e faça pull requests, espere até quem alguém aprove seu pull request.  