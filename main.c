#include <stdio.h>
#include <conio.h>
#include <string.h>

struct info{
   char first_name[25];
   char last_name[25];
   char email[25];

   char username[25];
   char password[25];
   char confirm_password[25];
};

void login();
void registration();


void system();

void options();
int main(){

   system("cls");

   options();

   printf("\n");
   printf("login successful");

   return 0;
}

void login(){

   system("cls");
   char usernameIn[10];
   char passwordIn[10];

   printf(
      "\n\n\n\n"
      "=============================================\n"
      "               L  O  G  I  N\n"
      "=============================================\n"
      "\n\n\n\n"
   );

   char user$pass[59] = "";


   printf("username: ");
   scanf("%s", &usernameIn);

   printf("password: ");
   scanf("%s", &usernameIn);


   strcat(user$pass, usernameIn);
   strcat(user$pass, ", ");
   strcat(user$pass, passwordIn);
   strcat(user$pass, "\n");


   FILE *LOGIN;
   LOGIN = fopen("database.txt", "r");
   char each_line[123];
   while(fgets(each_line, 123, LOGIN) != NULL){
      if(strcmp(each_line, user$pass) == 0){
         system("cls");
      }
   }


}


void registration(){
   FILE *registerr;
   struct info registration;

   printf(
      "\n\n\n\n"
      "============================================="
      "\n"
      "           R E G I S T R A T I O N"
      "\n"
      "============================================="
      "\n\n\n\n\n"
   );


   printf("FIRST NAME\t\t: ");
   scanf("%s", &registration.first_name);

   printf("LAST NAME\t\t: ");
   scanf("%s", &registration.last_name);

   printf("EMAIL\t\t\t: ");
   scanf("%s", &registration.email);

   printf("USERNAME\t\t: ");
   scanf("%s", &registration.username);

   printf("PASSWORD\t\t: ");
   scanf("%s", &registration.password);

   printf("CONFIRM PASSOWORD\t: ");
   scanf("%s", &registration.confirm_password);


   registerr = fopen("database.txt", "a");

   fputs(registration.first_name, registerr);
   fputs(", ", registerr);

   fputs(registration.last_name, registerr);
   fputs(", ", registerr);

   fputs(registration.email, registerr);
   fputs(", ", registerr);

   fputs(registration.username, registerr);
   fputs(", ", registerr);

   fputs(registration.password, registerr);
   fputs(", ", registerr);

   fputs(registration.confirm_password, registerr);
   fputs("\n", registerr);

   fputs(registration.username, registerr);
   fputs(", ", registerr);

   fputs(registration.password, registerr);
   fputs("\n\n", registerr);

   fclose(registerr);

   login();
}


void options()
{
   printf(
      "\n\n\n\n"
      "=============================================\n"
      "           C H O O S E  O P T I O N\n"
      "=============================================\n"
      "\n\n\n\n"
   );

   printf(
      "1. REGISTRATION\n"
      "2. LOGIN\n"
   );

   printf("Enter an option: ");
   int option;
   scanf("%d", &option);
   if(option == 1){
      registration();
   }else if(option == 2){
      login();
   }
}
