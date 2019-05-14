#define ex1
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

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
    printf("Digite o nome do contato: ");
    gets(contact->name);
    printf("Digite o telefone do contato: ");
    gets(contact->phone);
    printf("Digite o mes do nascimento do contato: ");
    scanf("%d", &contact->birthMonth);
    printf("Digite o dia do nascimento do contato: ");
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
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    int result;
    if((p = fopen("contacts.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    while(fread(contact, sizeof(struct Contact), 1, p)){
        result = contact->birthMonth == current_time->tm_mon + 1 ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d \n", contact->name, contact->phone, contact->birthDay, contact->birthMonth);
        }
    }

    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
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


#ifdef ex3

struct Product{
    int code;
    char description[255];
    int quantity;
};

FILE *p;
main(){
    struct Product product;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir produto | 2 - Retirar produto | 3 - Procurar produto pela descricao | 4 - Listar todos os produtos | 5 - Listar produtos nao disponiveis | 9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertProduct(&product);
                break;
            case 2:
                removeProduct(&product);
                break;
            case 3:
                getProductByDescription(&product);
                break;
            case 4:
                getProducts(&product);
                break;
            case 5:
                getUnavailableProducts(&product);
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
void insertProduct(struct Product *product){
    if((p = fopen("products.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o codigo do produto: ");
    scanf("%d", &product->code);
    getchar();
    printf("Digite a descricao do produto: ");
    gets(product->description);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &product->quantity);
    fwrite(product, sizeof(struct Product), 1, p);
    fclose(p);
}

void removeProduct(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    int code = 0;
    int quantity = 0;
    int result, result2;
    int i = 0;
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    printf("Digite quanto quer retirar: ");
    scanf("%d", &quantity);

    while(fread(product, sizeof(struct Product), 1, p)){
        result = code == product->code ? 1 : 0;
        if(result == 1){
            result2 = product->quantity >= quantity ? 1 : 0;
            if(result2)
            {
                product->quantity -= quantity;
                fseek(p, sizeof(struct Product) * i, 0);
                fwrite(product, sizeof(struct Product), 1, p);
                break;
            }
            else{
                printf("Você não tem essa quantidade desse produto\n");
            }
        }
        i++;
    }
    if(result != 1 && result2 != 0){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}

void getProductByDescription(struct Product *product){
    if((p = fopen("products.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char description[64];
    int result;
    printf("Digite a descrição do produto: ");
    scanf("%s", &description);
    while(fread(product, sizeof(struct Product), 1, p)){
        result = areEqual(&description, product->description);
        if(result == 1){
            printf("%d, %s, %d \n", product->code, product->description, product->quantity);
            break;
        }
    }
    if(result != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}
void getProducts(struct Product *product){
    if((p = fopen("products.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(product, sizeof(struct Product), 1, p)){
        printf("%d, %s, %d \n", product->code, product->description, product->quantity);
    }
    fclose(p);
}

void getUnavailableProducts(struct Product *product){
    if((p = fopen("products.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(product, sizeof(struct Product), 1, p)){
        if(product->quantity == 0){
            printf("%d, %s, %d \n", product->code, product->description, product->quantity);
        }
    }
    fclose(p);
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

#endif // ex3


#ifdef ex4

struct User{
    char name[64];
    char address[255];
    char city[64];
    char state[64];
    char zipCode[64];
};

FILE *p;
main(){
    struct User user;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir usuario | 2 - Listar usuarios | 3 - Procurar usuario | 4 - Alterar usuario | 5 - Deletar usuario | 9 - Sair\n");        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertUser(&user);
                break;
            case 2:
                getUsers(&user);
                break;
            case 3:
                getUserByName(&user);
                break;
            case 4:
                updateUser(&user);
                break;
            case 5:
                removeUser(&user);
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
void insertUser(struct User *user){
    if((p = fopen("users.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do usuario: ");
    gets(user->name);
    printf("Digite o endereco do usuario: ");
    gets(user->address);
    printf("Digite a cidade do usuario: ");
    gets(user->city);
    printf("Digite o estado do usuario: ");
    gets(user->state);
    printf("Digite o CEP do usuario: ");
    gets(user->zipCode);
    fwrite(user, sizeof(struct User), 1, p);
    fclose(p);
}

void removeUser(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    scanf("%s", &name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            *user->name = '\0';
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}


void updateUser(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    scanf("%s", &name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("Alterando usuario...\n");
            getchar();
            printf("Digite o nome do usuario: ");
            gets(user->name);
            printf("Digite o endereco do usuario: ");
            gets(user->address);
            printf("Digite a cidade do usuario: ");
            gets(user->city);
            printf("Digite o estado do usuario: ");
            gets(user->state);
            printf("Digite o CEP do usuario: ");
            gets(user->zipCode);
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
}

void getUserByName(struct User *user){
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char name[64];
    int result;
    printf("Digite a descrição do produto: ");
    scanf("%s", &name);
    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("%s, %s, %s, %s, %s \n", user->name, user->address, user->city, user->state, user->zipCode);
            break;
        }
    }
    if(result != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(p);
}
void getUsers(struct User *user){
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(user, sizeof(struct User), 1, p)){
        if(user->name[0] != '\0'){
            printf("%s, %s, %s, %s, %s \n", user->name, user->address, user->city, user->state, user->zipCode);
        }
    }
    fclose(p);
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

#endif // ex4

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
