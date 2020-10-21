<?php

namespace shopndrop_protocol;


// base include
require_once __DIR__.'/../generic_protocol/str_helper.php';
// includes
require_once __DIR__.'/../basic_objects/str_helper.php';
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

function to_string__ride_resolution_e( $r )
{
    $map = array
    (
        ride_resolution_e__UNDEF => 'UNDEF',
        ride_resolution_e__EXPIRED_OR_COMPLETED => 'EXPIRED_OR_COMPLETED',
        ride_resolution_e__CANCELLED => 'CANCELLED',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__order_resolution_e( $r )
{
    $map = array
    (
        order_resolution_e__UNDEF => 'UNDEF',
        order_resolution_e__DELIVERED => 'DELIVERED',
        order_resolution_e__DECLINED_BY_SHOPPER => 'DECLINED_BY_SHOPPER',
        order_resolution_e__RIDE_CANCELLED => 'RIDE_CANCELLED',
        order_resolution_e__CANCELLED_BY_SHOPPER => 'CANCELLED_BY_SHOPPER',
        order_resolution_e__CANCELLED_BY_USER => 'CANCELLED_BY_USER',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__order_state_e( $r )
{
    $map = array
    (
        order_state_e__UNDEF => 'UNDEF',
        order_state_e__IDLE_WAITING_ACCEPTANCE => 'IDLE_WAITING_ACCEPTANCE',
        order_state_e__ACCEPTED_WAITING_DELIVERY => 'ACCEPTED_WAITING_DELIVERY',
        order_state_e__DELIVERED_WAITING_FEEDBACK => 'DELIVERED_WAITING_FEEDBACK',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__gender_e( $r )
{
    $map = array
    (
        gender_e__UNDEF => 'UNDEF',
        gender_e__MALE => 'MALE',
        gender_e__FEMALE => 'FEMALE',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

// objects

function to_string__ProductItem( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " name=" . \basic_parser\to_string__string( $r->name );
    $res .= " unit=" . \basic_parser\to_string__string( $r->unit );
    $res .= " price=" . \basic_parser\to_string__float( $r->price );
    $res .= " weight=" . \basic_parser\to_string__float( $r->weight );

    $res .= ")";

    return $res;
}

function to_string__ShoppingItem( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " product_item_id=" . \basic_parser\to_string__int( $r->product_item_id );
    $res .= " amount=" . \basic_parser\to_string__int( $r->amount );

    $res .= ")";

    return $res;
}

function to_string__ShoppingList( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " items=" . \basic_parser\to_string__vector( $r->items, '\shopndrop_protocol\to_string__ShoppingItem' ); // Array

    $res .= ")";

    return $res;
}

function to_string__GeoPosition( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " plz=" . \basic_parser\to_string__int( $r->plz );
    $res .= " latitude=" . \basic_parser\to_string__float( $r->latitude );
    $res .= " longitude=" . \basic_parser\to_string__float( $r->longitude );

    $res .= ")";

    return $res;
}

function to_string__RideSummary( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " position=" . to_string__GeoPosition( $r->position );
    $res .= " delivery_time=" . \basic_objects\to_string__LocalTime( $r->delivery_time );
    $res .= " max_weight=" . \basic_parser\to_string__float( $r->max_weight );

    $res .= ")";

    return $res;
}

function to_string__Ride( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " is_open=" . \basic_parser\to_string__bool( $r->is_open );
    $res .= " summary=" . to_string__RideSummary( $r->summary );
    $res .= " pending_order_ids=" . \basic_parser\to_string__vector( $r->pending_order_ids, '\basic_parser\to_string__int' ); // Array
    $res .= " accepted_order_id=" . \basic_parser\to_string__int( $r->accepted_order_id );
    $res .= " resolution=" . to_string__ride_resolution_e( $r->resolution );

    $res .= ")";

    return $res;
}

function to_string__Address( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " plz=" . \basic_parser\to_string__int( $r->plz );
    $res .= " country=" . \basic_parser\to_string__string( $r->country );
    $res .= " city=" . \basic_parser\to_string__string( $r->city );
    $res .= " street=" . \basic_parser\to_string__string( $r->street );
    $res .= " house_number=" . \basic_parser\to_string__string( $r->house_number );
    $res .= " extra_address_line=" . \basic_parser\to_string__string( $r->extra_address_line );

    $res .= ")";

    return $res;
}

function to_string__Order( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " is_open=" . \basic_parser\to_string__bool( $r->is_open );
    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );
    $res .= " delivery_address=" . to_string__Address( $r->delivery_address );
    $res .= " shopping_list_id=" . \basic_parser\to_string__int( $r->shopping_list_id );
    $res .= " state=" . to_string__order_state_e( $r->state );
    $res .= " resolution=" . to_string__order_resolution_e( $r->resolution );

    $res .= ")";

    return $res;
}

// base messages

function to_string__Request( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= \generic_protocol\to_string__Request( $r );


    $res .= ")";

    return $res;
}

// messages

function to_string__AddRideRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " ride=" . to_string__RideSummary( $r->ride );

    return $res;
}

function to_string__AddRideResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );

    return $res;
}

function to_string__CancelRideRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );

    return $res;
}

function to_string__CancelRideResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetRideRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );

    return $res;
}

function to_string__GetRideResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " ride=" . to_string__Ride( $r->ride );

    return $res;
}

function to_string__AddOrderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );
    $res .= " shopping_list=" . to_string__ShoppingList( $r->shopping_list );
    $res .= " delivery_address=" . to_string__Address( $r->delivery_address );

    return $res;
}

function to_string__AddOrderResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );

    return $res;
}

function to_string__CancelOrderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );

    return $res;
}

function to_string__CancelOrderResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

function to_string__AcceptOrderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );

    return $res;
}

function to_string__AcceptOrderResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

function to_string__DeclineOrderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );

    return $res;
}

function to_string__DeclineOrderResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

function to_string__MarkDeliveredOrderRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );

    return $res;
}

function to_string__MarkDeliveredOrderResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

function to_string__RateShopperRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );
    $res .= " stars=" . \basic_parser\to_string__int( $r->stars );

    return $res;
}

function to_string__RateShopperResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'shopndrop_protocol\ProductItem'         => 'to_string__ProductItem',
        'shopndrop_protocol\ShoppingItem'         => 'to_string__ShoppingItem',
        'shopndrop_protocol\ShoppingList'         => 'to_string__ShoppingList',
        'shopndrop_protocol\GeoPosition'         => 'to_string__GeoPosition',
        'shopndrop_protocol\RideSummary'         => 'to_string__RideSummary',
        'shopndrop_protocol\Ride'         => 'to_string__Ride',
        'shopndrop_protocol\Address'         => 'to_string__Address',
        'shopndrop_protocol\Order'         => 'to_string__Order',
        // messages
        'shopndrop_protocol\AddRideRequest'         => 'to_string__AddRideRequest',
        'shopndrop_protocol\AddRideResponse'         => 'to_string__AddRideResponse',
        'shopndrop_protocol\CancelRideRequest'         => 'to_string__CancelRideRequest',
        'shopndrop_protocol\CancelRideResponse'         => 'to_string__CancelRideResponse',
        'shopndrop_protocol\GetRideRequest'         => 'to_string__GetRideRequest',
        'shopndrop_protocol\GetRideResponse'         => 'to_string__GetRideResponse',
        'shopndrop_protocol\AddOrderRequest'         => 'to_string__AddOrderRequest',
        'shopndrop_protocol\AddOrderResponse'         => 'to_string__AddOrderResponse',
        'shopndrop_protocol\CancelOrderRequest'         => 'to_string__CancelOrderRequest',
        'shopndrop_protocol\CancelOrderResponse'         => 'to_string__CancelOrderResponse',
        'shopndrop_protocol\AcceptOrderRequest'         => 'to_string__AcceptOrderRequest',
        'shopndrop_protocol\AcceptOrderResponse'         => 'to_string__AcceptOrderResponse',
        'shopndrop_protocol\DeclineOrderRequest'         => 'to_string__DeclineOrderRequest',
        'shopndrop_protocol\DeclineOrderResponse'         => 'to_string__DeclineOrderResponse',
        'shopndrop_protocol\MarkDeliveredOrderRequest'         => 'to_string__MarkDeliveredOrderRequest',
        'shopndrop_protocol\MarkDeliveredOrderResponse'         => 'to_string__MarkDeliveredOrderResponse',
        'shopndrop_protocol\RateShopperRequest'         => 'to_string__RateShopperRequest',
        'shopndrop_protocol\RateShopperResponse'         => 'to_string__RateShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_string( $obj );
}

// namespace_end shopndrop_protocol


?>
