#include "numeros.hpp"

int64_t divide (int64_t a, int64_t b)
{
    if (a % b == 0) return (a / b);
    return (a < 0 ? (b < 0 ? (a / b) + 1 : (a / b) - 1) : a / b);
}

int64_t mod (int64_t a, int64_t b) {return a - divide (a, b) * b;}

algebra::algebra (int64_t val1, int64_t val2) : a(val1), b(val2), numDiv(0){}

void algebra::mdcE ()
{
    int64_t rAnt, sAnt, rAtual, sAtual;
    int64_t aTemp, bTemp, rAux, sAux, resto, quociente;

    aTemp = min (a, b);
    bTemp = max (a, b);

    rAnt = 0;
    sAnt = 1;
    rAtual = 1;
    sAtual = -1 * divide (aTemp, bTemp);
    ++numDiv;

    resto = mod (aTemp, bTemp);
    aTemp = bTemp;
    bTemp = resto;

    while (bTemp)
    {
        quociente = divide (aTemp, bTemp);
        ++numDiv;

        rAux = rAtual;
        sAux = sAtual;
        rAtual = rAnt - quociente * rAtual;
        sAtual = sAnt - quociente * sAtual;

        resto = mod (aTemp, bTemp);
        aTemp = bTemp;
        bTemp = resto;
    }

    Mdc = abs (aTemp);
    r = rAnt;
    s = sAnt;
}

void algebra::mmc () {Mmc = (abs(a) * abs(b)) / Mdc; ++numDiv;}

bool algebra::verificaEqDiofantina (int64_t c) {return !(c % Mdc);}

void algebra::coefsEqDiofantina (int64_t c)
{
    if (!algebra::verificaEqDiofantina (c)) 
    {
        std::cout << " Numero escolhido nao eh divisivel pelo mdc (" << a << ", " << b << ")";
        return; 
    }

    cof1X = r * c / Mdc;
    cof2X = b / Mdc;
    cof1Y = s * c / Mdc;
    cof2Y = a / Mdc;
}

algebra::~algebra (){};