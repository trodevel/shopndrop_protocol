/*

Request Validator.

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

// $Revision: 10787 $ $Date:: 2019-04-06 #$ $Author: serge $


#include "request_validator.h"      // self

#include "request_parser.h"         // MalformedRequest

#include "generic_protocol/request_validator.h"     // generic_protocol::RequestValidator::validate
#include "basic_objects/validator.h"                // basic_objects::Validator::validate

namespace shopndrop_protocol {

bool RequestValidator::validate( const id_t & r, const std::string & key)
{
    if( r == 0 )
        throw RequestParser::MalformedRequest( key + " is 0" );

    return true;
}

bool RequestValidator::validate( const order_status_e & r )
{
    return true;
}

bool RequestValidator::validate( const ProductItem & r )
{
    return true;
}

bool RequestValidator::validate( const ShoppingItem & r )
{
    return true;
}

bool RequestValidator::validate( const ShoppingList & r )
{
    return true;
}

bool RequestValidator::validate( const Ride & r )
{
    basic_objects::Validator::validate( & r.delivery_time );

    return true;
}

bool RequestValidator::validate( const Address & r )
{
    return true;
}

bool RequestValidator::validate( const AddRideRequest & r )
{
    validate( r.ride );

    return generic_protocol::RequestValidator::validate( & r );
}

bool RequestValidator::validate( const CancelRideRequest & r )
{
    return generic_protocol::RequestValidator::validate( & r );
}

bool RequestValidator::validate( const GetRideRequest & r )
{
    return generic_protocol::RequestValidator::validate( & r );
}

bool RequestValidator::validate( const AddOrderRequest & r )
{
    return generic_protocol::RequestValidator::validate( & r );
}

bool RequestValidator::validate( const CancelOrderRequest & r )
{
    return generic_protocol::RequestValidator::validate( & r );
}

bool RequestValidator::validate( const GetPersonalUserInfoRequest & r )
{
    return generic_protocol::RequestValidator::validate( & r );
}

} // namespace shopndrop_protocol
