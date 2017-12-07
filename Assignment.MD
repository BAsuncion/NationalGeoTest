In this second version of National Geographic Bee  assignment,  you will be reading 10 random questions ( no repetition ) from a file.  And would store the 10 questions in a linked list.

 

a node in the linked list: 

struct   _question   {

    char question [ 300 ] ;

     char choice1 [ 200 ] ;

     char choice2 [ 200 ] ;

     char choice3 [ 200 ] ;

     char choice4 [ 200 ] ;

     int correctAnswer ;

    struct   _question   *next;

}  ;

struct _question  *QuestionListPtr ;

 

The linked list with the head node at QuestionListPtr will have 10 nodes , each node storing a question.

 

Then you would prompt each and every question to the student: 

 

Your algorithm would be :

   for ( i = 0 ; i < 10 ; i++ ) {

    Prompt  question i from QuestionListPtr to the student.

    The student would respond with a number.  

    If the number matches the correctAnswer ,  You will print "Good job" , increment the score.  

    if the number did not match the correctAnswer ,  You will print "Sorry incorrect .

 }

 

 When the quiz is done,  you will mail the score  to an mail address.
