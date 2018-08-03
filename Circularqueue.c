#include<stdio.h>
#include<conio.h>
#define MAX 5

int Queue[MAX],Front = -1, Rear = -1;

void push(int value) {
	if((Front == 0 && Rear == MAX-1) || Rear + 1 == Front) {
		printf("\nQueue is full,cannot add ");
	} else {
		if(Front == -1 && Rear == -1) {
			Front = Rear = 0;
		} else {
				if(Rear == MAX - 1 && Front != 0) {
				Rear = 0;
			} else {
				Rear++;
			}
		}
		Queue[Rear] = value;
		printf("\nValue added Succesfully. ");
	}
	return;
}

int Remove() {
	int temp = -999;
	if(Front == -1 ) {
		Front = Rear = -1;
	} else {
		temp = Queue[Front];
		if(Front == MAX - 1) {
			Front = 0;
		} else {
			if(Front == Rear) {
				Front = Rear = -1;
			} else {
				Front++;
			}
		}
	}
	return temp;
}
	
void peek() {
	if(Rear == -1) {
		printf("\nQueue is empty ");
	} else {
		printf("Queue Frount is %d " , Queue[Front]);
	}
}

void display() {
	int index;
	printf("\n");
	if(Rear == -1 ) {
		printf("\nQueue is empty ");
	} else {
		if(Rear >= Front) {
			for(index = Front; index <= Rear; index++) {
				printf("%d\t",Queue[index]);
			} 
		} else {
			if(Rear < Front) {
				for(index = Front; index < MAX; index++) {
						printf("%d\t",Queue[index]);
				}
				for(index = 0; index <= Rear ; index++) {
					printf("%d\t",Queue[index]);
				}	
			}	
		}
	}
	return;
}
		
void main() {
	int value,option;
	
	do {
		printf("\n**********MENU**********");
		printf("\n1.Push");
		printf("\n2.Remove");
		printf("\n3.Peek");
		printf("\n4.display");
		printf("\n5.exit");
		printf("\nEnter your option ");
		scanf("%d" , &option);
		switch(option) {
			case 1: 
				printf("\nEnter the number to push ");
				scanf("%d" , &value);
				push(value);
			break;
			case 2:
				value = Remove();
				if(value == -999) {
					printf("\nQueue is empty");
				} else {
					printf("\n Value deleted is %d " , value);
				}
			break;
			case 3:
				peek();
			break;
			case 4:
				display();
			break;
		}
	} while(option != 5);
	return;
}
