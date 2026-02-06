*Este projeto foi criado como parte do currículo da 42 por davidos-

# ft_printf

Uma implementação personalizada da função `printf()` da biblioteca padrão C.

## Descrição

**ft_printf** é um projeto do currículo da Escola 42 que recria o comportamento da função padrão `printf()`. 
O objetivo é compreender funções variádicas, saída formatada e conversões de tipos em C.

O projeto está dividido em duas partes:
- **Obrigatória**: Implementa conversões básicas (`cspdiuxX%`)
- **Bonus**: Adiciona suporte para flags (`-0.# +`), largura e precisão

O principal desafio deste projeto foi a **parte bonus**, particularmente gerir a lógica complexa necessária para lidar com múltiplas combinações de flags.
E as suas interações com diferentes especificadores de conversão. 
Compreender como largura, precisão e várias flags afetam a formatação da saída em diferentes tipos de dados exigiu planeamento cuidadoso e testes extensivos.

## Funcionalidades

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

## Algoritmo e Estrutura de Dados

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
- **Abordagem de struct**: Escolhida em vez de parâmetros individuais para evitar argumentos excessivos em funções (conformidade com a norma) 
							e melhorar a manutenibilidade do código
- **Parsing sequencial**: Simplifica a lógica e espelha o comportamento real do printf
- **Funções de impressão separadas**: Cada tipo de conversão tem lógica dedicada para separação clara de responsabilidades
- **Utilitários auxiliares**: `ft_print_padding`, `ft_hex_len`, etc. reduzem a duplicação de código

## Instruções

### Compilação

Clona o repositório e compila a biblioteca:
```bash
git clone git@github.com:p1nh4/ft_printf.git ft_printf
cd ft_printf
make
```

Regras de make disponíveis:
- `make` - Compila a parte obrigatória
- `make bonus` - Compila com funcionalidades bonus
- `make clean` - Remove ficheiros objeto
- `make fclean` - Remove ficheiros objeto e biblioteca
- `make re` - Recompila do zero

### Uso no Teu Projeto

Inclui o header e liga a biblioteca:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Olá, %s!\n", "mundo");
    ft_printf("Número: %d\n", 42);
    ft_printf("Hex: %#x\n", 255);
    return (0);
}
```

Compila o teu programa:
```bash
cc teu_programa.c -L. -lftprintf -I include -o teu_programa
```

## Exemplos de Uso

Consulta o diretório `tests/` para exemplos práticos de uso de todas as conversões e flags.

## Testes

### Executar a Suite de Testes

O projeto inclui ficheiros de teste no diretório `tests/`:
```bash
# Compila e executa testes básicos
make test

# Compila e executa testes de casos especiais
make test_special
```

### Testes Manuais

Também podes criar os teus próprios ficheiros de teste:
```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;
    
    // Compara com o printf original
    ret1 = ft_printf("ft_printf: %d\n", 42);
    ret2 = printf("printf:    %d\n", 42);
    
    printf("Valores de retorno: %d vs %d\n", ret1, ret2);
    return (0);
}
```

### Testers Externos

O projeto foi testado com:
- [printfTester](https://github.com/Tripouille/printfTester) - PASSOU
- [ft_printf_test](https://github.com/cacharle/ft_printf_test) - 877/905 testes passados
- [printf-unit-test](https://github.com/alelievr/printf-unit-test) - Problemas de compatibilidade conhecidos

## Recursos

### Documentação e Referências

Esta na pasta `docs/` para referências deste projeto.

### Declaração de Uso de IA

**Claude AI** foi usado neste projeto para os seguintes propósitos:

1. **Simplificação de Documentação**: Organizar e resumir documentação técnica complexa sobre o comportamento do printf e funções variádicas em explicações digeríveis

2. **Exemplos de Código**: Encontrar exemplos de código relevantes e padrões de implementação para conversões específicas (hexadecimal, formatação de ponteiros, etc.)

3. **Compreensão de Conceitos**: Obter explicações claras sobre:
   - Como `va_list`, `va_start`, `va_arg` e `va_end` funcionam internamente
   - A relação entre diferentes flags e a sua prioridade
   - Casos extremos no comportamento do printf (ex: precision=0 com valor 0)

4. **Testes e Validação**: 
   - Gerar casos de teste para condições extremas
   - Depurar segmentation faults e comportamento inesperado
   - Validar saída contra o printf original

5. **Revisão de Código**: Identificar potenciais problemas com:
   - Memory leaks em conversões de strings
   - Riscos de buffer overflow
   - Problemas de conformidade com a norma

**O que NÃO foi feito por IA:**
- O design do algoritmo principal e implementação
- A codificação efetiva das funções de conversão
- A lógica de parsing das flags bonus
- Resolução de problemas para interações complexas de flags

Todo o código foi escrito manualmente pelo estudante. A IA foi usada como ferramenta de aprendizagem e assistente de debugging, não como gerador de código.

tem como simplificar esta parte? 


### Declaração de Uso de IA

**Claude AI** foi usado neste projeto como ferramenta de aprendizagem e assistente de debugging para:

- **Documentação**: Simplificar e organizar documentação técnica complexa sobre printf e funções variádicas
- **Conceitos**: Auxiliar na explicação interna de `va_list`, `va_start`, `va_arg`, `va_end` e comportamento de flags
- **Exemplos**: Encontrar padrões de implementação para conversões específicas (hexadecimal, ponteiros, etc.)
- **Debugging**: Identificar e corrigir segmentation faults, memory leaks e problemas de conformidade com a norma
- **Testes**: Gerar casos de teste para condições extremas e validar saída contra o printf original

**Todo o código foi escrito manualmente.** A IA foi ferramenta de aprendizagem, não gerador de código. 

## Estrutura do Projeto
```
ft_printf/
├── include/
│   ├── ft_printf.h              # Header principal (obrigatório)
│   ├── ft_printf_bonus.h        # Header bonus
│   └── ft_printf_bonus_utils.h  # Header de utilitários bonus
├── lib/
│   └── libft/                   # Biblioteca C pessoal
├── src/
│   ├── ft_printf.c              # Função principal
│   ├── ft_process_specifier.c   # Router de conversões
│   ├── ft_print_*.c             # Funções de conversão individuais
│   └── *_bonus.c                # Implementações bonus
├── tests/
│   ├── test_printf.c            # Testes básicos
│   └── test_casos_especiais.c   # Testes de casos extremos
├── docs/
│   ├── concepts.md              # Teoria e conceitos
│   ├── examples.md              # Exemplos de código
│   ├── tutoriais.md             # Tutoriais
│   ├── testing.md               # Recursos de teste
│   └── bonus.md                 # Referência bonus
├── Makefile
└── README.md
```

## Conformidade com a Norma

Este projeto segue estritamente a [Norma 42](https://github.com/42School/norminette):
- Máximo de 25 linhas por função
- Máximo de 5 funções por ficheiro
- Sem funções proibidas (apenas malloc, free, write, va_* permitidas)
- Gestão adequada de erros e memória

---
## Bom Código!
```c
#include <unistd.h>

int main(void)
{
    char *autor = "@p1nh4";
    write(1, autor, 6);  
    return (0);
}
```

