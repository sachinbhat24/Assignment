/*
AUTHOR : SACHIN V B, SACHIN R
DESCRIPTION: PROGRAM FOR SIGN UP BY TAKING USER_NAME AND PASSWORD
*/

#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>


char* date()
{
			time_t t;
			time(&t);
			return (ctime(&t));
}


main(int argc,char **argv)
{
	
	char *filename=NULL;
	char *log_file=NULL;
	int c;


	while((c=getopt(argc,argv,"f:l:"))!=-1)
	switch(c)
	{
	    case 'f': filename=optarg;
			break;
	    case 'l': log_file=optarg;
			break;
	    default:
		printf("Please enter as -f <file_name> -l <log_file> followed by your argument\n");
		   return 1;
	}



	FILE *fp, *fp1;

	fp1=fopen(log_file, "w");

	fp=fopen(filename, "r");

	if(fp==NULL)
	{
		
		printf("File couldnt be opened. \nPlease make sure filename passed exists(login.txt/or any other file being passed. \n");
		return;
	}
	
	
	char user_name[100], password[100]; 
	int flag=0, flag1=0;

	while(flag==0)
	{
		printf("Enter user_name :");
		scanf("%s", user_name);

		while(strlen(user_name)<3 || strlen(user_name)>21)
		{
			printf("User_name should have 3-20 characters\n");
			printf("Enter user_name : ");
			scanf("%s", user_name);
		}

		while(1)
		{
			char str[100];
			char user[100];

			int i=0;

			if(feof(fp))
				break;

			fscanf(fp, "%s", str);

			while(str[i]!=',' && str[i]!=EOF)
			{
				user[i]=str[i];
				i++;
			} 
		
			user[i]='\0';

			i++;
		
			while(str[i]!='\0')
				i++;

			if(strcmp(user_name,user)==0)
			{
				printf("SELECTED USER NAME ALREADY EXISTS.\nPLEASE SELECT OTHER USER_NAME \n\n");
				flag1=1;
				break;
			}

		}
		
		if(flag1==1)
			flag=0;
		else
			flag=1;
		
		flag1=0;
		fseek(fp, 0, SEEK_SET);
	}

	fclose(fp);

	fprintf(fp1, "%s Entered user_name :%s\n",date(), user_name );	

	flag=0;

	fp=fopen(filename, "a");

	if(flag!=1)
	{
		printf("Enter password :");
		scanf("%s",password);

		while(strlen(password)<3 || strlen(password)>16)
		{
			printf("Password should have 3-15 characters\n");
			printf("Enter password :");
			scanf("%s",password);
		}
		
		fprintf(fp1, "%s Entered password :%s\n",date(),password);	
		fprintf(fp, "%s,%s\n", user_name,password);
			
	}
	
	printf("\nSUCESSFULLY SUBMITTED\n");
	fprintf(fp1, "%sOutput displayed : SUCCESSFULLY SUBMITTED\n",date());

	fclose(fp);

	fclose(fp1);


}

