//Brandon Asuncion
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

typedef struct _question {
	char question[300];
	char choice1 [200];
	char choice2 [200];
	char choice3 [200];
	char choice4 [200];
	int correctAnswer;
	int usersAnswer;
	char score[12];
	struct _question *next;
} Nat_Q ;
Nat_Q *head, *curr;
Nat_Q *CreateNode(Nat_Q);
Nat_Q getARandomQuestion();
 
void PromptTheQuestions(Nat_Q*ptr);
void AddNode(Nat_Q*,Nat_Q);
void Review (Nat_Q*);
void email();


void main ( ) 
{
	srand(time(NULL));

	int i = 0;
	Nat_Q*currPtr = NULL , *backUpPtr = NULL  ;
	currPtr = backUpPtr = NULL ;
	
	Nat_Q test  = getARandomQuestion ();
	backUpPtr = currPtr = CreateNode(test);   

	while (i<9){
		Nat_Q test = getARandomQuestion();
		AddNode (currPtr,test);
		i++;
	}
	currPtr = backUpPtr; 
	PromptTheQuestions(currPtr);
	currPtr = backUpPtr;
	Review (currPtr);
} 
Nat_Q getARandomQuestion()
{
	Nat_Q test;
	FILE *fp;

	fp = fopen("questionbank.txt","r");

	if (fp == NULL){
		perror("Error opening the file");
		exit(1);
	}

	char line[300];
	int qNumber,i = 0;

	qNumber = rand()%50+1;

	int skipLines = (qNumber-1)*6;

	while (i<skipLines){
		fgets (line,300,fp);
		i++;
	}
	fgets (line,300,fp);
	strcpy(test.question,line);
	fgets (line,300,fp);
	strcpy(test.choice1, line);
	fgets (line,300,fp);
	strcpy(test.choice2,line);
	fgets (line,300,fp);
	strcpy(test.choice3,line);
	fgets (line,300,fp);
	strcpy(test.choice4,line);
	fgets (line,300,fp);
	sscanf (line,"%d",&test.correctAnswer);

	fclose (fp);
	return test;
}
void PromptTheQuestions (Nat_Q*ptr )
{
	int point=1;
	while (ptr!= NULL){
		printf("%s",ptr->question);
		printf("%s", ptr->choice1);
		printf("%s", ptr->choice2);
		printf("%s", ptr->choice3);
		printf("%s", ptr->choice4);

		scanf("%d",&(ptr->usersAnswer));
		ptr = ptr->next; 
	}
}
void Review (Nat_Q*ptr)
{
	int  point=0;
	char mailAddress[32];
	char body[200];
	char subject [64]= "Test results from the National Bee";
	while (ptr!=NULL){
		printf("%s",ptr->question);
		printf("%s",ptr->choice1);
		printf("%s",ptr->choice2);
		printf("%s",ptr->choice3);
		printf("%s",ptr->choice4);
		printf("The correct answer is %d\n",ptr->correctAnswer);
		printf("You Answered as %d \n",ptr->usersAnswer);
		if (ptr->usersAnswer == ptr->correctAnswer){
			printf("Good Job!\n");		
			point++;
		}
		else{
			printf("Your answer is incorrect :(\n");
		}
		ptr = ptr->next;
	}
	printf("Your score is %d out of 10\n",point);
	printf("Please Enter an email address:\n");
	scanf("%s", &mailAddress);
	snprintf(body,100," Your score in the National Geographic Bee is %d/10.",point);
	execlp ("./mymail.sh", "./mymail.sh", subject, body, mailAddress, NULL);
}
Nat_Q* CreateNode (Nat_Q input)
{
	Nat_Q*ptr = (Nat_Q*)malloc(sizeof(Nat_Q));

	if(ptr != NULL){
		*ptr = input;
		ptr->next = NULL;
		return ptr;
	}
	return NULL;
}
void AddNode (Nat_Q *hptr, Nat_Q test)
{
	Nat_Q *temp = CreateNode (test);
	while (hptr->next != NULL)
		hptr = hptr->next;
	hptr->next = temp;
}
