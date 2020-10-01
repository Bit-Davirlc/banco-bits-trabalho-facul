#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int main()
{

    printf("%i", numeroPorExtenso(4560.98));

    return 0;
}