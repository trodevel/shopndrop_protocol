<?php

// $Revision: 10897 $ $Date:: 2019-04-25 #$ $Author: serge $

require_once 'shopndrop_protocol.php';

echo "OK\n";

$session_id = "afafaf";

{
    $ride = new \shopndrop_protocol\Ride( \shopndrop_protocol\GeoPosition::withPlz( 50668 ), new \basic_objects\LocalTime( 2019, 05, 22, 17, 30, 0 ), 2.5 );

    $req = new \shopndrop_protocol\AddRideRequest( $session_id, $ride );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
