MAKEFILE, COMPILAÇÃO E TESTES

=== MAKEFILE ===
    
Makefile - Criação:
    https://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories
    https://unix.stackexchange.com/questions/767435/help-with-makefile-for-c-program
    https://cboard.cprogramming.com/c-programming/150667-makefile-problem%3B-create-obj-file-outside-src-folder.html
    https://stackoverflow.com/questions/16344719/how-to-create-directory-if-needed

Makefile basico:
    https://make.mad-scientist.net/papers/rules-of-makefiles/
    https://www.youtube.com/watch?v=ygoRdBBOdYU
    https://www.lucavall.in/blog/crafting-clean-maintainable-understandable-makefile-for-c-project

Makefile - Relinks:
    https://unix.stackexchange.com/questions/26409/how-to-avoid-make-redoing-a-library
    https://stackoverflow.com/questions/42718392/how-to-avoid-my-makefile-to-relink
    https://stackoverflow.com/questions/52502399/what-does-it-mean-for-a-makefile-to-relink

=== COMPILAÇÃO ===
cc  -- Compilador
    invoca o compilador C (geralmente GCC ou Clang) para iniciar o processo de compilação e ligação (linking).
 
 -Wall -- Flag de Aviso
    ativa todos os avisos recomendados pelo compilador.

 -Wextra -- Flag de Aviso
    Ativa avisos adicionais que não estão incluídos em -Wall.

 -Werror -- Flag de Aviso
    "Transforma todos os avisos (warnings) em erros de compilação, forçando você a corrigi-los."

 src/ft_printf.c -- Arquivo Fonte
    O arquivo de código fonte que você deseja compilar.

 -Iinclude -- Flag de Pré-Processamento
    Diz ao compilador para procurar arquivos de cabeçalho (.h) na pasta include/. 
  
  -Llib -- Flag de Ligação (Linker) 
    Diz ao linker para procurar bibliotecas estáticas ou dinâmicas na pasta lib/.
 
  -lft -- Flag de Ligação (Linker) 
    Diz ao linker para vincular o programa à biblioteca chamada libft.a (o lib inicial e o .a final são adicionados au
 
--- testes
#   Compila
    cc -Wall -Wextra -Werror tests/test_printf.c -L. -lftprintf -I include -o test_printf
  
#   Executa
   ./test_printf
  ou
#   Compilar e executar via Makefile
    make test -- e removido no fim ./test_printf
 
--- valgrind
#   executar compilação
    cc -Wall -Wextra -Werror tests/test_printf.c -L. -lftprintf -I include -o test_printf
 
#   valgrind
    valgrind --leak-check=full --show-leak-kinds=all ./test_printf

=== TESTES ===

printfTester: https://github.com/Tripouille/printfTester OK
ft_printf_test: https://github.com/cacharle/ft_printf_test# 877/28
printf-unit-test: https://github.com/alelievr/printf-unit-test# KO

