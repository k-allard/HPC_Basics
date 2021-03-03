/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstParallel.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:14:51 by kallard           #+#    #+#             */
/*   Updated: 2021/03/03 22:27:29 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <omp.h>

///usr/local/opt/llvm/bin/clang++ -fopenmp -L/usr/local/opt/llvm/lib -I/usr/local/opt/llvm/include firstParallel.cpp
int main(int argc, char **argv) 
{
	int n = 1;
	printf("n in sequential processing at entry is: %d\n", n);
	#pragma omp parallel firstprivate(n) num_threads(4)
	{
		printf("n in parallel processing at entry is: %d\n", n);
		n = omp_get_thread_num();
		printf("n in parallel processing at exit is: %d\n", n);
	}
	printf("n in sequential processing at exit is: %d\n", n);
	return 0;
}

// #include <stdio.h>
// #include <omp.h>

// int main()
// {
//     int n = 0;
//     omp_set_max_active_levels(2);
// #pragma omp parallel num_threads(2) reduction(+:n)
//     {
// 		n = 0;
// #pragma omp parallel num_threads(2) reduction(+:n)
// 		{
// 			n = 1;
// 		}
//     }
//     printf("%d ", n);
//     n = 0;
//     omp_set_max_active_levels(1);
// #pragma omp parallel num_threads(2) reduction(+:n)
//     {
// 		n = 0;
// #pragma omp parallel num_threads(2) reduction(+:n)
// 		{
// 			n = 1;
// 		}
//     }
//     printf("%d ", n);
// }

// #include <stdio.h>
// #include <omp.h>

// int main()
// {
//     int n=1;
//     omp_set_max_active_levels(10);
//     omp_set_num_threads(2);
// #pragma omp parallel if (n>10) 
//     {
// 	printf("Print ");
//     }
// }