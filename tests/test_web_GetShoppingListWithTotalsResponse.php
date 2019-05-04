<?php

// $Revision: 11035 $ $Date:: 2019-05-03 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetShoppingListWithTotalsResponse;4;121212;3;Milch;Packung;1.09;1;232323;2;Brot;St=C3=BCck;1.49;0.5;343434;1;Apfel;kg;2.49;1.5;454545;1;Nutella;Dose;1.99;0.3;10.73;5.8;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
