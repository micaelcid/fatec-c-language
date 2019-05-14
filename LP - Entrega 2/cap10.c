#define ex2
#include "stdio.h"
#include "stdlib.h"

#ifdef ex1
main(){
    FILE *p;
    char c;
    int count = 0;
    int sizeOfFile = 0;
    if((p = fopen("arq.txt", "w")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(1){
        printf("Digite um caractere: ");
        c = getchar();
        if(c == '0'){
            fclose(p);
            break;
        }
        putc(c, p);
        count++;
        getchar();
    }

    if((p = fopen("arq.txt","r"))==NULL)
	{
        printf("erro na abertura do arquivo \n");
        exit(0);
	}

	char result[count];
    fscanf(p,"%s ",result);
    printf("%s", result);
}
#endif // ex1

#ifdef ex2

struct Contact{
    char name[64];
    char phone[15];
    int birthDay;
    int birthMonth;
};

FILE *p;
main(){
    struct Contact contact;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir contato | 2 - Deletar contato | 3 - Procurar contato pelo nome | 4 - Listar todos os contatos | 5 - Listar contatos que comecam com a letra | 6 - Listar aniversariantes do mes | 9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertContact(&contact);
                break;
            case 2:
                deleteContact(&contact);
                break;
            case 3:
                getContactByName(&contact);
                break;
            case 4:
                getContacts(&contact);
                break;
            case 5:
                getContactsByInitial(&contact);
                break;
            case 6:
                getBirthdayPeopleOfTheMonth(&contact);
                break;
            case 9:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9){
            break;
        }
    }
}
void insertContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do usuario: ");
    gets(contact->name);
    printf("Digite o telefone do usuario: ");
    gets(contact->phone);
    printf("Digite o mes do nascimento do usuario: ");
    scanf("%d", &contact->birthMonth);
    printf("Digite o dia do nascimento do usuario: ");
    scanf("%d", &contact->birthDay);
    fwrite(contact, sizeof(struct Contact), 1, p);
    fclose(p);
}

void deleteContact(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            *contact->name = '\0';
            fseek(p, sizeof(struct Contact) * i, 0);
            fwrite(contact, sizeof(struct Contact), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

void getContactByName(struct Contact *contact){
    if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    printf("Digite o nome do contato: ");
    scanf("%s", &name);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = areEqual(&name, contact->name);
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
            break;
        }
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}
void getContacts(struct Contact *contact){
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(contact, sizeof(struct Contact), 1, p)){
        if(*contact->name != '\0'){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }
    fclose(p);
}

void getContactsByInitial(struct Contact *contact){
if((p = fopen("contacts.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char initial;
    int result;
    printf("Digite uma letra: ");
    scanf("%s", &initial);
    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = contact->name[0] == initial ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}
void getBirthdayPeopleOfTheMonth(struct Contact *contact){

}

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}

#endif // ex2

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
