package transversalpoo; //Pasta 

import java.util.Scanner; //Biblioteca pra lermos informações

public class Main {

	public static void main(String args[]) {
		
		//Constantes 
		final int qtde_dias = 5;
		final double min_temp = 16, max_temp = 42;
		
		//Variaveis
		int cont_maior_media = 0, cont_menor_media = 0, dia = 0;
		double temp_atual, soma_temp = 0, media_temp = 0;
		double menor_temp, maior_temp;
		
		//Setando as variaveis de comparação de menor e maior temperatura
		menor_temp = max_temp;
		maior_temp = min_temp;
		
		//Instanciando as classes
		Scanner ler = new Scanner(System.in);
		Clima temp = new Clima();
		
		//Declarando um vetor que vai receber as temperaturas
		double vetorTemperaturas[] = new double[qtde_dias];
		
		//Imprimindo o cabeçalho 
		System.out.println("\t Transversal\nMatéria: Programação Orientada à Objetos.");
		System.out.println("Equipe: Guilherme Lima, João Tavares, José Felipe, Josias Santos, Massimo D’Luca.");
		System.out.println("\nIntervalo de Temperaturas Aceitas: (" + min_temp + "°C - " + max_temp + "°C)");
		System.out.println("Separe o decimal por virgula!\n");
		
		/* Laço responsável por receber as temperaturas e armazenar se estiver
		no intervalo, também vai acumular a soma e verificar qual a maior e menor 
		temperatura */
		
		for (dia = 0; dia < qtde_dias; dia++) {
			System.out.println("Informe uma temperatura: ");
			temp.setTemperatura(ler.nextDouble()); //Ler um valor double
			temp_atual = temp.getTemperatura(); //Pegar o valor 
				
			/* Se o valor estiver fora do intervalo vai dar erro e vamos ficar no loop
			infinito até informar um valor válido */
			
				if (temp_atual < min_temp || temp_atual > max_temp) {
					System.out.println("Valor inválido.\n");
					dia--;
				}
				else { //Se o valor estiver dentro do intervalo
					
					//Armarzenamos o valor dentro do vetor
					vetorTemperaturas[dia] = temp.getTemperatura(); 
					soma_temp += vetorTemperaturas[dia]; //acumulando a soma
					
					//Variavel de comparação de menor e maior temperatura
					if (vetorTemperaturas[dia] > maior_temp)
						maior_temp = vetorTemperaturas[dia];
					else if (vetorTemperaturas[dia] < menor_temp)
						menor_temp = vetorTemperaturas[dia];
				}
		}
		
		//Calculando a media 
		media_temp = soma_temp / (float) qtde_dias;

		//Fechando o Scanner
		ler.close();
		
		//Laço pra verificar a qtde de dias com temperatura maior ou menor que a media
		System.out.println("\nImprimindo todas as temperaturas informadas");
		for (dia = 0; dia < qtde_dias; dia++) {
			System.out.println("Temperatura " + (dia + 1) + ": " + vetorTemperaturas[dia] + "°C");
				
			//Se a temperatura for maior ou menor que a media ia incrementar o contador
				if (vetorTemperaturas[dia] > media_temp)
					cont_maior_media++;
				else
					cont_menor_media++;
			}
		
		//Imprimindo o relatorio 
		System.out.println("\nA maior temperatura é de " + maior_temp + "°C");
		System.out.println("A menor temperatura é de " + menor_temp + "°C");
		System.out.println("A média das temperaturas é de " + media_temp + "°C\n");
		System.out.println(cont_maior_media + " dias tiveram a temperatura maior que a media");
		System.out.println(cont_menor_media + " dias tiveram a temperatura menor que a media\n");
		
			if (media_temp >= 28) 
				System.out.println(media_temp + "°C é considerado um clima quente."); 
			else if (media_temp > 0 && media_temp <= 20)
				System.out.println(media_temp + "°C é considerado um clima frio.");
			else
				System.out.println(media_temp + "°C é considerado um clima moderado.");
		}
	
}
