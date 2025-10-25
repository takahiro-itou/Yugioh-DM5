
#include    "PackCardList.h"

#include    <iostream>


constexpr   int     NUM_CARDS   = 928;

int  g_cardTable[NUM_CARDS + 1] = { 0 };

void  initializeCardTable()
{
    for ( int i = 0; i <= NUM_CARDS; ++ i ) {
        g_cardTable[i]  = 0;
    }

    for ( int p = 0; p < PackListId::NUM_PACKS; ++ p ) {
        const  int  val = (1 << p);
        const  int  nc  = packTable[p].numCards;
        int prv = 0;
        for ( int j = 0; j < nc; ++ j ) {
            if (  packTable[p].cardList[j].rarity == CardRarity::NORMAL ) {
                continue;
            }
            const  int  ci  = packTable[p].cardList[j].number;
            if ( ci < prv ) {
                std::cerr   <<  "Not sorted (or typo) card number."
                            <<  " in p = "  <<  p
                            <<  ", idx = "  <<  j
                            <<  ", prv = "  <<  prv
                            <<  ", ci  = "  <<  ci
                            <<  std::endl;
            }
            prv = ci;
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

    std::cerr   <<  "ID = 928"
                <<  ", Actual = "   <<  g_cardTable[928]
                <<  ", Expect = "   <<  0x00900000
                <<  std::endl;
}

int  computeObtainCardList(
        const  int  bitPack,
        int         cardList[])
{
    int num = 0;

    for ( int i = 1; i <= NUM_CARDS; ++ i ) {
        const  int  pat = g_cardTable[i];
        if ( pat & bitPack ) {
            cardList[num++] = i;
        }
    }

    return ( num );
}

int main(int argc, char * argv[])
{
    int obtainCards[928];

    initializeCardTable();

    int     bitPack = 0x00000001;
    const  int  num = computeObtainCardList(bitPack, obtainCards);
    std::cout   <<  "Packs = "      <<  bitPack
                <<  ", Cards = "    <<  num
                <<  std::endl;

    return ( 0 );
}
