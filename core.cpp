#include "numeros.hpp"
#include "aux.hpp"
#include <unistd.h>

unsigned char menu ()
{
    unsigned char opcao;

    std::cout << "\n +====================MENU====================+\n";
    std::cout << " 1. Resolver equacao diofantina\n";
    std::cout << " 2. Resolver congruencia linear\n";
    std::cout << " 3. MDC & MMC\n";
    std::cout << " +============================================+\n";
    std::cout << " Opcao escolhida: ";
    opcao = getchar() - '0';

    return opcao;
}

int main ()
{
    algebra nt;
    int64_t c, t;
    unsigned char opcao, i; 
    bool valida;

    opcao = menu ();
    if (opcao < 1 || opcao > 3) return 0;
    nt.getNumbers ();

    if (nt.a == 0 && nt.b == 0)
    {
        std::cout << " Entrada invalida" << std::endl;
        return 0;
    }

    nt.mdcE ();
    switch (opcao) 
    {
        case 1:
            std::cout << "vazio\n";
            break;
        case 2:
            std::cout << " c = ";
            get (c);
            nt.coefsEqDiofantina (c);
            std::cout << std::endl << " +====================ED=====================+" << std::endl;
            std::cout << " r = " << nt.r << ", s = " << nt.s << std::endl; 

            std::cout << " x = " << nt.cof1X;
            if (nt.cof2X < 0) std::cout << " - " << abs (nt.cof2X) << "t";
            else std::cout << " + " << nt.cof2X << "t";

            std::cout << std::endl << " y = " << nt.cof1Y;
            if (nt.cof2Y < 0) std::cout << " + " << abs (nt.cof2Y) << "t";
            else std::cout << " - " << nt.cof2Y << "t";
            std::cout << " \n+===========================================+" << std::endl;

            std::cout << std::endl << " Deseja inserir um valor de t?\n";
            std::cout << " Opcao escolhida: ";
            std::cin >> i;
            if (i == 'S' || i == 's')
            {
                std::cout << " t = ";
                get (t);
                std::cout << " x = " << nt.cof1X + nt.cof2X * t << std::endl;
                std::cout << " y = " << nt.cof1Y - nt.cof2Y * t << "\n\n";
            }
            break;
        case 3:
            std::cout << std::endl << " +====================MDC====================+" << std::endl;
            std::cout << " mdc(" << nt.a << ", " << nt.b << ") = " << nt.Mdc << std::endl;
            if (nt.numDiv == 1) std::cout << " " << nt.numDiv << " divisao" << std::endl;
            else std::cout << " " << nt.numDiv << " divisoes " << std::endl;
            std::cout << " +===========================================+" << std::endl;

            nt.mmc ();
            std::cout << std::endl << " +====================MMC====================+" << std::endl;
            std::cout << " mmc(" << nt.a << ", " << nt.b << ") = " << nt.Mmc << std::endl;
            std::cout << " " << nt.numDiv << " divisoes " << std::endl;
            std::cout << " +===========================================+\n\n";

            break;
    }

    return 0;
}