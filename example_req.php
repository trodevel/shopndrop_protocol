<?php

// $Revision: 10919 $ $Date:: 2019-04-26 #$ $Author: serge $

require_once 'shopndrop_protocol.php';

echo "OK\n";

$session_id = "afafaf";

{
    $ride = new \shopndrop_protocol\Ride( \shopndrop_protocol\GeoPosition::withPlz( 50668 ), new \basic_objects\LocalTime( 2019, 05, 22, 17, 30, 0 ), 2.5 );

    $req = new \shopndrop_protocol\AddRideRequest( $session_id, $ride );

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

    $req = new \shopndrop_protocol\AddOrderRequest( $session_id, $ride_id, $shopping_list );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id        = 101;

    $req = new \shopndrop_protocol\CancelOrderRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $user_id    = 101;

    $req = new \shopndrop_protocol\GetPersonalUserInfoRequest( $session_id, $user_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

/**************************************************
 * WEB REQUESTS
 **************************************************/

{
    $req = new \shopndrop_protocol\GetProductItemListRequest( $session_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $ride_id    = 101;

    $req = new \shopndrop_protocol\GetRideOrderInfoRequest( $session_id, $ride_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $user_id    = 115;

    $req = new \shopndrop_protocol\GetDashScreenUserRequest( $session_id, $user_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $user_id    = 115;

    $req = new \shopndrop_protocol\GetDashScreenShopperRequest( $session_id, $user_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
