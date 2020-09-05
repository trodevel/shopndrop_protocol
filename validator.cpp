// includes
#include "validator.h"
#include "generic_protocol/validator.h"
#include "basic_objects/validator.h"
#include "basic_parser/validator.h"

namespace shopndrop_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

bool validate( const std::string & prefix, const ride_resolution_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( ride_resolution_e::UNDEF ), true, true, static_cast<unsigned>( ride_resolution_e::CANCELLED ) );

    return true;
}

bool validate( const std::string & prefix, const order_resolution_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( order_resolution_e::UNDEF ), true, true, static_cast<unsigned>( order_resolution_e::CANCELLED_BY_USER ) );

    return true;
}

bool validate( const std::string & prefix, const order_state_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( order_state_e::UNDEF ), true, true, static_cast<unsigned>( order_state_e::DELIVERED_WAITING_FEEDBACK ) );

    return true;
}

bool validate( const std::string & prefix, const gender_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( gender_e::UNDEF ), true, true, static_cast<unsigned>( gender_e::FEMALE ) );

    return true;
}

// objects

bool validate( const std::string & prefix, const ProductItem & r )
{
    validate( prefix + ".NAME", r.name, true, true, static_cast<std::size_t>( 1 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".UNIT", r.unit, true, true, static_cast<std::size_t>( 1 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".PRICE", r.price, true, false, static_cast<double>( 0 ), false, false, static_cast<double>( 0 ) );
    validate( prefix + ".WEIGHT", r.weight, true, false, static_cast<double>( 0 ), false, false, static_cast<double>( 0 ) );

    return true;
}

bool validate( const std::string & prefix, const ShoppingItem & r )
{
    validate( prefix + ".PRODUCT_ITEM_ID", r.product_item_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( prefix + ".AMOUNT", r.amount, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const std::string & prefix, const ShoppingList & r )
{
    validate_t( prefix + ".ITEMS", r.items, static_cast<bool (*)( const std::string &, const ShoppingItem &  )>( &validate ), true, true, static_cast<std::size_t>( 1 ), false, false, static_cast<std::size_t>( 0 ) ); // Array

    return true;
}

bool validate( const std::string & prefix, const GeoPosition & r )
{
    validate( prefix + ".PLZ", r.plz, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( prefix + ".LATITUDE", r.latitude, true, true, static_cast<double>( 0 ), true, true, static_cast<double>( 0 ) );
    validate( prefix + ".LONGITUDE", r.longitude, true, true, static_cast<double>( 0 ), true, true, static_cast<double>( 0 ) );

    return true;
}

bool validate( const std::string & prefix, const RideSummary & r )
{
    validate( prefix + ".POSITION", r.position );
    ::basic_objects::validator::validate( prefix + ".DELIVERY_TIME", r.delivery_time );
    validate( prefix + ".MAX_WEIGHT", r.max_weight, true, false, static_cast<double>( 0 ), false, false, static_cast<double>( 0 ) );

    return true;
}

bool validate( const std::string & prefix, const Ride & r )
{
    validate( prefix + ".IS_OPEN", r.is_open );
    validate( prefix + ".SUMMARY", r.summary );
    validate_t( prefix + ".PENDING_ORDER_IDS", r.pending_order_ids, static_cast<bool (*)( const std::string &, uint32_t )>( &validate ) ); // Array
    validate( prefix + ".ACCEPTED_ORDER_ID", r.accepted_order_id );
    validate( prefix + ".RESOLUTION", r.resolution );

    return true;
}

bool validate( const std::string & prefix, const Address & r )
{
    validate( prefix + ".PLZ", r.plz, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( prefix + ".COUNTRY", r.country, true, false, static_cast<std::size_t>( 0 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".CITY", r.city, true, false, static_cast<std::size_t>( 0 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".STREET", r.street, true, false, static_cast<std::size_t>( 0 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".HOUSE_NUMBER", r.house_number, true, false, static_cast<std::size_t>( 0 ), false, false, static_cast<std::size_t>( 0 ) ); // String
    validate( prefix + ".EXTRA_ADDRESS_LINE", r.extra_address_line ); // String

    return true;
}

bool validate( const std::string & prefix, const Order & r )
{
    validate( prefix + ".IS_OPEN", r.is_open );
    validate( prefix + ".RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( prefix + ".DELIVERY_ADDRESS", r.delivery_address );
    validate( prefix + ".SHOPPING_LIST_ID", r.shopping_list_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( prefix + ".STATE", r.state );
    validate( prefix + ".RESOLUTION", r.resolution );

    return true;
}

// base messages

bool validate( const Request & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::Request&>( r ) );


    return true;
}

// messages

bool validate( const AddRideRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "RIDE", r.ride );

    return true;
}

bool validate( const AddRideResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const CancelRideRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const CancelRideResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetRideRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const GetRideResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "RIDE", r.ride );

    return true;
}

bool validate( const AddOrderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( "SHOPPING_LIST", r.shopping_list );
    validate( "DELIVERY_ADDRESS", r.delivery_address );

    return true;
}

bool validate( const AddOrderResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const CancelOrderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const CancelOrderResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

bool validate( const AcceptOrderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const AcceptOrderResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

bool validate( const DeclineOrderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const DeclineOrderResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

bool validate( const MarkDeliveredOrderRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const MarkDeliveredOrderResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

bool validate( const RateShopperRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ORDER_ID", r.order_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    validate( "STARS", r.stars, true, true, static_cast<uint32_t>( 0 ), true, true, static_cast<uint32_t>( 5 ) );

    return true;
}

bool validate( const RateShopperResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

} // namespace validator

} // namespace shopndrop_protocol

