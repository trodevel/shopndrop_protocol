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

// $Revision: 10697 $ $Date:: 2019-03-31 #$ $Author: serge $

#ifndef LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H
#define LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H

#include <cstdint>              // uint32_t
#include <map>                  // std::map
#include <vector>               // std::vector

#include "generic_protocol/generic_protocol.h"   // generic_protocol::Request
#include "basic_objects/basic_objects.h" // basic_objects::TimeWindow
#include "voice_enum.h"         // voice_e
#include "urgency_enum.h"       // urgency_e

namespace shopndrop_protocol {

struct Request: public generic_protocol::Request
{
    virtual ~Request() {};
};

typedef uint32_t    id_t;

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

namespace web
{
struct ShoppingItem
{
    ::shopndrop_protocol::ShoppingItem shopping_item;
    ProductItem     product_item;
};
}

struct ShoppingList
{
    std::vector<ShoppingItem>   items;
};

namespace web
{
struct ShoppingList
{
    std::vector<ShoppingItem>   items;
};
}

struct Ride
{
    uint32_t        plz;
    basic_objects::LocalTime delivery_time;
    double          max_weight;
};

struct RideWithId
{
    id_t            id;
    Ride            ride;
};

namespace web
{
struct RideWithRequests
{
    RideWithId      ride;
    uint32_t        num_requests;
};
}

namespace web
{
struct RideRequest
{
    id_t            request_id;
    double          sum;
    double          earning;
    double          weight;
    uint32_t        plz;
    std::string     address;
};
}

struct GetPersonalUserInfoRequest: public Request
{
    id_t            user_id;
};

enum class gender_e
{
    UNDEF   = 0,
    MALE    = 1,
    FEMALE  = 2,
};

struct GetPersonalUserInfoResponse: public generic_protocol::BackwardMessage
{
    id_t            user_id;
    gender_e        gender;
    std::string     name;
    std::string     first_name;
    std::string     company_name;
    std::string     email;
    std::string     email_2;
    std::string     phone;
    std::string     phone_2;
    std::string     timezone;
};

} // namespace shopndrop_protocol

#endif // LIB_SHOPNDROP_PROTOCOL_SHOPNDROP_PROTOCOL_H
