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

#define     PACK_CARD(number, rarity)   \
    { number, CardRarity::rarity }

constexpr   PackCardListEntry
pclVol1[] = {
#    include    "Vol1.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardList
packTable[] = {
    { 40, pclVol1 },

};

#endif
