#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    //CLEARS THE PAST SCREEN.
    system("clear");

    //PRINTING THE LOGO FOR CIPHER.
    printf("\n  ########  ########   ########   ##     ##   #######   ########\n");
    printf(" ##            ##     ##      ##  ##     ##  ##        ##      ##\n");
    printf(" ##            ##     ##      ##  ##     ##  ##        ##      ##\n");
    printf(" ##            ##     #########   #########  ########  #########\n");
    printf(" ##            ##     ##          ##     ##  ##        ##   ##\n");
    printf(" ##            ##     ##          ##     ##  ##        ##    ##\n");
    printf("  ########  ########  ##          ##     ##   #######  ##     ##\n\n");

    //TAKING THE INPUT AS PER MENU.
    int n,c;
    printf("WELCOME TO CIPHER, AN AI-SAFE CRYPTOSYSTEM FOR SHARING YOUR CONFIDENTIAL TEXT-BASED DATA SECURELY.\n1. ENTER '1' TO ENCRYPT A MESSAGE.\n2. ENTER '2' TO DECRYPT A MESSAGE.\n3. ENTER '3' TO EXIT THE PROGRAM.\n\nINPUT:");
    scanf("%d",&n);

    //SCANF ADDS NEW LINE AND FGETS READS IT AS AN EMPTY STRING SO THE BELOW LINE HELPS WITH THAT.
    while((c = getchar()) != '\n') { }
    
    //ALGORITHM TO ENCRYPT THE DATA.
    if(n==1){

        //TAKING SENTENCE IN INPUT AS STRING.
        char word[5000]={0};
        printf("ENTER THE MESSAGE YOU WANT TO ENCRYPT:\n\n");
        fgets(word,sizeof(word),stdin);

        //LENGTH IS THE NUMBER OF CHARACTERS AFTER WHICH THE STRING TERMINATES.
        int length=strlen(word)-1;

        //FLIPPING THE CHARACTERS OF WORD.
        for(int i=0;i<(length-1);i++){
            for(int j=0;j<(length-i-1);j++){
                char temp=word[j];
                word[j]=word[j+1];
                word[j+1]=temp;
            }
        }

        //MANIPULATING THE BITS.
        for(int i=0;i<length;i++){
            switch (i%6){
                case 1:
                    word[i]=word[i]^5;
                    break;
                case 2:
                    word[i]=word[i]^3;
                    break;
                case 3:
                    word[i]=word[i]^4;
                    break;
                case 4:
                    word[i]=word[i]^6;
                    break;
                case 5:
                    word[i]=word[i]^1;
                    break;
                case 0:
                    word[i]=word[i]^7;
            }
        }

        //FLIPPING THE FIRST HALF OF THE SENTENCE.
        for(int i=0;i<(length/2-1);i++){
            for(int j=0;j<(length/2-1)-i;j++){
                char temp=word[j];
                word[j]=word[j+1];
                word[j+1]=temp;
            }
        }
        printf("\n");
        printf("HERE IS THE ENCRYPTED MESSAGE:\n\n");
        printf("%s\n\n",word);
    }

    //ALGORITHM TO DECRYPT THE DATA.
    else if(n==2){
        
        //TAKING SENTENCE IN INPUT AS STRING.
        char word[5000]={0};
        printf("ENTER THE ENCRYPTED MESSAGE:\n\n");
        fgets(word,sizeof(word),stdin);

        //LENGTH IS THE NUMBER OF CHARACTERS AFTER WHICH THE STRING TERMINATES.
        int length=strlen(word)-1;

        //FLIPPING THE FIRST HALF OF THE SENTENCE.
        for(int i=0;i<(length/2-1);i++){
            for(int j=0;j<(length/2-1)-i;j++){
                char temp=word[j];
                word[j]=word[j+1];
                word[j+1]=temp;
            }
        }

        //MANIPULATING THE BITS.
        for(int i=0;i<length;i++){
            switch (i%6){
                case 1:
                    word[i]=word[i]^5;
                    break;
                case 2:
                    word[i]=word[i]^3;
                    break;
                case 3:
                    word[i]=word[i]^4;
                    break;
                case 4:
                    word[i]=word[i]^6;
                    break;
                case 5:
                    word[i]=word[i]^1;
                    break;
                case 0:
                    word[i]=word[i]^7;
            }
        }

        //FLIPPING THE SENTENCE.
        for(int i=0;i<(length-1);i++){
            for(int j=0;j<(length-i-1);j++){
                char temp=word[j];
                word[j]=word[j+1];
                word[j+1]=temp;
            }
        }
        printf("\n");
        printf("HERE IS THE DECRYPTED MESSAGE:\n\n");
        printf("%s\n\n",word);
    }
    printf("THANKS FOR USING THE PROGRAM.\n");
}