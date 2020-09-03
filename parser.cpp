// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "generic_protocol/parser.h"
#include "basic_objects/parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace shopndrop_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

void get_value_or_throw( ride_resolution_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ride_resolution_e>( res_i );
}

void get_value_or_throw( order_resolution_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<order_resolution_e>( res_i );
}

void get_value_or_throw( order_state_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<order_state_e>( res_i );
}

void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<gender_e>( res_i );
}

// objects

void get_value_or_throw( ProductItem * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->name, prefix + ".NAME", r );
    get_value_or_throw( & res->unit, prefix + ".UNIT", r );
    get_value_or_throw( & res->price, prefix + ".PRICE", r );
    get_value_or_throw( & res->weight, prefix + ".WEIGHT", r );
}

void get_value_or_throw( ShoppingItem * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->product_item_id, prefix + ".PRODUCT_ITEM_ID", r );
    get_value_or_throw( & res->amount, prefix + ".AMOUNT", r );
}

void get_value_or_throw( ShoppingList * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw_t( & res->items, prefix + ".ITEMS", r, static_cast<void (*)( ShoppingItem * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GeoPosition * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->plz, prefix + ".PLZ", r );
    get_value_or_throw( & res->latitude, prefix + ".LATITUDE", r );
    get_value_or_throw( & res->longitude, prefix + ".LONGITUDE", r );
}

void get_value_or_throw( RideSummary * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->position, prefix + ".POSITION", r );
    ::basic_objects::parser::get_value_or_throw( & res->delivery_time, prefix + ".DELIVERY_TIME", r );
    get_value_or_throw( & res->max_weight, prefix + ".MAX_WEIGHT", r );
}

void get_value_or_throw( Ride * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->is_open, prefix + ".IS_OPEN", r );
    get_value_or_throw( & res->summary, prefix + ".SUMMARY", r );
    get_value_or_throw_t( & res->pending_order_ids, prefix + ".PENDING_ORDER_IDS", r, static_cast<void (*)( uint32_t * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw( & res->accepted_order_id, prefix + ".ACCEPTED_ORDER_ID", r );
    get_value_or_throw( & res->resolution, prefix + ".RESOLUTION", r );
}

void get_value_or_throw( Address * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->plz, prefix + ".PLZ", r );
    get_value_or_throw( & res->country, prefix + ".COUNTRY", r );
    get_value_or_throw( & res->city, prefix + ".CITY", r );
    get_value_or_throw( & res->street, prefix + ".STREET", r );
    get_value_or_throw( & res->house_number, prefix + ".HOUSE_NUMBER", r );
    get_value_or_throw( & res->extra_address_line, prefix + ".EXTRA_ADDRESS_LINE", r );
}

void get_value_or_throw( Order * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->is_open, prefix + ".IS_OPEN", r );
    get_value_or_throw( & res->ride_id, prefix + ".RIDE_ID", r );
    get_value_or_throw( & res->delivery_address, prefix + ".DELIVERY_ADDRESS", r );
    get_value_or_throw( & res->shopping_list_id, prefix + ".SHOPPING_LIST_ID", r );
    get_value_or_throw( & res->state, prefix + ".STATE", r );
    get_value_or_throw( & res->resolution, prefix + ".RESOLUTION", r );
}

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
}

// messages

void get_value_or_throw( AddRideRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->ride, "RIDE", r );
}

void get_value_or_throw( AddRideResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->ride_id, "RIDE_ID", r );
}

void get_value_or_throw( CancelRideRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->ride_id, "RIDE_ID", r );
}

void get_value_or_throw( CancelRideResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetRideRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->ride_id, "RIDE_ID", r );
}

void get_value_or_throw( GetRideResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->ride, "RIDE", r );
}

void get_value_or_throw( AddOrderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->ride_id, "RIDE_ID", r );
    get_value_or_throw( & res->shopping_list, "SHOPPING_LIST", r );
    get_value_or_throw( & res->delivery_address, "DELIVERY_ADDRESS", r );
}

void get_value_or_throw( AddOrderResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
}

void get_value_or_throw( CancelOrderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
}

void get_value_or_throw( CancelOrderResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

void get_value_or_throw( AcceptOrderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
}

void get_value_or_throw( AcceptOrderResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

void get_value_or_throw( DeclineOrderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
}

void get_value_or_throw( DeclineOrderResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

void get_value_or_throw( MarkDeliveredOrderRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
}

void get_value_or_throw( MarkDeliveredOrderResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

void get_value_or_throw( RateShopperRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->order_id, "ORDER_ID", r );
    get_value_or_throw( & res->stars, "STARS", r );
}

void get_value_or_throw( RateShopperResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

// to object

Object * to_AddRideRequest( const generic_request::Request & r )
{
    std::unique_ptr<AddRideRequest> res( new AddRideRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddRideResponse( const generic_request::Request & r )
{
    std::unique_ptr<AddRideResponse> res( new AddRideResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelRideRequest( const generic_request::Request & r )
{
    std::unique_ptr<CancelRideRequest> res( new CancelRideRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelRideResponse( const generic_request::Request & r )
{
    std::unique_ptr<CancelRideResponse> res( new CancelRideResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetRideRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetRideRequest> res( new GetRideRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetRideResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetRideResponse> res( new GetRideResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddOrderRequest( const generic_request::Request & r )
{
    std::unique_ptr<AddOrderRequest> res( new AddOrderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AddOrderResponse( const generic_request::Request & r )
{
    std::unique_ptr<AddOrderResponse> res( new AddOrderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelOrderRequest( const generic_request::Request & r )
{
    std::unique_ptr<CancelOrderRequest> res( new CancelOrderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CancelOrderResponse( const generic_request::Request & r )
{
    std::unique_ptr<CancelOrderResponse> res( new CancelOrderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AcceptOrderRequest( const generic_request::Request & r )
{
    std::unique_ptr<AcceptOrderRequest> res( new AcceptOrderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AcceptOrderResponse( const generic_request::Request & r )
{
    std::unique_ptr<AcceptOrderResponse> res( new AcceptOrderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeclineOrderRequest( const generic_request::Request & r )
{
    std::unique_ptr<DeclineOrderRequest> res( new DeclineOrderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_DeclineOrderResponse( const generic_request::Request & r )
{
    std::unique_ptr<DeclineOrderResponse> res( new DeclineOrderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_MarkDeliveredOrderRequest( const generic_request::Request & r )
{
    std::unique_ptr<MarkDeliveredOrderRequest> res( new MarkDeliveredOrderRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_MarkDeliveredOrderResponse( const generic_request::Request & r )
{
    std::unique_ptr<MarkDeliveredOrderResponse> res( new MarkDeliveredOrderResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_RateShopperRequest( const generic_request::Request & r )
{
    std::unique_ptr<RateShopperRequest> res( new RateShopperRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_RateShopperResponse( const generic_request::Request & r )
{
    std::unique_ptr<RateShopperResponse> res( new RateShopperResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
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

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return generic_protocol::parser::to_forward_message( r );
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace shopndrop_protocol

