# Analisador Léxico

---

## Gramática

A gramática utilizada neste projeto é definida como:

- Conjunto de variáveis: {C, E, P, N, A, B}
- Conjunto de terminais: {i, e, w, x, (, ), >, =, -, 3, 4, 5, 6, 7, 8}
- Símbolo inicial: P
  - Regras de produção:
    - C → i ( E ) N e N
    - C → w ( P > 3 ) N x = x - 3
    - E → N > 1
    - P → x = A | x = B
    - N → A + B | B - A | A - B
    - A → 3 | 4 | 5
    - B → 6 | 7 | 8

### Autômato Finito

![gramatica.svg](gramatica.svg)

Esse diagrama mostra as transições de estado que ocorrem conforme os caracteres da cadeia são processados.

### Exemplos de Cadeias Válidas

Abaixo estão dois exemplos de cadeias válidas que podem ser reconhecidas por esta gramática:

1. `i(7-4>1)4+6e6-3`
2. `w(x=6>3)3+6x=x-3`

### Instruções de Uso

1. Compile o código:
   ```bash
   gcc gramatica.c -o gramatica
   ```

2. Execute o programa passando a cadeia a ser validada como argumento:
   ```bash
   ./gramatica "i(7-4>1)4+6e6-3"
   ```

3. O programa exibirá uma das seguintes mensagens:
    - `Cadeia reconhecida`: se a cadeia for válida de acordo com a gramática.
    - `Cadeia não reconhecida`: se a cadeia não for válida.

### Estrutura do Código

O código implementa um autômato finito que simula a análise das cadeias com base nos estados e transições definidos na gramática. Cada estado é representado em um bloco `case` dentro de um `switch`, onde as transições ocorrem conforme o caractere atual da cadeia.

### Exemplo de Execução

Entrada:
```bash
./gramatica "i(7-4>1)4+6e6-3"
```

Saída:
```
Cadeia reconhecida
```

### Arquivos

- `gramatica.c`: código-fonte do programa.
- `gramatica.svg`: diagrama do autômato que representa a gramática.

---

## Múltiplos de 6

O segundo analisador léxico verifica se um número, representado em binário, é múltiplo de 6. Ele utiliza um autômato finito para identificar a validade da cadeia de bits de entrada.

### Autômato Finito

![multiplos.svg](multiplos.svg)

Esse diagrama ilustra os estados e transições que ocorrem durante a verificação de uma cadeia de bits. O autômato é projetado para reconhecer múltiplos de 6 com base em sua representação binária.

### Instruções de Uso

1. Compile o código:
   ```bash
   gcc multiplos.c -o multiplos
   ```

2. Execute o programa passando uma cadeia binária que represente um número a ser verificado:
   ```bash
   ./multiplos "1100"
   ```

3. O programa exibirá uma das seguintes mensagens:
    - `Cadeia reconhecida`: se a cadeia binária representar um múltiplo de 6.
    - `Cadeia não reconhecida`: se a cadeia binária não for múltiplo de 6.

### Exemplos de Cadeias Válidas

- O número `12` em binário é `1100`, que é múltiplo de 6.
- O número `42` em binário é `101010`, que também é múltiplo de 6.

### Estrutura do Código

O código funciona como um autômato finito onde os estados são definidos para verificar a validade de uma cadeia de bits. As transições ocorrem com base nos valores dos bits (`0` ou `1`) e seguem a lógica de identificação de múltiplos de 6.

### Exemplo de Execução

Entrada:
```bash
./multiplos "1100"
```

Saída:
```
Cadeia reconhecida
```

Entrada:
```bash
./multiplos "101010"
```

Saída:
```
Cadeia reconhecida
```

### Arquivos

- `multiplos.c`: código-fonte do programa que verifica múltiplos de 6.
- `multiplos.svg`: diagrama do autômato que representa as transições para identificar múltiplos de 6.

---

## Vogal-Consoante-Vogal

Este analisador léxico verifica se uma cadeia de três letras segue o padrão **VCV** (vogal, consoante, vogal), utilizando um autômato finito para processar a cadeia.

### Regras:

- A cadeia de entrada deve ter 3 caracteres.
- O primeiro e o terceiro caracteres devem ser vogais (a, e, i, o, u, maiúsculas ou minúsculas).
- O segundo caractere deve ser uma consoante (qualquer letra que não seja vogal, maiúscula ou minúscula).

### Autômato Finito

![vcv.svg](vcv.svg)

Esse diagrama mostra as transições de estado que ocorrem conforme os caracteres da cadeia são processados.

### Instruções de Uso

1. Compile o código:
   ```bash
   gcc vcv.c -o vcv
   ```

2. Execute o programa passando uma cadeia de três letras como argumento:
   ```bash
   ./vcv "aba"
   ```

3. O programa exibirá uma das seguintes mensagens:
    - `Cadeia reconhecida`: se a cadeia seguir o formato VCV.
    - `Cadeia não reconhecida`: se a cadeia não seguir o formato VCV.

### Estrutura do Código

O código define um autômato finito com 4 estados, conforme descrito abaixo:

- **Estado 1**: Estado inicial, espera uma vogal.
- **Estado 2**: Espera uma consoante.
- **Estado 3**: Espera uma vogal.
- **Estado 4**: Estado final (cadeia válida).

Cada estado é verificado dentro de um loop que percorre os caracteres da cadeia de entrada.

### Exemplo de Execução

Entrada:
```bash
./vcv "aba"
```

Saída:
```
Cadeia reconhecida
```

Entrada:
```bash
./vcv "abc"
```

Saída:
```
Cadeia não reconhecida
```

### Arquivos

- `vcv.c`: código-fonte do programa que verifica cadeias no formato VCV.

---

## Analisador Léxico com FLEX para as Linguagens A, B e C

Este projeto implementa um analisador léxico para três linguagens distintas (A, B e C) usando a ferramenta **FLEX**. O arquivo `AnaLex.flex` contém todas as regras lexicais necessárias para identificar cadeias válidas nas linguagens especificadas.

### Linguagens

1. **Linguagem A**: Reconhece expressões aritméticas complexas envolvendo números de 3 a 8, operadores `+` e `-`, e condições como `>` e `=`.

2. **Linguagem B**: Trata cadeias de números binários, que podem conter `0` e `1`, e termina sempre com `1`.

3. **Linguagem C**: Processa cadeias com o padrão vogal-consoante-vogal, onde a vogal pode ser qualquer uma das letras `a, e, i, o, u` (maiúsculas ou minúsculas) e a consoante é qualquer outra letra do alfabeto.

### Estrutura

- **Flex Rules (Regras do FLEX)**: Cada regra da linguagem é definida no arquivo `.flex`, usando expressões regulares para identificar padrões válidos.
- **Funções Auxiliares**:
    - `reconhecida()`: Imprime "Cadeia reconhecida" quando uma cadeia é aceita.
    - `nao_reconhecida()`: Imprime "Cadeia não reconhecida" quando uma cadeia é rejeitada.

### Como Utilizar

1. **Instale o Flex**:
   ```bash
   sudo apt-get install flex
   ```

2. **Compile o analisador**:
   ```bash
   flex AnaLex.flex
   gcc lex.yy.c -o AnaLex -lfl
   ```

3. **Execute o analisador** com a cadeia de entrada desejada:
   ```bash
   ./AnaLex "sua_cadeia_de_teste"
   ```

    - **Exemplo 1**: Para uma cadeia válida na Linguagem A:
      ```bash
      ./AnaLex "i(3+6>1)"
      # Saída: Cadeia reconhecida
      ```

    - **Exemplo 2**: Para uma cadeia válida na Linguagem B:
      ```bash
      ./AnaLex "1010"
      # Saída: Cadeia reconhecida
      ```

    - **Exemplo 3**: Para uma cadeia válida na Linguagem C:
      ```bash
      ./AnaLex "aCa"
      # Saída: Cadeia reconhecida
      ```

### Arquivo `AnaLex.flex`

O arquivo `AnaLex.flex` contém todas as definições de expressões regulares e a lógica de análise para as linguagens A, B e C.