
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

typedef     const   PackCardListEntry  *    PackCardList;


#define     PACK_CARD(number, rarity)   \
    { number, CardRarity::rarity }

constexpr   PackCardListEntry
pclVol1[] = {
#    include    "Vol1.pcl"
    PACK_CARD( 0, NOTHING )
};

constexpr   PackCardList
packTable[] = {
    pclVol1,
};

#if 0
constexpr   PackCardList
packTable[][64] = {
    {
#    include    "Vol1.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol2.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol3.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol4.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol5.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol6.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "Vol7.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "MagicRuler.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "PharaohsServant.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "CurseOfAnubis.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "LegendOfBlueEyesWhiteDragon.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "PhantomGod.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "DarkCeremony.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "PremiumPack3.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "ExpertPack1.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "ExpertPack2.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "ExpertPack3.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "ExpertPack4.pcl"
        PACK_CARD( 0, NOTHING )
    } , {
#    include    "ExpertPack5.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "DuelistPack.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "DuelFinalist.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "RareSelection.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "LimitedPack.pcl"
        PACK_CARD( 0, NOTHING )
    }, {
#    include    "GrandpaPack.pcl"
        PACK_CARD( 0, NOTHING )
    },
};

#endif

int main(int argc, char * argv[])
{
    return ( 0 );
}
