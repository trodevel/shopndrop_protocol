/*

Request Parser.

Copyright (C) 2019 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 11229 $ $Date:: 2019-05-10 #$ $Author: serge $

#include "request_parser.h"         // self

#include "basic_parser/get_value.h" // basic_parser::get_value_or_throw
#include "basic_objects/parser.h"   // basic_objects::Parser

#include "parser.h"                 // Parser
#include "generic_protocol/request_parser.h" // generic_protocol::RequestParser::to_request()
#include "request_validator.h"      // RequestValidator

namespace shopndrop_protocol {

using basic_parser::get_value_or_throw;
using basic_parser::get_value_or_throw_uint32;
using basic_parser::get_value_or_throw_double;

generic_protocol::ForwardMessage* RequestParser::to_forward_message( const generic_request::Request & r )
{
    auto type = RequestParser::detect_request_type( r );

    typedef request_type_e KeyType;
    typedef RequestParser Type;

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

    static const std::map<KeyType, PPMF> funcs =
    {
        { KeyType::AddRideRequest,              & Type::to_AddRideRequest },
        { KeyType::AddOrderRequest,             & Type::to_AddOrderRequest },
        { KeyType::CancelOrderRequest,          & Type::to_CancelOrderRequest },
        { KeyType::CancelRideRequest,           & Type::to_CancelRideRequest },
        { KeyType::GetPersonalUserInfoRequest,  & Type::to_GetPersonalUserInfoRequest },
        { KeyType::GetRideRequest,              & Type::to_GetRideRequest },
        { KeyType::GetPersonalUserInfoRequest,  & Type::to_GetPersonalUserInfoRequest },
    };

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return generic_protocol::RequestParser::to_forward_message( r );
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return Parser::to_request_type( cmd );
}

void RequestParser::to_Id( id_t * res, const std::string & key, const generic_request::Request & r )
{
    get_value_or_throw_uint32( * res, key, r );
}

void RequestParser::to_order_state( order_state_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t state;

    get_value_or_throw_uint32( state, key, r );

    * res = static_cast<order_state_e>( state );
}

void RequestParser::to_order_resolution( order_resolution_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t resolution;

    get_value_or_throw_uint32( resolution, key, r );

    * res = static_cast<order_resolution_e>( resolution );
}

void RequestParser::to_ProductItem( ProductItem * res, const generic_request::Request & r )
{
    get_value_or_throw( res->name,          "NAME", r );
    get_value_or_throw( res->unit,          "UNIT", r );
    get_value_or_throw_double( res->price,  "PRICE", r );
    get_value_or_throw_double( res->weight, "WEIGHT", r );
}

RequestParser::ForwardMessage * RequestParser::to_AddRideRequest( const generic_request::Request & r )
{
    auto * res = new AddRideRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Ride( & res->ride, r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_CancelRideRequest( const generic_request::Request & r )
{
    auto res = new CancelRideRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Id( & res->ride_id, "RIDE_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetRideRequest( const generic_request::Request & r )
{
    auto * res = new GetRideRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Id( & res->ride_id, "RIDE_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_AddOrderRequest( const generic_request::Request & r )
{
    auto * res = new AddOrderRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Id( & res->ride_id, "RIDE_ID", r );

    to_ShoppingList( & res->shopping_list, r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_CancelOrderRequest( const generic_request::Request & r )
{
    auto * res = new CancelOrderRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Id( & res->order_id, "ORDER_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetPersonalUserInfoRequest( const generic_request::Request & r )
{
    auto * res = new GetPersonalUserInfoRequest;

    generic_protocol::RequestParser::to_request( res, r );

    to_Id( & res->user_id, "USER_ID", r );

    RequestValidator::validate( * res );

    return res;
}

void RequestParser::to_ShoppingList( ShoppingList * res, const generic_request::Request & r )
{
    std::vector<uint32_t> shopping_items;

    r.get_vector_uint32( "SHOPPING_LIST", shopping_items );

    auto size = shopping_items.size() / 2;

    for( size_t i = 0; i < size; ++i )
    {
        ShoppingItem si;

        si.product_item_id  = shopping_items[ 0 + i * 2 ];
        si.amount           = shopping_items[ 1 + i * 2 ];

        res->items.push_back( si );
    }
}

void RequestParser::to_GeoPosition( GeoPosition * res, const generic_request::Request & r )
{
    get_value_or_throw_uint32( res->plz,       "PLZ", r );

    res->latitude   = 0;    // currently not supported
    res->longitude  = 0;    // currently not supported
}

void RequestParser::to_Ride( Ride * res, const generic_request::Request & r )
{
    to_GeoPosition( & res->position, r );

    basic_objects::Parser::to_LocalTime( & res->delivery_time, "DELIVERY_TIME", r );

    get_value_or_throw_double( res->max_weight, "MAX_WEIGHT", r );
}

void RequestParser::to_Address( Address * res, const generic_request::Request & r )
{
    get_value_or_throw_uint32( res->plz,    "PLZ", r );

    get_value_or_throw( res->city,          "CITY", r );
    get_value_or_throw( res->street,        "STREET", r );
    get_value_or_throw( res->house_number,  "HOUSE_NUMBER", r );
    r.get_value( "EAL", res->extra_address_line );
    get_value_or_throw( res->country,       "COUNTRY", r );
}

void RequestParser::to_ShoppingItem( ShoppingItem * res, const generic_request::Request & r )
{
    to_Id( & res->product_item_id, "PRODUCT_ITEM_ID", r );

    get_value_or_throw_uint32( res->amount,             "AMOUNT", r );
}

namespace web {

generic_protocol::ForwardMessage* RequestParser::to_forward_message( const generic_request::Request & r )
{
    auto type = RequestParser::detect_request_type( r );

    typedef request_type_e KeyType;
    typedef RequestParser Type;

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

    static const std::map<KeyType, PPMF> funcs =
    {
        { KeyType::GetProductItemListRequest,   & Type::to_GetProductItemListRequest },
        { KeyType::GetDeliveryRequestInfoRequest,     & Type::to_GetDeliveryRequestInfoRequest },
        { KeyType::GetShoppingListWithTotalsRequest,    & Type::to_GetShoppingListWithTotalsRequest },
        { KeyType::GetDashScreenUserRequest,    & Type::to_GetDashScreenUserRequest },
        { KeyType::GetDashScreenShopperRequest, & Type::to_GetDashScreenShopperRequest },
    };

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return ::shopndrop_protocol::RequestParser::to_forward_message( r );
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return Parser::to_request_type( cmd );
}

RequestParser::ForwardMessage * RequestParser::to_GetProductItemListRequest( const generic_request::Request & r )
{
    auto * res = new GetProductItemListRequest;

    generic_protocol::RequestParser::to_request( res, r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetDeliveryRequestInfoRequest( const generic_request::Request & r )
{
    auto * res = new GetDeliveryRequestInfoRequest;

    generic_protocol::RequestParser::to_request( res, r );

    ::shopndrop_protocol::RequestParser::to_Id( & res->ride_id, "RIDE_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetShoppingListWithTotalsRequest( const generic_request::Request & r )
{
    auto * res = new GetShoppingListWithTotalsRequest;

    generic_protocol::RequestParser::to_request( res, r );

    ::shopndrop_protocol::RequestParser::to_Id( & res->shopping_list_id, "SHOPPING_LIST_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetDashScreenUserRequest( const generic_request::Request & r )
{
    auto * res = new GetDashScreenUserRequest;

    generic_protocol::RequestParser::to_request( res, r );

    ::shopndrop_protocol::RequestParser::to_Id( & res->user_id, "USER_ID", r );

    RequestValidator::validate( * res );

    return res;
}

RequestParser::ForwardMessage * RequestParser::to_GetDashScreenShopperRequest( const generic_request::Request & r )
{
    auto * res = new GetDashScreenShopperRequest;

    generic_protocol::RequestParser::to_request( res, r );

    ::shopndrop_protocol::RequestParser::to_Id( & res->user_id, "USER_ID", r );

    RequestValidator::validate( * res );

    return res;
}


} // namespace web

} // namespace shopndrop_protocol
