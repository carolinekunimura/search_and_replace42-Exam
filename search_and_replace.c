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
(char *string, char x, char y)

O primeiro parametro é uma srting, o segundo um char que quando identificado na string será substituido pelo terceiro argumento, também um char.
Caso o segundo parametro não seja identificado na string, o programa escreve a string segui de uma linha.
Se os parametros 2 e 3 tiverem mais que um char, o programa devolve uma linha em branco.
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
Ao receber os parametro diretamente o terminal, é feita a leitura e organização dos argumentos da seguinte forma:
w
~argc~ recebe a quantidade parametros que foi escrita no terminal.
No caso da função search_and_replace:

$./search_and_replace "Olá" "l" "b"

Nesse caso foram passados 4 parametros, o nome do programa a ser executado e seus 3 argumentos --> argc == 4

No paramentro argv, um ponteiro para um ponteiro que ir listar os argumentos sendo:

argv[0] --> search_and_replace
argv[1] --> "Olá"
argv[2] --> "l"
argv[3] --> "b"
*/

int	main(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc == 4) /* Nesse programa sao permitidos apenas tres argumentos, portanto, caso sejam passados menos ou mais do que 4 parametros no terminal (função + argumentos), o programa não roda */
	{
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1) /* caso os argumentos 2 e 3 tenham mais do que 1 char, o programa também não executa*/
		{
			while(argv[1][i]) /* argv[1][0] == "O" */
			{
				if (argv[1][i] == argv[2][0]) /* Compara cada char da string com o char do argumento 2 */
					write(1, &argv[3][0], 1); /* Se forem iguais, é feita a troca printando o argumento 3 aos inves do argv[1][i] */
				else 
					write(1, &argv[1][i], 1); /*se não forem iguais, imprime o valor na posição em que a string está */
				i++;
			}
		}
	}
	write(1, "\n", 1); /* Ao final, adiciona um '\n' */
	return (0);
}
