// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "generic_protocol/csv_helper.h"
#include "basic_objects/csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace shopndrop_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

std::ostream & write( std::ostream & os, const ride_resolution_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const order_resolution_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const order_state_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

// objects

std::ostream & write( std::ostream & os, const ProductItem & r )
{
    write( os, r.name );
    write( os, r.unit );
    write( os, r.price );
    write( os, r.weight );

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingItem & r )
{
    write( os, r.product_item_id );
    write( os, r.amount );

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingList & r )
{
    write_t( os, r.items, static_cast<std::ostream & (*)( std::ostream &, const ShoppingItem &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GeoPosition & r )
{
    write( os, r.plz );
    write( os, r.latitude );
    write( os, r.longitude );

    return os;
}

std::ostream & write( std::ostream & os, const RideSummary & r )
{
    write( os, r.position );
    ::basic_objects::csv_helper::write( os, r.delivery_time );
    write( os, r.max_weight );

    return os;
}

std::ostream & write( std::ostream & os, const Ride & r )
{
    write( os, r.is_open );
    write( os, r.summary );
    write_t( os, r.pending_order_ids, static_cast<std::ostream & (*)( std::ostream &, uint32_t )>( &write ) ); // Array
    write( os, r.accepted_order_id );
    write( os, r.resolution );

    return os;
}

std::ostream & write( std::ostream & os, const Address & r )
{
    write( os, r.plz );
    write( os, r.country );
    write( os, r.city );
    write( os, r.street );
    write( os, r.house_number );
    write( os, r.extra_address_line );

    return os;
}

std::ostream & write( std::ostream & os, const Order & r )
{
    write( os, r.is_open );
    write( os, r.ride_id );
    write( os, r.delivery_address );
    write( os, r.shopping_list_id );
    write( os, r.state );
    write( os, r.resolution );

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{

    return os;
}

// messages

std::ostream & write( std::ostream & os, const AddRideRequest & r )
{
    write( os, std::string( "shopndrop/AddRideRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.ride );

    return os;
}

std::ostream & write( std::ostream & os, const AddRideResponse & r )
{
    write( os, std::string( "shopndrop/AddRideResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelRideRequest & r )
{
    write( os, std::string( "shopndrop/CancelRideRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelRideResponse & r )
{
    write( os, std::string( "shopndrop/CancelRideResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetRideRequest & r )
{
    write( os, std::string( "shopndrop/GetRideRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetRideResponse & r )
{
    write( os, std::string( "shopndrop/GetRideResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.ride );

    return os;
}

std::ostream & write( std::ostream & os, const AddOrderRequest & r )
{
    write( os, std::string( "shopndrop/AddOrderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.ride_id );
    write( os, r.shopping_list );
    write( os, r.delivery_address );

    return os;
}

std::ostream & write( std::ostream & os, const AddOrderResponse & r )
{
    write( os, std::string( "shopndrop/AddOrderResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelOrderRequest & r )
{
    write( os, std::string( "shopndrop/CancelOrderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const CancelOrderResponse & r )
{
    write( os, std::string( "shopndrop/CancelOrderResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const AcceptOrderRequest & r )
{
    write( os, std::string( "shopndrop/AcceptOrderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const AcceptOrderResponse & r )
{
    write( os, std::string( "shopndrop/AcceptOrderResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const DeclineOrderRequest & r )
{
    write( os, std::string( "shopndrop/DeclineOrderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const DeclineOrderResponse & r )
{
    write( os, std::string( "shopndrop/DeclineOrderResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const MarkDeliveredOrderRequest & r )
{
    write( os, std::string( "shopndrop/MarkDeliveredOrderRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.order_id );

    return os;
}

std::ostream & write( std::ostream & os, const MarkDeliveredOrderResponse & r )
{
    write( os, std::string( "shopndrop/MarkDeliveredOrderResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const RateShopperRequest & r )
{
    write( os, std::string( "shopndrop/RateShopperRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.order_id );
    write( os, r.stars );

    return os;
}

std::ostream & write( std::ostream & os, const RateShopperResponse & r )
{
    write( os, std::string( "shopndrop/RateShopperResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

std::ostream & write_AddRideRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddRideRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AddRideResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddRideResponse &>( rr );

    return write( os, r );
}

std::ostream & write_CancelRideRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelRideRequest &>( rr );

    return write( os, r );
}

std::ostream & write_CancelRideResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelRideResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetRideRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetRideRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetRideResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetRideResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AddOrderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddOrderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AddOrderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AddOrderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_CancelOrderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelOrderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_CancelOrderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CancelOrderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AcceptOrderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AcceptOrderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AcceptOrderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AcceptOrderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_DeclineOrderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeclineOrderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_DeclineOrderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const DeclineOrderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_MarkDeliveredOrderRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const MarkDeliveredOrderRequest &>( rr );

    return write( os, r );
}

std::ostream & write_MarkDeliveredOrderResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const MarkDeliveredOrderResponse &>( rr );

    return write( os, r );
}

std::ostream & write_RateShopperRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const RateShopperRequest &>( rr );

    return write( os, r );
}

std::ostream & write_RateShopperResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const RateShopperResponse &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( AddRideRequest ),
        HANDLER_MAP_ENTRY( AddRideResponse ),
        HANDLER_MAP_ENTRY( CancelRideRequest ),
        HANDLER_MAP_ENTRY( CancelRideResponse ),
        HANDLER_MAP_ENTRY( GetRideRequest ),
        HANDLER_MAP_ENTRY( GetRideResponse ),
        HANDLER_MAP_ENTRY( AddOrderRequest ),
        HANDLER_MAP_ENTRY( AddOrderResponse ),
        HANDLER_MAP_ENTRY( CancelOrderRequest ),
        HANDLER_MAP_ENTRY( CancelOrderResponse ),
        HANDLER_MAP_ENTRY( AcceptOrderRequest ),
        HANDLER_MAP_ENTRY( AcceptOrderResponse ),
        HANDLER_MAP_ENTRY( DeclineOrderRequest ),
        HANDLER_MAP_ENTRY( DeclineOrderResponse ),
        HANDLER_MAP_ENTRY( MarkDeliveredOrderRequest ),
        HANDLER_MAP_ENTRY( MarkDeliveredOrderResponse ),
        HANDLER_MAP_ENTRY( RateShopperRequest ),
        HANDLER_MAP_ENTRY( RateShopperResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return ::generic_protocol::csv_helper::write( os, r );
}

} // namespace csv_helper

} // namespace shopndrop_protocol

