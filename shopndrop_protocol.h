/*

Shopndrop Protocol messages.

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

// $Revision: 10718 $ $Date:: 2019-04-02 #$ $Author: serge $

#ifndef LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H
#define LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H

#include <cstdint>              // uint32_t
#include <map>                  // std::map
#include <vector>               // std::vector

#include "generic_protocol/generic_protocol.h"   // generic_protocol::Request
#include "basic_objects/basic_objects.h" // basic_objects::LocalTime

namespace shopndrop_protocol {

struct Request: public generic_protocol::Request
{
    virtual ~Request() {};
};

typedef uint32_t    id_t;

/**************************************************
 * OBJECTS
 **************************************************/

struct ProductItem
{
    std::string     name;
    std::string     unit;
    double          price;
    double          weight;
};

struct ShoppingItem
{
    id_t            product_item_id;
    uint32_t        amount;
};

struct ShoppingList
{
    std::vector<ShoppingItem>   items;
};


struct Ride
{
    uint32_t        plz;
    basic_objects::LocalTime delivery_time;
    double          max_weight;
};

enum class order_status_e
{
    CANCELLED                   = 0,
    WAITING_ACCEPTANCE          = 1,
    ACCEPTED_WAITING_DELIVERY   = 2,
    DELIVERED_WAITING_FEEDBACK  = 3,
    CLOSED_FEEDBACK_RECEIVED    = 4,
};

enum class gender_e
{
    UNDEF   = 0,
    MALE    = 1,
    FEMALE  = 2,
};

struct Address
{
    uint32_t    plz;
    std::string city;
    std::string street;
    std::string house_number;
    std::string extra_address_line;
    std::string country;
};

struct Order
{
    basic_objects::LocalTime delivery_time;
    id_t            shopping_list_id;
    double          sum;
    order_status_e  status;
};

/**************************************************
 * WEB OBJECTS
 **************************************************/

namespace web
{

struct ShoppingItemWithProduct
{
    ShoppingItem    shopping_item;
    ProductItem     product_item;
};

struct ShoppingList
{
    std::vector<ShoppingItemWithProduct>   items;
};

struct ShoppingListWithTotals
{
    ShoppingList    shopping_list;
    double          price;
    double          weight;
};

struct RideWithShopper
{
    id_t            ride_id;
    Ride            ride;
    std::string     shopper_name;
};

struct RideWithRequests
{
    id_t            ride_id;
    Ride            ride;
    uint32_t        num_requests;
};

struct OrderRequestInfo
{
    id_t            order_id;
    double          sum;
    double          earning;
    double          weight;
    uint32_t        plz;
    std::string     address;
};

struct AcceptedOrderUser
{
    id_t            order_id;
    Order           order;
    std::string     shopper_name;
};

struct AcceptedOrderShopper
{
    id_t            order_id;
    Order           order;
    std::string     address;
    uint32_t        plz;
    double          earning;
    double          weight;
};

struct DashScreenUser
{
    basic_objects::LocalTime        current_time;

    std::vector<RideWithShopper>        rides;
    std::vector<AcceptedOrderUser>      orders;
};

struct DashScreenShopper
{
    basic_objects::LocalTime        current_time;

    std::vector<RideWithRequests>   rides;
    std::vector<AcceptedOrderShopper>      orders;
};

}   // namespace web

/**************************************************
 * REQUESTS
 **************************************************/

struct GetPersonalUserInfoRequest: public Request
{
    id_t            user_id;
};

struct GetPersonalUserInfoResponse: public generic_protocol::BackwardMessage
{
    id_t            user_id;
    gender_e        gender;
    std::string     first_name;
    std::string     last_name;
    std::string     company_name;
    std::string     email;
    std::string     phone;
    std::string     timezone;
};

/**************************************************
 * WEB REQUESTS
 **************************************************/

namespace web
{
struct GetRideOrderInfoRequest: public Request
{
    id_t            ride_id;
};

struct GetRideOrderInfoResponse: public generic_protocol::BackwardMessage
{
    std::vector<OrderRequestInfo>    rides;
};
}

} // namespace shopndrop_protocol

#endif // LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H
