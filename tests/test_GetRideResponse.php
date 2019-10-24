<?php

// $Revision: 11428 $ $Date:: 2019-05-15 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'GetRideResponse;1;50668;0;0;20190522180000;2.5;3;565656;737373;878787;121212;0;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
