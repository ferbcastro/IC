#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define absoluto(a) (a > 0 ? a : -a)

struct info
{
    long a, b;
    int numDiv;
    int r, s, mdc, mmc; // troque por long 
};

long mod (long a, long b)
{
    long quociente = a / b;

    if (a < 0)
    {
        if (b < 0)
            return a - (quociente + 1) * b;
        else 
            return a - (quociente - 1) * b;
    }

    return a - quociente * b;
}

/* V5 deve corrigir erro na funcao divide. Erro corrigido em numeros.cpp */
long divide (long a, long b){ return (a < 0 ? (b < 0 ? (a / b) + 1 : (a / b) - 1) : a / b);}

void mdcE (struct info* i)
{
    long resto, quociente, a, b;
    int rAnt, sAnt, rAtual, sAtual;
    int auxR, auxS;

    i->numDiv = 0;
    a = i->a;
    b = i->b;

    rAnt = 0;
    sAnt = 1;
    rAtual = 1;
    sAtual = -1 * divide (a, b);
    resto = mod (a, b);
    a = b;
    b = resto;
    ++i->numDiv;

    while (b)
    {
        quociente = divide (a, b);
        auxR = rAtual;
        auxS = sAtual;
        rAtual = rAnt - (quociente * rAtual);
        sAtual = sAnt - (quociente * sAtual);
        rAnt = auxR;
        sAnt = auxS;

        resto = mod (a, b);
        a = b;
        b = resto;
        ++i->numDiv;
    }

    i->mdc = a; // deve ser valor absoluto de a
    i->r = rAnt;
    i->s = sAnt;
}

void mmc (struct info *i)
{
    i->mmc = (absoluto (i->a) * absoluto (i->b)) / i->mdc;
    ++i->numDiv;
}

int main ()
{
    struct info i;
    long c, t, cof1X, cof2X, cof1Y, cof2Y;
    char opcao, valida;

    printf (" a = ");
    scanf ("%ld", &i.a);
    while (getchar() != '\n');
    printf (" b = ");
    scanf ("%ld", &i.b);
    while (getchar() != '\n');

    // MDC 
    mdcE (&i);
    printf ("\n +====================MDC====================+\n");
    printf (" mdc(%ld, %ld) = %ld\n", i.a, i.b, i.mdc);
    if (i.numDiv > 1)
        printf (" %d divisoes \n", i.numDiv);
    else
        printf (" %d divisão \n", i.numDiv);
    printf (" +===========================================+\n");

    // MMC
    mmc (&i);
    printf ("\n +====================MMC====================+\n");
    printf (" mmc(%ld, %ld) = %ld\n", i.a, i.b, i.mmc);
    printf (" %d divisoes\n", i.numDiv);
    printf (" +===========================================+\n\n");

    //EQUACAO DIOFANTINA
    valida = 0;
    do
    {
        printf (" Deseja computar equacao diofantina? \n Digite 'S' para continuar e 'N' para sair: ");
        opcao = getchar ();
        getchar ();

        if (opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n')
        {
            printf (" Opcao invalida");
            fflush (stdout);
            sleep (1);
            printf ("\r               ");

            printf ("\033[F\r");
            printf ("                                             ");
            printf ("\033[F\r");
        }
        else valida = 1;
    } while (!valida);
    
    if (opcao == 'N' || opcao == 'n') return 0;

    printf (" c = ");
    scanf ("%ld", &c);
    while (getchar() != '\n');
    if (c % i.mdc != 0)
    {
        printf (" Numero escolhido nao eh divisivel pelo mdc(%ld, %ld)\n", i.a, i.b);
        return 0;
    }
    cof1X = i.r * c / i.mdc;
    cof2X = i.b / i.mdc;
    cof1Y = i.s * c / i.mdc;
    cof2Y = i.a / i.mdc;
    
    printf ("\n +====================ED=====================+\n");
    printf (" r = %d, s = %d\n", i.r, i.s);
    printf (" x = %d + %dt e ", cof1X, cof2X);
    if (cof2Y < 0)
        printf ("y = %d + %dt\n", cof1Y, absoluto (cof2Y));
    else
        printf ("y = %d - %dt\n", cof1Y, cof2Y);
    printf (" +===========================================+\n\n");

    valida = 0;
    do
    {
        printf (" Deseja inserir um valor de t? \n Digite 'S' para continuar e 'N' para sair: ");
        opcao = getchar ();
        getchar ();

        if (opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n')
        {
            printf (" Opcao invalida");
            fflush (stdout);
            sleep (1);
            printf ("\r               ");

            printf ("\033[F\r");
            printf ("                                             ");
            printf ("\033[F\r");
        }
        else valida = 1;
    } while (!valida);

    if (opcao == 'N' || opcao == 'n') return 0;
    
    printf (" t = ");
    scanf ("%ld", &t);
    printf (" x = %ld\n y = %ld\n\n", cof1X + cof2X * t, cof1Y - cof2Y * t);

    return 0;
}
/* 
 *  V4:
 *  ACEITA NUMEROS MAIORES
 *  FAZ CALCULO COM A E B NEGATIVOS
 *  CALCULA X E Y ESPECIFICO
 *  'S' E 'N' DEIXA DE SER CASE SENSITIVE
 */