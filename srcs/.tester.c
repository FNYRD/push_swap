


	//imprimi con len 3!!!!!!
	// top_a = -1;
	// while (top_a++ < 2)
	// {
	//     ft_printf("%d", stack_a[top_a]);
	//     ft_printf("\n");
	// }

	//referencias de inicio de top y len!!!!!
	// top_a = 0;//REFERENCIA
	// top_b = len;//REFERENCIA
//    print_test(stack_a, &top_a,  stack_b, &top_b, len - 1, len);

//BORRAR!!!!!
// static void print_helper(int  *stack_a, int *top_a, int tail, int  *stack_b, int *top_b)
// {
//     int topf;
//     int topf2;
//     int i;

//     i = 0;
//     topf = *top_a;
//     topf2 = *top_b;
//     ft_printf("\n");
//     while (i <= tail)
//     {
//         if(topf <= tail)
//             ft_printf("%d", stack_a[topf]);
//         else
//             ft_printf(" "); 
//         ft_printf("   ");  
//         if (topf2 <= tail)
//             ft_printf("%d", stack_b[topf2]);
//         ft_printf("\n"); 
//         topf++;
//         topf2++;
//         i++;
//     }
//     ft_printf("\n\n");
// }

// static void    print_test(int  *stack_a, int *top_a,  int *stack_b, int *top_b, int tail, int len)
// {
//     ft_printf("Antes\n");
//     int i = 0;
//     print_helper(stack_a,top_a, tail, stack_b, top_b);

//     ft_printf("Push 3 numero de a para b\n");
//     while (i++ < 3)
//         pb(stack_a, top_a,  stack_b, top_b);
//     print_helper(stack_a,top_a, tail, stack_b, top_b);

//     ft_printf("Rotate reverse de los dos\n");
//     rrr(stack_a, top_a, stack_b, top_b, tail);
//     print_helper(stack_a,top_a, tail, stack_b, top_b);

//     ft_printf("Rotate normal de los dos\n");
//     rr(stack_a, top_a, stack_b, top_b, tail);
//     print_helper(stack_a,top_a, tail, stack_b, top_b);

//     ft_printf("Swap de los dos\n");
//     ss(stack_a, *top_a, len, stack_b, *top_b);
//     print_helper(stack_a,top_a, tail, stack_b, top_b);

//     ft_printf("Push 3 numero de b para a\n");
//     i = 0;
//     while (i++ < 2)
//         pa(stack_a, top_a,  stack_b, top_b);
//     print_helper(stack_a,top_a, tail, stack_b, top_b);
// }



// static	void	print_helper(int *stack_a, int *top_a, int tail, int *stack_b, int *top_b)
// {
// 	int topf;
// 	int topf2;
// 	int i;

// 	i = 0;
// 	topf = *top_a;
// 	topf2 = *top_b;
// 	ft_printf("\n");
// 	while (i <= tail)
// 	{
// 		if(topf <= tail)
// 			ft_printf("%d", stack_a[topf]);
// 		else
// 			ft_printf(" "); 
// 		ft_printf("   ");  
// 		if (topf2 <= tail)
// 			ft_printf("%d", stack_b[topf2]);
// 		ft_printf("\n"); 
// 		topf++;
// 		topf2++;
// 		i++;
// 	}
// 	ft_printf("\n");
// }

// static void    print_test(int  *stack_a, int *top_a,  int *stack_b, int *top_b, int tail, int len)
// {
// 	(void)len;
// 	ft_printf("%d\n", tail);
// 	ft_printf("Antes\n");
// 	int i = 0;
// 	print_helper(stack_a,top_a, tail, stack_b, top_b);
// 	ft_printf("Push 3 numero de a para b\n");
// 	while (i++ < 3)
// 		pb(stack_a, top_a,  stack_b, top_b);
// 	print_helper(stack_a,top_a, tail, stack_b, top_b);
// 	ft_printf("target: %d\n", stack_b[fnd_target_a(stack_a[*top_a], stack_b, *top_b, tail)]);
// }