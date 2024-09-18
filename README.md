# Analisador Léxico

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