#include "numeros.hpp"
#include "aux.hpp"
#include <unistd.h>
#include <vector>
#include <tuple>

using namespace std;

unsigned char menu ()
{
    unsigned char opcao;

    cout << "\n +====================MENU====================+\n";
    cout << " 1. Resolver congruencia linear\n    Forma: aX \u2261 c(mod b)\n";
    cout << " 2. Resolver equacao diofantina\n    Forma: aX + bY = c\n";
    cout << " 3. Resolver sistema de congruencias lineares\n    Forma: aX \u2261 c(mod b) ...\n";
    cout << " 4. MDC & MMC\n";
    cout << " +============================================+\n";
    cout << " Opcao escolhida: ";
    opcao = getchar() - '0';

    return opcao;
}

int main ()
{
    algebra nt;
    int64_t t, solucao(0), produto(1);
    unsigned char opcao, i;
    bool valida;
    vector<tuple<int64_t, int64_t>> vet;
    int qtd, j;

    opcao = menu ();
    if (opcao < 1 || opcao > 3) return 0;

    switch (opcao) 
    {
        case 1:
        case 2:
            nt.getNumbersEqD ();
            nt.mdcE ();
            nt.coefsEqDiofantina ();

            cout << endl << " +====================ED/CL=====================+" << endl;
            cout << " r = " << nt.r << ", s = " << nt.s << endl;
            cout << " x = " << nt.cof1X;
            if (nt.cof2X < 0) cout << " - " << abs (nt.cof2X) << "t";
            else cout << " + " << nt.cof2X << "t";

            cout << endl << " y = " << nt.cof1Y;
            if (nt.cof2Y < 0) cout << " + " << abs (nt.cof2Y) << "t";
            else cout << " - " << nt.cof2Y << "t";
            cout << "\n +==============================================+" << endl;

            if (opcao == 2)
            {
                cout << " \nDeseja inserir um valor de t? (S/N)\n";
                cout << " Opcao escolhida: ";
                cin >> i;
                if (i == 'S' || i == 's')
                {
                    cout << " t = ";
                    get (t);
                    cout << " x = " << nt.cof1X + nt.cof2X * t << endl;
                    cout << " y = " << nt.cof1Y - nt.cof2Y * t << "\n\n";
                }
            }
            else
            {
                cout << "\n Deseja listar solucoes unicas? (S/N)\n";
                cout << " Opcao escolhida: ";
                cin >> i;
                if (i == 'S' || i == 's')
                {
                    cout << "\n";
                    for (j = 0; j < nt.Mdc; j++)
                        cout << " x" << j << " = " << nt.cof1X + nt.cof2X * j << "\n";
                    cout << "\n";
                }
            } 

            break;
        case 3:
            cout << " Quantas equacoes deseja computar? Digite um numero: ";
            cin >> qtd; 
            
            for (j = 0; j < qtd; j++)
            {
                nt.getNumbersEqD ();
                nt.mdcE ();
                cout << "\n";
                if (!nt.verificaEqDiofantina (nt.c))
                {
                    cout << " Entrada invalida" << endl;
                    exit (0);
                }

                if (nt.mdc (produto, nt.b / nt.Mdc) != 1) 
                {
                    cout << " Entrada invalida\n";
                    break;
                }
                produto *= (nt.b / nt.Mdc);
                vet.push_back (make_tuple (nt.r * nt.c / nt.Mdc, nt.b / nt.Mdc));
            }

            for (auto& it : vet)
            {
                nt.a = get<1>(it);
                nt.b = produto / nt.a;
                nt.mdcE ();
                solucao += (get<0>(it) * nt.s * nt.b);
            }

            cout << "\n x = " << solucao << " + " << produto << "t\n\n";
            break;
        case 4:
            nt.getNumbers ();
            nt.mdcE ();
            cout << endl << " +====================MDC====================+" << endl;
            cout << " mdc(" << nt.a << ", " << nt.b << ") = " << nt.Mdc << endl;
            if (nt.numDiv == 1) cout << " " << nt.numDiv << " divisao" << endl;
            else cout << " " << nt.numDiv << " divisoes " << endl;
            cout << " +===========================================+" << endl;

            nt.mmc ();
            cout << endl << " +====================MMC====================+" << endl;
            cout << " mmc(" << nt.a << ", " << nt.b << ") = " << nt.Mmc << endl;
            cout << " " << nt.numDiv << " divisoes " << endl;
            cout << " +===========================================+\n\n";

            break;
    }

    return 0;
}