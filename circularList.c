#include <stdio.h>
#include <stdlib.h>

typedef struct list_t list_t;

struct list_t {
	void* data;
	list_t* succ;
	list_t* pred;
};

void* xmalloc(size_t size){
	void* p;

	p = malloc(size);
	if(p == NULL){
		fprintf(stderr, "%s\n", "Out of memory");
		exit(1);
	}
	return p;
}

/* create a new l i s t node with th i s data . */
list_t* new_list(void* data){
	list_t* list;
	list = xmalloc(sizeof(list_t));
	list->succ = list->pred = list;
	list->data = data;
	return list;
}

/* deallocate ent ire l i s t but not any data pointer . */
void free_list(list_t* list){
	list_t* p;
	list_t* q;
	if (list == NULL)
		return;
	list->pred->succ = NULL;
	p = list;
	while(p != NULL){
		q = p->succ;
		free(p);
		p = q;
	}
}

size_t length(list_t* list){
	size_t n;
	list_t* p;

	if (list == NULL)
		return 0;
	n = 0;
	p = list;
	do {
		n += 1;
		p = p->succ;
	} 
	while (p != list);
	
	return n;
}

static void insert(list_t** list, void* data){
	list_t* h;
	list_t* p;

	p = new_list(data);

	h = *list;

	if(h != NULL){
		h->pred->succ = p;
		p->pred = h->pred;
		p->succ = h;
		h->pred = p;
	}
	else{
		*list = p;
	}
}

/* insert data f i r s t in the l i s t . */
void insert_first(list_t** list, void* data){
	insert(list, data);

	*list = (*list)->pred;
}

/* insert data f i r s t in the l i s t . */
void insert_last(list_t** list, void* data){
	insert(list, data);
}

/* i f the l i s t i s empty , return NULL, otherwise
* remove (and free ) the f i r s t node in the l i s t
* and return i t s data pointer .
*/
void* remove_first(list_t** list){

	list_t* h;
	void* data;

	h = *list;

	if (h == NULL)
		return NULL;

	data = h->data;

	if (h == h->succ)
		*list = NULL;
	else{
		*list = h->succ;

		h->pred->succ = h->succ;
		h->succ->pred = h->pred;
		free(h)
	}
	return data;
}

void** list_to_array(list_t* list, size_t* size){
	size_t n;
	size_t i;
	void** a;

	n = *size = length(list);

	if (n == 0)
		return NULL;
	a = xmalloc(n*sizeof(void*))
	for (i = 0; i < n; ++i)
	{
		a[i] = list->succ;
		list = list->succ;
	}
	return a;
}













