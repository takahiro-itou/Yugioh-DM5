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
pclVol3[41] = {
#    include    "Vol3.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol4[41] = {
#    include    "Vol4.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol5[41] = {
#    include    "Vol5.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol6[41] = {
#    include    "Vol6.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclVol7[41] = {
#    include    "Vol7.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclMagicRuler[41] = {
#    include    "MagicRuler.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclPharaohsServant[41] = {
#    include    "PharaohsServant.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardListEntry
pclCurseOfAnubis[41] = {
#    include    "CurseOfAnubis.pcl"
    PACK_CARD( 0, NOTHING )
};

#define     PACK_ENTRY(name)  \
    { getArraySize(pcl ## name) - 1, pcl ## name }

constexpr   PackCardList
packTable[] = {
    PACK_ENTRY(Vol1),
    PACK_ENTRY(Vol2),
    PACK_ENTRY(Vol3),
    PACK_ENTRY(Vol4),
    PACK_ENTRY(Vol5),
    PACK_ENTRY(Vol6),
    PACK_ENTRY(Vol7),
};

#endif
