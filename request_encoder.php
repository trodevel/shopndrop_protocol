<?php

namespace shopndrop_protocol;


// base include
require_once __DIR__.'/../generic_protocol/request_encoder.php';
// includes
require_once __DIR__.'/../basic_objects/request_encoder.php';
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

function to_generic_request__ride_resolution_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__order_resolution_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__order_state_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

function to_generic_request__gender_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

// objects

function to_generic_request__ProductItem( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".NAME", $r->name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".UNIT", $r->unit );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".PRICE", $r->price );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".WEIGHT", $r->weight );

    return $res;
}

function to_generic_request__ShoppingItem( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".PRODUCT_ITEM_ID", $r->product_item_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".AMOUNT", $r->amount );

    return $res;
}

function to_generic_request__ShoppingList( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".ITEMS", $r->items, '\shopndrop_protocol\to_generic_request__ShoppingItem' ); // Array

    return $res;
}

function to_generic_request__GeoPosition( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".PLZ", $r->plz );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".LATITUDE", $r->latitude );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".LONGITUDE", $r->longitude );

    return $res;
}

function to_generic_request__RideSummary( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__GeoPosition( $prefix . ".POSITION", $r->position );
    $res .= "&" . \basic_objects\to_generic_request__LocalTime( $prefix . ".DELIVERY_TIME", $r->delivery_time );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".MAX_WEIGHT", $r->max_weight );

    return $res;
}

function to_generic_request__Ride( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__bool( $prefix . ".IS_OPEN", $r->is_open );
    $res .= "&" . to_generic_request__RideSummary( $prefix . ".SUMMARY", $r->summary );
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".PENDING_ORDER_IDS", $r->pending_order_ids, '\basic_parser\to_generic_request__int' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".ACCEPTED_ORDER_ID", $r->accepted_order_id );
    $res .= "&" . to_generic_request__ride_resolution_e( $prefix . ".RESOLUTION", $r->resolution );

    return $res;
}

function to_generic_request__Address( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".PLZ", $r->plz );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".COUNTRY", $r->country );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".CITY", $r->city );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".STREET", $r->street );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".HOUSE_NUMBER", $r->house_number );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".EXTRA_ADDRESS_LINE", $r->extra_address_line );

    return $res;
}

function to_generic_request__Order( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__bool( $prefix . ".IS_OPEN", $r->is_open );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".RIDE_ID", $r->ride_id );
    $res .= "&" . to_generic_request__Address( $prefix . ".DELIVERY_ADDRESS", $r->delivery_address );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".SHOPPING_LIST_ID", $r->shopping_list_id );
    $res .= "&" . to_generic_request__order_state_e( $prefix . ".STATE", $r->state );
    $res .= "&" . to_generic_request__order_resolution_e( $prefix . ".RESOLUTION", $r->resolution );

    return $res;
}

// base messages

function to_generic_request__Request( & $r )
{
    $res = "";
    // base class
    $res .= \generic_protocol\to_generic_request__Request( $r );


    return $res;
}

// messages

function to_generic_request__AddRideRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AddRideRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . to_generic_request__RideSummary( "RIDE", $r->ride );

    return $res;
}

function to_generic_request__AddRideResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AddRideResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "RIDE_ID", $r->ride_id );

    return $res;
}

function to_generic_request__CancelRideRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/CancelRideRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "RIDE_ID", $r->ride_id );

    return $res;
}

function to_generic_request__CancelRideResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/CancelRideResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetRideRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/GetRideRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "RIDE_ID", $r->ride_id );

    return $res;
}

function to_generic_request__GetRideResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/GetRideResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__Ride( "RIDE", $r->ride );

    return $res;
}

function to_generic_request__AddOrderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AddOrderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "RIDE_ID", $r->ride_id );
    $res .= "&" . to_generic_request__ShoppingList( "SHOPPING_LIST", $r->shopping_list );
    $res .= "&" . to_generic_request__Address( "DELIVERY_ADDRESS", $r->delivery_address );

    return $res;
}

function to_generic_request__AddOrderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AddOrderResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );

    return $res;
}

function to_generic_request__CancelOrderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/CancelOrderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );

    return $res;
}

function to_generic_request__CancelOrderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/CancelOrderResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__AcceptOrderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AcceptOrderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );

    return $res;
}

function to_generic_request__AcceptOrderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/AcceptOrderResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__DeclineOrderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/DeclineOrderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );

    return $res;
}

function to_generic_request__DeclineOrderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/DeclineOrderResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__MarkDeliveredOrderRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/MarkDeliveredOrderRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );

    return $res;
}

function to_generic_request__MarkDeliveredOrderResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/MarkDeliveredOrderResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__RateShopperRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/RateShopperRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "ORDER_ID", $r->order_id );
    $res .= "&" . \basic_parser\to_generic_request__int( "STARS", $r->stars );

    return $res;
}

function to_generic_request__RateShopperResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_protocol/RateShopperResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'shopndrop_protocol\AddRideRequest'         => 'to_generic_request__AddRideRequest',
        'shopndrop_protocol\AddRideResponse'         => 'to_generic_request__AddRideResponse',
        'shopndrop_protocol\CancelRideRequest'         => 'to_generic_request__CancelRideRequest',
        'shopndrop_protocol\CancelRideResponse'         => 'to_generic_request__CancelRideResponse',
        'shopndrop_protocol\GetRideRequest'         => 'to_generic_request__GetRideRequest',
        'shopndrop_protocol\GetRideResponse'         => 'to_generic_request__GetRideResponse',
        'shopndrop_protocol\AddOrderRequest'         => 'to_generic_request__AddOrderRequest',
        'shopndrop_protocol\AddOrderResponse'         => 'to_generic_request__AddOrderResponse',
        'shopndrop_protocol\CancelOrderRequest'         => 'to_generic_request__CancelOrderRequest',
        'shopndrop_protocol\CancelOrderResponse'         => 'to_generic_request__CancelOrderResponse',
        'shopndrop_protocol\AcceptOrderRequest'         => 'to_generic_request__AcceptOrderRequest',
        'shopndrop_protocol\AcceptOrderResponse'         => 'to_generic_request__AcceptOrderResponse',
        'shopndrop_protocol\DeclineOrderRequest'         => 'to_generic_request__DeclineOrderRequest',
        'shopndrop_protocol\DeclineOrderResponse'         => 'to_generic_request__DeclineOrderResponse',
        'shopndrop_protocol\MarkDeliveredOrderRequest'         => 'to_generic_request__MarkDeliveredOrderRequest',
        'shopndrop_protocol\MarkDeliveredOrderResponse'         => 'to_generic_request__MarkDeliveredOrderResponse',
        'shopndrop_protocol\RateShopperRequest'         => 'to_generic_request__RateShopperRequest',
        'shopndrop_protocol\RateShopperResponse'         => 'to_generic_request__RateShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_generic_request( $obj );
}

// namespace_end shopndrop_protocol


?>
