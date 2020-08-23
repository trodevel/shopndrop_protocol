// includes
#include "dummy_creator.h"
#include "generic_protocol/dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "basic_objects/dummy_creator.h"
#include "object_initializer.h"

namespace shopndrop_protocol
{

namespace dummy
{

// enums

ride_resolution_e create__ride_resolution_e()
{
    static const unsigned SIZE = 3;

    static const ride_resolution_e values[SIZE] = { ride_resolution_e::UNDEF, ride_resolution_e::EXPIRED_OR_COMPLETED, ride_resolution_e::CANCELLED,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

order_resolution_e create__order_resolution_e()
{
    static const unsigned SIZE = 6;

    static const order_resolution_e values[SIZE] = { order_resolution_e::UNDEF, order_resolution_e::DELIVERED, order_resolution_e::DECLINED_BY_SHOPPER, order_resolution_e::RIDE_CANCELLED, order_resolution_e::CANCELLED_BY_SHOPPER, order_resolution_e::CANCELLED_BY_USER,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

order_state_e create__order_state_e()
{
    static const unsigned SIZE = 4;

    static const order_state_e values[SIZE] = { order_state_e::UNDEF, order_state_e::IDLE_WAITING_ACCEPTANCE, order_state_e::ACCEPTED_WAITING_DELIVERY, order_state_e::DELIVERED_WAITING_FEEDBACK,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

gender_e create__gender_e()
{
    static const unsigned SIZE = 3;

    static const gender_e values[SIZE] = { gender_e::UNDEF, gender_e::MALE, gender_e::FEMALE,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

// objects

ProductItem create__ProductItem()
{
    ProductItem res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        );

    return res;
}

ShoppingItem create__ShoppingItem()
{
    ShoppingItem res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

ShoppingList create__ShoppingList()
{
    ShoppingList res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__vector_t<ShoppingItem, ShoppingItem(*)()>( & dummy::create__ShoppingItem ) // Array
        );

    return res;
}

GeoPosition create__GeoPosition()
{
    GeoPosition res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        );

    return res;
}

RideSummary create__RideSummary()
{
    RideSummary res;

    ::shopndrop_protocol::initialize( & res
        , dummy::create__GeoPosition()
        , ::basic_objects::dummy::create__LocalTime()
        , ::basic_parser::dummy::create__double()
        );

    return res;
}

Ride create__Ride()
{
    Ride res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__bool()
        , dummy::create__RideSummary()
        , ::basic_parser::dummy::create__vector_t<uint32_t, uint32_t(*)()>( & ::basic_parser::dummy::create__uint32 ) // Array
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ride_resolution_e()
        );

    return res;
}

Address create__Address()
{
    Address res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

Order create__Order()
{
    Order res;

    ::shopndrop_protocol::initialize( & res
        , ::basic_parser::dummy::create__bool()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__Address()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__order_state_e()
        , dummy::create__order_resolution_e()
        );

    return res;
}

// messages

AddRideRequest * create__AddRideRequest()
{
    auto res = new AddRideRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , dummy::create__RideSummary()
        );

    return res;
}

AddRideResponse * create__AddRideResponse()
{
    auto res = new AddRideResponse;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

CancelRideRequest * create__CancelRideRequest()
{
    auto res = new CancelRideRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

CancelRideResponse * create__CancelRideResponse()
{
    auto res = new CancelRideResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

GetRideRequest * create__GetRideRequest()
{
    auto res = new GetRideRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetRideResponse * create__GetRideResponse()
{
    auto res = new GetRideResponse;

    ::shopndrop_protocol::initialize( res
        , dummy::create__Ride()
        );

    return res;
}

AddOrderRequest * create__AddOrderRequest()
{
    auto res = new AddOrderRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__ShoppingList()
        , dummy::create__Address()
        );

    return res;
}

AddOrderResponse * create__AddOrderResponse()
{
    auto res = new AddOrderResponse;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

CancelOrderRequest * create__CancelOrderRequest()
{
    auto res = new CancelOrderRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

CancelOrderResponse * create__CancelOrderResponse()
{
    auto res = new CancelOrderResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

AcceptOrderRequest * create__AcceptOrderRequest()
{
    auto res = new AcceptOrderRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

AcceptOrderResponse * create__AcceptOrderResponse()
{
    auto res = new AcceptOrderResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

DeclineOrderRequest * create__DeclineOrderRequest()
{
    auto res = new DeclineOrderRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

DeclineOrderResponse * create__DeclineOrderResponse()
{
    auto res = new DeclineOrderResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

MarkDeliveredOrderRequest * create__MarkDeliveredOrderRequest()
{
    auto res = new MarkDeliveredOrderRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

MarkDeliveredOrderResponse * create__MarkDeliveredOrderResponse()
{
    auto res = new MarkDeliveredOrderResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

RateShopperRequest * create__RateShopperRequest()
{
    auto res = new RateShopperRequest;

    ::shopndrop_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

RateShopperResponse * create__RateShopperResponse()
{
    auto res = new RateShopperResponse;

    ::shopndrop_protocol::initialize( res
        );

    return res;
}

} // namespace dummy

} // namespace shopndrop_protocol

