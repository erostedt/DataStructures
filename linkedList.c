#include <stdlib.h>
#include <stdio.h>

typedef struct list_t list_t;
typedef struct link_t link_t;

struct list_t {
	list_t* first;
	list_t* last;
};


struct link_t {
	
	link_t* next;
	void* data;

};

void* xmalloc(size_t size){
	void* p;

	p = malloc(size);
	if(p == NULL){
		fprintf(stderr, "%s\n", "OOM");
		exit(1);
	}
	return p;
}

list_t* new_list(void){
	list_t* head;
	head = xmalloc(sizeof(list_t));
	head->first = head->last = NULL;
	return head;
}

link_t* new_link(void* data){
	link_t* link;
	link = xmalloc(sizeof(link_t));
	link_t->next = NULL;
	link_t->data = data;
	return link;
}

void free_list(list_t* head){
	link_t* p;
	link_t* q;

	p = head->first;
	free(head);
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
}

size_t length(list_t* head){
	link_t* p;
	p = head->first;
	size_t count = 0;
	while(p != NULL){
		count++;
		p = p->next;
	}
	return count;
}

void insert_first(list_t* head, void* data){
	link_t* link;
	link = new_link(data);

	if (head->last == NULL)
		head->last = link;
	else
		link->next = head->first;
	head->first = link;
}

void insert_last(list_t* head, void* data){
	link_t* link;
	link = new_link(data);

	if(head->first == NULL)
		head->first = link;
	else
		head->last->next = link;
	head->last = link;
}

void reverse(list_t* head){
	link_t* p;
	link_t* q;
	link_t* r;

	q = head->first;
	p = NULL;
	while(q != NULL){
		r = q->next;
		q->next = p;
		r = p;
		q = r;
	}
	head->last = head->first;
	head->first = p; 
}













