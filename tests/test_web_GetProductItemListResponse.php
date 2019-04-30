<?php

// $Revision: 10986 $ $Date:: 2019-04-29 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetProductItemListResponse;4;121212;Milch;Packung;1.09;1;232323;Brot;St=C3=BCck;1.49;0.5;343434;Apfel;kg;2.49;1.5;454545;Nutella;Dose;1.99;0.3;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
