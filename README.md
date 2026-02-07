*Este projeto foi criado como parte do currículo da 42 por davidos-*

## Description

Uma implementação personalizada da função `printf()` da biblioteca padrão C.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/2/2c/Printf.svg" alt="Printf Diagram" width="600" style="background-color: white; padding: 20px; border-radius: 8px;"/>
</p>

**ft_printf** é um projeto do currículo da Escola 42 que recria o comportamento da função padrão `printf()`. 
O objetivo é compreender funções variádicas, saída formatada e conversões de tipos em C.

O projeto está dividido em duas partes:
- **Obrigatória**: Implementa conversões básicas (`cspdiuxX%`)
- **Bonus**: Adiciona suporte para flags (`-0.# +`), largura e precisão

O principal desafio deste projeto foi a **parte bonus**, gerir a lógica complexa necessária para lidar com múltiplas combinações de flags e as suas interações com diferentes especificadores de conversão. Compreender como largura, precisão e várias flags afetam a formatação da saída em diferentes tipos de dados exigiu planeamento cuidadoso e testes extensivos.

## Instructions

### Compilação
```bash
git clone git@github.com:p1nh4/ft_printf.git
cd ft_printf
make          # Compila mandatory
make bonus    # Compila com bonus
```

Outras regras:
- `make clean` - Remove ficheiros objeto
- `make fclean` - Remove objetos e biblioteca
- `make re` - Recompila do zero

### Uso

Usar no seu projeto:
```c
#include "ft_printf.h"
#include "ft_printf_bonus.h"
```

Compilar com ft_printf:
```bash
cc teu_programa.c -L. -lftprintf -I include -o programa
```

Ver `tests/` para exemplos completos de uso.

### Testes
```bash
make test          # Testes básicos
make test_special  # Casos especiais
```

**Testers externos:**
- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf_test](https://github.com/cacharle/ft_printf_test) - 877/905
- [printf-unit-test](https://github.com/alelievr/printf-unit-test)

## Resources

### Documentação

Referências completas estão em `docs/`:
- `concepts.md` - Teoria (va_list, conversões, ponteiros)
- `examples.md` - Exemplos de código
- `tutoriais.md` - Guias passo-a-passo
- `testing.md` - Recursos de teste
- `bonus.md` - Especificação de flags

### Uso de IA

**AI** foi usado como assistente de aprendizagem para:
- Simplificar documentação técnica sobre printf e funções variádicas
- Explicar funcionamento de `va_list`, `va_start`, `va_arg`, `va_end`
- Debugging (segfaults, memory leaks, conformidade com norma)
- Gerar casos de teste e validar output

## Features

### Conversões Obrigatórias
- `%c` - Imprime um único caractere
- `%s` - Imprime uma string
- `%p` - Imprime um endereço de ponteiro em formato hexadecimal (`0x...`)
- `%d` / `%i` - Imprime um inteiro decimal com sinal
- `%u` - Imprime um inteiro decimal sem sinal
- `%x` - Imprime um número em hexadecimal minúsculo
- `%X` - Imprime um número em hexadecimal maiúsculo
- `%%` - Imprime o sinal de percentagem

### Funcionalidades Bonus
- **Flags:**
  - `-` : Alinhamento à esquerda dentro da largura do campo
  - `0` : Preenchimento com zeros em vez de espaços
  - `.` : Especificação de precisão
  - `#` : Forma alternativa (adiciona prefixo `0x` para hex)
  - `+` : Sempre mostra o sinal para números
  - ` ` (espaço) : Adiciona espaço antes de números positivos
- **Largura**: Largura mínima do campo
- **Precisão**: Máximo de dígitos ou comprimento da string

## Algorithm and Data Structure

### Algoritmo Principal

A implementação usa uma **abordagem de parsing caractere por caractere**:

1. **Loop Principal** (`ft_printf`):
   - Itera através da string de formato
   - Imprime caracteres literais diretamente
   - Quando `%` é encontrado, delega ao parser

2. **Parsing de Flags** (`ft_parse_flags_bonus`):
   - Analisa sequencialmente flags, largura e precisão
   - Armazena valores analisados numa estrutura `t_flags`
   - Continua até encontrar um especificador de conversão válido

3. **Processamento de Conversão** (`ft_process_specifier_bonus`):
   - Encaminha para a função de impressão apropriada baseada no especificador
   - Cada função de impressão lida com a sua lógica de formatação específica

### Estrutura de Dados
```c
typedef struct s_flags
{
    int   width;       // Largura mínima do campo
    int   precision;   // Precisão para números/strings
    char  plus;        // Flag '+'
    char  minus;       // Flag '-'
    char  zeros;       // Flag '0'
    char  space;       // Flag ' '
    char  hashtag;     // Flag '#'
}   t_flags;
```

**Justificação:**
- **Abordagem de struct**: Escolhida em vez de parâmetros individuais para evitar argumentos 
    excessivos em funções (conformidade com a norma) e melhorar a manutenibilidade do código
- **Parsing sequencial**: Simplifica a lógica e espelha o comportamento real do printf
- **Funções de impressão separadas**: Cada tipo de conversão tem lógica dedicada para separação clara 
    de responsabilidades
- **Utilitários auxiliares**: `ft_print_padding`, `ft_hex_len`, etc. reduzem a duplicação de código

## Project Structure
```
ft_printf/
├── include/          # Headers (mandatory + bonus)
├── lib/libft/        # Biblioteca pessoal
├── src/              # Implementações (mandatory + *_bonus.c)
├── tests/            # Suite de testes
├── docs/             # Documentação de referência
├── Makefile
└── README.md
```

## Norm Compliance

Segue a [Norma 42](https://github.com/42School/norminette):
- ≤25 linhas/função, ≤5 funções/ficheiro
- Apenas `malloc`, `free`, `write`, `va_*`
- Gestão adequada de erros e memória

---
```c
#include <unistd.h>

int main(void)
{
    char *autor = "@p1nh4";
    write(1, autor, 6);  
    return (0);
}
```
