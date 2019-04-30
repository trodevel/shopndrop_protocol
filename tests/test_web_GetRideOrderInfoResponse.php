<?php

// $Revision: 10992 $ $Date:: 2019-04-30 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetRideOrderInfoResponse;4;121212;10.35;1.19423;2;50668;0;0;Eigelstein=201;232323;7.62;0.879231;2.7;50667;0;0;Hohe=20Strasse=2017;343434;12.67;1.46192;1.5;50672;0;0;Antwerpener=20Strasse=2025;454545;20.39;2.35269;1;50674;0;0;Lindenstrasse=2056;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
