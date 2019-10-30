<?php

// $Revision: 12269 $ $Date:: 2019-10-25 #$ $Author: serge $

require_once 'shopndrop_protocol_web.php';

echo "OK\n";

$session_id = "afafaf";

{
    $ride_summary = new \shopndrop_protocol\RideSummary( \shopndrop_protocol\GeoPosition::withPlz( 50668 ), new \basic_objects\LocalTime( 2019, 05, 22, 17, 30, 0 ), 2.5 );

    $req = new \shopndrop_protocol\AddRideRequest( $session_id, $ride_summary );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id    = 101;

    $req = new \shopndrop_protocol\CancelRideRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id    = 101;

    $req = new \shopndrop_protocol\GetRideRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $items = array();

    array_push( $items, new \shopndrop_protocol\ShoppingItem( 1212, 1 ) );
    array_push( $items, new \shopndrop_protocol\ShoppingItem( 2323, 2 ) );
    array_push( $items, new \shopndrop_protocol\ShoppingItem( 3434, 7 ) );

    $shopping_list  = new \shopndrop_protocol\ShoppingList( $items );

    $delivery_address = new \shopndrop_protocol\Address( 50668, "Germany", "Köln", "Eigelstein", "10", "" );

    $req = new \shopndrop_protocol\AddOrderRequest( $session_id, $ride_id, $shopping_list, $delivery_address );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $req = new \shopndrop_protocol\CancelOrderRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $req = new \shopndrop_protocol\AcceptOrderRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $req = new \shopndrop_protocol\DeclineOrderRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $req = new \shopndrop_protocol\MarkDeliveredOrderRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;
    $stars          = 4;

    $req = new \shopndrop_protocol\RateShopperRequest( $session_id, $ride_id, $stars );

    echo "req = " . $req->to_generic_request() . "\n";
}

/**************************************************
 * WEB REQUESTS
 **************************************************/

{
    $req = new \shopndrop_protocol\web\GetProductItemListRequest( $session_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id    = 101;

    $req = new \shopndrop_protocol\web\GetShoppingRequestInfoRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $shopping_list_id   = 232323;

    $req = new \shopndrop_protocol\web\GetShoppingListWithTotalsRequest( $session_id, $shopping_list_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $user_id    = 115;

    $req = new \shopndrop_protocol\web\GetDashScreenUserRequest( $session_id, $user_id, \shopndrop_protocol\GeoPosition::withPlz( 50668 ) );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $user_id    = 115;

    $req = new \shopndrop_protocol\web\GetDashScreenShopperRequest( $session_id, $user_id, \shopndrop_protocol\GeoPosition::withPlz( 50668 ) );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
