#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType{
	int info;
	struct nodeType *next;
} node;


void insertAtBeg(node **start ,int item){
	node *ptr;
	
	ptr = (node*) malloc(sizeof(node));
	
	ptr->info = item;
	ptr->next = *start;
	*start = ptr;
}

void insertAtEnd(node **start ,int item){
	node *ptr , *last;
	ptr = (node*) malloc(sizeof(node));
	ptr->info = item;
	ptr->next = NULL;
	
	if(*start == NULL){
		// if ll is empty
		*start = ptr;
	}else{
		last = *start;
		
		// traverssing to the last node
		while(last->next != NULL){
			last = last->next;
		}
		
		// setting the last element next to the new node address
		last->next = ptr;
	}
}

void display(node* start){
	// to display all the element of the ll
	
	if(start == NULL){
		printf("Linked List Is Empty");
		return;
	}
	
	// traversing till end
	while(start != NULL){
		printf("%d -> " , start->info);
		start = start->next;
	} 
	printf("\n\n");
	
}

void deleteAtBeg(node **start){
	node *ptr;
	
	if(*start == NULL){
		printf("\n Linked List is empty");
		return;
	}
	
	ptr = *start;
	
	*start = ptr->next;
	
	printf("\n Deleted Value = %d" , ptr->info);
	
	free(ptr);
	
}

void deleteAtEnd(node **start){
	node *ptr , *last;
	
	if(*start == NULL){
		printf("\n Linked List is empty");
		return;
	}
	
	if((*start)->next == NULL){
		ptr = *start;
		*start = ptr->next;	
	}else{
		
		last = *start;
		
		while(last->next->next != NULL){ // to stop the ptr at 2nd end node of the ll
			last = last->next;
		}
		
		ptr = last->next; // used to store the value of deleted node
		
		last->next = NULL;
		
		printf("\n Deleted Value = ", ptr->info);
		
		free(ptr);
	}	
}

node* searchItem(node *start ,int item){
	while(start != NULL && start->info != item){
		start = start->next;
	}
	
	return start;
}

void displayInRev(node *start){
//	using recursion instead of loop
	if(start->next != NULL){
		displayInRev(start->next);
	}
	
	printf("%d ->" , start->info);
}

void insertAfterLoc(node **start , int item , int after){
	// insert item in ll after given location
	
	node *ptr , *loc;
	
	// using user defined function to search the location of item to insert after
	loc = searchItem(*start,after);
	if(loc == NULL){
		printf("Location not found");

		return;
	}

	ptr = (node*) malloc(sizeof(node));
	ptr->info = item;
	
	// main
	ptr->next = loc->next;
	loc->next = ptr;	
}

void insertBefor(node **start , int item , int before){
	node *ptr , *loc , *temp;
	
	loc = *start;
	temp = NULL;
	
	while(loc != NULL && loc->info != before){
		temp = loc;
		loc = loc->next;
	}
	
	if(loc == NULL){
		printf("\n Location Not Found");
		return;
	}
	ptr = (node*) malloc(sizeof(node));
	ptr->info = item;
	
	if(loc == *start){
		ptr->next = *start;
		*start = ptr;
	}else{
		ptr->next = temp->next;
		temp->next = ptr;
	}
}

void reverseLl(node **start){
	// we will use three pointer 
	
	node *pnode , *cnode , *nnode;
	
	// we are starting from start
	pnode = NULL;
	cnode = *start;
	nnode = cnode->next;
	
	while(nnode != NULL){
		pnode = cnode;
		cnode = nnode;
		nnode = cnode->next;
		cnode->next = pnode;
	}
	
	*start = cnode;
	
}

void main(){
	// creatin empty linked list head
	int item , ch , loc;
	
	node *head;
	head = NULL;
	
	while(1){
	
		printf("\n 1-> Insert At beginning ");
		printf("\n 2-> Insert At End ");
		printf("\n 3-> Insert after location");
		printf("\n 4-> Insert At before location");
		printf("\n 5-> Delete At beginning");
		printf("\n 6-> Delete At End");
		printf("\n 7-> Reverse LL");
		printf("\n 8-> Display LL");
		printf("\n 0-> To Quit");
		printf("\n 1-> Enter Your Choice = ");
		scanf("%d" , &ch);
		
		switch(ch){
			case 0:
				printf("\nThanks For Using");
				exit(0);
				break;
			case 1:
				printf("\n Enter Item To Insert At Beginning = "); 
				scanf("%d" , &item);
				insertAtBeg(&head , item);
				break;
			case 2:
				printf("\n Enter Item To Insert At End = "); 
				scanf("%d" , &item);
				insertAtEnd(&head , item);
				break;
			case 3:
				
				printf("\n Enter Item To Insert  = "); 
				scanf("%d" , &item);
				printf("\n Enter the Location = ");
				scanf("%d", &loc);
				insertAfterLoc(&head , item , loc);
				break;
			case 4:
				
				printf("\n Enter Item To Insert  = "); 
				scanf("%d" , &item);
				printf("\n Enter the Location = ");
				scanf("%d", &loc);
				insertBefor(&head , item , loc);
				break;
			case 5:
				deleteAtBeg(&head);
				break;
			case 6:
				deleteAtEnd(&head);
				break;
			case 7:
				reverseLl(&head);
				break;
			case 8:
				display(head);
				break;
			default:
				printf("Invalid Input");
				break;
				
		}
	}

}

