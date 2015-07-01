#include <stdio.h>
#define MAX_VERTICES 100
#define MIN_VERTICES 1
#define MAX_ARESTAS MAX_VERTICES * (MAX_VERTICES - 1) / 2
#define MIN_ARESTAS 0

int main(){

	int m; // relacoes de amizade (arestas)
	int n; // numero de convidados (vertices)
	int instancias = 0; // numero de instancias "k"
	int matriz[MAX_VERTICES][MAX_VERTICES];
	int vetorGrupo[MAX_VERTICES];


	do{
		if(scanf("%d %d", &n, &m) == EOF)
			return 0;

		for (int i = 0; i < n; i++)
		{
			vetorGrupo[i] = 0;
			for (int j = 0; j < n; j++)
			{
				matriz[i][j] = 0;
			}
		}

		instancias++;
		if(n < MIN_VERTICES)
			return 0;
		if(n > MAX_VERTICES)
			return 0;
		if(m > MAX_ARESTAS)
			return 0;
		if(m < MIN_ARESTAS)
			return 0;
		
		for(int i = 0; i < m; i++){	
			int a, b;
			scanf("%d %d", &a, &b);
			matriz[a-1][b-1] = 1;
			matriz[b-1][a-1] = 1;
		}

		bool flag = true;

		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
			{
				if(matriz[i][j] == 1){
					if(vetorGrupo[i] == 0 && vetorGrupo[j] == 0){
						vetorGrupo[i] = 1;
						vetorGrupo[j] = 2;
					}else if(vetorGrupo[i] != 0 && vetorGrupo[j] == 0){
						if(vetorGrupo[i] == 1){
							vetorGrupo[j] = 2;
						}else{
							vetorGrupo[j] = 1;							
						}
					}else if(vetorGrupo[i] == 0 && vetorGrupo[j] != 0){
						if(vetorGrupo[j] == 1){
							vetorGrupo[i] = 2;
						}else{
							vetorGrupo[i] = 1;							
						}
					}else{
						if(vetorGrupo[i] == vetorGrupo[j]){
							flag = false;
						}
					}
				}
			}
		}

		printf("Instancia %d\n", instancias);

		if(flag){
			printf("sim\n\n");
		}else{
			printf("nao\n\n");
		}

	}while(1);

	return 0;
}
