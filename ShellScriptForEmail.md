Step1:

We will utilize a shell script ,  store this in a file,  say mymail.sh 

make sure you give executable privileges to this shell script.

chmod u+x mymail.sh

 

c-prog>cat mymail.sh
#!/bin/bash
echo $1 | mail -s "This is score in your Bee" $2

 

You can test the above script by 

mymail.sh  "hello , how are you?  "  yourmailaddress.com 

 

Step 2:

You need a C program to kick off this shell script.   We will using a execlp function to launch this shell script.

 

The contents of this file is:

#include <stdio.h>
#include <unistd.h>
main ( )
{

char mailAddress [32] = "sankarsrivatsa@gmail.com";
char body[200] = "Your score in the National Geographic bee is 8/10 ";


execlp ( "./mymail.sh", "./mymail.sh", body, mailAddress, NULL );

}

 

Step 3:

 You have the shell script and you have the C program.  Compile the C program.  

and make sure the shell script has exe permissions.

 

Step 4: 

run the program.
