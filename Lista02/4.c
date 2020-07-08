#include <stdio.h>
#include <stdlib.h>

int race[99] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int lastEntry = 0;
int currentLap = 0;

void whoFirst() {
    int lap = currentLap * 10;
    int firstCar = lap - 10;
    printf("O primeiro colocado é o carro %i", race[firstCar]);
    puts("----------------------------------------------------");
    main();    
}

void whereEveryone() {
    int endingPos = currentLap * 10;
    int startPos = endingPos - 10;

    for (;startPos < endingPos; startPos++) {
        printf("O carro %i está na pos. %i\n", race[startPos], (10 - (endingPos - startPos))+1 );
    }
    puts("----------------------------------------------------");
    main();
}

void whereIsHe() {
    int lap, car, startPos, endingPos, aswer;

    puts("Qual volta deseja saber ?");
    scanf("%i", &lap);
    
    puts("Qual carro deseja saber ?");
    scanf("%i", &car);

    endingPos = lap * 10;
    startPos = endingPos - 10;

    for (;startPos < endingPos; startPos++) {
        if (race[startPos] == car) {
            aswer = 10 - (endingPos - startPos);
        }
    }

    printf("O carro %i está na pos. %i na volta %i\n", car, aswer + 1, lap);
    puts("----------------------------------------------------");    
    main();
}

void insertPos() {
    int i;
    if (lastEntry == 0) {
        i = 0;
    }else {
        i = lastEntry;
    }
    for (; i < 20; i++) {
        printf("Insira o valor %i \n", i);
        scanf("%i", &race[i]);
        switch (i) {
        case 10:
            currentLap = 2;
            break;
        case 20:
            currentLap = 3;        
            break;
        case 30:
            currentLap = 4;
            break;
        case 40:
            currentLap = 5;
            break;
        case 50:
            currentLap = 6;
            break;
        case 60:
            currentLap = 7;
            break;
        case 70:
            currentLap = 8;
            break;
        case 80:
            currentLap = 9;
            break;
        case 90:
            currentLap = 10;
            break;
        }
        if (race[i] == 0){
            lastEntry = i;
            break;
        }
    }
    puts("----------------------------------------------------");
    main();
}

int main() {
    int option;
    
    puts("Escolha a Opção:");
    puts("[0] - Inserir mais posições da corrida(vetor).");
    puts("[1] - Quem está em primeiro ?");
    puts("[2] - Imprimir a posição de todos os carros.");
    puts("[3] - Descobrir a volta do carro");
    puts("[4] - Sair");
    
    scanf("%i", &option);

    switch (option) {
    case 0:
        insertPos();
        break;  
    case 1:
        whoFirst();
        break;
    case 2:
        whereEveryone();
        break;
    case 3:
        whereIsHe();
        break;
    case 4:
        puts("Desenvolvido por Mateus Sponton Marques da Silva - 0030481921039");
        break;
    }

    return 0;
}