
#include    "PackCardList.h"

#include    <iostream>


int  g_cardTable[PackListId::NUM_CARDS + 1] = { 0 };

/**
**    ゲーム進行で絶対手に入るパック。
**
**  - 最初から選択可能
**      - VOL1
**      - VOL2
**      - VOL3
**  - ステージ進行時
**      - ExpertPack2   : ステージ１で全員に２勝。ステージ２開始
**      - ExpertPack4   : ステージ２で全員に３勝。ステージ３開始
**      - PremiumPack3  : ステージ３で全員に４勝。ステージ４開始
**  - その他
**      - GrandpaPack
**      - WeeklyJumpGiftPackA
**      - WeeklyJumpGiftPackB
**      - VJumpGiftPack
**/

constexpr  int  pbEssential = (
        PackBits::VOL1 | PackBits::VOL2 | PackBits::VOL3
        | PackBits::EXPERTPACK2
        | PackBits::EXPERTPACK4
        | PackBits::PREMIUMPACK3
        | PackBits::GRANDPA_PACK
        | PackBits::WEEKLY_JUMP_GIFT_PACK_A
        | PackBits::WEEKLY_JUMP_GIFT_PACK_B
        | PackBits::VJUMP_GIFT_PACK);

/**
**    他の条件の前にほぼ成立するパック。
**
**  -ステージ内で１０勝。
**      - ExpertPack1   : ステージ１内で１０勝
**      - VOL5          : ステージ２内で１０勝
**      - MagicRuler    : ステージ３内で１０勝
**      - Duelist_Pack  : ステージ４内で１０勝
**/

constexpr  int  pbStage10Win = (
        PackBits::EXPERTPACK1
        | PackBits::VOL5
        | PackBits::MAGIC_RULER
        | PackBits::DUELIST_PACK
);

void  initializeCardTable()
{
    for ( int i = 0; i <= PackListId::NUM_CARDS; ++ i ) {
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
    int exp = (PackBits::LEGEND_OF_BLUE_EYES_WHITE_DRAGON);
    std::cerr   <<  "ID = 001"
                <<  ", Actual = "   <<  g_cardTable[1]
                <<  ", Expect = "   <<  exp
                <<  std::endl;

    exp = (PackBits::VOL2 | PackBits::PHANTOM_GOD
           | PackBits::DUELIST_PACK | PackBits::RARE_SELECTION
           | PackBits::VJUMP_GIFT_PACK);
    std::cerr   <<  "ID = 623"
                <<  ", Actual = "   <<  g_cardTable[623]
                <<  ", Expect = "   <<  exp
                <<  std::endl;

    exp = (PackBits::DUEL_FINALIST | PackBits::GRANDPA_PACK);
    std::cerr   <<  "ID = 928"
                <<  ", Actual = "   <<  g_cardTable[928]
                <<  ", Expect = "   <<  exp
                <<  std::endl;
}

int  computeObtainCardList(
        const  int  bitPack,
        int         obtCardList[],
        int         remCardList[])
{
    int num = 0;
    int rem = 0;
    for ( int i = 1; i <= PackListId::NUM_CARDS; ++ i ) {
        const  int  pat = g_cardTable[i];
        if ( pat & bitPack ) {
            obtCardList[num ++] = i;
        } else {
            remCardList[rem ++] = i;
        }
    }

    return ( num );
}

void
showObtrainRemainCards(
        const  int  bitPack)
{
    int obtainCards[928];
    int remainCards[928];

    const  int  num = computeObtainCardList(
                            bitPack, obtainCards, remainCards);
    const  int  rem = (PackListId::NUM_CARDS - num);
    std::cout   <<  "Packs = "      <<  bitPack
                <<  ", Cards = "    <<  num
                <<  ", Rems  = "    <<  rem
                <<  std::endl;

    for ( int i = 0; i < rem; ++ i ) {
        std::cout   <<  remainCards[i]  <<  ", ";
    }

    return;
}

int main(int argc, char * argv[])
{
    initializeCardTable();

    int     bitPack = pbEssential | pbStage10Win;
    showObtrainRemainCards(bitPack);

    return ( 0 );
}
