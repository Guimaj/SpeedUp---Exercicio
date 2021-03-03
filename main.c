#include<stdio.h>
#include<time.h>
#include<math.h>


int testaPrimo(int n) {
    int EhPrimo = 1,
        d=2;
    if (n <= 1)
    EhPrimo = 0;

    while (EhPrimo == 1 && d <= n /2) {
    if (n % d  == 0)
        EhPrimo = 0;
    d = d + 1;
    }
    return EhPrimo;
}

int isPrimo(int num) {
    int i = 0;
    
    if(num <= 1)
    	return 0;
    	
	for(i=2;i<num;i++){
		if(num % i == 0)
			return 0;
	}
	
	return 1;
}

int isPrimoAlternativo(int num) {
    int i = 0;
    int ehPrimo = 1;

    for(i = 2; pow(i,2) <= num; i++) {
        if (num % i == 0) {
            ehPrimo = 0;
            break;
        }
    }
	
	return ehPrimo;
}

int main(){
	
  int numeros[8] = {7,37,8431,13033,524287,664283,3531271,2147483647};
  float tempos[8][30];
  int ehPrimo = 0;
  int i,j,k = 0;

  for(i=0; i < 8; i++){
  	
  	  double tempo_total_numero = 0;
  	  double somatorio = 0;
  	  double media = 0;
  	  double desvioPadrao = 0;
  	 	
	  for(j=0; j < 30; j++){
	
		  clock_t tempo_inicial = clock();
		
		  ehPrimo = isPrimoAlternativo(numeros[i]);
		
		  clock_t tempo_final = clock();
		
		  double tempo_total = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
		  double tempo_em_milisegundos = tempo_total * 1000;
		  
		  if(ehPrimo == 0){
		  	printf("Numero %d nao eh primo e demorou %f \n", numeros[i],tempo_em_milisegundos);
		  }else{
		  	printf("Numero %d eh primo e demorou %f \n", numeros[i],tempo_em_milisegundos);
		  }
		  tempos[i][j] = tempo_em_milisegundos;
		  tempo_total_numero = tempo_total_numero + tempo_em_milisegundos;
		  
	}
	
	media = tempo_total_numero/30;
	
	for(k=0; k<30;k++){
		somatorio = somatorio + pow(tempos[i][k] -media,2);	
	}
	
	desvioPadrao = sqrt(somatorio/29);

	printf("Media dos tempos do numero %d eh %f\n", numeros[i],media);
	printf("Desvio padrao do numero %d eh %f\n", numeros[i],desvioPadrao);
  }

  return 0;
}




