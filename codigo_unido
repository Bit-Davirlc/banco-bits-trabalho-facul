//Trabalho desenvolvido por Walter Dalla e Davi Robson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

void anterior(char *str, int temAnterior)
{
    if (temAnterior == 1)
    {
        strcat(str, "e ");
    }
}

char *unidade(int unidade)
{
    switch (unidade)
    {
    case 1:
        return "um";
    case 2:
        return "dois";
    case 3:
        return "três";
    case 4:
        return "quatro";
    case 5:
        return "cinco";
    case 6:
        return "seis";
    case 7:
        return "sete";
    case 8:
        return "oito";
    case 9:
        return "nove";
    case 0:
        return "";
    }
}

char *dezena(int dezena, int unidade)
{
    switch (dezena)
    {
    case 1:
        switch (unidade)
        {
        case 0:
            return "dez";
        case 1:
            return "onze";
        case 2:
            return "doze";
        case 3:
            return "treze";
        case 4:
            return "quatorze ou catorze";
        case 5:
            "quinze";
        case 6:
            return "dezesseis";
        case 7:
            return "dezessete";
        case 8:
            return "dezoito";
        case 9:
            return "dezenove";
        default:
            return "";
            break;
        }
    case 2:
        return "vinte";
    case 3:
        return "trinta";
    case 4:
        return "quarenta";
    case 5:
        return "cinquenta";
    case 6:
        return "sessenta";
    case 7:
        return "setenta";
    case 8:
        return "oitenta";
    case 9:
        return "noventa";
    case 0:
        return "";
    default:
        return "";
    }
}

char *centena(int centena)
{
    switch (centena)
    {
    case 1:
        return "cento";
    case 2:
        return "duzentos";
    case 3:
        return "trezentos";
    case 4:
        return "quatrocentos";
    case 5:
        return "quinhentos";
    case 6:
        return "seiscentos";
    case 7:
        return "setecentos";
    case 8:
        return "oitocentos";
    case 9:
        return "novecentos";
    case 0:
        return "";
    default:
        return "";
    }
}
int saque(double valor) {
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, inteiro_int;
	double o, p, q, r, s, t, u, v, inteiro, flutuante;
	flutuante = modf(valor, &inteiro);
	inteiro_int = (int)inteiro;
	
	//Separação das notas
	a = inteiro_int / 100; b = inteiro_int % 100;
	c = b / 50; d = b % 50;
	e = d / 20; f = d % 20;
	g = f / 10; h = f % 10;
	i = h / 5; j = h % 5;
	k = j / 2; l = j % 2;
	m = l / 1; n = l % 1;
	
	//Separação das moedas
	o = (flutuante * 100) / 50; p = (int) (flutuante * 100) % (int) 50;
	q = p / 25; r = (int) p % (int) 25;
	s = r / 10; t = (int) r % (int) 10;
	u = t / 1; v = (int) t % 1;
	
	printf ("NOTAS:\n");//Impressão de notas
	printf("%d nota(s) de B$ 100.00\n", a);
	printf("%d nota(s) de B$ 50.00\n", c);
	printf("%d nota(s) de B$ 20.00\n", e);
	printf("%d nota(s) de B$ 10.00\n", g);
	printf("%d nota(s) de B$ 5.00\n", i);
	printf("%d nota(s) de B$ 2.00\n", k);
	
	printf("MOEDAS:\n");// Impressão de moedas
	printf("%d moeda(s) de B$ 1.00\n", (int)m);
	printf("%d moeda(s) de B$ 0.50\n", (int)o);
	printf("%d moeda(s) de B$ 0.25\n", (int)q);
	printf("%d moeda(s) de B$ 0.10\n", (int)s);
	printf("%d moeda(s) de B$ 0.01\n", (int)u);
	
	return 0;
}

int dataPorExtenso() {}

int numeroPorExtenso(double valor)
{

    char
        numeroEscrito[100];

    int power = 0;
    for (power = 0; pow(10, power + 1) < valor; power++)
        ;

    double valorRestante = floor(valor);
    int intpart = (int)valor;
    double cenbits = (valor - intpart) * 100;

    int temAnterior = 0;

    for (; power >= 0; power--)
    {
        //printf("%.0i => %.0lf\n", power, valor / pow(10, power));
        int valorAtual = floor(valorRestante / pow(10, power));
        valorRestante = valorRestante - valorAtual * pow(10, power);
        if (valorAtual == 0)
        {
            temAnterior = 0;
        }
        switch (power)
        {
        case 0:
            anterior(numeroEscrito, temAnterior);
            temAnterior = 1;
            strcat(numeroEscrito, unidade(valorAtual));
            break;
        case 1:
            anterior(numeroEscrito, temAnterior);
            temAnterior = 1;
            strcat(numeroEscrito, dezena(valorAtual, valorRestante - valorAtual * pow(10, power - 1)));
            break;
        case 2:
            temAnterior = 1;
            strcat(numeroEscrito, centena(valorAtual));
            break;
        case 3:
            anterior(numeroEscrito, temAnterior);
            temAnterior = 1;
            strcat(numeroEscrito, unidade(valorAtual));
            strcat(numeroEscrito, " mil");
            break;

        case 4:
            anterior(numeroEscrito, temAnterior);
            temAnterior = 1;
            strcat(numeroEscrito, dezena(valorAtual, valorRestante - valorAtual * pow(10, power - 1)));
            break;
        case 5:
            anterior(numeroEscrito, temAnterior);
            temAnterior = 1;
            strcat(numeroEscrito, centena(valorAtual));
            break;

        default:
            strcat(numeroEscrito, "");
            break;
        }

        if (valorAtual != 0)
        {
            strcat(numeroEscrito, " ");
        }
    }
    strcat(numeroEscrito, "Bits");

    if (cenbits != 0)
    {
        strcat(numeroEscrito, " e ");
        int valorDezena = floor(cenbits / 10);
        int valorUnidade = cenbits - valorDezena * 10;

        strcat(numeroEscrito, dezena(valorDezena, valorUnidade));
        strcat(numeroEscrito, " CentBits");
    }

    printf("%s\n", numeroEscrito);

    return 0;
}

void gotoxy(int x, int y)//Função para interface gráfica 
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	
	setlocale(LC_ALL, "");//Definindo idioma local
	
	system("mode con:cols=100 lines=40");//Definindo tamanho da interface
	
	int coluna = 5, linha = 3;
	
	double valor;
	char opcao, reprocessamento;
	
	do{
	
	gotoxy(40, 3);//Titulo
	printf("Teste de Interface");
	
	gotoxy(30, linha+3);
	printf("1 - Saque");
	
	gotoxy(50, linha+3);
	printf("2 - Preenchimento de cheques");
	
	opcao = getch();//Decidir entre Saque ou Preenchimento
	
	switch(opcao){
		case '1':
			system ("cls");
			gotoxy(coluna, linha+5);
			scanf("%lf", &valor);
			saque(valor);
			break;
		
		case '2':
			system ("cls");
			gotoxy(coluna, linha+5);
			float valor;
		    char numeroEscrito[100];
		    int power = 0;
		    
		    scanf("%f", &valor);		    
			printf("%d\n", numeroPorExtenso(valor));
		}
		
		printf("Deseja refazer? Pressione 1 para SIM\n");
		reprocessamento = getch();
		system ("cls");
	}while(reprocessamento = 1);
			
	return 0;
}
