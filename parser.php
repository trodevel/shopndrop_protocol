<?php

namespace shopndrop_protocol;


// includes
require_once __DIR__.'/../generic_protocol/parser.php';
require_once __DIR__.'/../basic_objects/parser.php';
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse__ride_resolution_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__order_resolution_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__order_state_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__gender_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// objects

function parse__ProductItem( & $csv_arr, & $offset )
{
    $res = new ProductItem;

    $res->name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->unit = \basic_parser\parse__string( $csv_arr, $offset );
    $res->price = \basic_parser\parse__float( $csv_arr, $offset );
    $res->weight = \basic_parser\parse__float( $csv_arr, $offset );

    return $res;
}

function parse__ShoppingItem( & $csv_arr, & $offset )
{
    $res = new ShoppingItem;

    $res->product_item_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->amount = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__ShoppingList( & $csv_arr, & $offset )
{
    $res = new ShoppingList;

    $res->items = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_protocol\parse__ShoppingItem' ); // Array

    return $res;
}

function parse__GeoPosition( & $csv_arr, & $offset )
{
    $res = new GeoPosition;

    $res->plz = \basic_parser\parse__int( $csv_arr, $offset );
    $res->latitude = \basic_parser\parse__float( $csv_arr, $offset );
    $res->longitude = \basic_parser\parse__float( $csv_arr, $offset );

    return $res;
}

function parse__RideSummary( & $csv_arr, & $offset )
{
    $res = new RideSummary;

    $res->position = parse__GeoPosition( $csv_arr, $offset );
    $res->delivery_time = \basic_objects\parse__LocalTime( $csv_arr, $offset );
    $res->max_weight = \basic_parser\parse__float( $csv_arr, $offset );

    return $res;
}

function parse__Ride( & $csv_arr, & $offset )
{
    $res = new Ride;

    $res->is_open = \basic_parser\parse__bool( $csv_arr, $offset );
    $res->summary = parse__RideSummary( $csv_arr, $offset );
    $res->pending_order_ids = \basic_parser\parse__vector( $csv_arr, $offset, '\basic_parser\parse__int' ); // Array
    $res->accepted_order_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->resolution = parse__ride_resolution_e( $csv_arr, $offset );

    return $res;
}

function parse__Address( & $csv_arr, & $offset )
{
    $res = new Address;

    $res->plz = \basic_parser\parse__int( $csv_arr, $offset );
    $res->country = \basic_parser\parse__string( $csv_arr, $offset );
    $res->city = \basic_parser\parse__string( $csv_arr, $offset );
    $res->street = \basic_parser\parse__string( $csv_arr, $offset );
    $res->house_number = \basic_parser\parse__string( $csv_arr, $offset );
    $res->extra_address_line = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__Order( & $csv_arr, & $offset )
{
    $res = new Order;

    $res->is_open = \basic_parser\parse__bool( $csv_arr, $offset );
    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->delivery_address = parse__Address( $csv_arr, $offset );
    $res->shopping_list_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->state = parse__order_state_e( $csv_arr, $offset );
    $res->resolution = parse__order_resolution_e( $csv_arr, $offset );

    return $res;
}

// base messages

function parse__Request( & $res, & $csv_arr, & $offset )
{
    // base class
    \generic_protocol\parse__Request( $res, $csv_arr, $offset );


}

// messages

function parse__AddRideRequest( & $csv_arr )
{
    $res = new AddRideRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->ride = parse__RideSummary( $csv_arr, $offset );

    return $res;
}

function parse__AddRideResponse( & $csv_arr )
{
    $res = new AddRideResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__CancelRideRequest( & $csv_arr )
{
    $res = new CancelRideRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__CancelRideResponse( & $csv_arr )
{
    $res = new CancelRideResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetRideRequest( & $csv_arr )
{
    $res = new GetRideRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetRideResponse( & $csv_arr )
{
    $res = new GetRideResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->ride = parse__Ride( $csv_arr, $offset );

    return $res;
}

function parse__AddOrderRequest( & $csv_arr )
{
    $res = new AddOrderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->shopping_list = parse__ShoppingList( $csv_arr, $offset );
    $res->delivery_address = parse__Address( $csv_arr, $offset );

    return $res;
}

function parse__AddOrderResponse( & $csv_arr )
{
    $res = new AddOrderResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__CancelOrderRequest( & $csv_arr )
{
    $res = new CancelOrderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__CancelOrderResponse( & $csv_arr )
{
    $res = new CancelOrderResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__AcceptOrderRequest( & $csv_arr )
{
    $res = new AcceptOrderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__AcceptOrderResponse( & $csv_arr )
{
    $res = new AcceptOrderResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__DeclineOrderRequest( & $csv_arr )
{
    $res = new DeclineOrderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__DeclineOrderResponse( & $csv_arr )
{
    $res = new DeclineOrderResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__MarkDeliveredOrderRequest( & $csv_arr )
{
    $res = new MarkDeliveredOrderRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__MarkDeliveredOrderResponse( & $csv_arr )
{
    $res = new MarkDeliveredOrderResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__RateShopperRequest( & $csv_arr )
{
    $res = new RateShopperRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->stars = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__RateShopperResponse( & $csv_arr )
{
    $res = new RateShopperResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

// generic

class Parser extends \generic_protocol\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return NULL;

    $handler_map = array(
        // messages
        'shopndrop/AddRideRequest'         => 'parse__AddRideRequest',
        'shopndrop/AddRideResponse'         => 'parse__AddRideResponse',
        'shopndrop/CancelRideRequest'         => 'parse__CancelRideRequest',
        'shopndrop/CancelRideResponse'         => 'parse__CancelRideResponse',
        'shopndrop/GetRideRequest'         => 'parse__GetRideRequest',
        'shopndrop/GetRideResponse'         => 'parse__GetRideResponse',
        'shopndrop/AddOrderRequest'         => 'parse__AddOrderRequest',
        'shopndrop/AddOrderResponse'         => 'parse__AddOrderResponse',
        'shopndrop/CancelOrderRequest'         => 'parse__CancelOrderRequest',
        'shopndrop/CancelOrderResponse'         => 'parse__CancelOrderResponse',
        'shopndrop/AcceptOrderRequest'         => 'parse__AcceptOrderRequest',
        'shopndrop/AcceptOrderResponse'         => 'parse__AcceptOrderResponse',
        'shopndrop/DeclineOrderRequest'         => 'parse__DeclineOrderRequest',
        'shopndrop/DeclineOrderResponse'         => 'parse__DeclineOrderResponse',
        'shopndrop/MarkDeliveredOrderRequest'         => 'parse__MarkDeliveredOrderRequest',
        'shopndrop/MarkDeliveredOrderResponse'         => 'parse__MarkDeliveredOrderResponse',
        'shopndrop/RateShopperRequest'         => 'parse__RateShopperRequest',
        'shopndrop/RateShopperResponse'         => 'parse__RateShopperResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\Parser::parse_csv_array( $csv_arr );
}

}

# namespace_end shopndrop_protocol


?>
