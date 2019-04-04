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

// $Revision: 10767 $ $Date:: 2019-04-05 #$ $Author: serge $

#ifndef LIB_SHOPNDROP_PROTOCOL_CSV_RESPONSE_ENCODER_H
#define LIB_SHOPNDROP_PROTOCOL_CSV_RESPONSE_ENCODER_H

#include "shopndrop_protocol.h"     // ProductItem, ...
#include <sstream>                  // std::ostream

namespace shopndrop_protocol {

class CsvResponseEncoder
{
public:
    static std::ostream & write( std::ostream & os, const ProductItem & r );
    static std::ostream & write( std::ostream & os, const ShoppingItem & r );
    static std::ostream & write( std::ostream & os, const ShoppingList & r );
    static std::ostream & write( std::ostream & os, const Ride & r );
    static std::ostream & write( std::ostream & os, const Address & r );
    static std::ostream & write( std::ostream & os, const Order & r );
    static std::ostream & write( std::ostream & os, order_status_e r );
    static std::ostream & write( std::ostream & os, const web::ProductItemWithId & r );
    static std::ostream & write( std::ostream & os, const web::ShoppingItemWithProduct & r );
    static std::ostream & write( std::ostream & os, const web::ShoppingList & r );
    static std::ostream & write( std::ostream & os, const web::ShoppingListWithTotals & r );
    static std::ostream & write( std::ostream & os, const web::RideWithShopper & r );
    static std::ostream & write( std::ostream & os, const web::RideWithRequests & r );
    static std::ostream & write( std::ostream & os, const web::OrderRequestInfo & r );
    static std::ostream & write( std::ostream & os, const web::AcceptedOrderUser & r );
    static std::ostream & write( std::ostream & os, const web::AcceptedOrderShopper & r );
    static std::ostream & write( std::ostream & os, const web::DashScreenUser & r );
    static std::ostream & write( std::ostream & os, const web::DashScreenShopper & r );
    static std::string to_csv( const AddRideResponse & r );
    static std::string to_csv( const CancelRideResponse & r );
    static std::string to_csv( const CancelOrderResponse & r );
    static std::string to_csv( const GetPersonalUserInfoResponse & r );
    static std::string to_csv( const generic_protocol::BackwardMessage & r );
    static std::string to_csv( const web::GetProductItemListResponse & r );
    static std::string to_csv( const web::GetRideOrderInfoResponse & r );
    static std::string to_csv( const web::GetDashScreenUserResponse & r );
    static std::string to_csv( const web::GetDashScreenShopperResponse & r );
};

} // namespace shopndrop_protocol

#endif // LIB_SHOPNDROP_PROTOCOL_CSV_RESPONSE_ENCODER_H
