#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LSIZ 128
#define RSIZ 10

// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

int isKeyword2(char buffer[]){
	char keywords[32][10] = {"if", "else","do","while","break","continue","switch","case","short",
	                         "int","long","double","float","char","return","void","NULL","struct"
	                         };
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

// DRIVER FUNCTION
int main()
{

    printf("\n\n 170709050 Gizem Pesen:\n");
	printf("------------------------------------------------------\n");
	printf("the filename to be opened : stringtoparse.txt .\n");

//------------------------------------------------------------------
    char ch, str[15],buffer[15], operators[] = "+, -, *, /, >,<,= ", delimeters[] = "(){}[]<>,", integernum[] = "1,2,3,4,5,6,7,8,9,0";
    FILE *fp;

    int i,j=0;

    fp = fopen("stringtoparse.txt","r");

    if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i]){
   				printf("'%c' IS AN OPERATOR\n", ch);
        }
            else if (ch == delimeters[i]){
                printf("'%c' IS AN DELÝMETER\n", ch);
            }
            else if (ch == integernum[i]){
                printf("'%c' IS AN INTEGER NUMBER\n", ch);
            }
   		}
   		   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;

   				if(isKeyword(buffer) == 1)
   					printf("'%s' IS A KEYWORD\n", buffer);
   				else
   					printf("'%s' IS A VALID IDENTIFIER\n", buffer);
   		}

	}

     while((ch = fgetc(fp))!= EOF){
         if(isDelimiter(ch)== true ){
         printf("'%c' IS AN DELIMETER\n", ch);
             }
         }
         fclose(fp);
         return 0;
     }







 //if(isOperator(fgetc(fp)) == true){
 //  				printf("'%c' IS AN OPERATOR\n", ch);
 //           } return 0;


