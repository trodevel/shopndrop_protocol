#ifndef APG_SHOPNDROP__PARSER_H
#define APG_SHOPNDROP__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace shopndrop_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums

void get_value_or_throw( ride_resolution_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( order_resolution_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( order_state_e * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r );

// objects

void get_value_or_throw( ProductItem * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingItem * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingList * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( GeoPosition * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( RideSummary * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Ride * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Address * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Order * res, const std::string & key, const generic_request::Request & r );

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r );

// messages

void get_value_or_throw( AddRideRequest * res, const generic_request::Request & r );
void get_value_or_throw( AddRideResponse * res, const generic_request::Request & r );
void get_value_or_throw( CancelRideRequest * res, const generic_request::Request & r );
void get_value_or_throw( CancelRideResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetRideRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetRideResponse * res, const generic_request::Request & r );
void get_value_or_throw( AddOrderRequest * res, const generic_request::Request & r );
void get_value_or_throw( AddOrderResponse * res, const generic_request::Request & r );
void get_value_or_throw( CancelOrderRequest * res, const generic_request::Request & r );
void get_value_or_throw( CancelOrderResponse * res, const generic_request::Request & r );
void get_value_or_throw( AcceptOrderRequest * res, const generic_request::Request & r );
void get_value_or_throw( AcceptOrderResponse * res, const generic_request::Request & r );
void get_value_or_throw( DeclineOrderRequest * res, const generic_request::Request & r );
void get_value_or_throw( DeclineOrderResponse * res, const generic_request::Request & r );
void get_value_or_throw( MarkDeliveredOrderRequest * res, const generic_request::Request & r );
void get_value_or_throw( MarkDeliveredOrderResponse * res, const generic_request::Request & r );
void get_value_or_throw( RateShopperRequest * res, const generic_request::Request & r );
void get_value_or_throw( RateShopperResponse * res, const generic_request::Request & r );

// to_... functions

Object * to_AddRideRequest( const generic_request::Request & r );
Object * to_AddRideResponse( const generic_request::Request & r );
Object * to_CancelRideRequest( const generic_request::Request & r );
Object * to_CancelRideResponse( const generic_request::Request & r );
Object * to_GetRideRequest( const generic_request::Request & r );
Object * to_GetRideResponse( const generic_request::Request & r );
Object * to_AddOrderRequest( const generic_request::Request & r );
Object * to_AddOrderResponse( const generic_request::Request & r );
Object * to_CancelOrderRequest( const generic_request::Request & r );
Object * to_CancelOrderResponse( const generic_request::Request & r );
Object * to_AcceptOrderRequest( const generic_request::Request & r );
Object * to_AcceptOrderResponse( const generic_request::Request & r );
Object * to_DeclineOrderRequest( const generic_request::Request & r );
Object * to_DeclineOrderResponse( const generic_request::Request & r );
Object * to_MarkDeliveredOrderRequest( const generic_request::Request & r );
Object * to_MarkDeliveredOrderResponse( const generic_request::Request & r );
Object * to_RateShopperRequest( const generic_request::Request & r );
Object * to_RateShopperResponse( const generic_request::Request & r );

} // namespace parser

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__PARSER_H
