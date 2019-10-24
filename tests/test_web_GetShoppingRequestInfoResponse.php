<?php

// $Revision: 11428 $ $Date:: 2019-05-15 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetShoppingRequestInfoResponse;4;121212;10.35;1.19423;2;50668;Germany;K=C3=B6ln;Eigelstein;1;=;232323;7.62;0.879231;2.7;50667;Germany;K=C3=B6ln;Hohe=20Strasse;17;=;343434;12.67;1.46192;1.5;50672;Germany;K=C3=B6ln;Antwerpener=20Strasse;25;=;454545;20.39;2.35269;1;50674;Germany;K=C3=B6ln;Lindenstrasse;56;=;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
