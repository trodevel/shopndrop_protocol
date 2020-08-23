// system includes
#include <map>

// includes
#include "str_helper.h"
#include "generic_protocol/str_helper.h"
#include "basic_objects/str_helper.h"
#include "basic_parser/str_helper.h"

namespace shopndrop_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

std::ostream & write( std::ostream & os, const ride_resolution_e r )
{
    typedef ride_resolution_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( EXPIRED_OR_COMPLETED ) },
        { Type:: TUPLE_VAL_STR( CANCELLED ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const order_resolution_e r )
{
    typedef order_resolution_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( DELIVERED ) },
        { Type:: TUPLE_VAL_STR( DECLINED_BY_SHOPPER ) },
        { Type:: TUPLE_VAL_STR( RIDE_CANCELLED ) },
        { Type:: TUPLE_VAL_STR( CANCELLED_BY_SHOPPER ) },
        { Type:: TUPLE_VAL_STR( CANCELLED_BY_USER ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const order_state_e r )
{
    typedef order_state_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( IDLE_WAITING_ACCEPTANCE ) },
        { Type:: TUPLE_VAL_STR( ACCEPTED_WAITING_DELIVERY ) },
        { Type:: TUPLE_VAL_STR( DELIVERED_WAITING_FEEDBACK ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const ProductItem & r )
{
    os << "(";

    os << " name="; write( os, r.name );
    os << " unit="; write( os, r.unit );
    os << " price="; write( os, r.price );
    os << " weight="; write( os, r.weight );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingItem & r )
{
    os << "(";

    os << " product_item_id="; write( os, r.product_item_id );
    os << " amount="; write( os, r.amount );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingList & r )
{
    os << "(";

    os << " items="; write_t( os, r.items, static_cast<std::ostream & (*)( std::ostream &, const ShoppingItem &  )>( &write ) ); // Array

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const GeoPosition & r )
{
    os << "(";

    os << " plz="; write( os, r.plz );
    os << " latitude="; write( os, r.latitude );
    os << " longitude="; write( os, r.longitude );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const RideSummary & r )
{
    os << "(";

    os << " position="; write( os, r.position );
    os << " delivery_time="; ::basic_objects::str_helper::write( os, r.delivery_time );
    os << " max_weight="; write( os, r.max_weight );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Ride & r )
{
    os << "(";

    os << " is_open="; write( os, r.is_open );
    os << " summary="; write( os, r.summary );
    os << " pending_order_ids="; write_t( os, r.pending_order_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    os << " accepted_order_id="; write( os, r.accepted_order_id );
    os << " resolution="; write( os, r.resolution );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Address & r )
{
    os << "(";

    os << " plz="; write( os, r.plz );
    os << " country="; write( os, r.country );
    os << " city="; write( os, r.city );
    os << " street="; write( os, r.street );
    os << " house_number="; write( os, r.house_number );
    os << " extra_address_line="; write( os, r.extra_address_line );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Order & r )
{
    os << "(";

    os << " is_open="; write( os, r.is_open );
    os << " ride_id="; write( os, r.ride_id );
    os << " delivery_address="; write( os, r.delivery_address );
    os << " shopping_list_id="; write( os, r.shopping_list_id );
    os << " state="; write( os, r.state );
    os << " resolution="; write( os, r.resolution );

    os << ")";

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    os << "(";


    os << ")";

    return os;
}

// messages

std::ostream & write( std::ostream & os, const AddRideRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " ride="; write( os, r.ride );

    return os;
}

std::ostream & write( std::ostream & os, const AddRideResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " ride_id="; write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelRideRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " ride_id="; write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelRideResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetRideRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " ride_id="; write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetRideResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " ride="; write( os, r.ride );

    return os;
}

std::ostream & write( std::ostream & os, const AddOrderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " ride_id="; write( os, r.ride_id );
    os << " shopping_list="; write( os, r.shopping_list );
    os << " delivery_address="; write( os, r.delivery_address );

    return os;
}

std::ostream & write( std::ostream & os, const AddOrderResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " order_id="; write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelOrderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " order_id="; write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelOrderResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const AcceptOrderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " order_id="; write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const AcceptOrderResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeclineOrderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " order_id="; write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeclineOrderResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const MarkDeliveredOrderRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " order_id="; write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const MarkDeliveredOrderResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const RateShopperRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " order_id="; write( os, r.order_id );
    os << " stars="; write( os, r.stars );

    return os;
}

std::ostream & write( std::ostream & os, const RateShopperResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

} // namespace str_helper

} // namespace shopndrop_protocol

