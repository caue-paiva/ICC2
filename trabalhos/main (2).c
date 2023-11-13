/*
José Carlos Andrade do Nascimento - 12549450
Filipe Bueno Balsani - 4621914
Yvin Miguel Juanico Carvalho - 13677239
Tiago Carvalho de Freitas - 11800754
Thales Sena de Queiroz - 14608873
Caue Paiva Lira - 14675416
*/

/*
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DESCR 51

typedef struct tempo {
	int hh;
	int mm;
	int ss;
	int total_segundos;
	char tempo_em_string[9];
} horario;

// estrutura de um proceso
typedef struct _processo {
	char nome[MAX_DESCR];
	horario tempo;
	int prioridade;
} celula;

void inserir_prioridade(celula * lista_prioridade, int prioridade, char tempo[9], char descricao[MAX_DESCR], int index);
void inserir_tempo(celula * lista_tempo,  int prioridade, char tempo[9], char descricao[MAX_DESCR], int index);
celula remover_tempo (celula * ordenacao_tempo, int prioridade, int index);
celula remover_prioridade(celula * ordenacao_prioridade, int tempo, int index);

int main(void) {
	celula ordenacao_tempo[101]; // ordennado em funçao do tempo
	celula ordenacao_prioridade[101];// ordenando em funcçao da prioridade
	int index=-1; // isso aponta para o indice do ultimo elemento (praticamente o tamanho da fila atualmente).
	int O_PRIMEIROBARRAN=0; // UTILIZADO PARA FAZER COM QUE A SAIDA SAIA NO FORMATO ESPERADO.
	for (;;) {
		char command[7];
		scanf(" %s", command);

		if( !strcmp(command,"add")) {
			
			int prioridade;
			char tempo[9], descricao[MAX_DESCR];
			
			scanf("%d %s %s", &prioridade, tempo, descricao);
			inserir_tempo(ordenacao_tempo, prioridade, tempo, descricao, index);
			

			inserir_prioridade(ordenacao_prioridade, prioridade, tempo, descricao, index);
			index++;
					
		}
		else if (!strcmp(command, "exec")) {
			char op[3];
			scanf(" %s", op);
			
			if (!strcmp(op, "-p")) {
				remover_tempo(ordenacao_tempo, ordenacao_prioridade[index].prioridade, index);
				index--;

			}
			else if (!strcmp(op, "-t")) {
				remover_prioridade(ordenacao_prioridade, ordenacao_tempo[index].tempo.total_segundos, index);
				index--;
				
			}
		}
		else if (!strcmp(command, "next")) {
			char op[3];
			scanf(" %s", op);
			
			if (!strcmp(op, "-p")) {
				if(!O_PRIMEIROBARRAN)
					O_PRIMEIROBARRAN=1;
				else
				 	printf("\n");

				printf("%.2d %.2d:%.2d:%.2d %s\n", ordenacao_prioridade[index].prioridade,
				ordenacao_prioridade[index].tempo.hh,
				ordenacao_prioridade[index].tempo.mm,
				ordenacao_prioridade[index].tempo.ss,
				ordenacao_prioridade[index].nome);
			}
			else if (!strcmp(op, "-t")) {
				if(!O_PRIMEIROBARRAN)
					O_PRIMEIROBARRAN=1;
				else
				 	printf("\n");
				printf("%.2d %.2d:%.2d:%.2d %s\n", ordenacao_tempo[index].prioridade,
				ordenacao_tempo[index].tempo.hh,
				ordenacao_tempo[index].tempo.mm,
				ordenacao_tempo[index].tempo.ss,
				ordenacao_tempo[index].nome);
			}
		}
		else if (!strcmp(command, "change")) {
			char op[3];
			scanf(" %s", op);
			
			if (!strcmp(op, "-p")) {
				char change[6];
				scanf(" %s", change);

				char from[3], to[3];
				int j=0;

				//-------pegando quem vai virar quem
				for(;;j++){
					if(change[j]=='|'){
						from[j]='\0';
						j++;
						break;
					}
					from[j]=change[j];
				}
				int i=0;
				for(;j<strlen(change);j++, i++){
					to[i]=change[j];
				}
				//-------pegando quem vai virar quem

				int From=0;
				int To=0;
	
				//-------TRANSFORMANDO EM INTEIRO
				if(strlen(from)==1){
					From=from[0]-'0';
				}else{
					From=(from[0]-'0')*10+from[1]-'0';
				}

				if(i==1){
					To=to[0]-'0';
				}else{
					To=(to[0]-'0')*10+to[1]-'0';
				}
				//-------TRANSFORMANDO EM INTEIRO
				//printf("%d %d\n", From, To);
				//-------REMOVENDO A ANTIGA E ADCIONANDO ORDENADAMENTE
				celula removida=remover_tempo(ordenacao_tempo, From, index);
				remover_prioridade(ordenacao_prioridade, removida.tempo.total_segundos, index);
				index--;
				removida.prioridade=To;
				
				inserir_prioridade(ordenacao_prioridade, removida.prioridade, removida.tempo.tempo_em_string, removida.nome, index);
				inserir_tempo(ordenacao_tempo, removida.prioridade, removida.tempo.tempo_em_string, removida.nome, index);
				index++;
				//-------REMOVENDO A ANTIGA E ADCIONANDO ORDENADAMENTE
			}
			else if (!strcmp(op, "-t")) {
				char change[18];
				scanf(" %s", change);
				
				char from[9], to[9];
				int j=0;

				//-------pegando quem vai virar quem
				int ot=0;
				for(;j<strlen(change);j++){
					if(change[j]=='|'){
						ot=1;
						j++;
					}
					if(!ot) from[j]=change[j];
					else to[j-9]=change[j];
				}
				
				//-------pegando quem vai virar quem

				int From=0;
				int To=0;

				//-------TRANSFORMANDO EM INTEIRO
				int h = (from[0]-'0')*10 + (from[1]-'0');
				int m = (from[3]-'0')*10 + (from[4]-'0');
				int s = (from[6]-'0')*10 + (from[7]-'0');
				From=3600*h+60*m+s;
				h = (to[0]-'0')*10 + (to[1]-'0');
				m = (to[3]-'0')*10 + (to[4]-'0');
				s = (to[6]-'0')*10 + (to[7]-'0');
				To=3600*h+60*m+s;
				//-------TRANSFORMANDO EM INTEIRO
				
				
				//-------REMOVENDO A ANTIGA E ADCIONANDO ORDENADAMENTE
				celula removida=remover_prioridade(ordenacao_prioridade, From, index);
				remover_tempo(ordenacao_tempo, removida.prioridade, index);
				index--;
				inserir_prioridade(ordenacao_prioridade, removida.prioridade, to, removida.nome, index);
				inserir_tempo(ordenacao_tempo, removida.prioridade, to, removida.nome, index);
				index++;
				//-------REMOVENDO A ANTIGA E ADCIONANDO ORDENADAMENTE
			}
		}
		else if (!strcmp(command, "print")) {
			char op[3];
			scanf(" %s", op);
			
			if (!strcmp(op, "-p")) {
				if(!O_PRIMEIROBARRAN)
					O_PRIMEIROBARRAN=1;
				else
				 	printf("\n");
				for(int i=index;i>=0;i--){
					printf("%.2d %.2d:%.2d:%.2d %s\n", ordenacao_prioridade[i].prioridade,
					ordenacao_prioridade[i].tempo.hh,
					ordenacao_prioridade[i].tempo.mm,
					ordenacao_prioridade[i].tempo.ss,
					ordenacao_prioridade[i].nome);
				}
			}
			else if (!strcmp(op, "-t")) {
				if(!O_PRIMEIROBARRAN)
					O_PRIMEIROBARRAN=1;
				else
				 	printf("\n");
				for(int i=index;i>=0;i--){
					printf("%.2d %.2d:%.2d:%.2d %s\n", ordenacao_tempo[i].prioridade,
					ordenacao_tempo[i].tempo.hh,
					ordenacao_tempo[i].tempo.mm,
					ordenacao_tempo[i].tempo.ss,
					ordenacao_tempo[i].nome);
				}
			}
		}
		else if (!strcmp(command, "quit")) {
			break;
		}
		
	}
}


void inserir_prioridade(celula * lista_prioridade, int prioridade, char tempo[9], char descricao[MAX_DESCR], int index) {
	// busca para saber index do novo elemento
	int inicio = 0;
	int fim = index;
	//----BUSCA BINARIA
	while(inicio < fim) {
		int mid = (fim + inicio)/2;
		if (lista_prioridade[mid].prioridade > prioridade ) {
			 fim = mid-1;
		}
		else if(lista_prioridade[mid].prioridade < prioridade) {
			inicio = mid+1;
		}
		
	}
	//----BUSCA BINARIA

	if (fim < 0 ) fim = 0;
	else if (lista_prioridade[fim].prioridade < prioridade ) {
		fim++;
	}

	// reajuste da lista + insercao no index fim
	
	for (int i = index; i >= fim; i--) {
		lista_prioridade[i+1] = lista_prioridade[i];
	}

	lista_prioridade[fim].prioridade = prioridade;
	
	int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	horario new_tempo = {h, m, s, 3600*h + 60*m + s};

	lista_prioridade[fim].tempo = new_tempo; 
	strcpy(lista_prioridade[fim].nome, descricao);
	strcpy(lista_prioridade[fim].tempo.tempo_em_string, tempo);

}

void inserir_tempo(celula * lista_tempo,  int prioridade, char tempo[9], char descricao[MAX_DESCR], int index) {
	// busca para saber index do novo elemento
	int inicio = 0;
	int fim = index;
	
	int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	int tempo_total = 3600*h+60*m+s;
	//----BUSCA BINARIA
	while(inicio < fim) {
		int mid = (fim + inicio)/2;
		if (lista_tempo[mid].tempo.total_segundos < tempo_total ) {
			 fim = mid-1;
		}
		else if(lista_tempo[mid].tempo.total_segundos > tempo_total) {
			inicio = mid+1;
		}
		
	}
	//----BUSCA BINARIA

	if (fim < 0 ) fim = 0;
	else if (lista_tempo[fim].tempo.total_segundos > tempo_total) {
		fim++;
	}

	// reajuste da lista + insercao no index fim
	
	for (int i = index; i >= fim; i--) {
		lista_tempo[i+1] = lista_tempo[i];
	}

	lista_tempo[fim].prioridade = prioridade;
	
	//int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	//int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	//int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	horario new_tempo = {h, m, s, 3600*h + 60*m + s};

	lista_tempo[fim].tempo = new_tempo; 
	strcpy(lista_tempo[fim].nome, descricao);
	strcpy(lista_tempo[fim].tempo.tempo_em_string, tempo);

}

celula remover_tempo (celula * ordenacao_tempo, int prioridade, int index) {
	int i = 0;
	for(; i < index; i ++) {
		if(ordenacao_tempo[i].prioridade == prioridade) break;
	}
	celula retorno=ordenacao_tempo[i];
	for ( int j = i; j < index; j++) {
		ordenacao_tempo[j] = ordenacao_tempo[j+1];
	}

	return retorno;
}

celula remover_prioridade(celula * ordenacao_prioridade, int tempo, int index) {

	int i = 0;
	for(; i < index; i ++) {
		if(ordenacao_prioridade[i].tempo.total_segundos == tempo) break;
	}
	celula retorno=ordenacao_prioridade[i];
	for ( int j = i; j < index; j++) {
		ordenacao_prioridade[j] = ordenacao_prioridade[j+1];
	}
	return retorno;
}
