#include<stdio.h>
#include<conio.h>
#define MAX 10

int Queue[MAX],Front = -1, Rear = -1;

void pushFront(int value) {
	if(Front < 1) {
		printf("\nCannot enter at Front ");
	} else {
		Front--;
		Queue[Front] = value;
		printf("\nValue added Succesfully. ");
	}
	return;
}
void pushRear(int value) {
	if(Rear == MAX-1) {
		printf("\nQueue is full,cannot enter ");
	} else {
		if(Front == -1 && Rear == -1) {
			Front = Rear = 0;
		} else {
			Rear++;
		}
		Queue[Rear] = value;
		printf("\nValue added Succesfully. ");
	}
	return;
}

int RemoveFront() {
	int temp = -999;
	if(Front == -1 || Front > Rear) {
		Front = Rear = -1;
	} else {
			temp = Queue[Front];
			Front++;
		}
	return temp;
}

int RemoveRear() {
	int temp = -999;
	if(Rear == -1 || Front > Rear) {
		Front = Rear = -1;
	} else {
			temp = Queue[Rear];
			Rear--;
		}
	return temp;
}
	
void peek() {
	if(Rear == -1 || Rear < Front) {
		printf("\nQueue is empty ");
	} else {
		printf("Queue Frount is %d " , Queue[Front]);
	}
}

void display() {
	int index;
	printf("\n");
	if(Rear == -1 || Rear < Front) {
		printf("\nQueue is empty ");
	}
	for(index = Front; index <= Rear; index++) {
		printf("%d\t",Queue[index]);
	}
	return;
}

void main() {
	int value,optionOne,optionTwo;
	
	do {
		printf("\n**********MENU**********");
		printf("\n1.Input Restricted Queue");
		printf("\n2.Output Restricted Queue");
		printf("\n3.Exit");
		printf("\nEnter your option ");
		scanf("%d" , &optionOne);
		switch(optionOne) {
			case 1: do {
						printf("\n**********MENU**********");
						printf("\n1.Push");
						printf("\n2.Remove Front");
						printf("\n3.Remove Rear");
						printf("\n4.Peek");	
						printf("\n5.Display");
						printf("\n6.Exit");
						printf("\nEnter your option ");
						scanf("%d" , &optionTwo);
						switch(optionTwo) {
							case 1:
								printf("\nEnter the number to push ");
								scanf("%d" , &value);
								pushRear(value);
							break;
							
							case 2:
								value = RemoveFront();
								if(value == -999) {
									printf("\nQueue is empty");
								} else {
									printf("\n Value deleted is %d " , value);
								}
							break;
							
							case 3:
								value = RemoveRear();
								if(value == -999) {
									printf("\nQueue is empty");
								} else {
									printf("\n Value deleted is %d " , value);
								}
							break;
								
							case 4:
								peek();
							break;
							
							case 5:
								display();
							break;
						}
					} while(optionTwo != 6);
			case 2: do {
						printf("\n**********MENU**********");
						printf("\n1.Push Front");
						printf("\n2.Push Rear");
						printf("\n3.Remove");
						printf("\n4.Peek");
						printf("\n5.Display");		
						printf("\n6.Exit");
						printf("\nEnter your option ");
						scanf("%d" , &optionTwo);
						switch(optionTwo) {
							case 1:
								printf("\nEnter the number to push ");
								scanf("%d" , &value);
								pushFront(value);
							break;
							
							case 2:
								printf("\nEnter the number to push ");
								scanf("%d" , &value);
								pushRear(value);
							break;
							
							case 3:
								value = RemoveFront();
								if(value == -999) {
									printf("\nQueue is empty");
								} else {
									printf("\n Value deleted is %d " , value);
								}
							break;
								
							case 4:
								peek();
							break;
							
							case 5:
								display();
							break;
						}
					} while(optionTwo != 6);
	} 
}while(optionOne != 3);
	return;
}
