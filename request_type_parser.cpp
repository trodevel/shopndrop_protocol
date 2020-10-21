// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace shopndrop_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"shopndrop_protocol/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddRideRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddRideResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelRideRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelRideResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetRideRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetRideResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddOrderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AddOrderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelOrderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CancelOrderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AcceptOrderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AcceptOrderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeclineOrderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( DeclineOrderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( MarkDeliveredOrderRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( MarkDeliveredOrderResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( RateShopperRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( RateShopperResponse ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace shopndrop_protocol

