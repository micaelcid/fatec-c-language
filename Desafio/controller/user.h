#ifndef USER_CONTROLLER_H_INCLUDED
#define USER_CONTROLLER_H_INCLUDED

FILE *p;

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

#endif // USER_CONTROLLER_H_INCLUDED
