
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
#include    "Vol1.pcl"
        PACK_CARD( 0, NOTHING )
    }
};

int main(int argc, char * argv[])
{
    return ( 0 );
}
