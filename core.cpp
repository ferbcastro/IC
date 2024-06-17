#include "numeros.hpp"
#include <unistd.h>

int main ()
{
    int64_t c, t; 
    bool valida;
    char opcao, i;

    int64_t a; 
    std::cout << " a = ";
    std::cin >> a;
    while (std::cin.get () != '\n');

    int64_t b; 
    std::cout << " b = ";
    std::cin >> b;
    while (std::cin.get () != '\n');
    algebra nt (a, b);

    if (a == 0 && b == 0)
    {
        std::cout << " Entrada invalida para calculo de mdc" << std::endl;
        return 0;
    }

    nt.mdcE ();
    std::cout << std::endl << " +====================MDC====================+" << std::endl;
    std::cout << " mdc(" << a << " ," << b << ") = " << nt.Mdc << std::endl;
    if (nt.numDiv == 1) std::cout << " " << nt.numDiv << " divisao" << std::endl;
    else std::cout << " " << nt.numDiv << " divisoes " << std::endl;
    std::cout << " +===========================================+" << std::endl;
    
    nt.mmc ();
    std::cout << std::endl << " +====================MMC====================+" << std::endl;
    std::cout << " mmc(" << a << ", " << b << ") = " << nt.Mmc << std::endl;
    std::cout << " " << nt.numDiv << " divisoes " << std::endl;
    std::cout << " +===========================================+" << std::endl;

    i = 46;
    valida = false;
    std::cout << std::endl << " Deseja computar equacao diofantina?" << std::endl;
    do
    {
        std::cout << " Digite 'S' para continuar ou 'N' para sair: ";
        std::cin >> opcao;   
        while (std::cin.get () != '\n');

        if (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n')
        {
            std::cout << " Opcao invalida" << std::flush;
            sleep (1);
            std::cout << "\r               ";

            std::cout << "\033[F\r";
            while (i--) std::cout << " ";
            std::cout << "\r";
        }
        else valida = true;
    } while (!valida);

    if (opcao == 'N' || opcao == 'n') return 0;

    std::cout << " c = ";
    std::cin >> c;
    while (std::cin.get () != '\n');
    nt.coefsEqDiofantina (c);
    std::cout << std::endl << " +====================ED=====================+" << std::endl;
    std::cout << " r = " << nt.r << ", s = " << nt.s << std::endl; 

    std::cout << " x = " << nt.cof1X;
    if (nt.cof2X < 0) std::cout << " - " << abs (nt.cof2X) << "t";
    else std::cout << " + " << nt.cof2X << "t";

    std::cout << std::endl << " y = " << nt.cof1Y;
    if (nt.cof2Y < 0) std::cout << " + " << abs (nt.cof2Y) << "t";
    else std::cout << " - " << nt.cof2Y << "t" << std::endl;
    std::cout << " +===========================================+" << std::endl;

    i = 46;
    valida = false;
    std::cout << std::endl << " Deseja inserir um valor de t?" << std::endl;
    do
    {
        std::cout << " Digite 'S' para continuar ou 'N' para sair: ";
        std::cin >> opcao;   
        while (std::cin.get () != '\n');

        if (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n')
        {
            std::cout << " Opcao invalida" << std::flush;
            sleep (1);
            std::cout << "\r               ";

            std::cout << "\033[F\r";
            while (i--) std::cout << " ";
            std::cout << "\r";
        }
        else valida = true;
    } while (!valida);
    
    if (opcao == 'N' || opcao == 'n') return 0;

    std::cout << " t = ";
    std::cin >> t;
    while (std::cin.get () != '\n');
    std::cout << " x = " << nt.cof1X + nt.cof2X * t << std::endl;
    std::cout << " y = " << nt.cof1Y - nt.cof2Y * t << "\n\n";

    return 0;
}