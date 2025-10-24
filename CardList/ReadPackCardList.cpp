
#include    "PackCardList.h"

#include    <iostream>


constexpr   int     NUM_CARDS   = 928;

int  g_cardTable[NUM_CARDS + 1] = { 0 };

void  initializeCardTable()
{
    for ( int i = 0; i <= NUM_CARDS; ++ i ) {
        g_cardTable[i]  = 0;
    }
    for ( int p = 0; p < getArraySize(packTable); ++ p ) {
        const  int  val = (1 << p);
        const  int  nc  = packTable[p].numCards;
        for ( int j = 0; j < nc; ++ j ) {
            const  int  ci  = packTable[p].cardList[j].number;
            g_cardTable[ci] |= val;
        }
    }

    //  DEBUG PRINT
    std::cerr   <<  "ID = 001"
                <<  ", Actual = "   <<  g_cardTable[1]
                <<  ", Expect = "   <<  0x00000400
                <<  std::endl;

    std::cerr   <<  "ID = 623"
                <<  ", Actual = "   <<  g_cardTable[623]
                <<  ", Expect = "   <<  0x04280802
                <<  std::endl;

}

int main(int argc, char * argv[])
{
    initializeCardTable();

    return ( 0 );
}
