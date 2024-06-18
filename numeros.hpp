#ifndef __NT__
#define __NT__
#include <iostream>
#include <cstdint>
#include <cmath>

int64_t divide (int64_t a, int64_t b);

int64_t mod (int64_t a, int64_t b);

class algebra
{
    public: 
        int64_t a, b, c;
        int64_t numDiv;
        int64_t Mdc, Mmc;
        int64_t r, s; 
        int64_t cof1X, cof2X, cof1Y, cof2Y; 

        algebra ();
        void getNumbers ();
        void mdcE ();
        int64_t mdc (int64_t a, int64_t b);
        void mmc ();
        void coefsEqDiofantina ();
        void getNumbersEqD ();
        bool verificaEqDiofantina (int64_t c);
        ~algebra ();
    private:
        int64_t mdcRec (int64_t a, int64_t b);
};
#endif