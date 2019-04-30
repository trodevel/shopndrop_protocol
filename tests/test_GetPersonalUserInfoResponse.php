<?php

// $Revision: 10977 $ $Date:: 2019-04-29 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'GetPersonalUserInfoResponse;123;1;John;Doe;Yoyodine=20Corp.;john.doe@yoyodine.com;+491234567890;Europe/Berlin;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
