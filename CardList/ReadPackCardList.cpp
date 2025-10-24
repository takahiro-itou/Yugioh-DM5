
#include    "PackCardList.h"

constexpr   int     NUM_CARDS   = 928;

int  g_cardTable[NUM_CARDS + 1] = { 0 };

void  initializeCardTable()
{
    for ( int i = 0; i <= NUM_CARDS; ++ i ) {
        g_cardTable[i]  = 0;
    }
    for ( int p = 0; p < getArraySize(packTable); ++ p ) {
        const  int  nc  = packTable[p].numCards;
        for ( int j = 0; j < nc; ++ j ) {
        }
    }
}

int main(int argc, char * argv[])
{
    return ( 0 );
}
