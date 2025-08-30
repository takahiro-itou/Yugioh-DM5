
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

struct  PackCardList
{
    int         number;
    CardRarity  rarity;
};

#define     PACK_CARD(number, rarity)   \
    { number, CardRarity::rarity }


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
    },
};

int main(int argc, char * argv[])
{
    return ( 0 );
}
