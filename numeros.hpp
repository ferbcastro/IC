#ifndef __NT__
#define __NT__
#include <iostream>
#include <cstdint>
#include <cmath>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a < 0 ? -a : a)

int64_t divide (int64_t a, int64_t b);

int64_t mod (int64_t a, int64_t b);

class algebra
{
    public: 
        int64_t a, b;
        int64_t numDiv;
        int64_t Mdc, Mmc;
        int64_t r, s; 
        int64_t cof1X, cof2X, cof1Y, cof2Y; 

        algebra ();
        void getNumbers ();
        void mdcE ();
        void mmc ();
        void coefsEqDiofantina (int64_t c);
        ~algebra ();
    private:
        bool verificaEqDiofantina (int64_t c);
};
#endif