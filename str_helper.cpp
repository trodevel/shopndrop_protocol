/*

String Helper. Provides to_string() function.

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

#include "str_helper.h"             // self

#include <sstream>                  // std::ostringstream
#include <iomanip>                  // std::setfill
#include <map>

#include "utils/to_string_t.h"       // to_string()

#include "basic_objects/str_helper.h"   // basic_objects::StrHelper

namespace shopndrop_protocol {

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

const std::string & StrHelper::to_string( const request_type_e s )
{
    typedef request_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( AddRideRequest ) },
        { Type:: TUPLE_VAL_STR( CancelRideRequest ) },
        { Type:: TUPLE_VAL_STR( GetRideRequest ) },
        { Type:: TUPLE_VAL_STR( AddOrderRequest ) },
        { Type:: TUPLE_VAL_STR( CancelOrderRequest ) },
        { Type:: TUPLE_VAL_STR( GetPersonalUserInfoRequest ) },
    };

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

const std::string & StrHelper::to_string( const order_state_e s )
{
    typedef order_state_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( IDLE_WAITING_ACCEPTANCE ) },
        { Type:: TUPLE_VAL_STR( ACCEPTED_WAITING_DELIVERY ) },
        { Type:: TUPLE_VAL_STR( DELIVERED_WAITING_FEEDBACK ) },
    };

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

const std::string & StrHelper::to_string( const order_resolution_e s )
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

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

std::ostream & StrHelper::write( std::ostream & os, const GeoPosition & l )
{
    os << "plz " << l.plz << " latitude " << l.latitude << " longitude " << l.longitude;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const Ride & l )
{
    write( os, l.position );
    os << " delivery_time ";
    basic_objects::StrHelper::write( os, l.delivery_time );
    os << " max_weight " << l.max_weight;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const AddRideRequest & l )
{
    os << "ride { ";
    write( os, l.ride );
    os <<  " }";

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const CancelRideRequest & l )
{
    os << "ride_id " << l.ride_id;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const GetRideRequest & l )
{
    os << "ride_id " << l.ride_id;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const AddOrderRequest & l )
{
    os << "ride_id " << l.ride_id;
    os << " shopping_list { ";
    os << " } ";

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const CancelOrderRequest & l )
{
    os << "order_id " << l.order_id;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const GetPersonalUserInfoRequest & l )
{
    os << "user_id " << l.user_id;

    return os;
}

} // namespace shopndrop_protocol


namespace shopndrop_protocol {

namespace web {

const std::string & StrHelper::to_string( const request_type_e s )
{
    typedef request_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( GetProductItemListRequest ) },
        { Type:: TUPLE_VAL_STR( GetDeliveryRequestInfoRequest ) },
        { Type:: TUPLE_VAL_STR( GetDashScreenUserRequest ) },
        { Type:: TUPLE_VAL_STR( GetDashScreenShopperRequest ) },
    };

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

std::ostream & StrHelper::write( std::ostream & os, const GetProductItemListRequest & l )
{
    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const GetDeliveryRequestInfoRequest & l )
{
    os << "ride_id " << l.ride_id;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const GetDashScreenUserRequest & l )
{
    os << "user_id " << l.user_id;

    return os;
}
std::ostream & StrHelper::write( std::ostream & os, const GetDashScreenShopperRequest & l )
{
    os << "user_id " << l.user_id;

    return os;
}

} // namespace web

} // namespace shopndrop_protocol
