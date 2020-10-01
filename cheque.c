#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
        return "zero";
    default:
        return "unidade";
    }
}

char *dezena(int dezena, int unidade)
{
    switch (dezena)
    {
    case 1:
        switch (unidade)
        {
        case 10:
            return "dez";
        case 11:
            return "onze";
        case 12:
            return "doze";
        case 13:
            return "treze";
        case 14:
            return "quatorze ou catorze";
        case 15:
            "quinze";
        case 16:
            return "dezesseis";
        case 17:
            return "dezessete";
        case 18:
            return "dezoito";
        case 19:
            return "dezenove";
        default:
            return "?";
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
        return "dezena";
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
        return "?";
    default:
        return "?centena?";
    }
}

int main()
{
    // 3-mil
    // 2-cento, duzentos, tresentos, quatrocentos...
    // 1 - douze, treze, quatorze, vinte, trinta ...
    // 0 - um, doiz, trez, quatro
    //dois mil, cento e três Bits e treze CentBits,
    float valor = 6969.13;

    char
        numeroEscrito[100];

    int power = 0;
    for (power = 0; pow(10, power + 1) < valor; power++)
        ;

    double valorRestante = floor(valor);

    for (; power >= 0; power--)
    {
        //printf("%.0i => %.0lf\n", power, valor / pow(10, power));
        int valorAtual = floor(valorRestante / pow(10, power));
        valorRestante = valorRestante - valorAtual * pow(10, power);

        switch (power)
        {
        case 0:
            strcat(numeroEscrito, unidade(valorAtual));
            break;
        case 1:
            strcat(numeroEscrito, dezena(valorAtual, valorRestante - valorAtual * pow(10, power - 1)));
            break;
        case 2:
            strcat(numeroEscrito, centena(valorAtual));
            break;
        case 3:
            strcat(numeroEscrito, unidade(valorAtual));
            strcat(numeroEscrito, " mil");
            break;

        case 4:
            strcat(numeroEscrito, dezena(valorAtual, valorRestante - valorAtual * pow(10, power - 1)));
            strcat(numeroEscrito, " mil");
            break;
        case 5:
            strcat(numeroEscrito, centena(valorAtual));
            strcat(numeroEscrito, " mil");
            break;

        default:
            strcat(numeroEscrito, "?");
            break;
        }
        if (valorAtual != 0)
        {
            strcat(numeroEscrito, " ");
        }
    }

    printf("%s\n", numeroEscrito);
    return 0;
}