#include <stdio.h> //Biblioteca padrão de entrada e saída
#include <stdlib.h> //Usar o system(pause)
#include <locale.h> //Acentos do portugues

#define QTDE_DIAS 5 //Tamanho do vetor
#define MIN_TEMPERATURA 16.0 
#define MAX_TEMPERATURA 42.0

//Funções
void apresentacao(); 
void avisoIntervaloTemp();

int main() 
{
	//Informe a codificação que ira receber acentos
	setlocale(LC_ALL, "Portuguese"); 
	
	//Variaveis
    int dia = 0, contMaiorMedia = 0, contMenorMedia = 0;
    float temperaturas[QTDE_DIAS];
    float maiorTemp = MIN_TEMPERATURA;
    float menorTemp = MAX_TEMPERATURA;
    float somaTemp = 0, mediaTemp = 0;
    
    //Imprime o cabeçalho 
    apresentacao();
    avisoIntervaloTemp();
    
    //Laço pra receber as temperaturas
	printf("Separe o decimal por virgula!\n\n");
    for (dia = 0; dia < QTDE_DIAS; dia++) {
    	
        float temp;
        
        do { //Recebendo as temperaturas na variavel temp
            printf("Informe a temperatura para o dia %d: ", dia + 1);
            scanf("%f", &temp);
            fflush(stdin); //Limpar o buffer do teclado
            
            //Condições
            
            //1 cond: Receber somente temperaturas entre MIN (16°) e MAX (42°)
            if (temp < MIN_TEMPERATURA || temp > MAX_TEMPERATURA) {
                printf("Valor inválido.\n\n");
            } else {
                temperaturas[dia] = temp; //Guarda a temperatura no vetor
                somaTemp += temp; //Acumula as temperaturas
                
                /* Se a temperatura for maior que a MIN (16) iremos armazerar o valor
                No caso vai ser os primeiros valores, pra usar como comparação */
                if (temp > maiorTemp) maiorTemp = temp; 
                if (temp < menorTemp) menorTemp = temp;
            }
        } 
		while (temp < MIN_TEMPERATURA || temp > MAX_TEMPERATURA);
		//Fazer isso enquanto temperatura for invalida
    }	

	printf("\n");
    mediaTemp = somaTemp / QTDE_DIAS; //Calculamos a media de tempraturas
    
    //Laço pra verificarmos os dias que tiveram temp maior que a media
    for (dia = 0; dia < QTDE_DIAS; dia++)
    {
    	if (temperaturas[dia] > mediaTemp) contMaiorMedia++; 
    	else contMenorMedia++;
    }
    
    //Limpa a tela e imprime o cabeçalho de novo
    system("pause");
	system("cls");
	apresentacao();
	
	//Imprime todas as temperaturas inseridas
	printf("\nTodas as temperaturas inseridas\n\n");
	for (dia = 0; dia < QTDE_DIAS; dia++)
    {
    	printf("Dia %d - Temperatura: %.1f°C\n", dia + 1, temperaturas[dia]);
    }
    
    //Relatorio das temperaturas
    printf("\nMaior Temperatura: %.1f°C\n", maiorTemp);
    printf("Menor Temperatura: %.1f°C\n", menorTemp);
    printf("Temperatura média: %.1f°C\n\n", mediaTemp);
    printf("%d dias tiveram temperatura maior que a média.\n", contMaiorMedia);
    printf("%d dias tiveram temperatura menor que a média.\n", contMenorMedia);
    
    //Verificando se o clima é frio, quente ou ameno
    if (mediaTemp >= 28) 
		printf("\n%.1f°C é considerado um clima quente.\n", mediaTemp); 
    else if (mediaTemp > 0 && mediaTemp <= 20)
		printf("\n%.1f°C é considerado um clima frio.\n", mediaTemp);  
	else
		printf("\n%.1f°C é considerado um clima moderado.\n", mediaTemp);
    
    //Encerrando o programa
    printf("\n");
	system("pause");
    return 0;
}

void apresentacao() {
	printf("\t%13cTransversal\n", ' ');
    printf("\t - Algoritmo de Relatório Climático -\n\n");
    printf("Matéria: Estruturas de Dados I\n");
    printf("Equipe: Guilherme Lima, João Tavares, José Felipe, Josias Santos, Massimo D’Luca.\n\n");
}

void avisoIntervaloTemp() {
    printf("\nIntervalo de Temperaturas Aceitas: (%.1f°C - %.1f°C)\n", MIN_TEMPERATURA, MAX_TEMPERATURA);
}
