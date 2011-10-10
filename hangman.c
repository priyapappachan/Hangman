#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
	{
	int flag,count=0,i;
	char word[11],guessword[10],guesschar,words[11][11];
	int n=5;
	int number=rand() % n;
	
	FILE *fp;
	fp=fopen("data","w");
	printf("enter any 5 words");
	for(i=1;i<=5;i++)
		{
		fscanf(stdin,"%s",words[i]);
		fprintf(fp,"%s",words[i]);
		}
	fclose(fp);
	fp=fopen("data","r");
	for(i=1;i<=number;i++)
		{
		fscanf(fp,"%s",words[i]);
		}
	strcpy(word,words[i]);
	fclose(fp);
	
	printf("\n%s\n",word);
	for(i=0;word[i]!='\0';i++)
		{
		guessword[i]='_';
		printf("_ ");
		}
	guessword[i]='\0';
	while(count!=7)
		{
		flag=1;	
		printf("\nEnter char to be guessed");	
		scanf(" %c", &guesschar);
		for(i=0;word[i]!='\0';i++)
			{
			if(guesschar==word[i])
				{
				guessword[i]=guesschar;
				printf("guess is correct\n\n");
				flag=0;
				}
			}
	if(flag==1)
		count++;
	switch(count)
		{
		case 0:printf("\ncontinue guessing ");break;	
		case 1:printf("\nH");break;
		case 2:printf("\nHA");break;
		case 3:printf("\nHAN");break;
		case 4:printf("\nHANG");break;
		case 5:printf("\nHANGM");break;
		case 6:printf("\nHANGMA");break;
		case 7:printf("\nHANGMAN \n \n GAME OVER");break;
		default: printf("continue guessing ");
		}
	if(count!=7)
		printf("\n%s",guessword);
	if(strcmp(guessword,word)==0)
		printf("\nCongrats");
	}
	return 0;
	} 	
