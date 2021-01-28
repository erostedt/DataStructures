static list_t* xfree_list;

list_t* new_list(void* data){
	list_t* p;

	if(xfree_list == NULL){
		p = xfree_list;
		xfree_list = xfree_list->succ;
	}
	else{
		p = malloc(sizeof(list_t));
	}
	p->pred = p->succ = p;
	p->data = data;
	return p;
}

void free_list(list_t* list){
	list->pred->succ = xfree_list;
	xfree_list = list;
}

void free_memory(void){
	list_t* p;
	list_t* q;

	p = xfree_list;

	while(p != NULL){
		q = p->succ;
		free(p);
		p = q;
	}
}