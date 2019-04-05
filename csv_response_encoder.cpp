/*

CSV response encoder.

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

// $Revision: 10771 $ $Date:: 2019-04-05 #$ $Author: serge $

#include "csv_response_encoder.h"       // self

#include <typeinfo>                     // typeid

#include "utils/nonascii_hex_codec.h"   // nonascii_hex_codec
#include "utils/csv_helper.h"           // CsvHelper
#include "utils/utils_assert.h"         // ASSERT

#include "generic_protocol/csv_helper.h"    // generic_protocol::CsvHelper::to_csv()
#include "basic_objects/csv_helper.h"       // basic_objects::CsvHelper::write()

#include "str_helper.h"

#define MODULENAME      "shopndrop_protocol::CsvResponseEncoder"

namespace shopndrop_protocol {

std::string CsvResponseEncoder::to_csv( const generic_protocol::BackwardMessage & r )
{
    if( typeid( r ) == typeid( CancelRideResponse ) )
    {
        return to_csv( static_cast<const CancelRideResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( CancelOrderResponse ) )
    {
        return to_csv( static_cast<const CancelOrderResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( AddRideResponse ) )
    {
        return to_csv( static_cast<const AddRideResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( web::GetRideOrderInfoResponse ) )
    {
        return to_csv( static_cast<const web::GetRideOrderInfoResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetPersonalUserInfoResponse ) )
    {
        return to_csv( static_cast<const GetPersonalUserInfoResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( web::GetProductItemListResponse ) )
    {
        return to_csv( static_cast<const web::GetProductItemListResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( web::GetDashScreenUserResponse ) )
    {
        return to_csv( static_cast<const web::GetDashScreenUserResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( web::GetDashScreenShopperResponse ) )
    {
        return to_csv( static_cast<const web::GetDashScreenShopperResponse&>( r ) );
    }
    else
    {
        return generic_protocol::CsvHelper::to_csv( r );
    }
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const Order & r )
{

    basic_objects::CsvHelper::write( os, r.delivery_time );
    utils::CsvHelper::write(
            os,
            r.shopping_list_id,
            r.sum );

    write( os, r.status );

    return os;
}

static std::ostream & CsvResponseEncoder::write( std::ostream & os, order_status_e r )
{
    utils::CsvHelper::write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::ProductItemWithId & r )
{
    utils::CsvHelper::write(
            os,
            r.product_item_id );

    write( os, r.product_item );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const ProductItem & r )
{
    return utils::CsvHelper::write(
            os,
            utils::nonascii_hex_codec::encode( r.name ),
            utils::nonascii_hex_codec::encode( r.unit ),
            r.price,
            r.weight );
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::ShoppingList & r )
{
    utils::CsvHelper::write_user_array<false>(
                os,
                r.items.begin(),
                r.items.end(),
                [](std::ostream & os, const web::ShoppingItemWithProduct & r ) { CsvResponseEncoder::write( os, r ); } );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::AcceptedOrderUser & r )
{
    utils::CsvHelper::write( os, r.order_id );

    write( os, r.order );

    utils::CsvHelper::write( os, utils::nonascii_hex_codec::encode( r.shopper_name ) );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::AcceptedOrderShopper & r )
{
    utils::CsvHelper::write( os, r.order_id );

    write( os, r.order );

    utils::CsvHelper::write(
            os,
            utils::nonascii_hex_codec::encode( r.address ),
            r.plz,
            r.earning,
            r.weight );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::DashScreenUser & r )
{
    basic_objects::CsvHelper::write( os, r.current_time );

    utils::CsvHelper::write_user_array<false>(
                os,
                r.rides.begin(),
                r.rides.end(),
                [](std::ostream & os, const web::RideWithShopper & r ) { CsvResponseEncoder::write( os, r ); } );

    utils::CsvHelper::write_user_array<false>(
                os,
                r.orders.begin(),
                r.orders.end(),
                [](std::ostream & os, const web::AcceptedOrderUser & r ) { CsvResponseEncoder::write( os, r ); } );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::DashScreenShopper & r )
{
    basic_objects::CsvHelper::write( os, r.current_time );

    utils::CsvHelper::write_user_array<false>(
                os,
                r.rides.begin(),
                r.rides.end(),
                [](std::ostream & os, const web::RideWithRequests & r ) { CsvResponseEncoder::write( os, r ); } );

    utils::CsvHelper::write_user_array<false>(
                os,
                r.orders.begin(),
                r.orders.end(),
                [](std::ostream & os, const web::AcceptedOrderShopper & r ) { CsvResponseEncoder::write( os, r ); } );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::OrderRequestInfo & r )
{
    return utils::CsvHelper::write(
            os,
            r.order_id,
            r.sum,
            r.earning,
            r.weight,
            r.plz,
            utils::nonascii_hex_codec::encode( r.address ) );
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const ShoppingList & r )
{
    utils::CsvHelper::write_user_array<false>(
                os,
                r.items.begin(),
                r.items.end(),
                [](std::ostream & os, const ShoppingItem & r ) { CsvResponseEncoder::write( os, r ); } );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const Ride & r )
{
    utils::CsvHelper::write( os, r.plz );
    basic_objects::CsvHelper::write( os, r.delivery_time );
    utils::CsvHelper::write( os, r.max_weight );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const ShoppingItem & r )
{
    utils::CsvHelper::write(
            os,
            r.product_item_id,
            r.amount );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const Address & r )
{
    utils::CsvHelper::write(
            os,
            r.plz,
            utils::nonascii_hex_codec::encode( r.city ),
            utils::nonascii_hex_codec::encode( r.street ),
            utils::nonascii_hex_codec::encode( r.house_number ),
            utils::nonascii_hex_codec::encode( r.extra_address_line ),
            utils::nonascii_hex_codec::encode( r.country ) );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::RideWithShopper & r )
{
    utils::CsvHelper::write( os, r.ride_id );

    write( os, r.ride );

    utils::CsvHelper::write( os, utils::nonascii_hex_codec::encode( r.shopper_name ) );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::ShoppingItemWithProduct & e )
{
    write( os, e.shopping_item );
    write( os, e.product_item );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::RideWithRequests & r )
{
    utils::CsvHelper::write( os, r.ride_id );

    write( os, r.ride );

    utils::CsvHelper::write( os, r.num_requests );

    return os;
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const web::ShoppingListWithTotals & r )
{
    write( os, r.shopping_list );

    utils::CsvHelper::write(
            os,
            r.price,
            r.weight );

    return os;
}

std::string CsvResponseEncoder::to_csv( const AddRideResponse & r )
{
    return utils::CsvHelper::to_csv( "AddRideResponse", r.ride_id );
}

std::string CsvResponseEncoder::to_csv( const CancelRideResponse & r )
{
    return utils::CsvHelper::to_csv( "CancelRideResponse" );
}

std::string CsvResponseEncoder::to_csv( const CancelOrderResponse & r )
{
    return utils::CsvHelper::to_csv( "CancelOrderResponse" );
}

std::string CsvResponseEncoder::to_csv( const web::GetRideOrderInfoResponse & r )
{
    std::ostringstream os;

    utils::CsvHelper::write(
            os,
            "web/GetRideOrderInfoResponse" ) ;

    utils::CsvHelper::write_user_array(
            os,
            r.rides.begin(),
            r.rides.end(),
            [](std::ostream & os, const web::OrderRequestInfo & r) { CsvResponseEncoder::write( os, r ); } );

    return os.str();
}

std::string CsvResponseEncoder::to_csv( const GetPersonalUserInfoResponse & r )
{
    return utils::CsvHelper::to_csv(
            "GetPersonalUserInfoResponse",
            r.user_id,
            static_cast<uint32_t>( r.gender ),
            r.first_name, r.last_name, r.company_name,
            r.email, r.phone, r.timezone );
}

std::string CsvResponseEncoder::to_csv( const web::GetProductItemListResponse & r )
{
    std::ostringstream os;

    utils::CsvHelper::write(
            os,
            "web/GetProductItemListResponse" ) ;

    utils::CsvHelper::write_user_array(
            os,
            r.product_items.begin(),
            r.product_items.end(),
            [](std::ostream & os, const web::ProductItemWithId & r) { CsvResponseEncoder::write( os, r ); } );

    return os.str();
}

std::string CsvResponseEncoder::to_csv( const web::GetDashScreenUserResponse & r )
{
    std::ostringstream os;

    utils::CsvHelper::write(
            os,
            "web/GetDashScreenUserResponse" ) ;

    write( os, r.dash_screen );

    return os.str();
}

std::string CsvResponseEncoder::to_csv( const web::GetDashScreenShopperResponse & r )
{
    std::ostringstream os;

    utils::CsvHelper::write(
            os,
            "web/GetDashScreenShopperResponse" ) ;

    write( os, r.dash_screen );

    return os.str();
}

} // namespace shopndrop_protocol
