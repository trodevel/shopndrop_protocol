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

#include "shopndrop_protocol.h"    // Request...

namespace shopndrop_protocol {

class RequestValidator
{
public:
    static bool validate( const id_t & r, const std::string & key );
    static bool validate( const order_status_e & r );
    static bool validate( const ProductItem & r );
    static bool validate( const ShoppingItem & r );
    static bool validate( const ShoppingList & r );
    static bool validate( const Ride & r );
    static bool validate( const Address & r );
    static bool validate( const AddRideRequest & r );
    static bool validate( const CancelRideRequest & r );
    static bool validate( const GetRideRequest & r );
    static bool validate( const AddOrderRequest & r );
    static bool validate( const CancelOrderRequest & r );
    static bool validate( const GetPersonalUserInfoRequest & r );
};

namespace web {

class RequestValidator
{
public:
    static bool validate( const GetProductItemListRequest & r );
    static bool validate( const GetRideOrderInfoRequest & r );
    static bool validate( const GetDashScreenUserRequest & r );
    static bool validate( const GetDashScreenShopperRequest & r );
};

} // namespace web

} // namespace shopndrop_protocol
