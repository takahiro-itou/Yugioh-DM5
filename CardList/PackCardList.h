//  -*-  coding: utf-8-with-signature;  mode: c++  -*-  //
/*************************************************************************
**                                                                      **
**                  ----   Yugioh DM5 Database.   ----                  **
**                                                                      **
**          Copyright (C), 2025-2025, Takahiro Itou                     **
**          All Rights Reserved.                                        **
**                                                                      **
**          License: (See COPYING or LICENSE files)                     **
**          GNU Affero General Public License (AGPL) version 3,         **
**          or (at your option) any later version.                      **
**                                                                      **
*************************************************************************/

/**
**      パックのカードリスト
**
**      @file       PackCardList.h
**/

#if !defined( YUGIOHDM5_INCLUDED_PACK_CARD_LIST_H )
#    define   YUGIOHDM5_INCLUDED_PACK_CARD_LIST_H

#include    <stddef.h>

enum class  CardRarity
{
    COMMON,
    NORMAL,
    SECRET,
    ULTRA,
    SUPER,
    RARE,
    NOTHING,
};

struct  PackCardListEntry
{
    int         number;
    CardRarity  rarity;
};

typedef     const   PackCardListEntry  *    CardList;

struct  PackCardList
{
    int         numCards;
    CardList    cardList;
};


//========================================================================
/**
**    配列の要素数を取得する。
**/

template  <typename  T,  size_t  N>
constexpr
size_t  getArraySize(T  (&)[N])
{
    return ( N );
}

//========================================================================
/**
**    パックのカードリスト
**/

#define     PACK_CARD(number, rarity)   \
    { number, CardRarity::rarity }

constexpr   PackCardListEntry
pclVol1[41] = {
#    include    "Vol1.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol2[41] = {
#    include    "Vol2.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol3[51] = {
#    include    "Vol3.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol4[51] = {
#    include    "Vol4.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol5[51] = {
#    include    "Vol5.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol6[53] = {
#    include    "Vol6.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol7[53] = {
#    include    "Vol7.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclMagicRuler[51] = {
#    include    "MagicRuler.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclPharaohsServant[53] = {
#    include    "PharaohsServant.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclCurseOfAnubis[53] = {
#    include    "CurseOfAnubis.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclLegendOfBlueEyesWhiteDragon[62] = {
#    include    "LegendOfBlueEyesWhiteDragon.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclPhantomGod[66] = {
#    include    "PhantomGod.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclDarkCeremony[17] = {
#    include    "DarkCeremony.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclPremiumPack3[11] = {
#    include    "PremiumPack3.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclExpertPack1[66] = {
#    include    "ExpertPack1.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclExpertPack2[64] = {
#    include    "ExpertPack2.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclExpertPack3[67] = {
#    include    "ExpertPack3.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclExpertPack4[67] = {
#    include    "ExpertPack4.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclExpertPack5[51] = {
#    include    "ExpertPack5.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclDuelistPack[37] = {
#    include    "DuelistPack.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclDuelFinalist[41] = {
#    include    "DuelFinalist.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclRareSelection[51] = {
#    include    "RareSelection.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclLimitedPack[41] = {
#    include    "LimitedPack.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclGrandpaPack[16] = {
#    include    "GrandpaPack.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclWeeklyJumpGiftPackA[149] = {
#    include    "WeeklyJumpGiftPackA.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclWeeklyJumpGiftPackB[52] = {
#    include    "WeeklyJumpGiftPackB.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVJumpGiftPack[52] = {
#    include    "VJumpGiftPack.pcl"
    PACK_CARD( 0, NOTHING )
};

#undef      PACK_CARD

#define     PACK_ENTRY(name)  \
    { getArraySize(pcl ## name) - 1, pcl ## name }

constexpr   PackCardList
packTable[27] = {
    PACK_ENTRY(Vol1),
    PACK_ENTRY(Vol2),
    PACK_ENTRY(Vol3),
    PACK_ENTRY(Vol4),
    PACK_ENTRY(Vol5),
    PACK_ENTRY(Vol6),
    PACK_ENTRY(Vol7),
    PACK_ENTRY(MagicRuler),
    PACK_ENTRY(PharaohsServant),
    PACK_ENTRY(CurseOfAnubis),
    PACK_ENTRY(LegendOfBlueEyesWhiteDragon),
    PACK_ENTRY(PhantomGod),
    PACK_ENTRY(DarkCeremony),
    PACK_ENTRY(PremiumPack3),
    PACK_ENTRY(ExpertPack1),
    PACK_ENTRY(ExpertPack2),
    PACK_ENTRY(ExpertPack3),
    PACK_ENTRY(ExpertPack4),
    PACK_ENTRY(ExpertPack5),
    PACK_ENTRY(DuelistPack),
    PACK_ENTRY(DuelFinalist),
    PACK_ENTRY(RareSelection),
    PACK_ENTRY(LimitedPack),
    PACK_ENTRY(GrandpaPack),
    PACK_ENTRY(WeeklyJumpGiftPackA),
    PACK_ENTRY(WeeklyJumpGiftPackB),
    PACK_ENTRY(VJumpGiftPack),
};

#undef      PACK_ENTRY

namespace  PackListId  {

enum  {
    VOL1    = 0,
    VOL2,
    VOL3,
    VOL4,
    VOL5,
    VOL6,
    VOL7,
    MAGIC_RULER,
    PHARAOHS_SERVANT,
    CURSE_OF_ANUBIS,
    LEGEND_OF_BLUE_EYES_WHITE_DRAGON,
    PHANTOM_GOD,
    DARK_CEREMONY,
    PREMIUMPACK3,
    EXPERTPACK1,
    EXPERTPACK2,
    EXPERTPACK3,
    EXPERTPACK4,
    EXPERTPACK5,
    DUELIST_PACK,
    DUEL_FINALIST,
    RARE_SELECTION,
    LIMITED_PACK,
    GRANDPA_PACK,
    WEEKLY_JUMP_GIFT_PACK_A,
    WEEKLY_JUMP_GIFT_PACK_B,
    VJUMP_GIFT_PACK,

    NUM_PACKS,
    NUM_CARDS   = 928,
};

}   //  End of namespace  PackListId

namespace  PackBits  {

enum  {
    VOL1                    = 0x00000001,
    VOL2                    = 0x00000002,
    VOL3                    = 0x00000004,
    VOL4                    = 0x00000008,
    VOL5                    = 0x00000010,
    VOL6                    = 0x00000020,
    VOL7                    = 0x00000040,
    MAGIC_RULER             = 0x00000080,
    PHARAOHS_SERVANT        = 0x00000100,
    CURSE_OF_ANUBIS         = 0x00000200,
    LEGEND_OF_BLUE_EYES_WHITE_DRAGON    = 0x00000400,
    PHANTOM_GOD             = 0x00000800,
    DARK_CEREMONY           = 0x00001000,
    PREMIUMPACK3            = 0x00002000,
    EXPERTPACK1             = 0x00004000,
    EXPERTPACK2             = 0x00008000,
    EXPERTPACK3             = 0x00010000,
    EXPERTPACK4             = 0x00020000,
    EXPERTPACK5             = 0x00040000,
    DUELIST_PACK            = 0x00080000,
    DUEL_FINALIST           = 0x00100000,
    RARE_SELECTION          = 0x00200000,
    LIMITED_PACK            = 0x00400000,
    GRANDPA_PACK            = 0x00800000,
    WEEKLY_JUMP_GIFT_PACK_A = 0x01000000,
    WEEKLY_JUMP_GIFT_PACK_B = 0x02000000,
    VJUMP_GIFT_PACK         = 0x04000000,
};

}   //  End of namespace  PackBits

#endif
