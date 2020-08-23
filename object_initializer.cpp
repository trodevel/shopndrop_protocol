// includes
#include "object_initializer.h"
#include "generic_protocol/object_initializer.h"
#include "basic_objects/object_initializer.h"

namespace shopndrop_protocol
{

// objects

void initialize( ProductItem * res
    , const std::string &  name
    , const std::string &  unit
    , double price
    , double weight
 )
{
    res->name = name;
    res->unit = unit;
    res->price = price;
    res->weight = weight;
}

void initialize( ShoppingItem * res
    , uint32_t product_item_id
    , uint32_t amount
 )
{
    res->product_item_id = product_item_id;
    res->amount = amount;
}

void initialize( ShoppingList * res
    , const std::vector<ShoppingItem> &  items
 )
{
    res->items = items;
}

void initialize( GeoPosition * res
    , uint32_t plz
    , double latitude
    , double longitude
 )
{
    res->plz = plz;
    res->latitude = latitude;
    res->longitude = longitude;
}

void initialize( RideSummary * res
    , const GeoPosition &  position
    , const basic_objects::LocalTime &  delivery_time
    , double max_weight
 )
{
    res->position = position;
    res->delivery_time = delivery_time;
    res->max_weight = max_weight;
}

void initialize( Ride * res
    , bool is_open
    , const RideSummary &  summary
    , const std::vector<uint32_t> &  pending_order_ids
    , uint32_t accepted_order_id
    , ride_resolution_e resolution
 )
{
    res->is_open = is_open;
    res->summary = summary;
    res->pending_order_ids = pending_order_ids;
    res->accepted_order_id = accepted_order_id;
    res->resolution = resolution;
}

void initialize( Address * res
    , uint32_t plz
    , const std::string &  country
    , const std::string &  city
    , const std::string &  street
    , const std::string &  house_number
    , const std::string &  extra_address_line
 )
{
    res->plz = plz;
    res->country = country;
    res->city = city;
    res->street = street;
    res->house_number = house_number;
    res->extra_address_line = extra_address_line;
}

void initialize( Order * res
    , bool is_open
    , uint32_t ride_id
    , const Address &  delivery_address
    , uint32_t shopping_list_id
    , order_state_e state
    , order_resolution_e resolution
 )
{
    res->is_open = is_open;
    res->ride_id = ride_id;
    res->delivery_address = delivery_address;
    res->shopping_list_id = shopping_list_id;
    res->state = state;
    res->resolution = resolution;
}

// base messages

void initialize( Request * res
    , const std::string &  base_class_param_1
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::Request*>( res ), base_class_param_1 );

}

// messages

void initialize( AddRideRequest * res
    , const std::string &  base_class_param_1
    , const RideSummary &  ride
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->ride = ride;
}

void initialize( AddRideResponse * res
    , uint32_t ride_id
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->ride_id = ride_id;
}

void initialize( CancelRideRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->ride_id = ride_id;
}

void initialize( CancelRideResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

void initialize( GetRideRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->ride_id = ride_id;
}

void initialize( GetRideResponse * res
    , const Ride &  ride
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->ride = ride;
}

void initialize( AddOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
    , const ShoppingList &  shopping_list
    , const Address &  delivery_address
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->ride_id = ride_id;
    res->shopping_list = shopping_list;
    res->delivery_address = delivery_address;
}

void initialize( AddOrderResponse * res
    , uint32_t order_id
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->order_id = order_id;
}

void initialize( CancelOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->order_id = order_id;
}

void initialize( CancelOrderResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

void initialize( AcceptOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->order_id = order_id;
}

void initialize( AcceptOrderResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

void initialize( DeclineOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->order_id = order_id;
}

void initialize( DeclineOrderResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

void initialize( MarkDeliveredOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->order_id = order_id;
}

void initialize( MarkDeliveredOrderResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

void initialize( RateShopperRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
    , uint32_t stars
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->order_id = order_id;
    res->stars = stars;
}

void initialize( RateShopperResponse * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

// messages (constructors)

AddRideRequest * create_AddRideRequest(
    const std::string &  base_class_param_1
    , const RideSummary &  ride
 )
{
    auto * res = new AddRideRequest;

    initialize( res, base_class_param_1, ride );

    return res;
}

AddRideResponse * create_AddRideResponse(
    uint32_t ride_id
 )
{
    auto * res = new AddRideResponse;

    initialize( res, ride_id );

    return res;
}

CancelRideRequest * create_CancelRideRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    auto * res = new CancelRideRequest;

    initialize( res, base_class_param_1, ride_id );

    return res;
}

CancelRideResponse * create_CancelRideResponse(
 )
{
    auto * res = new CancelRideResponse;

    initialize( res );

    return res;
}

GetRideRequest * create_GetRideRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    auto * res = new GetRideRequest;

    initialize( res, base_class_param_1, ride_id );

    return res;
}

GetRideResponse * create_GetRideResponse(
    const Ride &  ride
 )
{
    auto * res = new GetRideResponse;

    initialize( res, ride );

    return res;
}

AddOrderRequest * create_AddOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
    , const ShoppingList &  shopping_list
    , const Address &  delivery_address
 )
{
    auto * res = new AddOrderRequest;

    initialize( res, base_class_param_1, ride_id, shopping_list, delivery_address );

    return res;
}

AddOrderResponse * create_AddOrderResponse(
    uint32_t order_id
 )
{
    auto * res = new AddOrderResponse;

    initialize( res, order_id );

    return res;
}

CancelOrderRequest * create_CancelOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    auto * res = new CancelOrderRequest;

    initialize( res, base_class_param_1, order_id );

    return res;
}

CancelOrderResponse * create_CancelOrderResponse(
 )
{
    auto * res = new CancelOrderResponse;

    initialize( res );

    return res;
}

AcceptOrderRequest * create_AcceptOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    auto * res = new AcceptOrderRequest;

    initialize( res, base_class_param_1, order_id );

    return res;
}

AcceptOrderResponse * create_AcceptOrderResponse(
 )
{
    auto * res = new AcceptOrderResponse;

    initialize( res );

    return res;
}

DeclineOrderRequest * create_DeclineOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    auto * res = new DeclineOrderRequest;

    initialize( res, base_class_param_1, order_id );

    return res;
}

DeclineOrderResponse * create_DeclineOrderResponse(
 )
{
    auto * res = new DeclineOrderResponse;

    initialize( res );

    return res;
}

MarkDeliveredOrderRequest * create_MarkDeliveredOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 )
{
    auto * res = new MarkDeliveredOrderRequest;

    initialize( res, base_class_param_1, order_id );

    return res;
}

MarkDeliveredOrderResponse * create_MarkDeliveredOrderResponse(
 )
{
    auto * res = new MarkDeliveredOrderResponse;

    initialize( res );

    return res;
}

RateShopperRequest * create_RateShopperRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
    , uint32_t stars
 )
{
    auto * res = new RateShopperRequest;

    initialize( res, base_class_param_1, order_id, stars );

    return res;
}

RateShopperResponse * create_RateShopperResponse(
 )
{
    auto * res = new RateShopperResponse;

    initialize( res );

    return res;
}

} // namespace shopndrop_protocol

