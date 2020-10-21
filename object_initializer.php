<?php

namespace shopndrop_protocol;


// base include
require_once __DIR__.'/../generic_protocol/object_initializer.php';
// own includes
require_once __DIR__.'/../shopndrop_protocol/protocol.php';

// objects

function initialize__ProductItem( & $res
    , $name // string
    , $unit // string
    , $price // double
    , $weight // double
 )
{
    $res->name = $name;
    $res->unit = $unit;
    $res->price = $price;
    $res->weight = $weight;
}

function initialize__ShoppingItem( & $res
    , $product_item_id // uint32_t
    , $amount // uint32_t
 )
{
    $res->product_item_id = $product_item_id;
    $res->amount = $amount;
}

function initialize__ShoppingList( & $res
    , $items // array<ShoppingItem>
 )
{
    $res->items = $items;
}

function initialize__GeoPosition( & $res
    , $plz // uint32_t
    , $latitude // double
    , $longitude // double
 )
{
    $res->plz = $plz;
    $res->latitude = $latitude;
    $res->longitude = $longitude;
}

function initialize__RideSummary( & $res
    , $position // GeoPosition
    , $delivery_time // basic_objects\LocalTime
    , $max_weight // double
 )
{
    $res->position = $position;
    $res->delivery_time = $delivery_time;
    $res->max_weight = $max_weight;
}

function initialize__Ride( & $res
    , $is_open // bool
    , $summary // RideSummary
    , $pending_order_ids // array<uint32_t>
    , $accepted_order_id // uint32_t
    , $resolution // ride_resolution_e
 )
{
    $res->is_open = $is_open;
    $res->summary = $summary;
    $res->pending_order_ids = $pending_order_ids;
    $res->accepted_order_id = $accepted_order_id;
    $res->resolution = $resolution;
}

function initialize__Address( & $res
    , $plz // uint32_t
    , $country // string
    , $city // string
    , $street // string
    , $house_number // string
    , $extra_address_line // string
 )
{
    $res->plz = $plz;
    $res->country = $country;
    $res->city = $city;
    $res->street = $street;
    $res->house_number = $house_number;
    $res->extra_address_line = $extra_address_line;
}

function initialize__Order( & $res
    , $is_open // bool
    , $ride_id // uint32_t
    , $delivery_address // Address
    , $shopping_list_id // uint32_t
    , $state // order_state_e
    , $resolution // order_resolution_e
 )
{
    $res->is_open = $is_open;
    $res->ride_id = $ride_id;
    $res->delivery_address = $delivery_address;
    $res->shopping_list_id = $shopping_list_id;
    $res->state = $state;
    $res->resolution = $resolution;
}

// base messages

function initialize__Request( & $res
    , $base_class_param_1 // string
 )
{
    // base class
    \generic_protocol\initialize__Request( $res, $base_class_param_1 );

}

// messages

function initialize__AddRideRequest( & $res
    , $base_class_param_1 // string
    , $ride // RideSummary
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->ride = $ride;
}

function initialize__AddRideResponse( & $res
    , $ride_id // uint32_t
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->ride_id = $ride_id;
}

function initialize__CancelRideRequest( & $res
    , $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->ride_id = $ride_id;
}

function initialize__CancelRideResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

function initialize__GetRideRequest( & $res
    , $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->ride_id = $ride_id;
}

function initialize__GetRideResponse( & $res
    , $ride // Ride
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->ride = $ride;
}

function initialize__AddOrderRequest( & $res
    , $base_class_param_1 // string
    , $ride_id // uint32_t
    , $shopping_list // ShoppingList
    , $delivery_address // Address
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->ride_id = $ride_id;
    $res->shopping_list = $shopping_list;
    $res->delivery_address = $delivery_address;
}

function initialize__AddOrderResponse( & $res
    , $order_id // uint32_t
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->order_id = $order_id;
}

function initialize__CancelOrderRequest( & $res
    , $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->order_id = $order_id;
}

function initialize__CancelOrderResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

function initialize__AcceptOrderRequest( & $res
    , $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->order_id = $order_id;
}

function initialize__AcceptOrderResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

function initialize__DeclineOrderRequest( & $res
    , $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->order_id = $order_id;
}

function initialize__DeclineOrderResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

function initialize__MarkDeliveredOrderRequest( & $res
    , $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->order_id = $order_id;
}

function initialize__MarkDeliveredOrderResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

function initialize__RateShopperRequest( & $res
    , $base_class_param_1 // string
    , $order_id // uint32_t
    , $stars // uint32_t
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->order_id = $order_id;
    $res->stars = $stars;
}

function initialize__RateShopperResponse( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

// objects (constructors)

function create__ProductItem(
    $name // string
    , $unit // string
    , $price // double
    , $weight // double
 )
{
    $res = new ProductItem;

    initialize__ProductItem( $res, $name, $unit, $price, $weight );

    return $res;
}

function create__ShoppingItem(
    $product_item_id // uint32_t
    , $amount // uint32_t
 )
{
    $res = new ShoppingItem;

    initialize__ShoppingItem( $res, $product_item_id, $amount );

    return $res;
}

function create__ShoppingList(
    $items // array<ShoppingItem>
 )
{
    $res = new ShoppingList;

    initialize__ShoppingList( $res, $items );

    return $res;
}

function create__GeoPosition(
    $plz // uint32_t
    , $latitude // double
    , $longitude // double
 )
{
    $res = new GeoPosition;

    initialize__GeoPosition( $res, $plz, $latitude, $longitude );

    return $res;
}

function create__RideSummary(
    $position // GeoPosition
    , $delivery_time // basic_objects\LocalTime
    , $max_weight // double
 )
{
    $res = new RideSummary;

    initialize__RideSummary( $res, $position, $delivery_time, $max_weight );

    return $res;
}

function create__Ride(
    $is_open // bool
    , $summary // RideSummary
    , $pending_order_ids // array<uint32_t>
    , $accepted_order_id // uint32_t
    , $resolution // ride_resolution_e
 )
{
    $res = new Ride;

    initialize__Ride( $res, $is_open, $summary, $pending_order_ids, $accepted_order_id, $resolution );

    return $res;
}

function create__Address(
    $plz // uint32_t
    , $country // string
    , $city // string
    , $street // string
    , $house_number // string
    , $extra_address_line // string
 )
{
    $res = new Address;

    initialize__Address( $res, $plz, $country, $city, $street, $house_number, $extra_address_line );

    return $res;
}

function create__Order(
    $is_open // bool
    , $ride_id // uint32_t
    , $delivery_address // Address
    , $shopping_list_id // uint32_t
    , $state // order_state_e
    , $resolution // order_resolution_e
 )
{
    $res = new Order;

    initialize__Order( $res, $is_open, $ride_id, $delivery_address, $shopping_list_id, $state, $resolution );

    return $res;
}

// messages (constructors)

function create__AddRideRequest(
    $base_class_param_1 // string
    , $ride // RideSummary
 )
{
    $res = new AddRideRequest;

    initialize__AddRideRequest( $res, $base_class_param_1, $ride );

    return $res;
}

function create__AddRideResponse(
    $ride_id // uint32_t
 )
{
    $res = new AddRideResponse;

    initialize__AddRideResponse( $res, $ride_id );

    return $res;
}

function create__CancelRideRequest(
    $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    $res = new CancelRideRequest;

    initialize__CancelRideRequest( $res, $base_class_param_1, $ride_id );

    return $res;
}

function create__CancelRideResponse(
 )
{
    $res = new CancelRideResponse;

    initialize__CancelRideResponse( $res );

    return $res;
}

function create__GetRideRequest(
    $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    $res = new GetRideRequest;

    initialize__GetRideRequest( $res, $base_class_param_1, $ride_id );

    return $res;
}

function create__GetRideResponse(
    $ride // Ride
 )
{
    $res = new GetRideResponse;

    initialize__GetRideResponse( $res, $ride );

    return $res;
}

function create__AddOrderRequest(
    $base_class_param_1 // string
    , $ride_id // uint32_t
    , $shopping_list // ShoppingList
    , $delivery_address // Address
 )
{
    $res = new AddOrderRequest;

    initialize__AddOrderRequest( $res, $base_class_param_1, $ride_id, $shopping_list, $delivery_address );

    return $res;
}

function create__AddOrderResponse(
    $order_id // uint32_t
 )
{
    $res = new AddOrderResponse;

    initialize__AddOrderResponse( $res, $order_id );

    return $res;
}

function create__CancelOrderRequest(
    $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    $res = new CancelOrderRequest;

    initialize__CancelOrderRequest( $res, $base_class_param_1, $order_id );

    return $res;
}

function create__CancelOrderResponse(
 )
{
    $res = new CancelOrderResponse;

    initialize__CancelOrderResponse( $res );

    return $res;
}

function create__AcceptOrderRequest(
    $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    $res = new AcceptOrderRequest;

    initialize__AcceptOrderRequest( $res, $base_class_param_1, $order_id );

    return $res;
}

function create__AcceptOrderResponse(
 )
{
    $res = new AcceptOrderResponse;

    initialize__AcceptOrderResponse( $res );

    return $res;
}

function create__DeclineOrderRequest(
    $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    $res = new DeclineOrderRequest;

    initialize__DeclineOrderRequest( $res, $base_class_param_1, $order_id );

    return $res;
}

function create__DeclineOrderResponse(
 )
{
    $res = new DeclineOrderResponse;

    initialize__DeclineOrderResponse( $res );

    return $res;
}

function create__MarkDeliveredOrderRequest(
    $base_class_param_1 // string
    , $order_id // uint32_t
 )
{
    $res = new MarkDeliveredOrderRequest;

    initialize__MarkDeliveredOrderRequest( $res, $base_class_param_1, $order_id );

    return $res;
}

function create__MarkDeliveredOrderResponse(
 )
{
    $res = new MarkDeliveredOrderResponse;

    initialize__MarkDeliveredOrderResponse( $res );

    return $res;
}

function create__RateShopperRequest(
    $base_class_param_1 // string
    , $order_id // uint32_t
    , $stars // uint32_t
 )
{
    $res = new RateShopperRequest;

    initialize__RateShopperRequest( $res, $base_class_param_1, $order_id, $stars );

    return $res;
}

function create__RateShopperResponse(
 )
{
    $res = new RateShopperResponse;

    initialize__RateShopperResponse( $res );

    return $res;
}

// namespace_end shopndrop_protocol


?>
