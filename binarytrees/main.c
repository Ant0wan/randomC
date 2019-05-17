#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "ft_btree.h"
#include "ft_btree_rb.h"


void	applylevel(void *data, int current_level, int is_first_elem){
	printf("%s, %d, %d\n", (char*)data, current_level, is_first_elem);}
void donothing(void *ptr){printf("%s\n", (char*)ptr);}

/*	    	TEST UNBALANCED BINARY TREE
 *				
 *					c		
 *			     b		d	
 *			  a
*/

int main(void)
{
	t_rb_node	a, b, c, d;

	c.left = &b;
	c.right = &d;
	c.data = "c";
	c.color = RB_BLACK;
	b.left = &a;
	b.right = NULL;
	b.data = "b";
	b.color = RB_RED;
	a.left = NULL;
	a.right = NULL;
	a.data = "a";
	a.color = RB_RED;
	d.left = NULL;
	d.right = NULL;
	d.data = "d";
	d.color = RB_RED;

	char	*s = "a", *s1 = "a", *s2 = "b", *s3 = "c", *s4 = "d", *s5 = "e";
	char	*s6 = "f", *s7 = "g", *s8 = "h";

	t_rb_node	*root;
	root = &c;
	
	rb_insert(&root, (void*)s, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s1, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s2, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s3, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s4, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s5, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s6, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s7, (int (*)(void*, void*))&strcmp);
	rb_insert(&root, (void*)s8, (int (*)(void*, void*))&strcmp);
	
	printf("\n\n");
	btree_apply_by_level((t_btree*)root, applylevel);

	return (0);
}
