<?php

namespace shopndrop_protocol;


// includes
require_once __DIR__.'/../generic_protocol/html_helper.php';
require_once __DIR__.'/../basic_objects/html_helper.php';
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

function to_html_header__ride_resolution_e( $r )
{
    return array( 'RIDE_RESOLUTION_E' );
}

function to_html__ride_resolution_e( $r )
{
    return to_string__ride_resolution_e( $r ) . " (" . $r . ")";
}

function to_html_header__order_resolution_e( $r )
{
    return array( 'ORDER_RESOLUTION_E' );
}

function to_html__order_resolution_e( $r )
{
    return to_string__order_resolution_e( $r ) . " (" . $r . ")";
}

function to_html_header__order_state_e( $r )
{
    return array( 'ORDER_STATE_E' );
}

function to_html__order_state_e( $r )
{
    return to_string__order_state_e( $r ) . " (" . $r . ")";
}

function to_html_header__gender_e( $r )
{
    return array( 'GENDER_E' );
}

function to_html__gender_e( $r )
{
    return to_string__gender_e( $r ) . " (" . $r . ")";
}

// objects

function to_html__ProductItem( & $r )
{
    $header = array( 'NAME', 'UNIT', 'PRICE', 'WEIGHT' );

    $data = array(
        \basic_parser\to_html__string( $r->name ),
        \basic_parser\to_html__string( $r->unit ),
        \basic_parser\to_html__float( $r->price ),
        \basic_parser\to_html__float( $r->weight )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingItem( & $r )
{
    $header = array( 'PRODUCT_ITEM_ID', 'AMOUNT' );

    $data = array(
        \basic_parser\to_html__int( $r->product_item_id ),
        \basic_parser\to_html__int( $r->amount )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingList( & $r )
{
    $header = array( 'ITEMS' );

    $data = array(
        \basic_parser\to_html__vector( $r->items, '\shopndrop_protocol\to_html__ShoppingItem' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GeoPosition( & $r )
{
    $header = array( 'PLZ', 'LATITUDE', 'LONGITUDE' );

    $data = array(
        \basic_parser\to_html__int( $r->plz ),
        \basic_parser\to_html__float( $r->latitude ),
        \basic_parser\to_html__float( $r->longitude )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RideSummary( & $r )
{
    $header = array( 'POSITION', 'DELIVERY_TIME', 'MAX_WEIGHT' );

    $data = array(
        to_html__GeoPosition( $r->position ),
        \basic_objects\to_html__LocalTime( $r->delivery_time ),
        \basic_parser\to_html__float( $r->max_weight )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Ride( & $r )
{
    $header = array( 'IS_OPEN', 'SUMMARY', 'PENDING_ORDER_IDS', 'ACCEPTED_ORDER_ID', 'RESOLUTION' );

    $data = array(
        \basic_parser\to_html__bool( $r->is_open ),
        to_html__RideSummary( $r->summary ),
        \basic_parser\to_html__vector( $r->pending_order_ids, '\basic_parser\to_html__int' ),
        \basic_parser\to_html__int( $r->accepted_order_id ),
        to_html__ride_resolution_e( $r->resolution )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Address( & $r )
{
    $header = array( 'PLZ', 'COUNTRY', 'CITY', 'STREET', 'HOUSE_NUMBER', 'EXTRA_ADDRESS_LINE' );

    $data = array(
        \basic_parser\to_html__int( $r->plz ),
        \basic_parser\to_html__string( $r->country ),
        \basic_parser\to_html__string( $r->city ),
        \basic_parser\to_html__string( $r->street ),
        \basic_parser\to_html__string( $r->house_number ),
        \basic_parser\to_html__string( $r->extra_address_line )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Order( & $r )
{
    $header = array( 'IS_OPEN', 'RIDE_ID', 'DELIVERY_ADDRESS', 'SHOPPING_LIST_ID', 'STATE', 'RESOLUTION' );

    $data = array(
        \basic_parser\to_html__bool( $r->is_open ),
        \basic_parser\to_html__int( $r->ride_id ),
        to_html__Address( $r->delivery_address ),
        \basic_parser\to_html__int( $r->shopping_list_id ),
        to_html__order_state_e( $r->state ),
        to_html__order_resolution_e( $r->resolution )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

function to_html__Request( & $r )
{
    $header = array( 'generic_protocol::Request' );

    $data = array(
        \generic_protocol\to_html__Request( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// messages

function to_html__AddRideRequest( & $r )
{
    $header = array( 'Request', 'RIDE' );

    $data = array(
        to_html__Request( $r ),
        to_html__RideSummary( $r->ride )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddRideResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'RIDE_ID' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->ride_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelRideRequest( & $r )
{
    $header = array( 'Request', 'RIDE_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->ride_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelRideResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetRideRequest( & $r )
{
    $header = array( 'Request', 'RIDE_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->ride_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetRideResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'RIDE' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        to_html__Ride( $r->ride )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddOrderRequest( & $r )
{
    $header = array( 'Request', 'RIDE_ID', 'SHOPPING_LIST', 'DELIVERY_ADDRESS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->ride_id ),
        to_html__ShoppingList( $r->shopping_list ),
        to_html__Address( $r->delivery_address )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AddOrderResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'ORDER_ID' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->order_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelOrderRequest( & $r )
{
    $header = array( 'Request', 'ORDER_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->order_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CancelOrderResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AcceptOrderRequest( & $r )
{
    $header = array( 'Request', 'ORDER_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->order_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AcceptOrderResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeclineOrderRequest( & $r )
{
    $header = array( 'Request', 'ORDER_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->order_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DeclineOrderResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__MarkDeliveredOrderRequest( & $r )
{
    $header = array( 'Request', 'ORDER_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->order_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__MarkDeliveredOrderResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RateShopperRequest( & $r )
{
    $header = array( 'Request', 'ORDER_ID', 'STARS' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->order_id ),
        \basic_parser\to_html__int( $r->stars )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RateShopperResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'shopndrop_protocol\ProductItem'         => 'to_html__ProductItem',
        'shopndrop_protocol\ShoppingItem'         => 'to_html__ShoppingItem',
        'shopndrop_protocol\ShoppingList'         => 'to_html__ShoppingList',
        'shopndrop_protocol\GeoPosition'         => 'to_html__GeoPosition',
        'shopndrop_protocol\RideSummary'         => 'to_html__RideSummary',
        'shopndrop_protocol\Ride'         => 'to_html__Ride',
        'shopndrop_protocol\Address'         => 'to_html__Address',
        'shopndrop_protocol\Order'         => 'to_html__Order',
        // messages
        'shopndrop_protocol\AddRideRequest'         => 'to_html__AddRideRequest',
        'shopndrop_protocol\AddRideResponse'         => 'to_html__AddRideResponse',
        'shopndrop_protocol\CancelRideRequest'         => 'to_html__CancelRideRequest',
        'shopndrop_protocol\CancelRideResponse'         => 'to_html__CancelRideResponse',
        'shopndrop_protocol\GetRideRequest'         => 'to_html__GetRideRequest',
        'shopndrop_protocol\GetRideResponse'         => 'to_html__GetRideResponse',
        'shopndrop_protocol\AddOrderRequest'         => 'to_html__AddOrderRequest',
        'shopndrop_protocol\AddOrderResponse'         => 'to_html__AddOrderResponse',
        'shopndrop_protocol\CancelOrderRequest'         => 'to_html__CancelOrderRequest',
        'shopndrop_protocol\CancelOrderResponse'         => 'to_html__CancelOrderResponse',
        'shopndrop_protocol\AcceptOrderRequest'         => 'to_html__AcceptOrderRequest',
        'shopndrop_protocol\AcceptOrderResponse'         => 'to_html__AcceptOrderResponse',
        'shopndrop_protocol\DeclineOrderRequest'         => 'to_html__DeclineOrderRequest',
        'shopndrop_protocol\DeclineOrderResponse'         => 'to_html__DeclineOrderResponse',
        'shopndrop_protocol\MarkDeliveredOrderRequest'         => 'to_html__MarkDeliveredOrderRequest',
        'shopndrop_protocol\MarkDeliveredOrderResponse'         => 'to_html__MarkDeliveredOrderResponse',
        'shopndrop_protocol\RateShopperRequest'         => 'to_html__RateShopperRequest',
        'shopndrop_protocol\RateShopperResponse'         => 'to_html__RateShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

# namespace_end shopndrop_protocol


?>
