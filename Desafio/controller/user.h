#ifndef USER_CONTROLLER_H_INCLUDED
#define USER_CONTROLLER_H_INCLUDED

FILE *p;

void insertUser(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    printf("Digite o nome do usuario: ");
    gets(user->name);
    printf("Digite o endereco do usuario: ");
    gets(user->address);
    printf("Digite o ano de nascimento do usuario: ");
    scanf("%d", &user->birthYear);
    printf("Digite o mes de nascimento do usuario: ");
    scanf("%d", &user->birthMonth);
    printf("Digite o dia de nascimento do usuario: ");
    scanf("%d", &user->birthDay);
    getchar();
    printf("Digite a cidade do usuario: ");
    gets(user->city);
    printf("Digite o estado do usuario: ");
    gets(user->state);
    printf("Digite o CEP do usuario: ");
    gets(user->zipCode);
    fwrite(user, sizeof(struct User), 1, p);
    printf("Usuario inserido\n");
    fclose(p);
    printf("\n");
}

void removeUser(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    gets(name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            *user->name = '\0';
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            printf("Usuario deletado\n");
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
    printf("\n");
}


void updateUser(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    char name[64];
    int result;
    int i = 0;
    printf("Digite o nome do usuario: ");
    gets(name);

    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("Alterando usuario... Aperte ENTER para continuar\n");
            getchar();
            printf("Digite o nome do usuario: ");
            gets(user->name);
            printf("Digite o endereco do usuario: ");
            gets(user->address);
            printf("Digite o ano de nascimento do usuario: ");
            scanf("%d", &user->birthYear);
            printf("Digite o mes de nascimento do usuario: ");
            scanf("%d", &user->birthMonth);
            printf("Digite o dia de nascimento do usuario: ");
            scanf("%d", &user->birthDay);
            getchar();
            printf("Digite a cidade do usuario: ");
            gets(user->city);
            printf("Digite o estado do usuario: ");
            gets(user->state);
            printf("Digite o CEP do usuario: ");
            gets(user->zipCode);
            fseek(p, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, p);
            printf("Usuario alterado\n");
            break;
        }
        i++;
    }
    if(result != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
    printf("\n");
}

void getUserByName(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    char name[64];
    int result;
    int found = 0;
    printf("Digite o nome do usuario: ");
    gets(name);
    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&name, user->name);
        if(result == 1){
            printf("%s, %s, %d/%d/%d, %s, %s, %s \n", user->name, user->address, user->birthDay, user->birthMonth, user->birthYear, user->city, user->state, user->zipCode);
            found = 1;
        }
    }
    if(found == 0){
        printf("Usuario nao encontrado\n");
    }
    fclose(p);
    printf("\n");
}

void getUserByInitial(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    char name[8];
    int result;
    int found = 0;
    printf("Digite a inicial do nome do usuario: ");
    gets(name);
    while(fread(user, sizeof(struct User), 1, p)){
        result = name[0] == user->name[0] ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d/%d, %s, %s, %s \n", user->name, user->address, user->birthDay, user->birthMonth, user->birthYear, user->city, user->state, user->zipCode);
            found = 1;
        }
    }
    if(found == 0){
        printf("Usuarios nao encontrados\n");
    }
    fclose(p);
    printf("\n");
}

void getUserByBirthMonth(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    int month;
    int result;
    int found = 0;
    printf("Digite o numero de um mes de 1 a 12: ");
    scanf("%d", &month);
    while(fread(user, sizeof(struct User), 1, p)){
        result = month == user->birthMonth ? 1 : 0;
        if(result == 1){
            printf("%s, %s, %d/%d/%d, %s, %s, %s \n", user->name, user->address, user->birthDay, user->birthMonth, user->birthYear, user->city, user->state, user->zipCode);
            found = 1;
        }
    }
    if(found == 0){
        printf("Usuarios nao encontrados\n");
    }
    fclose(p);
    printf("\n");
}

void getUserByZipCode(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();
    char zipCode[64];
    int result;
    int found = 0;
    printf("Digite o CEP: ");
    gets(zipCode);
    while(fread(user, sizeof(struct User), 1, p)){
        result = areEqual(&zipCode, user->zipCode);
        if(result == 1){
            printf("%s, %s, %d/%d/%d, %s, %s, %s \n", user->name, user->address, user->birthDay, user->birthMonth, user->birthYear, user->city, user->state, user->zipCode);
            found = 1;
        }
    }
    if(found == 0){
        printf("Usuarios nao encontrados\n");
    }
    fclose(p);
    printf("\n");
}

void getUsers(struct User *user){
    printf("\n");
    if((p = fopen("users.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(user, sizeof(struct User), 1, p)){
        if(user->name[0] != '\0'){
            printf("%s, %s, %d/%d/%d, %s, %s, %s \n", user->name, user->address, user->birthDay, user->birthMonth, user->birthYear, user->city, user->state, user->zipCode);
        }
    }
    fclose(p);
    printf("\n");
}

#endif // USER_CONTROLLER_H_INCLUDED
