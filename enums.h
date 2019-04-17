/*

Core enums.

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

// $Revision: 10769 $ $Date:: 2019-04-05 #$ $Author: serge $

#ifndef SHOPNDROP_PROTOCOL_ENUMS_H
#define SHOPNDROP_PROTOCOL_ENUMS_H

namespace shopndrop_protocol {

enum class request_type_e
{
    UNDEF,
    AddRideRequest,
    CancelRideRequest,
    GetRideRequest,
    AddOrderRequest,
    CancelOrderRequest,
    GetPersonalUserInfoRequest,
};

namespace web {

enum class request_type_e
{
    UNDEF,
    GetProductItemListRequest,
    GetRideOrderInfoRequest,
    GetDashScreenUserRequest,
    GetDashScreenShopperRequest
};

} // namespace web

} // namespace shopndrop_protocol

#endif // SHOPNDROP_PROTOCOL_ENUMS_H
