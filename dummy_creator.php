<?php

namespace shopndrop_protocol;


// includes
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once __DIR__.'/../basic_objects/dummy_creator.php';
require_once 'object_initializer.php';

// enums

function create_dummy__ride_resolution_e()
{
    $SIZE = 3;

    $values = array( ride_resolution_e__UNDEF, ride_resolution_e__EXPIRED_OR_COMPLETED, ride_resolution_e__CANCELLED,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

function create_dummy__order_resolution_e()
{
    $SIZE = 6;

    $values = array( order_resolution_e__UNDEF, order_resolution_e__DELIVERED, order_resolution_e__DECLINED_BY_SHOPPER, order_resolution_e__RIDE_CANCELLED, order_resolution_e__CANCELLED_BY_SHOPPER, order_resolution_e__CANCELLED_BY_USER,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

function create_dummy__order_state_e()
{
    $SIZE = 4;

    $values = array( order_state_e__UNDEF, order_state_e__IDLE_WAITING_ACCEPTANCE, order_state_e__ACCEPTED_WAITING_DELIVERY, order_state_e__DELIVERED_WAITING_FEEDBACK,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

function create_dummy__gender_e()
{
    $SIZE = 3;

    $values = array( gender_e__UNDEF, gender_e__MALE, gender_e__FEMALE,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

// objects

function create_dummy__ProductItem()
{
    $res = new ProductItem;

    initialize__ProductItem( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        );
    return $res;
}

function create_dummy__ShoppingItem()
{
    $res = new ShoppingItem;

    initialize__ShoppingItem( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__ShoppingList()
{
    $res = new ShoppingList;

    initialize__ShoppingList( $res
        , \basic_parser\create_dummy__vector( '\shopndrop_protocol\create_dummy__ShoppingItem' ) // Array
        );
    return $res;
}

function create_dummy__GeoPosition()
{
    $res = new GeoPosition;

    initialize__GeoPosition( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        );
    return $res;
}

function create_dummy__RideSummary()
{
    $res = new RideSummary;

    initialize__RideSummary( $res
        , create_dummy__GeoPosition()
        , \basic_objects\create_dummy__LocalTime()
        , \basic_parser\create_dummy__float()
        );
    return $res;
}

function create_dummy__Ride()
{
    $res = new Ride;

    initialize__Ride( $res
        , \basic_parser\create_dummy__bool()
        , create_dummy__RideSummary()
        , \basic_parser\create_dummy__vector( '\basic_parser\create_dummy__int32' ) // Array
        , \basic_parser\create_dummy__int32()
        , create_dummy__ride_resolution_e()
        );
    return $res;
}

function create_dummy__Address()
{
    $res = new Address;

    initialize__Address( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__Order()
{
    $res = new Order;

    initialize__Order( $res
        , \basic_parser\create_dummy__bool()
        , \basic_parser\create_dummy__int32()
        , create_dummy__Address()
        , \basic_parser\create_dummy__int32()
        , create_dummy__order_state_e()
        , create_dummy__order_resolution_e()
        );
    return $res;
}

// messages

function create_dummy__AddRideRequest()
{
    $res = new AddRideRequest;

    initialize__AddRideRequest( $res
        , \basic_parser\create_dummy__string()
        , create_dummy__RideSummary()
        );
    return $res;
}

function create_dummy__AddRideResponse()
{
    $res = new AddRideResponse;

    initialize__AddRideResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__CancelRideRequest()
{
    $res = new CancelRideRequest;

    initialize__CancelRideRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__CancelRideResponse()
{
    $res = new CancelRideResponse;

    initialize__CancelRideResponse( $res
        );
    return $res;
}

function create_dummy__GetRideRequest()
{
    $res = new GetRideRequest;

    initialize__GetRideRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetRideResponse()
{
    $res = new GetRideResponse;

    initialize__GetRideResponse( $res
        , create_dummy__Ride()
        );
    return $res;
}

function create_dummy__AddOrderRequest()
{
    $res = new AddOrderRequest;

    initialize__AddOrderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , create_dummy__ShoppingList()
        , create_dummy__Address()
        );
    return $res;
}

function create_dummy__AddOrderResponse()
{
    $res = new AddOrderResponse;

    initialize__AddOrderResponse( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__CancelOrderRequest()
{
    $res = new CancelOrderRequest;

    initialize__CancelOrderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__CancelOrderResponse()
{
    $res = new CancelOrderResponse;

    initialize__CancelOrderResponse( $res
        );
    return $res;
}

function create_dummy__AcceptOrderRequest()
{
    $res = new AcceptOrderRequest;

    initialize__AcceptOrderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__AcceptOrderResponse()
{
    $res = new AcceptOrderResponse;

    initialize__AcceptOrderResponse( $res
        );
    return $res;
}

function create_dummy__DeclineOrderRequest()
{
    $res = new DeclineOrderRequest;

    initialize__DeclineOrderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__DeclineOrderResponse()
{
    $res = new DeclineOrderResponse;

    initialize__DeclineOrderResponse( $res
        );
    return $res;
}

function create_dummy__MarkDeliveredOrderRequest()
{
    $res = new MarkDeliveredOrderRequest;

    initialize__MarkDeliveredOrderRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__MarkDeliveredOrderResponse()
{
    $res = new MarkDeliveredOrderResponse;

    initialize__MarkDeliveredOrderResponse( $res
        );
    return $res;
}

function create_dummy__RateShopperRequest()
{
    $res = new RateShopperRequest;

    initialize__RateShopperRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__RateShopperResponse()
{
    $res = new RateShopperResponse;

    initialize__RateShopperResponse( $res
        );
    return $res;
}

# namespace_end shopndrop_protocol


?>
