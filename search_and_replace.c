/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:33:57 by ckunimur          #+#    #+#             */
/*   Updated: 2023/01/19 16:18:11 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SUBJECT 
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit

O exercício pede um programa  search_and_replace.c que recebe 3 parâmetros
the exercise asks for a program, search_and_replace.c, that takes 3 arguments.

(char *string, char x, char y)

O primeiro parametro é uma srting, o segundo um char que quando identificado na string será substituido pelo terceiro argumento, também um char.
The first is a string, the second a char, this will be identify on string and replaced by the third argument, a char too.

Caso o segundo parametro não seja identificado na string, o programa escreve a string segui de uma linha.
If the second argument is not found in the string, the program print the string with a '\n' at the end.

Se os parametros 2 e 3 tiverem mais que um char, o programa devolve uma linha em branco.
If argument two and three have more than one character, the program will print a blank line.

*/

#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
Quando usamos a função ~main~ podemos receber parametros direto do terminal.
The ~main~ function allows to receive arguments directly from the terminal.
*/

/*
Ao receber os parametro diretamente o terminal, é feita a leitura e organização dos argumentos da seguinte forma:
when receiving the parameters directly from the terminal, the organization happens as follows:

~argc~ recebe a quantidade parametros que foi escrita no terminal.
No caso da função search_and_replace:
~argc~ counts the number of parameters received.
In this program:

$./search_and_replace "Olá" "l" "b"

Nesse caso foram passados 4 parametros, o nome do programa a ser executado e seus 3 argumentos --> argc == 4
In this case, the program received parameters, the name of the program to be executed and 3 arguments.

No paramentro argv, um ponteiro para um ponteiro que ir listar os argumentos sendo:
In params argv a pointer to pointer to a list of params, like this:

argv[0] --> search_and_replace
argv[1] --> "Olá"
argv[2] -->	"l"
argv[3] --> "b"
*/

int	main(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc == 4) /* Nesse programa sao permitidos apenas tres argumentos, portanto, caso sejam passados menos ou mais do que 4 parametros no terminal (função + argumentos), o programa não roda 
					In this program only 3 arguments are allowed, so if you receive less or more than 4 parameters, the program will not work */
	{
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1) /* caso os argumentos 2 e 3 tenham mais do que 1 char, o programa também não executa 
																	If the arguments 2 and 3 has more than 1 char, the program will not work */
		{
			while(argv[1][i]) /* argv[1][0] == "O" */
			{
				if (argv[1][i] == argv[2][0]) /* Compara cada char da string com o char do argumento 2 
												Compares one by one char with argv[2] */
					write(1, &argv[3][0], 1); /* Se forem iguais, é feita a troca printando o argumento 3 aos inves do argv[1][i] 
												If they are equal, will change the char printing argv[3]*/
				else 
					write(1, &argv[1][i], 1); /*se não forem iguais, imprime o valor na posição em que a string esta 
												If it's not equal , print argcv[1][i] */
				i++;
			}
		}
	}
	write(1, "\n", 1); /* Ao final, adiciona um '\n'
						In the end, put a '\n'*/
	return (0);
}
