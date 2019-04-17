/*

Protocol response generator.

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

// $Revision: 10850 $ $Date:: 2019-04-18 #$ $Author: serge $

#ifndef LIB_SHOPNDROP_PROTOCOL_RESPONSE_GEN_H
#define LIB_SHOPNDROP_PROTOCOL_RESPONSE_GEN_H

#include "shopndrop_protocol.h"        // AddOrderResponse

namespace shopndrop_protocol {

inline AddRideResponse * create_AddRideResponse(
        id_t                            ride_id )
{
    auto * res = new AddRideResponse;

    res->ride_id    = ride_id;

    return res;
}

inline CancelRideResponse * create_CancelRideResponse()
{
    auto * res = new CancelRideResponse;

    return res;
}

inline Ride * init_Ride(
        Ride           * res,
        uint32_t        plz,
        const basic_objects::LocalTime & delivery_time,
        double          max_weight )
{
    res->plz            = plz;
    res->delivery_time  = delivery_time;
    res->max_weight     = max_weight;

    return res;
}

inline GetRideResponse * create_GetRideResponse(
        const Ride              & ride )
{
    auto * res = new GetRideResponse;

    res->ride   = ride;

    return res;
}

inline AddOrderResponse * create_AddOrderResponse( id_t order_id )
{
    auto * res = new AddOrderResponse;

    res->order_id   = order_id;

    return res;
}

inline CancelOrderResponse * create_CancelOrderResponse()
{
    auto * res = new CancelOrderResponse;

    return res;
}

inline GetPersonalUserInfoResponse * create_GetPersonalUserInfoResponse(
        id_t                user_id,
        gender_e            gender,
        const std::string   & first_name,
        const std::string   & last_name,
        const std::string   & company_name,
        const std::string   & email,
        const std::string   & phone,
        const std::string   & timezone )
{
    auto * res = new GetPersonalUserInfoResponse;

    res->user_id    = user_id;
    res->gender     = gender;
    res->first_name = first_name;
    res->last_name  = last_name;
    res->company_name = company_name;
    res->email      = email;
    res->phone      = phone;
    res->timezone   = timezone;

    return res;
}

} // namespace shopndrop_protocol

namespace shopndrop_protocol {

namespace web {

inline GetProductItemListResponse * create_GetProductItemListResponse(
        const std::vector<ProductItemWithId>  & product_items )
{
    auto * res = new GetProductItemListResponse;

    res->product_items  = product_items;

    return res;
}

inline GetRideOrderInfoResponse * create_GetRideOrderInfoResponse(
        const std::vector<OrderRequestInfo>    & rides )
{
    auto * res = new GetRideOrderInfoResponse;

    res->rides  = rides;

    return res;
}

inline GetDashScreenUserResponse * create_GetDashScreenUserResponse(
        const DashScreenUser & dash_screen )
{
    auto * res = new GetDashScreenUserResponse;

    res->dash_screen    = dash_screen;

    return res;
}

inline GetDashScreenShopperResponse * create_GetDashScreenShopperResponse(
        const DashScreenShopper & dash_screen )
{
    auto * res = new GetDashScreenShopperResponse;

    res->dash_screen    = dash_screen;

    return res;
}

inline DashScreenUser * init_DashScreenUser(
        DashScreenUser  * res,
        const basic_objects::LocalTime          & current_time,
        const std::vector<RideWithShopper>      & rides,
        const std::vector<AcceptedOrderUser>    & orders )
{
    res->current_time   = current_time;
    res->rides          = rides;
    res->orders         = orders;

    return res;
}

inline DashScreenShopper * init_DashScreenShopper(
        DashScreenShopper  * res,
        const basic_objects::LocalTime          & current_time,
        const std::vector<RideWithRequests>     & rides,
        const std::vector<AcceptedOrderShopper> & orders )
{
    res->current_time   = current_time;
    res->rides          = rides;
    res->orders         = orders;

    return res;
}

} // namespace web

} // namespace shopndrop_protocol

#endif // LIB_SHOPNDROP_PROTOCOL_RESPONSE_GEN_H
