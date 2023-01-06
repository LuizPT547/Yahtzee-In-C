#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define DADOS 5

void autor(){
    printf(" ________________________________\n|    Trabalho realizado por\t |\n|\tTiago Costa 78501\n \tLuis Lemos 78644\t |\n|________________________________|");
    printf("\n\n");
}

void menu();
void regras();
void jogo();

void jogadores(int, char[][MAX]);
void pontuacao(int[DADOS]);
void lances(int[DADOS], char[][MAX]);

int zero_pontos(int);

int main(){
    time_t t;
    srand((unsigned) time(&t));

    autor();
    menu();
}

int zero_pontos(int opcao){
    printf("Voce marcara esta caixa com""\033[31m"" 0 pontos\e[m.\033[97m Tem a certeza?");
    printf("\n\t\t1 - Sim\n\t\t2 - Nao\n\t\t\t-> \e[m");
    scanf("%d", &opcao);
    return opcao;
}

void pontuacao(int l[DADOS]){
    int op[2];
    int ups[6]={0};
    int i, numYahtzee=0, yahtzee=0;
    int pont=0, fh=0, seq=0; //pontos, full house, sequencia
    int op_esc[13]={0}; //opcao escolhida

    printf("\n\n");

    //upper section
    for(i=0; i<6; i++){
        if(l[i]==1){
            ups[0]++;
        }
        if(l[i]==2){
            ups[1]++;
        }
        if(l[i]==3){
            ups[2]++;
        }
        if(l[i]==4){
            ups[3]++;
        }
        if(l[i]==5){
            ups[4]++;
        }
        if(l[i]==6){
            ups[5]++;
        }
    }

    for(i=0; i<6; i++){
        if(ups[i]!=0){
            switch(i){
                case 0: printf("Voce esta legivel para marcar em Ases.\n"); break;
                case 1: printf("Voce esta legivel para marcar em Dois.\n"); break;
                case 2: printf("Voce esta legivel para marcar em Tres.\n"); break;
                case 3: printf("Voce esta legivel para marcar em Quatro.\n"); break;
                case 4: printf("Voce esta legivel para marcar em Cinco.\n"); break;
                case 5: printf("Voce esta legivel para marcar em Sexta.\n"); break;
            }
        }
    }

    //lower section
    for(i=0; i<5; i++){
        if(ups[i]>=3){ //trinca
            printf("Voce esta legivel para marcar em Trinca.\n");
        }
        if(ups[i]>=4){ //quadra
            printf("Voce esta legivel para marcar em Quadra.\n");
        }
        if(ups[i]==3 || ups[i]==2){ //full house
            fh++;
        }
        if(ups[i]==1){ //sequencia
            seq++;
        }
        if(ups[i]==5){ //yahtzee
            printf("Voce esta legivel para marcar em Yahtzee.\n");
            numYahtzee++;
        }
    }
    if(fh==5){ //full house
        printf("Voce esta legivel para marcar em Full House.\n");
    }
    if(seq>=4){ //sequencia baixa
        printf("Voce esta legivel para marcar em Sequencia Baixa.\n");
    }
    if(seq>=5){ //sequencia alta
        printf("Voce esta legivel para marcar em Sequencia Alta.\n");
    }

    if(numYahtzee>1 && numYahtzee<=4){
        printf("Voce marcou mais um Yahtzee, portanto tem um bonus");
    }

sete:
    printf("\n\nEm qual deseja marcar?");
    printf("\n\t1. Ases\n\t2. Dois\n\t3. Tres\n\t4. Quatro\n\t5. Cinco\n\t6. Seis");
    printf("\n\t7. Trinca\n\t8. Quadra\n\t9. Full House\n\t10. Seq. Baixa\n\t11. Seq. Alta\n\t12. Chance\n\t13. Yahtzee\n\t\t-> ");
    scanf("%d", &op[0]);
    switch (op[0]){
        case 1:
            if(op_esc[0]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[0]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[0]++; break; //alterar "pont+=0" para pôr no ficheiro
                    case 2: printf("\nSendo assim escolha novamente.");
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=ups[0];
                op_esc[0]++;
            }
            break;
        case 2:
            if(op_esc[1]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[1]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[1]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=2*ups[1];
                op_esc[1]++;
            }
            break;
        case 3:
            if(op_esc[2]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[2]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[2]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=3*ups[2];
                op_esc[2]++;
            }
            break;
        case 4:
            if(op_esc[3]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[3]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[3]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=4*ups[3];
                op_esc[3]++;
            }
            break;
        case 5:
            if(op_esc[4]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[4]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[4]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=5*ups[4];
                op_esc[4]++;
            }
            break;
        case 6:
            if(op_esc[5]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[5]==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[5]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=6*ups[5];
                op_esc[5]++;
            }
            break;
        case 7: // trinca
            if(op_esc[6]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[i]<3){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[6]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                for(i=0; i<6; i++){
                    if(ups[i]==3){
                        if(i==0){
                            pont+=3*1;
                        }
                        if(i==1){
                            pont+=3*2;
                        }
                        if(i==2){
                            pont+=3*3;
                        }
                        if(i==3){
                            pont+=3*4;
                        }
                        if(i==4){
                            pont+=3*5;
                        }
                        if(i==5){
                            pont+=3*6;
                        }
                    }
                }
                op_esc[6]++;
            }
            break;
        case 8: // quadra
            if(op_esc[7]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(ups[i]<4){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[7]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                for(i=0; i<6; i++){
                    if(ups[i]==4){
                        if(i==0){
                            pont+=4*1;
                        }
                        if(i==1){
                            pont+=4*2;
                        }
                        if(i==2){
                            pont+=4*3;
                        }
                        if(i==3){
                            pont+=4*4;
                        }
                        if(i==4){
                            pont+=4*5;
                        }
                        if(i==5){
                            pont+=4*6;
                        }
                    }
                }
                op_esc[7]++;
            }
            break;
        case 9: //full house
            if(op_esc[8]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(fh<5){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[8]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=25;
                op_esc[8]++;
            }
            break;
        case 10: // Seq. Baixa
            if(op_esc[9]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(seq<4){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[9]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=30;
                op_esc[9]++;
            }
            break;
        case 11: // Seq. Alta
            if(op_esc[10]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            if(seq<5){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[10]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=40;
                op_esc[10]++;
            }
            break;
        case 12: // Chance
            if(op_esc[11]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            for(i=0; i<5; i++){
                pont += l[i];
            }
            op_esc[11]++;
            break;
        case 13: // Yahtzee
            if(op_esc[12]!=0){
                printf("\033[31m""Ja escolheu esta opcao! Selecione novamente.\e[m\n");
                goto sete;
                break;
            }
            for(i=0; i<6; i++){ //Verifica se tem Yahtzee
                if(ups[i]==5){
                    yahtzee++;
                }
            }
            if(yahtzee==0){
                zero_pontos(op[1]);
                switch (op[1]){
                    case 1: pont+=0; op_esc[12]++; break;
                    case 2: printf("\nSendo assim escolha novamente."); goto sete; break;
                    default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                        goto sete; break;
                }
            }
            else{
                pont+=50;
                op_esc[12]++;
            }
            break;
        default:  printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
            goto sete; break;
    }
}

void jogadores(int np, char nome_jogador[][MAX]){
    int i=0;

    printf("\033[97mQual o numero de jogadores(maior ou igual a 2):\e[m ");
    scanf("%d", &np);
    fflush(stdin);
    printf("\n");

    if(np<2){
        printf("Numero de jogadores invalido! Lembre-se que o numero de jogadores tem de ser igual ou superior a 2.\n\n");
        jogadores(np, nome_jogador);
    }
    else{
        for(i=0; i<np; i++){
            printf("Insira o nome do %d jogador(maximo de 100 caracteres): ", i+1);
            fgets(nome_jogador[i], MAX, stdin);
            nome_jogador[i][strcspn(nome_jogador[i], "\n")] = 0;
        }
    }
}

void lances(int l[DADOS],char pnome[][MAX]){
    int np, n_rl[2] = {0}, op[2]; //numero de jogadores, numero de relances, opcao
    int i=0, j=0, p=0; //variaveis de iteracao
    int rl[DADOS]; //relances

/*------------------------lances----------------------------------------------------------------------------------------------*/
    for(i=0; i<np; i++){
        printf("\nComo o jogador \"%s\" foi o %d a inserir o nome sera o %d a jogar.\n", pnome[i], i+1, i+1);
        printf("%s o resultado dos seus primeiros lancamentos da ronda sao:\n\n\t-> ", pnome[i]);
        for(j=0; j<=4; j++){
            l[j] = (rand() % 6) + 1;
            printf("%d; ", l[j]);
        }
quatro:
        printf("\n\n\033[97mDeseja relancar?\n\t1.\e[m Sim\n\t\033[97m2.\e[m Nao\n\t\t-> ");
        scanf("%d", &op[0]);
        fflush(stdin);
        switch(op[0]){
            case 1:
    oito:
                printf("\nQuantos?\n\t-> ");
                scanf("%d", &n_rl[0]);
                if(n_rl[0]<1 || n_rl[0]>5){
                    printf("\033[31m""\tNumero Invalida! Insira de novo!\e[m\n");
                    goto oito;
                }
                if(n_rl[0]!=5){
                    printf("\nQuais dados? (1, 2, 3, 4 e 5).");
                    do{
                        printf("\n\t-> ");
                        scanf("%d", &rl[p]);
                        p++;
                    } while(p<n_rl[0]);
                    for(p=0; p<n_rl[0]; p++){
                        l[rl[p]-1] = (rand() % 6) + 1;
                    }
                }
                else{
                    for(p=0; p<n_rl[0]; p++){
                        l[p] = (rand() % 6) + 1;
                    }
                }
                printf("Os seus novos resultados sao:\n\n\t-> ");
                for(j=0; j<=4; j++){
                    printf("%d; ", l[j]);
                }
        seis:
                printf("\n\nDeseja relancar mais uma vez?\n\t1. Sim\n\t2. Nao\n\t\t-> ");
                scanf("%d", &op[1]);
                switch(op[1]){
                    case 1:
                        if(n_rl[0]==1){
                            for(p=0; p<n_rl[0]; p++){
                                l[rl[p]-1] = (rand() % 6) + 1;
                            }
                            printf("Os seus novos resultados sao:\n\n\t-> ");
                            for(j=0; j<=4; j++){
                                printf("%d; ", l[j]);
                            }
                            pontuacao(l);
                        }
                        else{
               cinco:
                            printf("\nQuantos?\n\t-> ");
                            scanf("%d", &n_rl[1]);
                            if(n_rl[1]<1 || n_rl[1]>5){
                                printf("\033[31m""\tNumero Invalida! Insira de novo!\e[m\n");
                                goto cinco;
                            }
                            if(n_rl[1]>n_rl[0]){
                                printf("O numero de relances tem de ser menor ou igual ao da tentativa anterior. Tente de novo");
                                goto cinco;
                            }
                            if(n_rl[1]!=5){
                                printf("\nQuais dados? (1, 2, 3, 4 e 5).");
                                p=0;
                                do{
                                    printf("\n\t-> ");
                                    scanf("%d", &rl[p]);
                                    p++;
                                } while(p<n_rl[1]);
                                for(p=0; p<n_rl[1]; p++){
                                    l[rl[p]-1] = (rand() % 6) + 1;
                                }
                            }
                            else{
                                for(p=0; p<n_rl[1]; p++){
                                    l[p] = (rand() % 6) + 1;
                                }
                            }
                            printf("Os seus novos resultados sao:\n\n\t-> ");
                            for(j=0; j<=4; j++){
                                printf("%d; ", l[j]);
                            }
                            pontuacao(l);
                        }
                        break;
                    case 2: pontuacao(l); printf("Entao passemos ao proximo jogador."); break;
                    default: printf("Opcao invalida! Selecione novamente."); goto seis; break;
                }
                break;
            case 2: pontuacao(l); printf("\n\nEntao passemos ao proximo jogador."); break;
            default: printf("Opcao invalida! Selecione novamente."); goto quatro; break;
        }
    }
}

void jogo(){
    int np, l[DADOS];
    char pnome[MAX][MAX];

    jogadores(np, pnome);
    lances(l, pnome);
}

void regras(){
    int op;
    printf("\033[34m""1.""\e[m O objetivo e ter uma pontuacao mais alta que os oponentes;\n");
    printf("\033[34m""2.""\e[m Cada Jogador ira fazer ate 3 lancamentos (de 5 dados) por ronda;\n");
    printf("\033[34m""3.""\e[m A cada lancamento (exceto no primeiro, onde se lancam sempre 5) o jogador vai ter a escolha\n");
    printf("   de manter todos ou descartar alguns dos dados;\n");
    printf("\033[34m""4.""\e[m Antes do final de cada turno, cada jogador deve declarar seus resultados de acordo com a combinacao dos dados obtida durante a jogada.");
    printf("\n\t\033[97mDeseja ver o tipo de combinacoes possiveis?\n");
dois:
    printf("\t\t1 - Sim\n\t\t2 - Nao\n\t\t\t-> \e[m");
    scanf("%d", &op);
    switch(op){
        case 1: printf("\n\t""\033[97m""Ases:""\e[m a soma de todos os dados de valor 1 (exemplo: 1-1-3-2-4 vale 2 pontos)\n");
            printf("\t""\033[97m""Dois:""\e[m a soma de todos os dados de valor 2 (exemplo: 2-2-2-5-6 vale 6 pontos)\n");
            printf("\t""\033[97m""Tres:""\e[m a soma de todos os dados de valor 3 (exemplo: 3-1-2-5-5 vale 3 pontos)\n");
            printf("\t""\033[97m""Quatros:""\e[m a soma de todos os dados de valor 4 (exemplo: 4-4-4-4-2 vale 16 pontos)\n");
            printf("\t""\033[97m""Cincos:""\e[m a soma de todos os dados de valor 5 (exemplo: 5-5-3-2-6 vale 10 pontos)\n");
            printf("\t""\033[97m""Seis:""\e[m a soma de todos os dados de valor 6 (exemplo: 6-6-6-1-3 vale 18 pontos)\n");
            printf("\t""\033[97m""Bonus:""\e[m se o total de pontos das categorias acima for superior a 63 soma-se, a esse valor, 35 pontos\n\n");

            printf("\t""\033[97m""Trinca:""\e[m a soma de 3 dados iguais (exemplo: 1-1-1-2-3 vale 3 pontos)\n");
            printf("\t""\033[97m""Quadra:""\e[m a soma de 4 dados iguais (exemplo: 3-3-3-3-4 vale 12 pontos)\n");
            printf("\t""\033[97m""Full House:""\e[m 3 dados iguais e outros 2 dados tambem iguais. (25 pontos)\n");
            printf("\t""\033[97m""Sequencia baixa:""\e[m a combinacao de 4 dados consecutivos (sem interrupcoes), como 1-2-3-4 (30 pontos)\n");
            printf("\t""\033[97m""Sequencia alta:""\e[m a combinacao de 5 dados consecutivos (sem interrupcoes), como 1-2-3-4-5 (40 pontos)\n");
            printf("\t""\033[97m""Chance:""\e[m a soma de 5 dados aleatórios (exemplo: 3-2-4-5-2 vale 16 pontos)\n");
            printf("\t""\033[97m""Yatzee:""\e[m uma combinacao de 5 dados iguais (50 pontos)\n\n");
            printf("\t""\033[97m""Bonus Yatzee:""\e[m por cada yahtzee que fizer ganha 100 pontos extra (num maximo de 4)\n");
            break;

        case 2: break;

        default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                goto dois; break;
    }
    printf("\n\033[34m""5.""\e[m"" Apenas se pode escolher uma combinacao por ronda. voce pode optar por pontuar 0 numa categoria a escolha.\n");

    printf("\nPodemos entao comecar um novo jogo?\n");
tres:
    printf("\t\t\033[97m1 - Sim\n\t\t2 - Nao\n\t\t-> \e[m");
    scanf("%d", &op);
    switch(op){
        case 1: system("cls"); jogo(); break;
        case 2: printf("Entao voltemos ao menu.\n\n");
                system("cls"); menu(); break;
        default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m");
                goto tres; break;
    }
}

void menu(){
    int op, np;
    char pnome[MAX][MAX];

    printf("Qual das seguintes opcoes deseja selecionar:\n");
um:
    printf("\033[34m""\t1.\e[m Apresentar as regras do jogo;\n");
    printf("\033[34m""\t2.\e[m Comecar um novo jogo;\n");
    printf("\033[34m""\t3.\e[m Continuar um jogo guardado;\n");
    printf("\033[34m""\t4.\e[m Sair da aplicacao.\n\t\t-> ");
    scanf("%d", &op);
    switch(op){
        case 1: system("cls"); regras(); break;
        case 2: system("cls"); jogo(); break;
        case 3: system("cls"); break;
        case 4: break;
        default: printf("\033[31m""\tOpcao Invalida! Insira de novo!\e[m\n");
                goto um; break;
    }
}
